#ifndef _GMEM_ASCEND_H_
#define  _GMEM_ASCEND_H_


/*
 * These definitions should be placed in the kernel,
 * which is a temporary implementation here.
 */

#define RPG_MAGIC 0x55

enum _RPG_IOCTL_CMD {
	_RPG_GET_HNUMA_ID = 1,
	_RPG_IOC_MAX_NR
};

struct rpg_hnid_arg {
	int *hnuma_id;
};

#define RPG_GET_HNUMA_ID \
	_IOW(RPG_MAGIC, _RPG_GET_HNUMA_ID, struct rpg_hnid_arg)

#endif
