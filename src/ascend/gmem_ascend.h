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
