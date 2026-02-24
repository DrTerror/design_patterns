/*! ***************************************************************************
 * @file
 * @brief Common defines
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 * @todo check undefs!
 *
 *****************************************************************************/

#ifndef COMMON_DEFINES_H_
#define COMMON_DEFINES_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

/* In-Out information for function parameters */
#define _IN_
#define _IN_OUT_
#define _OUT_

#if defined(linux) || defined(__linux__)
#    define NEW_LINE "\n"
#else
#    define NEW_LINE "\r\n"
#endif
#define TAB "\t"

#ifndef NO_ERROR
#    define NO_ERROR (0)
#endif
#ifndef ERROR
#    define ERROR (1)
#endif

#ifndef DISABLE
#    define DISABLE (0)
#endif
#ifndef ENALBE
#    define ENABLE (1)
#endif

#ifndef LOW
#    define LOW (0)
#endif
#ifndef HIGH
#    define HIGH (1)
#endif

#ifdef NO
#    undef NO
#endif
#define NO (0)

#ifdef YES
#    undef YES
#endif
#define YES (1)

#ifdef OFF
#    undef OFF
#endif
#define OFF (0)

#ifdef ON
#    undef ON
#endif
#define ON (1)

#ifdef FOREVER
#    undef FOREVER
#endif
#define FOREVER (1)

/* 32 bit codes */
#define BIT_00 0x00000001u /* b_0:0:0:0000_0001 */
#define BIT_01 0x00000002u /* b_0:0:0:0000_0010 */
#define BIT_02 0x00000004u /* b_0:0:0:0000_0100 */
#define BIT_03 0x00000008u /* b_0:0:0:0000_1000 */

#define BIT_04 0x00000010u /* b_0:0:0:0001_0000 */
#define BIT_05 0x00000020u /* b_0:0:0:0010_0000 */
#define BIT_06 0x00000040u /* b_0:0:0:0100_0000 */
#define BIT_07 0x00000080u /* b_0:0:0:1000_0000 */

#define BIT_08 0x00000100u /* b_0:0:0000_0001:0 */
#define BIT_09 0x00000200u /* b_0:0:0000_0010:0 */
#define BIT_10 0x00000400u /* b_0:0:0000_0100:0 */
#define BIT_11 0x00000800u /* b_0:0:0000_1000:0 */

#define BIT_12 0x00001000u /* b_0:0:0001_0000:0 */
#define BIT_13 0x00002000u /* b_0:0:0010_0000:0 */
#define BIT_14 0x00004000u /* b_0:0:0100_0000:0 */
#define BIT_15 0x00008000u /* b_0:0:1000_0000:0 */

#define BIT_16 0x00010000u /* b_0:0000_0001:0:0 */
#define BIT_17 0x00020000u /* b_0:0000_0010:0:0 */
#define BIT_18 0x00040000u /* b_0:0000_0100:0:0 */
#define BIT_19 0x00080000u /* b_0:0000_1000:0:0 */

#define BIT_20 0x00100000u /* b_0:0001_0000:0:0 */
#define BIT_21 0x00200000u /* b_0:0010_0000:0:0 */
#define BIT_22 0x00400000u /* b_0:0100_0000:0:0 */
#define BIT_23 0x00800000u /* b_0:1000_0000:0:0 */

#define BIT_24 0x01000000u /* b_0000_0001:0:0:0 */
#define BIT_25 0x02000000u /* b_0000_0010:0:0:0 */
#define BIT_26 0x04000000u /* b_0000_0100:0:0:0 */
#define BIT_27 0x08000000u /* b_0000_1000:0:0:0 */

#define BIT_28 0x10000000u /* b_0001_0000:0:0:0 */
#define BIT_29 0x20000000u /* b_0010_0000:0:0:0 */
#define BIT_30 0x40000000u /* b_0100_0000:0:0:0 */
#define BIT_31 0x80000000u /* b_1000_0000:0:0:0 */

/* Bases for number system */
#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16

// TODO big endian und little endian structs
#if defined(__GNUC__)
#    define PACKED_STRUCT struct __attribute__((__packed__))
#endif

// see endian.h
//#define LITTLE_ENDIAN 0 /* 2^0 + 2^1 + ... + 2^n */
//#define BIG_ENDIAN    1 /* 2^n + 2^n-1 + ... + 2^0 */

#endif /* COMMON_DEFINES_H_ */
