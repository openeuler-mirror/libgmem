/*
 * Copyright (c) 2023 yangyanchao6@huawei.com 
 * libgmem is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <dlfcn.h>

#include <gmem_common.h>

#include "gmem_ascend.h"

#define LIB_ASCENDCL_PATH "/usr/local/Ascend/ascend-toolkit/latest/aarch64-linux/lib64/libascendcl.so"

void init_gmemSemantics(void) __attribute__ ((constructor));
void exit_gmemSemantics(void) __attribute__ ((destructor));

typedef void (*Callback_fn)(void *userData);
typedef int (*ACLRT_LAUNCH_CB_FUNC)(Callback_fn fn, void *userData, int vlockType, void *stream);
ACLRT_LAUNCH_CB_FUNC aclrtLaunchCallback_fn;
void *handle;

int ascend_eager_free(void *userData, void *stream)
{
    return aclrtLaunchCallback_fn((void (*)(void *))gmemAdvise, userData, 1, stream);
}

int ascend_prefech(void *userData, void *stream)
{
    return aclrtLaunchCallback_fn((void (*)(void *))gmemAdvise, userData, 1, stream);
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
	handle = dlopen(LIB_ASCENDCL_PATH, RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	aclrtLaunchCallback_fn = (ACLRT_LAUNCH_CB_FUNC) dlsym(handle, "aclrtLaunchCallback");
	gmemSemantics.FreeEager = ascend_eager_free;
	gmemSemantics.Prefetch = ascend_prefech;
	gmemSemantics.GetNumaId = ascend_numaid;
}

void exit_gmemSemantics()
{
	dlclose(handle);
}
