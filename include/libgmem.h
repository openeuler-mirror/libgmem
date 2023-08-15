#ifndef _LIBGMEM_H
#define _LIBGMEM_H

#include <unistd.h>
#include <syscall.h>

/*
 * __NR_madvise 441
 */
#ifndef SYS_hmdvise
# ifndef __NR_hmadvise
#   define __NR_hmadvise -1
# endif
# define SYS_hmadvise __NR_hmadvise
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

#endif
