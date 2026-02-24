/*! ***************************************************************************
 * @file
 * @brief Common typedefs
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 *****************************************************************************/

#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

#include <stdint.h>
#include <float.h>

/* ****************************************************************************
 *  T Y P E S
 *************************************************************************** */

#if 0
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;

typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
typedef int64_t     s64;

typedef float       f32;
typedef double      f64;
#endif

// TODO big endian und little endian structs
#if defined(__GNUC__)
#    define PACKED_STRUCT struct __attribute__((__packed__))
#endif

#endif /* COMMON_TYPES_H_ */
