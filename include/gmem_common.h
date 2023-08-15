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
