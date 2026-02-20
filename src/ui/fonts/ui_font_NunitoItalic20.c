/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font C:/Users/rick_/SquareLine/assets/Nunito-Italic-VariableFont_wght.ttf -o C:/Users/rick_/SquareLine/assets\ui_font_NunitoItalic20.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_NUNITOITALIC20
#define UI_FONT_NUNITOITALIC20 1
#endif

#if UI_FONT_NUNITOITALIC20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x24, 0x94, 0x92, 0x52, 0x1, 0x0,

    /* U+0022 "\"" */
    0x4a, 0x55, 0x29, 0x0,

    /* U+0023 "#" */
    0x2, 0x20, 0x42, 0x4, 0x23, 0xff, 0x8, 0x40,
    0x88, 0x10, 0x81, 0x8, 0x11, 0xf, 0xfe, 0x21,
    0x2, 0x20, 0x42, 0x4, 0x20,

    /* U+0024 "$" */
    0x0, 0x0, 0x40, 0x8, 0xf, 0x82, 0xc, 0x80,
    0x50, 0x2, 0x0, 0x40, 0x6, 0x0, 0x38, 0x0,
    0xc0, 0x8, 0x0, 0x80, 0x26, 0xc, 0x3e, 0x1,
    0x0, 0x20, 0x0, 0x0,

    /* U+0025 "%" */
    0x0, 0x8, 0x78, 0x11, 0x18, 0x46, 0x11, 0x8,
    0x24, 0x10, 0x48, 0x21, 0x2f, 0x42, 0xb1, 0x79,
    0x42, 0x5, 0x4, 0x12, 0x8, 0x44, 0x10, 0x88,
    0x42, 0x9, 0x88, 0x1e, 0x0,

    /* U+0026 "&" */
    0x7, 0x3, 0x10, 0x42, 0x8, 0x41, 0x10, 0x14,
    0x3, 0x9, 0xa1, 0x42, 0x50, 0x2a, 0x3, 0x40,
    0x4c, 0x34, 0xf8, 0x40,

    /* U+0027 "'" */
    0x56, 0x80,

    /* U+0028 "(" */
    0x12, 0x22, 0x44, 0x48, 0x88, 0x88, 0x88, 0x88,
    0x80,

    /* U+0029 ")" */
    0x10, 0x84, 0x10, 0x84, 0x21, 0x10, 0x84, 0x21,
    0x10, 0x88, 0x40, 0x0,

    /* U+002A "*" */
    0x48, 0x50, 0xc7, 0xf3, 0x5, 0x12, 0x0,

    /* U+002B "+" */
    0x0, 0x1, 0x0, 0x40, 0x10, 0x4, 0x3f, 0xf0,
    0x80, 0x20, 0x8, 0x2, 0x0, 0x0,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x1, 0x2, 0x2, 0x4, 0x4, 0x4, 0x8, 0x8,
    0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80,

    /* U+0030 "0" */
    0x1e, 0x10, 0x90, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x50, 0x2c, 0x21, 0xe0,

    /* U+0031 "1" */
    0x4, 0x38, 0x90, 0x20, 0x41, 0x2, 0x4, 0x8,
    0x10, 0x20, 0x81, 0x1f, 0xc0,

    /* U+0032 "2" */
    0xf, 0xc, 0x30, 0x4, 0x1, 0x0, 0x40, 0x20,
    0x8, 0x4, 0x2, 0x1, 0x1, 0x80, 0x80, 0x40,
    0x3f, 0xe0,

    /* U+0033 "3" */
    0xf, 0xc, 0x20, 0x4, 0x1, 0x0, 0x80, 0x61,
    0xe0, 0x4, 0x0, 0x80, 0x20, 0x8, 0x2, 0xc1,
    0xf, 0x80,

    /* U+0034 "4" */
    0x0, 0x80, 0x60, 0x18, 0xa, 0x4, 0x82, 0x41,
    0x10, 0x84, 0x41, 0x10, 0x4f, 0xfc, 0x4, 0x2,
    0x0, 0x80,

    /* U+0035 "5" */
    0x1f, 0xc8, 0x2, 0x0, 0x80, 0x20, 0xb, 0xc5,
    0x9, 0x82, 0x0, 0x40, 0x10, 0x4, 0x2, 0x41,
    0xf, 0x80,

    /* U+0036 "6" */
    0xf, 0xc, 0x24, 0x5, 0x0, 0x80, 0x27, 0x8e,
    0x33, 0x4, 0x80, 0xa0, 0x28, 0xa, 0x4, 0x42,
    0xf, 0x0,

    /* U+0037 "7" */
    0x7f, 0xc0, 0x20, 0x8, 0x4, 0x2, 0x0, 0x80,
    0x40, 0x20, 0x8, 0x4, 0x2, 0x0, 0x80, 0x40,
    0x20, 0x0,

    /* U+0038 "8" */
    0xf, 0x86, 0x8, 0x81, 0x20, 0x24, 0x4, 0x41,
    0x7, 0xc3, 0x4, 0x80, 0x50, 0xa, 0x1, 0x40,
    0x44, 0x18, 0x7c, 0x0,

    /* U+0039 "9" */
    0x1f, 0xc, 0x24, 0x5, 0x1, 0x40, 0x50, 0x32,
    0x14, 0x79, 0x0, 0x40, 0x20, 0xa, 0x4, 0xc3,
    0xf, 0x0,

    /* U+003A ":" */
    0x60, 0x0, 0x0, 0x10,

    /* U+003B ";" */
    0x60, 0x0, 0x0, 0x12, 0x40,

    /* U+003C "<" */
    0x0, 0x20, 0x18, 0x1c, 0xc, 0x6, 0x1, 0x80,
    0xc, 0x0, 0x60, 0x3, 0x0, 0x10,

    /* U+003D "=" */
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xff, 0xc0,

    /* U+003E ">" */
    0x20, 0x3, 0x0, 0x18, 0x0, 0xc0, 0x6, 0x0,
    0xc0, 0x60, 0x30, 0x38, 0x18, 0x0,

    /* U+003F "?" */
    0x1e, 0x63, 0x1, 0x1, 0x1, 0x2, 0x4, 0x8,
    0x10, 0x20, 0x20, 0x0, 0x0, 0x60,

    /* U+0040 "@" */
    0x7, 0xe0, 0x18, 0x18, 0x20, 0x4, 0x40, 0x2,
    0x43, 0xd2, 0x84, 0x52, 0x88, 0x21, 0x88, 0x21,
    0x88, 0x21, 0x90, 0x21, 0x90, 0x22, 0x88, 0x62,
    0x88, 0xa6, 0x87, 0x1c, 0x40, 0x0, 0x20, 0x4,
    0x18, 0x18, 0x7, 0xe0,

    /* U+0041 "A" */
    0x0, 0x80, 0xc, 0x0, 0x90, 0x4, 0x80, 0x44,
    0x2, 0x10, 0x20, 0x81, 0x4, 0x10, 0x20, 0xff,
    0x88, 0x4, 0x80, 0x24, 0x1, 0x40, 0x4,

    /* U+0042 "B" */
    0x3f, 0xc2, 0x2, 0x20, 0x22, 0x2, 0x40, 0x24,
    0x6, 0x7f, 0x84, 0x4, 0x40, 0x24, 0x2, 0x40,
    0x28, 0x4, 0x80, 0xcf, 0xf8,

    /* U+0043 "C" */
    0xf, 0x86, 0xd, 0x80, 0xa0, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x0, 0x80, 0x10, 0x2, 0x0, 0x60,
    0x26, 0x8, 0x3e, 0x0,

    /* U+0044 "D" */
    0x3f, 0x81, 0x3, 0x8, 0x4, 0x40, 0x22, 0x1,
    0x20, 0x5, 0x0, 0x28, 0x2, 0x40, 0x12, 0x0,
    0x90, 0x9, 0x0, 0xc8, 0xc, 0x7f, 0x80,

    /* U+0045 "E" */
    0x3f, 0xe4, 0x0, 0x80, 0x10, 0x4, 0x0, 0x80,
    0x1f, 0xe2, 0x0, 0x40, 0x8, 0x1, 0x0, 0x40,
    0x8, 0x1, 0xff, 0x0,

    /* U+0046 "F" */
    0x3f, 0xe4, 0x0, 0x80, 0x10, 0x4, 0x0, 0x80,
    0x1f, 0xe2, 0x0, 0x40, 0x8, 0x1, 0x0, 0x40,
    0x8, 0x1, 0x0, 0x0,

    /* U+0047 "G" */
    0xf, 0x86, 0xd, 0x80, 0x20, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x1f, 0x80, 0x30, 0x6, 0x1, 0x60,
    0x26, 0x4, 0x3f, 0x0,

    /* U+0048 "H" */
    0x20, 0x8, 0x80, 0x22, 0x0, 0x88, 0x2, 0x40,
    0x9, 0x0, 0x27, 0xff, 0x90, 0x4, 0x40, 0x11,
    0x0, 0x44, 0x1, 0x20, 0x4, 0x80, 0x12, 0x0,
    0x80,

    /* U+0049 "I" */
    0x24, 0x92, 0x92, 0x49, 0x49, 0x0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x82, 0x8, 0x20,
    0x82, 0x10, 0xcc, 0x0,

    /* U+004B "K" */
    0x20, 0x24, 0x8, 0x86, 0x11, 0x2, 0x40, 0x90,
    0x1c, 0x3, 0x80, 0x58, 0x9, 0x81, 0x18, 0x41,
    0x88, 0x9, 0x0, 0x80,

    /* U+004C "L" */
    0x20, 0x10, 0x8, 0x4, 0x2, 0x2, 0x1, 0x0,
    0x80, 0x40, 0x20, 0x10, 0x10, 0x8, 0x7, 0xfc,

    /* U+004D "M" */
    0x20, 0x2, 0x60, 0x4, 0xc0, 0x19, 0x80, 0x52,
    0x80, 0xa9, 0x2, 0x52, 0x9, 0x22, 0x22, 0x44,
    0x44, 0x85, 0x9, 0xc, 0x14, 0x8, 0x28, 0x0,
    0x90, 0x1, 0x0,

    /* U+004E "N" */
    0x20, 0x9, 0x80, 0x4c, 0x2, 0x50, 0x14, 0x41,
    0x22, 0x9, 0x8, 0x48, 0x42, 0x41, 0x12, 0x4,
    0x90, 0x25, 0x0, 0xc8, 0x6, 0x40, 0x10,

    /* U+004F "O" */
    0xf, 0x83, 0x6, 0x60, 0x24, 0x1, 0x80, 0x18,
    0x1, 0x80, 0x18, 0x1, 0x80, 0x18, 0x2, 0x80,
    0x28, 0x4, 0x60, 0x83, 0xf0,

    /* U+0050 "P" */
    0x3f, 0xc4, 0xc, 0x80, 0x90, 0x12, 0x2, 0x80,
    0x50, 0x13, 0xfc, 0x40, 0x8, 0x1, 0x0, 0x40,
    0x8, 0x1, 0x0, 0x0,

    /* U+0051 "Q" */
    0xf, 0x83, 0x6, 0x60, 0x24, 0x1, 0x80, 0x18,
    0x1, 0x80, 0x18, 0x1, 0x80, 0x18, 0x2, 0x80,
    0x28, 0x4, 0x60, 0x83, 0xf0, 0x1, 0x0, 0x10,
    0x0, 0x80, 0x8,

    /* U+0052 "R" */
    0x3f, 0xc4, 0xc, 0x80, 0x90, 0x12, 0x2, 0x80,
    0x50, 0x13, 0xfc, 0x41, 0x8, 0x11, 0x2, 0x40,
    0x28, 0x5, 0x0, 0x80,

    /* U+0053 "S" */
    0x1f, 0x86, 0x19, 0x0, 0xa0, 0x4, 0x0, 0x80,
    0xc, 0x0, 0x78, 0x0, 0x80, 0x8, 0x1, 0x0,
    0x2c, 0x18, 0x7e, 0x0,

    /* U+0054 "T" */
    0xff, 0xf0, 0x20, 0x4, 0x0, 0x40, 0x4, 0x0,
    0x40, 0x4, 0x0, 0x40, 0x8, 0x0, 0x80, 0x8,
    0x0, 0x80, 0x8, 0x0, 0x80,

    /* U+0055 "U" */
    0x40, 0x14, 0x1, 0x40, 0x14, 0x1, 0x80, 0x28,
    0x2, 0x80, 0x28, 0x2, 0x80, 0x28, 0x2, 0x80,
    0x48, 0x4, 0x41, 0x83, 0xe0,

    /* U+0056 "V" */
    0x80, 0x18, 0x1, 0x80, 0x28, 0x2, 0x40, 0x44,
    0x8, 0x40, 0x84, 0x10, 0x21, 0x2, 0x20, 0x24,
    0x1, 0x40, 0x18, 0x1, 0x80,

    /* U+0057 "W" */
    0x80, 0x20, 0x18, 0x6, 0x1, 0x40, 0x60, 0x24,
    0xa, 0x2, 0x40, 0xa0, 0x44, 0x11, 0x4, 0x41,
    0x10, 0x84, 0x21, 0x8, 0x24, 0x11, 0x2, 0x41,
    0x10, 0x28, 0xa, 0x2, 0x80, 0xa0, 0x30, 0xc,
    0x1, 0x0, 0xc0,

    /* U+0058 "X" */
    0x20, 0x8, 0x80, 0x82, 0x8, 0x10, 0x80, 0x48,
    0x2, 0x80, 0xc, 0x0, 0x60, 0x5, 0x0, 0x44,
    0x4, 0x20, 0x40, 0x84, 0x2, 0x40, 0x10,

    /* U+0059 "Y" */
    0x80, 0x30, 0x9, 0x2, 0x20, 0x82, 0x20, 0x28,
    0x6, 0x0, 0x80, 0x10, 0x2, 0x0, 0x40, 0x8,
    0x1, 0x0, 0x40, 0x0,

    /* U+005A "Z" */
    0x3f, 0xf0, 0x2, 0x0, 0x20, 0x4, 0x0, 0x80,
    0x10, 0x2, 0x0, 0x40, 0x8, 0x0, 0x80, 0x10,
    0x2, 0x0, 0x40, 0xf, 0xfc,

    /* U+005B "[" */
    0x1c, 0x82, 0x8, 0x20, 0x82, 0x10, 0x41, 0x4,
    0x10, 0x42, 0x8, 0x20, 0x83, 0x80,

    /* U+005C "\\" */
    0x88, 0x88, 0x44, 0x44, 0x44, 0x22, 0x22, 0x22,

    /* U+005D "]" */
    0x3c, 0x10, 0x82, 0x8, 0x20, 0x82, 0x8, 0x41,
    0x4, 0x10, 0x41, 0x8, 0x23, 0x80,

    /* U+005E "^" */
    0x2, 0x1, 0x80, 0xa0, 0x24, 0x11, 0x8, 0x42,
    0x9, 0x2, 0x80, 0xa0, 0x10,

    /* U+005F "_" */
    0xff, 0xc0,

    /* U+0060 "`" */
    0x91, 0x10,

    /* U+0061 "a" */
    0x3e, 0x41, 0x1, 0x1, 0x3f, 0xc1, 0x82, 0x82,
    0xc6, 0x7a,

    /* U+0062 "b" */
    0x20, 0x10, 0x8, 0x8, 0x4, 0xf3, 0x8d, 0x2,
    0x81, 0x40, 0xc0, 0x70, 0x38, 0x1e, 0x34, 0xf0,

    /* U+0063 "c" */
    0x1e, 0x61, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x42, 0x3c,

    /* U+0064 "d" */
    0x0, 0x40, 0x10, 0x4, 0x1, 0x1e, 0x98, 0x64,
    0xa, 0x2, 0x80, 0xa0, 0x28, 0x12, 0x4, 0x43,
    0xf, 0x40,

    /* U+0065 "e" */
    0x1e, 0x10, 0x90, 0x50, 0x1f, 0xfc, 0x2, 0x1,
    0x0, 0x43, 0x1e, 0x0,

    /* U+0066 "f" */
    0xe, 0x20, 0x81, 0xf, 0xc4, 0x10, 0x20, 0x40,
    0x81, 0x2, 0x8, 0x10, 0x0,

    /* U+0067 "g" */
    0x1e, 0xb0, 0xd0, 0x30, 0x18, 0xc, 0x6, 0x5,
    0x2, 0x43, 0x1e, 0x80, 0x40, 0x2c, 0x21, 0xe0,

    /* U+0068 "h" */
    0x20, 0x10, 0x8, 0x8, 0x4, 0xf3, 0x89, 0x82,
    0x81, 0x41, 0x20, 0xa0, 0x50, 0x28, 0x14, 0x8,

    /* U+0069 "i" */
    0x20, 0x4, 0x92, 0x52, 0x49, 0x0,

    /* U+006A "j" */
    0x4, 0x0, 0x0, 0x8, 0x20, 0x82, 0x8, 0x21,
    0x4, 0x10, 0x41, 0x4, 0x23, 0x0,

    /* U+006B "k" */
    0x20, 0x20, 0x20, 0x40, 0x41, 0x42, 0x4c, 0x50,
    0x60, 0xa0, 0x90, 0x88, 0x84, 0x82,

    /* U+006C "l" */
    0x22, 0x24, 0x44, 0x44, 0x48, 0x88, 0x87,

    /* U+006D "m" */
    0x5e, 0x39, 0x87, 0x14, 0x18, 0x50, 0x41, 0x41,
    0x5, 0x4, 0x18, 0x10, 0x60, 0x81, 0x82, 0x6,
    0x8, 0x20,

    /* U+006E "n" */
    0x5f, 0x38, 0x98, 0x28, 0x14, 0x12, 0xa, 0x5,
    0x2, 0x81, 0x40, 0x80,

    /* U+006F "o" */
    0x1e, 0x30, 0x90, 0x50, 0x18, 0xc, 0x6, 0x5,
    0x2, 0x42, 0x1e, 0x0,

    /* U+0070 "p" */
    0x2f, 0x8e, 0x32, 0x4, 0x81, 0x20, 0x50, 0x14,
    0x5, 0x81, 0x51, 0x93, 0xc4, 0x1, 0x0, 0x80,
    0x20, 0x0,

    /* U+0071 "q" */
    0x1e, 0xb0, 0xd0, 0x30, 0x18, 0xc, 0x6, 0x5,
    0x2, 0x43, 0x1e, 0x80, 0x40, 0x20, 0x10, 0x10,

    /* U+0072 "r" */
    0x5d, 0x84, 0x10, 0x41, 0x8, 0x20, 0x82, 0x0,

    /* U+0073 "s" */
    0x3c, 0x42, 0x40, 0x40, 0x60, 0x1c, 0x2, 0x2,
    0x86, 0x7c,

    /* U+0074 "t" */
    0x20, 0x82, 0x3f, 0x41, 0x4, 0x10, 0x41, 0x4,
    0x10, 0x38,

    /* U+0075 "u" */
    0x40, 0xa0, 0x50, 0x28, 0x24, 0x14, 0xa, 0x5,
    0x6, 0x47, 0x1f, 0x0,

    /* U+0076 "v" */
    0x80, 0xc0, 0x50, 0x48, 0x44, 0x22, 0x20, 0x90,
    0x50, 0x28, 0x8, 0x0,

    /* U+0077 "w" */
    0x83, 0x6, 0xc, 0x18, 0x50, 0xa1, 0x42, 0x89,
    0x12, 0x22, 0x45, 0xa, 0x14, 0x28, 0x60, 0xc1,
    0x81, 0x0,

    /* U+0078 "x" */
    0x20, 0x48, 0x21, 0x10, 0x28, 0xc, 0x3, 0x1,
    0x20, 0x88, 0x41, 0x20, 0x40,

    /* U+0079 "y" */
    0x80, 0xc0, 0x50, 0x48, 0x24, 0x22, 0x20, 0x90,
    0x50, 0x28, 0x8, 0x4, 0x4, 0x4, 0x2, 0x0,

    /* U+007A "z" */
    0x3f, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x3f, 0x80,

    /* U+007B "{" */
    0xe, 0x20, 0x40, 0x81, 0x2, 0x8, 0x10, 0x21,
    0x80, 0x81, 0x4, 0x8, 0x10, 0x20, 0x40, 0xe0,

    /* U+007C "|" */
    0x24, 0x92, 0x92, 0x49, 0x29, 0x24, 0x90,

    /* U+007D "}" */
    0x38, 0x10, 0x82, 0x8, 0x20, 0x82, 0x8, 0x11,
    0x84, 0x10, 0x41, 0x8, 0x23, 0x80,

    /* U+007E "~" */
    0x78, 0x13, 0x10, 0x38
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 79, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 68, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 109, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 11, .adv_w = 192, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 192, .box_w = 11, .box_h = 20, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 60, .adv_w = 293, .box_w = 15, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 212, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 65, .box_w = 2, .box_h = 6, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 111, .adv_w = 90, .box_w = 4, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 120, .adv_w = 90, .box_w = 5, .box_h = 18, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 132, .adv_w = 143, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 139, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 68, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 154, .adv_w = 133, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 155, .adv_w = 68, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 82, .box_w = 8, .box_h = 16, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 172, .adv_w = 192, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 192, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 68, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 356, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 370, .adv_w = 192, .box_w = 10, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 377, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 391, .adv_w = 137, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 302, .box_w = 16, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 441, .adv_w = 229, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 464, .adv_w = 213, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 213, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 232, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 182, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 172, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 230, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 240, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 95, .box_w = 6, .box_h = 15, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 631, .adv_w = 189, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 270, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 234, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 240, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 197, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 758, .adv_w = 240, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 785, .adv_w = 209, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 188, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 846, .adv_w = 230, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 867, .adv_w = 213, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 349, .box_w = 20, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 202, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 946, .adv_w = 185, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 966, .adv_w = 184, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 987, .adv_w = 90, .box_w = 6, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1001, .adv_w = 82, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1009, .adv_w = 90, .box_w = 6, .box_h = 18, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 1023, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 1036, .adv_w = 160, .box_w = 10, .box_h = 1, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 1038, .adv_w = 123, .box_w = 3, .box_h = 4, .ofs_x = 4, .ofs_y = 11},
    {.bitmap_index = 1040, .adv_w = 164, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1050, .adv_w = 182, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1066, .adv_w = 146, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1076, .adv_w = 182, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1094, .adv_w = 167, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 98, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 182, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1135, .adv_w = 177, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1151, .adv_w = 68, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1157, .adv_w = 69, .box_w = 6, .box_h = 18, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 1171, .adv_w = 150, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1185, .adv_w = 88, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1192, .adv_w = 268, .box_w = 14, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1210, .adv_w = 177, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1222, .adv_w = 172, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1234, .adv_w = 182, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1252, .adv_w = 182, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1268, .adv_w = 105, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1276, .adv_w = 152, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1286, .adv_w = 102, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1296, .adv_w = 174, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1308, .adv_w = 161, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1320, .adv_w = 266, .box_w = 14, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1338, .adv_w = 162, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1351, .adv_w = 161, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1367, .adv_w = 145, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1379, .adv_w = 102, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1395, .adv_w = 78, .box_w = 3, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1402, .adv_w = 102, .box_w = 6, .box_h = 18, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 1416, .adv_w = 192, .box_w = 10, .box_h = 3, .ofs_x = 1, .ofs_y = 4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 1, 0, 0, 0, 0, 2,
    0, 3, 0, 4, 0, 5, 6, 5,
    7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 8, 8, 0, 0, 0,
    9, 10, 11, 12, 13, 10, 14, 15,
    16, 0, 0, 17, 18, 19, 0, 0,
    10, 20, 21, 22, 23, 24, 25, 26,
    26, 27, 28, 29, 3, 0, 0, 0,
    5, 0, 30, 31, 32, 0, 33, 34,
    35, 30, 0, 0, 36, 37, 30, 30,
    31, 31, 35, 38, 39, 40, 35, 41,
    41, 42, 41, 43, 3, 0, 6, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 3, 4,
    2, 3, 5, 6, 0, 7, 8, 7,
    9, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 10, 10, 0, 0, 0,
    11, 12, 13, 0, 12, 0, 0, 0,
    12, 0, 0, 14, 0, 0, 0, 0,
    12, 0, 12, 0, 15, 16, 17, 18,
    18, 19, 20, 21, 3, 3, 5, 0,
    7, 0, 22, 23, 24, 24, 24, 25,
    24, 23, 23, 26, 23, 23, 27, 27,
    24, 27, 24, 27, 28, 29, 30, 31,
    31, 32, 31, 33, 8, 0, 5, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, -3, 0, -3,
    0, 0, -3, 0, 0, 10, 0, -3,
    0, -3, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 6, 0,
    -10, 0, -6, -2, -6, 0, 0, 0,
    -2, 0, 0, 0, 3, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 13, 0,
    0, 0, 13, 0, 6, -3, 0, 0,
    0, 13, 0, 10, 3, 10, 6, 0,
    0, -3, 0, 32, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, -13, -19, -35, -3, 3, 0, -22,
    -18, 0, 3, 0, 3, -3, 3, 0,
    0, 0, -3, 10, 0, 0, 0, 10,
    0, 3, 2, 0, 0, 0, 0, 0,
    0, -16, 0, -13, 22, 0, -22, -11,
    6, 10, 3, -18, -6, -16, 3, -19,
    3, -2, 0, -8, -6, 0, 0, 2,
    -10, -2, -16, 3, 0, -3, 0, 0,
    0, 0, -19, -13, 0, 0, -5, -8,
    0, -6, -8, -6, -14, 0, -14, -10,
    -14, 0, 0, 0, 5, 0, 0, 0,
    0, 0, 0, -6, -11, -3, -6, 0,
    0, 0, 13, 0, -35, -19, -13, -6,
    16, -3, -6, -13, 0, 13, 0, 13,
    3, 13, 6, -19, -2, -19, 0, 0,
    -19, -19, -3, -19, -10, -16, -19, 0,
    0, 0, 0, 0, -3, 0, -5, 19,
    0, -3, 0, 0, 6, 0, -11, 0,
    -6, 0, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, -29, 1,
    -3, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -11,
    0, -3, 0, -2, 0, -3, -10, 0,
    -14, 0, -5, -8, -14, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -22,
    6, -6, 10, 0, -11, -3, 0, 6,
    -2, -24, -2, -16, -6, -21, -3, 0,
    0, -2, -2, 0, 0, -2, -3, 0,
    -8, -6, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, -3,
    -3, 0, -3, 0, -3, -5, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, 0, 3, -8, 6, 0, 6, -6,
    -6, -3, -3, -3, 0, -5, -6, -6,
    -2, -5, 0, -11, -3, 0, 0, -3,
    -3, -3, -6, -3, -5, 0, 0, 0,
    0, 0, 0, 3, 0, 11, 0, 1,
    -2, -5, -1, -3, -6, 0, -3, -3,
    -3, 0, -3, 0, -2, -2, 0, 0,
    -3, -2, 0, -3, 0, 0, 0, 0,
    0, 0, 3, 0, -8, -2, -10, 0,
    3, -6, -19, -16, -8, -2, 0, -1,
    -6, -3, -3, -6, 0, -6, 0, 0,
    -3, -6, 0, -3, -2, -3, -11, 0,
    0, 0, 0, -3, 0, 0, 0, 3,
    0, 0, 0, 0, 0, 0, -3, 0,
    -3, -2, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 0, 0, -6, 3,
    -10, 13, 0, 0, -10, -10, 10, -10,
    -10, -3, -3, -3, -13, 0, 0, 0,
    -3, -3, 0, 0, -3, -5, -3, -8,
    -16, -6, 0, 0, 0, 0, 0, -13,
    3, -13, 14, 3, -24, -11, -8, 13,
    -6, -40, -8, -29, -6, -37, 0, 0,
    0, -2, -3, 0, 0, -3, -6, -3,
    -13, -6, 0, -1, 0, 0, -6, -3,
    0, -16, -10, -19, -3, 0, -3, -22,
    -19, 0, -6, 0, 0, -10, -2, -6,
    -8, 0, -6, 0, 0, -3, -5, 3,
    -2, -2, -5, -6, 0, 0, 0, 0,
    -3, 0, -11, 0, -3, 0, -2, 0,
    -3, -10, 0, -14, 0, -5, -8, -14,
    -5, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, -5, 10, 0, 0,
    -2, -3, 0, 0, -6, 0, -3, -3,
    -2, 0, 0, 0, -3, 0, 0, 0,
    -3, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, -1, -3, 0, 2, 0,
    3, 0, 0, -3, 0, -5, 0, -3,
    -3, -5, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, -10, 13, 3, -18, -14, -16,
    -11, 3, -14, -24, -18, -8, 3, 0,
    3, 0, 2, -2, -24, 0, -24, -8,
    0, -24, -24, -10, -22, -22, -24, -24,
    0, 0, 0, 0, 0, 0, -6, 0,
    -3, 0, 0, 0, -2, -10, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, 10, 3, -16,
    -14, -6, -6, 3, -5, -16, -18, -3,
    3, 0, 0, -5, 3, 0, -18, 0,
    -18, -5, 0, -18, -18, -3, -16, -8,
    -16, -18, 2, 0, 0, 0, 3, -3,
    3, -10, 6, 0, 0, -8, -6, 6,
    -3, 0, -3, -5, 0, -2, 0, 0,
    0, -2, -5, 0, 0, -2, -6, 0,
    -6, -8, -3, 1, 0, 0, -3, 10,
    3, -19, -14, -10, -11, 6, -14, -21,
    -14, -8, 5, 0, 3, -2, 0, 0,
    -24, 0, -24, -6, 0, -24, -24, -11,
    -22, -22, -26, -24, 0, 0, 0, 0,
    6, 0, 3, -6, 10, 0, 0, -5,
    -3, 6, -2, -2, 0, -2, 0, 0,
    0, -3, 0, -5, -3, 0, 0, -3,
    -3, -3, -8, -5, -6, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -3, -3, -8, 5, 0, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, -2, 0, -2, -3, -2, 0,
    0, 0, 0, 3, 0, 3, -3, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -3, 0, 3,
    -1, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -2,
    1, 3, 0, 0, -3, 16, 11, -6,
    -3, 0, 0, 16, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    -5, -3, 0, 0, -2, -6, 0, -2,
    -3, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 3, -10, 6, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, -5, 0, 0, 0, -3, -3,
    0, -5, -6, -2, 0, -10, -3, -2,
    0, -5, 3, -3, 11, 0, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, 0, 0, -2,
    -2, 0, -3, 0, 0, 2, 0, 0,
    -3, 6, 11, -6, -8, -3, 3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -2, 8, 0, 0,
    -2, 8, 0, 10, 2, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -3, -2, -2, 0,
    0, 0, 0, 26, 8, 3, -5, 16,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 2,
    0, 0, 0, 0, 0, 2, 3, 0,
    0, 0, 0, -6, 0, 3, -16, -6,
    -10, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -2,
    2, 0, 0, -3, 2, 0, 0, -3,
    -2, 0, 0, 0, 0, 0, 2, 3,
    -11, 3, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    -3, 0, 0, 0, -2, 0, 0, -3,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, -14, 0, 0, -6, 0, 0, 6,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -3, 0, 0, 0, -2, 0, 0,
    -2, -2, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 43,
    .right_class_cnt     = 33,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_NunitoItalic20 = {
#else
lv_font_t ui_font_NunitoItalic20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_NUNITOITALIC20*/

