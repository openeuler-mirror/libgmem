/*
 * Copyright (c) 2023 Huawei Technologies Co., Ltd. 
 * libgmem is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

#include <libgmem.h>
#include <jemalloc/jemalloc.h>

#define strong_alias(gmem_fn) __attribute__ ((alias (#gmem_fn)))

void *gmem_malloc(size_t size)
{
	return malloc(size);
}

void gmem_free(void *ptr)
{
	return free(ptr);
}

void *gmem_realloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}

void* malloc(size_t size) __THROW strong_alias(gmem_malloc);
void free(void *ptr) __THROW strong_alias(gmem_free);
void *realloc(void *ptr, size_t size) __THROW strong_alias(gmem_realloc);

