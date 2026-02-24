/*! ***************************************************************************
 * @file
 * @brief Compile time assertions in C
 *
 * @sa https://www.pixelbeat.org/programming/gcc/static_assert.html
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 *****************************************************************************/

#ifndef COMMON_STATIC_ASSERT_H_
#define COMMON_STATIC_ASSERT_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b)  ASSERT_CONCAT_(a, b)

/* These can't be used after statements in c89. */
#ifdef __COUNTER__
#    define STATIC_ASSERT(e, m)                                            \
        ;                                                                  \
        enum                                                               \
        {                                                                  \
            ASSERT_CONCAT(static_assert_, __COUNTER__) = 1 / (int) (!!(e)) \
        }
#else /* __COUNTER__ */
/* This can't be used twice on the same line so ensure if using in headers
     * that the headers are not included twice (by wrapping in #ifndef...#endif)
     * Note it doesn't cause an issue when used on same line of separate modules
     * compiled with gcc -combine -fwhole-program.  */
#    define STATIC_ASSERT(e, m)                                       \
        ;                                                             \
        enum                                                          \
        {                                                             \
            ASSERT_CONCAT(assert_line_, __LINE__) = 1 / (int) (!!(e)) \
        }
#endif /* __COUNTER__ */

#endif /* COMMON_STATIC_ASSERT_H_ */
