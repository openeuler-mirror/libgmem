/*
 * Copyright (c) 2023 Huawei Technologies Co., Ltd. 
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
#include <fcntl.h>

#include <libgmem.h>
#include <gmem_common.h>

int gmem_fd;

int init_libgmem(void) __attribute__ ((constructor));
void exit_libgmem(void) __attribute__ ((destructor));

int get_gmem_fd()
{
	gmem_fd = open("/dev/gmem", O_RDWR);
	if (gmem_fd == -1) {
		 perror("Get gmem fd failed");
		 return -ENXIO;
	}
	return 0;
}

void release_gmem_fd()
{
	close(gmem_fd);
}

int init_libgmem(void)
{
	if (get_gmem_fd()) {
		return -ENXIO;
	}
	init_device();
	return 0;
}

void exit_libgmem(void)
{
	release_gmem_fd();
	destory_device();
}

