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

#ifndef _GMEM_WAPPER_H_
#define _GMEM_WAPPER_H_

#include <libgmem.h>
#include <stdlib.h>
#include <syscall.h>
#include <rpg_dev.h>

typedef struct {
    int (*FreeEager)(void *userData, void *stream);
    int (*Prefetch)(void *userData, void *stream);
    int (*GetNumaId)(void);
} gmem_semantics;
extern gmem_semantics gmemSemantics;
extern int gmem_fd;

typedef struct hmadvise_arg gm_msg;
typedef gm_msg *gm_msg_t;

void init_device(void);
void destory_device(void);

int gmemAdvise(void *userData);
#endif
