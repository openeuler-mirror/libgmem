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

#ifndef _LIBGMEM_H
#define _LIBGMEM_H

#include <unistd.h>
#include <syscall.h>

__BEGIN_DECLS
/*
 * TODO: Remove these "ifndef" after kernel upgrade
 */
/*
 * __NR_madvise 441
 */
#ifndef SYS_hmdvise
# ifndef __NR_hmadvise
#   define __NR_hmadvise 441
# endif
# define SYS_hmadvise __NR_hmadvise
#endif

#ifndef MADV_PREFETCH
# define MADV_PREFETCH 32
#endif

#ifndef MADV_DONTNEED
# define MADV_DONTNEED 4
#endif

/*
 * gmemFreeEager - unmap memory data
 * @args
 *     addr:    start address of the memory to be migrated
 *     length:  length of the memory to be migrated
 *     stream:  the stream where work queue used by operation
 *
 * unmapp the logical page table of [addr, addr + length)
 */
int gmemFreeEager(unsigned long addr, size_t size, void *stream);

/*
 * gmemPrefetch - migrating memory data
 * @args
 *     addr:    start address of the memory to be migrated
 *     length:  length of the memory to be migrated
 *     stream:  the stream where work queue used by operation
 *
 * The physical data mapped by [addr, addr + length) will migrate to
 * the device corresponding to streamid. The hnuma node of the device
 *  in the current context needs to be automatically obtained
 * and the prefetch instruction of hmadvise is invoked.
 *
 * The asynchronous operation is non-blocking, but is executed in
 * sequence with the tasks in the stream.
 */
int gmemPrefetch(unsigned long addr, size_t length, void *stream);

/*
 * gmemGetNumaId - get the numaid of the current device
 * 
 * Returns the numaid of the current device. If it is a negative number,
 * it indicates that the acquisition failed.
 */
int gmemGetNumaId(void);
__END_DECLS

#endif
