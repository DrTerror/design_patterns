/*! ***************************************************************************
 * @file
 * @brief Common macros
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 *****************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* ****************************************************************************
 *  M A C R O S
 *************************************************************************** */

/* Only active if DEBUG is defined */
#ifdef DEBUG
#    define DBG(arg) arg
#else /* DEBUG */
#    define DBG(arg)
#endif /* DEBUG */

/*** Misc. ***/

/*! ***************************************************************************
 * @def MIN(a)
 * @brief Returns the minimum of two numbers
 * @param a Number a
 * @param b Number b
 * @returns Minimum
 *************************************************************************** */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/*! ***************************************************************************
 * @def MIN(a)
 * @brief Returns the maximum of two numbers
 * @param a Number a
 * @param b Number b
 * @returns Maximum
 *************************************************************************** */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/*! ***************************************************************************
 * @def LIMIT(x, min, max)
 * @brief Returns 'x' limited to the range specified by 'min' and 'max'
 * @param x
 * @param min
 * @param max
 * @returns Limited x value
 *************************************************************************** */
#define LIMIT(x, min, max) (((x) <= (min)) ? (min) : (((x) >= (max)) ? (max) : (x)))

/*! ***************************************************************************
 * @def ARRAY_ELEMENT_COUNT(a)
 * @brief Counts the elements of the given array a
 * @param a Array
 * @returns Number of elements
 * @note !!! Does not work with pointers !!!
 *************************************************************************** */
#define ARRAY_ELEMENT_COUNT(a) (sizeof((a)) / sizeof((a)[0]))

/*! ***************************************************************************
 * @def UNUSED
 * @brief reader friendly void-cast-macro
 * @param x    variable to voided
 *************************************************************************** */
#define UNUSED(x) (void) (x)

/* BCD coding */
#undef BCD_TO_BIN
#define BCD_TO_BIN(val) (((val) & 15) + ((val) >> 4) * 10)
#undef BIN_TO_BCD
#define BIN_TO_BCD(val) ((((val) / 10) << 4) + (val) % 10)

/* For booleans */
#define MAKE_BOOL(e) (!!(MAKE_BOOL(e))) /* 0 -> 0, 1+ -> 1 */
#define IS_TRUE(e)   ((e) != 0)
#define IS_FALSE(e)  ((e) == 0)

/*** Bit operations ***/

#define BIT_MASK(bit) (1U << ((bit) % CHAR_BIT))
#define BIT_SLOT(bit) ((bit) / CHAR_BIT)

/* Inverts a variable */
#define INVERT(var) (~(var))

/*! ***************************************************************************
 * @def SET_BIT_POS(ary, bit)
 * @brief Set nth-bit
 *
 * Set single bit at pos to '1' by generating a mask in the proper bit
 * location and ORing (|) x with the mask.
 *
 * @param x
 * @param pos
 *************************************************************************** */
#define SET_BIT_POS(ary, bit) ((ary)[BIT_SLOT(bit)] |= BIT_MASK(bit))

/* Sets a bit within a variable */
#define SET_BIT(var, mask) ((var) |= (mask))

/*! ***************************************************************************
 * @def CLEAR_BIT_POS(x, pos)
 * @brief Clear nth-bit
 *
 * Set single bit at pos to '0' by generating a mask in the proper bit
 * location and ANDing x with the mask.
 *
 * @param x
 * @param pos
 *************************************************************************** */
#define CLEAR_BIT_POS(x, pos) (x &= (~(1U << pos)))

/* Clears a bit within an 8-bit variable */
#define CLEAR_BIT_8(var, mask) ((var) &= (uint8_t) ~(mask))

/*! ***************************************************************************
 * @def TOGGLE_BIT_POS(x, pos)
 * @brief Toggle nth-bit
 *
 * Set single bit at pos to '1' by generating a mask in the proper bit
 * location and ex-ORing x with the mask.
 *
 * @param x
 * @param pos
 *************************************************************************** */
#define TOGGLE_BIT_POS(x, pos) (x ^= (1U << pos))

/* Toggles a bit within a variable */
#define TOGGLE_BIT(var, mask) ((var) ^= (mask))

/*! ***************************************************************************
 * @def GET_BITx(x, pos)
 * @brief Get bit from the given position
 *
 * @param x
 * @param pos
 * @returns
 *************************************************************************** */
#define GET_BIT(x, pos)  (((x) >> (pos)) & 1)
#define GET_BITS(x, pos) ((x & (1 << pos)) >> pos)

/*! ***************************************************************************
 * @def TEST_BIT(ary, bit)
 * @brief
 *
 * @param ary
 * @param bit
 * @returns
 *************************************************************************** */
