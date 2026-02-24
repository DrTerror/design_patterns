/*! ***************************************************************************
 * @file
 * @brief Needed Linux headers
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 *****************************************************************************/

#ifndef COMMON_LINUX_H_
#define COMMON_LINUX_H_

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

// Essential for serveral GCC and Linux functionalities
#define _GNU_SOURCE

// Thread names are limited to 16 chars
#define MAX_THREAD_NAME_LEN 16

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* Std */
#include <sys/types.h>
#include <sys/time.h>
#include <pthread.h>

/* IOs*/
#include <sys/ioctl.h>

/* Net */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include "net/if.h"

/* lists */
#ifdef __gnu_linux__
//#    include <linux/list.h>
//#    include <list.h>
#endif /* __gnu_linux__ */

#endif /* COMMON_LINUX_H_ */
