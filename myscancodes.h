#ifndef MYSCANCODES_H
#define MYSCANCODES_H

#define PRINTABLE_OFFSET 0x88
#define SPECIAL_CHARS_NO 72

// https://deskthority.net/wiki/Scancode
char * specialKeyNames[SPECIAL_CHARS_NO] = 
{
    "enter",
    "esc",
    "backspace",
    "tab",
    "space",
    "caps",
    "f1",
    "f2",
    "f3",
    "f4",
    "f5",
    "f6",
    "f7",
    "f8",
    "f9",
    "f10",
    "f11",
    "f12",
    "prsc",
    "sclk",
    "pause",
    "insert",
    "home",
    "pgup",
    "delete",
    "end",
    "pgdn",
    "right",
    "left",
    "down",
    "up",
    "numlock",
    "g/",
    "g*",
    "g-",
    "g+",
    "genter",
    "g1",
    "g2",
    "g3",
    "g4",
    "g5",
    "g6",
    "g7",
    "g8",
    "g9",
    "g0",
    "gdot",
    "app",
    "power",
    "execute",
    "help",
    "menu",
    "select",
    "stop",
    "again",
    "undo",
    "cut",
    "copy",
    "paste",
    "find",
    "mute",
    "volup",
    "voldn",
    "lctrl",
    "lshift",
    "lalt",
    "lwin",
    "rctrl",
    "rshift",
    "ralt",
    "rwin"
};

char specialKeyCodes[SPECIAL_CHARS_NO] = 
{
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x39,
    0x3A,
    0x3B,
    0x3C,
    0x3D,
    0x3E,
    0x3F,
    0x40,
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4D,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E,
    0x5F,
    0x60,
    0x61,
    0x62,
    0x63,
    0x65,
    0x66,
    0x74,
    0x75,
    0x76,
    0x77,
    0x78,
    0x79,
    0x7A,
    0x7B,
    0x7C,
    0x7D,
    0x7E,
    0x7F,
    0x80,
    0x81,
    /*
     * Keyboard.h library recognizes >=136 codes as not printables.
     * Above ones are below it so i need to add 136 to them manually, somewhere later.
     * lctrl and 7 next ones are above 136. Correcting them for future 136 adding in loop.
     * https://forum.arduino.cc/t/keyboard-write-with-number-pad-keys-from-leonardo/175304
     */
    0xE0 - PRINTABLE_OFFSET,
    0xE1 - PRINTABLE_OFFSET,
    0xE2 - PRINTABLE_OFFSET,
    0xE3 - PRINTABLE_OFFSET,
    0xE4 - PRINTABLE_OFFSET,
    0xE5 - PRINTABLE_OFFSET,
    0xE6 - PRINTABLE_OFFSET,
    0xE7 - PRINTABLE_OFFSET
};

#endif