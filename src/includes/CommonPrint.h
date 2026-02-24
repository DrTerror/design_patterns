/*! ***************************************************************************
 * @file
 * @brief Several print and debug macros
 *
 * @author hellfisch
 * @date 2023.07.10
 *
 *****************************************************************************/

#ifndef COMMON_PRINT_H_
#define COMMON_PRINT_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

#include <stdio.h>

#include "CommonDefines.h"

// FIXME for GetLocalTimeString
//#include "menu.h"

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

#define TIME_STRING_MAX_LEN 20

/* ****************************************************************************
 *  M A C R O S
 *************************************************************************** */

/*! ***************************************************************************
 * @def COMMON_DEBUG_INIT(x)
 * @brief Initialise the local debug mask variable
 *
 * @param x init value
 *************************************************************************** */
#if !defined(NDEBUG) && defined(DEBUG) && (DEBUG > 0)
#    define COMMON_DEBUG_INIT(x) static uint32_t commonDebugLevel = (x)
#    define COMMON_DEBUG_SET(x)  commonDebugLevel = (x)
#    define COMMON_DEBUG_GET     commonDebugLevel
#else /* DEBUG */
#    define COMMON_DEBUG_INIT(x)
#    define COMMON_DEBUG_SET(x)
#    define COMMON_DEBUG_GET
#endif /* DEBUG */

/*! ***************************************************************************
 * @def FOR_DEBUG(arg)
 * @brief Prints only for debugging purposes.
 *
 * Will be stripped in release builds.
 *************************************************************************** */
#if !defined(NDEBUG) && defined(DEBUG) && (DEBUG > 0)
#    define FOR_DEBUG(arg)            \
        do                            \
        {                             \
            if (commonDebugLevel > 0) \
            {                         \
                arg;                  \
            }                         \
        } while (0)
#else /* DEBUG */
#    define FOR_DEBUG(arg)
#endif /* DEBUG */

/*! ***************************************************************************
 * @def COMMON_PRINT_INIT
 * @brief Initialise the local print mask variable
 *
 * @param x init value
 *************************************************************************** */
// FIXME
//#if !defined(NDEBUG) && defined(DEBUG) && (DEBUG > 0)
#define COMMON_PRINT_INIT(x) static uint32_t commonVerboseLevel = (x)
#define COMMON_PRINT_SET(x)  commonVerboseLevel = (x)
#define COMMON_PRINT_GET     commonVerboseLevel
// #else /* DEBUG */
// #    define COMMON_PRINT_INIT(x)
// #    define COMMON_PRINT_SET(x)
// #    define COMMON_PRINT_GET
// #endif /* DEBUG */

/*! ***************************************************************************
 * @def PRINT_NL(doFlush, fstr, args...)
 * @brief Print to stdout
 *
 * Without time stamp, newline and flush (optional).
 *
 * @param doFlush Call fflush?
 * @param fstr format string
 * @param args Arguments for fstr
 *************************************************************************** */
