/*! ***************************************************************************
 * @file
 * @brief Binary conversion
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 * @todo - [ ] verify!
 *
 *****************************************************************************/

#ifndef COMMON_BINARY_H_
#define COMMON_BINARY_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

/* VERSION 1 */
/*
 * Disadvantages: (it's not such a big ones)
 * - The binary numbers have to be grouped 4 by 4;
 * - The binary literals have to be only unsigned integer numbers;
 *
 * Advantages:
 * - Total preprocessor driven, not spending processor time in pointless operations
 *   (like "?.. :..", "<<", "+") to the executable program (it may be performed
 *   hundred of times in the final application);
 * - It works "mainly in C" compilers and C++ as well (template+enum solution
 *   works only in C++ compilers);
 * - It has only the limitation of "longness" for expressing "literal constant"
 *   values. There would have been earlyish longness limitation (usually
 *   8bits:0-255) if one had expressed constant values by parsing resolve of
 *   "enum solution"(usually 255 = reach enum definition limit), differently,
 *   "literal constant" limitations, in the compiler allows greater numbers;
 * - Some other solutions demand exagerated number of constant definitions
 *   (too much define's in my opinion) including long or several header files
 *   (in most cases not easily readable and understandable, and make the project
 *   become unnecessarily confused and extended, like that using "BOOST_BINARY()");
 * - Simplicity of the solution: easily readable, understandable and adjustable
 *   for other cases (could be extended for grouping 8 by 8 too);
 */

#define B_0000  0
#define B_0001  1
#define B_0010  2
#define B_0011  3
#define B_0100  4
#define B_0101  5
#define B_0110  6
#define B_0111  7
#define B_1000  8
#define B_1001  9
#define B_1010  a
#define B_1011  b
#define B_1100  c
#define B_1101  d
#define B_1110  e
#define B_1111  f

#define _B2H(bits)  B_##bits
#define B2H(bits)   _B2H(bits)

#ifndef _HEX
#   define _HEX(n)  0x##n
#endif
#define HEX(n)      _HEX(n)
#define _CCAT(a,b)  a##b
#define CCAT(a,b)   _CCAT(a,b)

#define BYTE(a,b)               HEX( CCAT(B2H(a),B2H(b)) )
#define WORD(a,b,c,d)           HEX( CCAT(CCAT(B2H(a),B2H(b)),CCAT(B2H(c),B2H(d))) )
#define DWORD(a,b,c,d,e,f,g,h)  HEX( CCAT(CCAT(CCAT(B2H(a),B2H(b)),CCAT(B2H(c),B2H(d))),CCAT(CCAT(B2H(e),B2H(f)),CCAT(B2H(g),B2H(h)))) )

/* using example */
// unsigned char b = BYTE(0100,0001);
// unsigned int w = WORD(1101,1111,0100,0011);
// unsigned long int dw = DWORD(1101,1111,0100,0011,1111,1101,0010,1000);
/* ------------------------------------------------------------------------- */

/* VERSION 2 */

#define HEX__(n) 0x##n##LU
#define B8__(x) ( ( (x&0x0000000FLU) ?   1 : 0) \
                  +((x&0x000000F0LU) ?   2 : 0) \
                  +((x&0x00000F00LU) ?   4 : 0) \
                  +((x&0x0000F000LU) ?   8 : 0) \
                  +((x&0x000F0000LU) ?  16 : 0) \
                  +((x&0x00F00000LU) ?  32 : 0) \
                  +((x&0x0F000000LU) ?  64 : 0) \
                  +((x&0xF0000000LU) ? 128 : 0) )

#define B8(d)                   ( (unsigned char) B8__(HEX__(d)) )
#define B16(dmsb,dlsb)          ( ((unsigned short) B8(dmsb) <<  8) + B8(dlsb) )
#define B32(dmsb,db2,db3,dlsb)  ( (  (unsigned long) B8(dmsb) << 24) \
                                  + ((unsigned long) B8(db2)  << 16) \
                                  + ((unsigned long) B8(db3)  <<  8) \
                                  + B8(dlsb) )

/* using example */
/* unsigned const number = B16(00000001,00000101); */

#endif /* COMMON_BINARY_H_ */
