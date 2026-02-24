/*! ***************************************************************************
 * @file
 * @brief Lower ASCII table
 *
 * @author hellfisch
 * @date 2023.06.15
 *
 *****************************************************************************/

#ifndef COMMON_ASCII_H_
#define COMMON_ASCII_H_

/* ****************************************************************************
 *  I N C L U D E S
 *************************************************************************** */

/* ****************************************************************************
 *  D E F I N E S
 *************************************************************************** */

#define ASCII_TBL_NUL 0x00 /* Null */
#define ASCII_TBL_SOH 0x01 /* Start of Header */
#define ASCII_TBL_STX 0x02 /* Start of Text */
#define ASCII_TBL_ETX 0x03 /* End of Text */
#define ASCII_TBL_EOT 0x04 /* End of Transmission */
#define ASCII_TBL_ENQ 0x05 /* Enquiry */
#define ASCII_TBL_ACK 0x06 /* Acknowledge */
#define ASCII_TBL_BEL 0x07 /* Bell */
#define ASCII_TBL_BS  0x08 /* Backspace */
#define ASCII_TBL_HT  0x09 /* Horizontal Tab */
#define ASCII_TBL_LF  0x0A /* Line Feed */
#define ASCII_TBL_VT  0x0B /* Vertical Tab */
#define ASCII_TBL_FF  0x0C /* Form Feed */
#define ASCII_TBL_CR  0x0D /* Carriage Return */
#define ASCII_TBL_SO  0x0E /* Shift Out */
#define ASCII_TBL_SI  0x0F /* Shift In */
#define ASCII_TBL_DLE 0x10 /* Data Link Escape */
#define ASCII_TBL_DC1 0x11 /* Device Control 1 */
#define ASCII_TBL_DC2 0x12 /* Device Control 2 */
#define ASCII_TBL_DC3 0x13 /* Device Control 3 */
#define ASCII_TBL_DC4 0x14 /* Device Control 4 */
#define ASCII_TBL_NAK 0x15 /* Negative Acknowledge */
#define ASCII_TBL_SYN 0x16 /* Synchronize */
#define ASCII_TBL_ETB 0x17 /* End of Transmission Block */
#define ASCII_TBL_CAN 0x18 /* Cancel */
#define ASCII_TBL_EOM 0x19 /* End of Medium */
#define ASCII_TBL_SUB 0x1A /* Substitute */
#define ASCII_TBL_ESC 0x1B /* Escape */
#define ASCII_TBL_FS  0x1C /* File Separator */
#define ASCII_TBL_GS  0x1D /* Group Separator */
#define ASCII_TBL_RS  0x1E /* Record Separator */
#define ASCII_TBL_US  0x1F /* Unit Separator */
#define ASCII_TBL_SP  0x20 /* Space */
#define ASCII_TBL_DEL 0x7F /* Delete */

// Console handling
#define COMMON_CONSOLE_CLEAR "\033c" /* wokring with ubuntu */

#endif /* COMMON_ASCII_H_ */
