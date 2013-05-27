#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <time.h>
#include <termios.h>

//#ifdef __cplusplus
//extern "C" {
//#endif

typedef union {
  unsigned char wlan_mac_address[6];
} nv_item_type;


/* temp until they appear in a header file somewhere */
extern void oncrpc_task_start(void);
extern void oncrpc_init(void);
extern int nv_null(void);
static int nv_available;

typedef enum {
    NV_READ_F,          /* Read item */
    NV_WRITE_F,         /* Write item */
} nv_func_enum_type;

typedef enum {
    NV_WLAN_MAC_ADDRESS_I                          = 4678
} nv_items_enum_type;

typedef enum {
    NV_DONE_S,
    NV_BUSY_S
} nv_stat_enum_type;

nv_stat_enum_type nv_cmd_remote (nv_func_enum_type cmd,nv_items_enum_type item,nv_item_type *data_ptr);


#ifdef __cplusplus
}
#endif


unsigned char *read_mac() {
    static nv_item_type my_nv_item;
    static nv_stat_enum_type cmd_result;
	int i;
        oncrpc_init();
        oncrpc_task_start();
	nv_available = nv_null();
	cmd_result = nv_cmd_remote(NV_READ_F,  NV_WLAN_MAC_ADDRESS_I, &my_nv_item);
	printf("WLAN Address\n");
	for(i=5;i>0;i--)
		printf("%2x:",my_nv_item.wlan_mac_address[i]);
	return my_nv_item.wlan_mac_address;
}

