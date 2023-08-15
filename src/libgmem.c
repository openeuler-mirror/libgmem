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

#include <errno.h>
#include <linux/mman.h>
#include <stdio.h>
#include <stdlib.h>

#include <libgmem.h>
#include <gmem_common.h>

gmem_semantics gmemSemantics;

static void mix_userData(gm_msg_t userData, unsigned long addr, size_t length, int hnid, int behavior)
{
	userData->behavior = behavior;
	userData->addr = addr;
	userData->size = length;
	userData->hnid = hnid;
}

int gmemAdvise(void *userData)
{
	gm_msg_t msg = (gm_msg_t)userData;
	int ret = syscall(SYS_hmadvise, msg->hnid, msg->addr, msg->size, msg->behavior);
	if(ret) {
		printf("hmadvise failed: addr:%lx, size:%lx, behavior:%d, hnid:%d\n", msg->addr, msg->size, msg->behavior, msg->hnid);
	}
	return ret;
}

int gmemFreeEager(unsigned long addr, size_t length, void *stream)
{
	int ret = -1;
	gm_msg_t userData = (gm_msg_t)malloc(sizeof(struct gm_msg));
	mix_userData(userData, addr, length, -1, MADV_DONTNEED);
	if (!stream) {
		ret = gmemAdvise(userData);
	} else if(gmemSemantics.FreeEager != NULL) {
		ret = gmemSemantics.FreeEager(userData, stream);
	}
	free(userData);
	return ret;
}

int gmemPrefetch(unsigned long addr, size_t length, void *stream)
{
	int ret = -1;
	gm_msg_t userData = (gm_msg_t)malloc(sizeof(struct gm_msg));
	mix_userData(userData, addr, length, gmemGetNumaId(), MADV_PREFETCH);
	if (!stream) {
		ret = gmemAdvise(userData);
	} else if(gmemSemantics.Prefetch != NULL) {
		ret = gmemSemantics.FreeEager(userData,stream);
	}
	free(userData);
	return ret;
}

int gmemGetNumaId(void)
{
	int ret = -1;
	if(gmemSemantics.GetNumaId != NULL) {
		 ret = gmemSemantics.GetNumaId();
	}
	return ret;
}