#if (defined __gnu_linux__) || (defined _WIN32)
#    define PRINT_NL(doFlush, fstr, args...)                                           \
        do                                                                             \
        {                                                                              \
            fprintf(stdout, "[%s@%d] " fstr NEW_LINE, __FUNCTION__, __LINE__, ##args); \
            if (doFlush)                                                               \
                fflush(stdout);                                                        \
        } while (0)
#endif /* __gnu_linux__ */

/*! ***************************************************************************
 * @def PRINT_TIME_NL(outType, doFlush, fstr, args...)
 * @brief Print to outType (stdout, stderr)
 *
 * With time stamp, newline and flush (optional).
 *
 * @param outType stdout, stderr
 * @param doFlush Call fflush?
 * @param fstr format string
 * @param args Arguments for fstr
 *************************************************************************** */
#if (IS_GETTIME_DEFINED)
#    if (defined __gnu_linux__) || (defined _WIN32)
#        define PRINT_TIME_NL(outType, doFlush, fstr, args...)                                                                                      \
            do                                                                                                                                      \
            {                                                                                                                                       \
                char timeBuffer[TIME_STRING_MAX_LEN] = {0};                                                                                         \
                fprintf(outType, "[%s@%d] %s: " fstr NEW_LINE, __FUNCTION__, __LINE__, GetLocalTimeString(timeBuffer, sizeof(timeBuffer)), ##args); \
                if (doFlush)                                                                                                                        \
                    fflush(outType);                                                                                                                \
            } while (0)
#    endif /* __gnu_linux__ */
#endif     /* IS_GETTIME_DEFINED */

/*! ***************************************************************************
 * @def PRINT_TIME_NL_MASK(outType, doFlush, fstr, mask, args...)
 * @brief Print to outType (stdout, stderr)
 *
 * With time stamp, newline and flush (optional).
 *
 * @param outType stdout, stderr
 * @param doFlush Call fflush?
 * @param fstr format string
 * @param mask verbose bit mask @sa COMMON_PRINT_INIT
 * @param args Arguments for fstr
 *************************************************************************** */
#if (IS_GETTIME_DEFINED)
#    if (defined __gnu_linux__) || (defined _WIN32)
#        define PRINT_TIME_NL_MASK(outType, doFlush, mask, fstr, args...)                                                                               \
            do                                                                                                                                          \
            {                                                                                                                                           \
                if (commonVerboseLevel & mask)                                                                                                          \
                {                                                                                                                                       \
                    char timeBuffer[TIME_STRING_MAX_LEN] = {0};                                                                                         \
                    fprintf(outType, "[%s@%d] %s: " fstr NEW_LINE, __FUNCTION__, __LINE__, GetLocalTimeString(timeBuffer, sizeof(timeBuffer)), ##args); \
                    if (doFlush)                                                                                                                        \
                        fflush(outType);                                                                                                                \
                }                                                                                                                                       \
            } while (0)
#    endif /* __gnu_linux__ */
#endif     /* IS_GETTIME_DEFINED */

/*! ***************************************************************************
 * @def PRINT_TIME_ERRNO_NL(doFlush, fstr, args...)
 * @brief Print to stderr with errno infos
 *
 * With time stamp, newline and flush (optional).
 *
 * @param doFlush Call fflush?
 * @param fstr format string
 * @param args Arguments for fstr
 *************************************************************************** */
#if (IS_GETTIME_DEFINED)
#    if (defined __gnu_linux__) || (defined _WIN32)
#        define PRINT_TIME_ERRNO_NL(doFlush, fstr, args...)                                                                                                                                           \
            do                                                                                                                                                                                        \
            {                                                                                                                                                                                         \
                int  tmpErrno                        = errno;                                                                                                                                         \
                char timeBuffer[TIME_STRING_MAX_LEN] = {0};                                                                                                                                           \
                fprintf(stderr, "[%s@%d] %s: !!! ERROR: " fstr " %s(%d)" NEW_LINE, __FUNCTION__, __LINE__, GetLocalTimeString(timeBuffer, sizeof(timeBuffer)), ##args, strerror(tmpErrno), tmpErrno); \
                if (doFlush)                                                                                                                                                                          \
                    fflush(stderr);                                                                                                                                                                   \
            } while (0)
#    endif /* __gnu_linux__ */
#endif     /* IS_GETTIME_DEFINED */

/*! ***************************************************************************
 * @def PRINT_TIME_ERR_NL(doFlush, fstr, args...)
 * @brief Print to stderr
 *
 * With time stamp, newline and flush (optional).
 *
 * @param doFlush Call fflush?
 * @param fstr format string
 * @param args Arguments for fstr
 *************************************************************************** */
#if (IS_GETTIME_DEFINED)
#    if (defined __gnu_linux__) || (defined _WIN32)
#        define PRINT_TIME_ERR_NL(doFlush, fstr, args...)                                                                                                     \
            do                                                                                                                                                \
            {                                                                                                                                                 \
                char timeBuffer[TIME_STRING_MAX_LEN] = {0};                                                                                                   \
                fprintf(stderr, "[%s@%d] %s: !!! ERROR: " fstr NEW_LINE, __FUNCTION__, __LINE__, GetLocalTimeString(timeBuffer, sizeof(timeBuffer)), ##args); \
                if (doFlush)                                                                                                                                  \
                    fflush(stderr);                                                                                                                           \
            } while (0)
#    endif /* __gnu_linux__ */
#endif     /* IS_GETTIME_DEFINED */

#endif /* COMMON_PRINT_H_ */
