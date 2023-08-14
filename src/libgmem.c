#include <errno.h>
#include <linux/mman.h>
#include <stdio.h>
#include <stdlib.h>

#include <libgmem.h>

struct gm_msg {
	int behavior;
	unsigned long addr;
	size_t size;
	int hnid;
};
typedef struct gm_msg *gm_msg_t;

void gmemAdvise(void *userData) {
	struct gm_msg *msg = (struct gm_msg *)userData;
	int ret = syscall(SYS_hmadvise, msg->hnid, msg->addr, msg->size, msg->behavior);
	if(ret) {
		printf("hmadvise failed: addr:%lx, size:%lx, behavior:%d, hnid:%d\n", msg->addr, msg->size, msg->behavior, msg->hnid);
	}
}

int gmemFreeEager(unsigned long addr, size_t length, void *stream)
{
	return 0;
}

int gmemPrefetch(unsigned long addr, size_t length, void *stream)
{
 	return 0;
}

int gmemGetNumaId(void)
{
	return 0;
}
