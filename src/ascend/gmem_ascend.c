#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <gmem_common.h>

#include "acl/acl.h"
#include "gmem_ascend.h"

void init_gmemSemantics(void) __attribute__ ((constructor));

int ascend_eager_free(void *userData, void *stream)
{
    return aclrtLaunchCallback((void (*)(void*))gmemAdvise, userData, ACL_CALLBACK_BLOCK, (aclrtStream)stream);
}

int ascend_prefech(void *userData, void *stream)
{
    return aclrtLaunchCallback((void (*)(void*))gmemAdvise, userData, ACL_CALLBACK_BLOCK, (aclrtStream)stream);
}

int ascend_numaid(void)
{
	int ret, id, fd;
	struct rpg_hnid_arg arg;

	fd = open("/dev/remote_pager", O_RDWR);
	if (fd == -1) {
		perror("Get davinci_manager fd failed");
		return -ENXIO;
	}


	arg.hnuma_id = &id;
	ret = ioctl(fd, RPG_GET_HNUMA_ID, &arg);
	if (ret < 0) {
		perror("Get hnuma id ioctl failed.");
		return ret;
	}
	close(fd);
	return id;
}

void init_gmemSemantics()
{
	gmemSemantics.FreeEager = ascend_eager_free;
	gmemSemantics.Prefetch = ascend_prefech;
	gmemSemantics.GetNumaId = ascend_numaid;
}
