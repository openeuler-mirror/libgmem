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

#ifndef _GMEM_WAPPER_H_
#define _GMEM_WAPPER_H_

#include <stdlib.h>

struct gm_msg {
	int behavior;
	unsigned long addr;
	size_t size;
	int hnid;
};
typedef struct gm_msg *gm_msg_t;

typedef struct {
    int (*FreeEager)(void *userData, void *stream);
    int (*Prefetch)(void *userData, void *stream);
    int (*GetNumaId)(void);
} gmem_semantics;
extern gmem_semantics gmemSemantics;

int gmemAdvise(void *userData);
#endif
