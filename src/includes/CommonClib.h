/*! ***************************************************************************
 * @file
 * @brief Common C-Lib headers
 *
 * C-Lib
 *
 * @author hellfisch
 * @date 2023.09.05
 *
 *****************************************************************************/

#ifndef COMMON_CLIB_H_
#define COMMON_CLIB_H_

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

// Essential for serveral GCC and Linux functionalities
#define _GNU_SOURCE

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* C-Lib */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
//#include <math.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

#ifdef DEBUGGING_ON
#    include <assert.h> /* C Diagnostics Library */
#endif

#endif /* COMMON_CLIB_H_ */