#define TEST_BIT(ary, bit) ((ary)[BIT_SLOT(bit)] & BIT_MASK(bit))

/*! ***************************************************************************
 * @def CHECK_BIT(x, pos)
 * @brief Macro to check nth-bit
 *
 * Set single bit at pos to '1' by generating a mask in the proper bit
 * location and ANDing x with the mask.
 *
 * @param x Value to check against
 * @param pos Position
 * @returns It evaluates 1 if a bit is set otherwise 0
 *************************************************************************** */
#define CHECK_BIT(x, pos) (x & (1UL << pos))

/*** Swappings ***/

/* Macro to swap byte of 16-bit integer variable */
#define SWAP_BYTE_16(val) ((uint16_t) ((uint16_t) (val) >> 8) | (uint16_t) ((uint16_t) (val) << 8))

/* Macro to swap byte of 32-bit integer variable */
#define SWAP_BYTE_32(val) ((((uint32_t) (val) & (uint32_t) 0x000000FFU) << 24) | (((uint32_t) (val) & (uint32_t) 0x0000FF00U) << 8) | (((uint32_t) (val) & (uint32_t) 0x00FF0000U) >> 8) | (((uint32_t) (val) & (uint32_t) 0xFF000000U) >> 24))

/* Macro to swap byte of 64-bit integer variable */
#define SWAP_BYTE_64(val) ((((uint64_t) (val) & (uint64_t) 0x00000000000000FFLL) << 56) | (((uint64_t) (val) & (uint64_t) 0x000000000000FF00LL) << 40) | (((uint64_t) (val) & (uint64_t) 0x0000000000FF0000LL) << 24) | (((uint64_t) (val) & (uint64_t) 0x00000000FF000000LL) << 8) | (((uint64_t) (val) & (uint64_t) 0x000000FF00000000LL) >> 8) | (((uint64_t) (val) & (uint64_t) 0x0000FF0000000000LL) >> 24) | (((uint64_t) (val) & (uint64_t) 0x00FF000000000000LL) >> 40) | (((uint64_t) (val) & (uint64_t) 0xFF00000000000000LL) >> 56))

/* Macro to swap nibbles */
#define SWAP_NIBBLES(x) ((x & 0x0F) << 4 | (x & 0xF0) >> 4)

/* Macro to swap two numbers */
#define SWAP(x, y) (x ^= y ^= x ^= y)

/* Macro to swap odd-even bits */
#define SWAP_ODD_EVEN_BIT(x) ((x & 0xAAAAAAAA) >> 1 | (x & 0x55555555) << 1);

/*** Shiftings ***/

/*! ***************************************************************************
 * @def SHIFT_L_N_BYTE(b ,n)
 * @brief Shifts b left by n bytes.
 * @param b variable to shift left
 * @param n bytes to shift
 * @returns left shifted value of n by n bytes
 *************************************************************************** */
#define SHIFT_L_N_BYTE(b, n)      ((b) << ((n) * 8))
#define SHIFT_L_N_BYTE_T(b, n, t) ((t) (b) << ((n) * 8))

/*! ***************************************************************************
 * @def SHIFT_R_N_BYTE(b ,n)
 * @brief Shifts b right by n bytes.
 * @param b variable to shift right
 * @param n bytes to shift
 * @returns right shifted value of n by n bytes
 *************************************************************************** */
#define SHIFT_R_N_BYTE(b, n) ((b) >> ((n) * 8))

/*** String operations ***/

/*! ***************************************************************************
 * @def TOSTRING(x)
 * @brief Convert an array of characters into a C string
 *
 * @param x Text
 *************************************************************************** */
#define STRINGIFY(x) #x
#define TOSTRING(x)  STRINGIFY(x)

/*! ***************************************************************************
 * @def STR_EQ(str1, str2)
 * @brief Are two strings equal?
 *
 * @param str1 String1
 * @param str2 String2
 *************************************************************************** */
#define STR_EQ(str1, str2) (strcmp((str1), (str2)) == 0)

/*** Error handling ***/

#define EXCEPT_THROW(label) goto label
#define EXCEPT_CATCH(label) \
    while (0)               \
    label:

/*! ***************************************************************************
 * @def TODO(x)
 * @brief Prompt a compiler TODO message
 *
 * @param x message
 *************************************************************************** */
#define DO_PRAGMA(x) _Pragma(#x)
#define TODO(x)      DO_PRAGMA(message("TODO - " #x))

/*! ***************************************************************************
 * @brief Make module defined variables
 *************************************************************************** */
#define _MODULE_NAME(m) #m
#define MODULE_DATE(m) (m##_modDate)
#define MODULE_TIME(m) (m##_modTime)

#endif /* COMMON_MACROS_H_ */
