#ifndef KEYLOG_H
#define KEYLOG_H

#include <vector>
#include <string>
#include <stdexcept>

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

typedef set1 Xset2; // for X-11 sets (for my virtual machine testing)
// Maybe Windows specific


std::vector<vcodes> getPressedKeyboardState(std::string path = "/dev/input/event2");
std::string getAscii(std::vector<vcodes>);

// Generic
void writeToFile(std::string, std::string);

/*
 * To convert any enum class with all the members of vcodes to the apporpriate set.
 * Precondition:
 * T1 and T2 must have all of the members of vcodes.
 * Postcondition:
 * T1 member is converted to T2 member.
 * Returns:
 * appropriate T2 member or throws an exception otherwise.
 * The only reason this is in the header is to make the method accessible for others
 * to include their own sets. I'm not implementing set2 and there may be other sets
 * of scancodes in the future (Hopefully not).
 */
template<typename T1, typename T2>
T2 convert(T1 x) {
    T2 v;
    switch (x) {
        case T1::BACK:
        v = T2::BACK;
        break;
        case T1::TAB:
        v = T2::TAB;
        break;
        case T1::RETURN:
        v = T2::RETURN;
        break;
        case T1::LSHIFT:
        case T1::RSHIFT:
        v = T2::SHIFT;
        break;
        case T1::LCONTROL:
        case T1::RCONTROL:
        v = T2::CONTROL;
        break;
        case T1::LALT:
        case T1::RALT:
        v = T2::MENU;
        break;
        case T1::PAUSE:
        v = T2::PAUSE;
        break;
        case T1::CAPITAL:
        v = T2::CAPITAL;
        break;
        case T1::ESCAPE:
        v = T2::ESCAPE;
        break;
        case T1::SPACE:
        v = T2::SPACE;
        break;
        case T1::END:
        v = T2::END;
        break;
        case T1::HOME:
        v = T2::HOME;
        break;
        case T1::LEFT:
        v = T2::LEFT;
        break;
        case T1::UP:
        v = T2::UP;
        break;
        case T1::RIGHT:
        v = T2::RIGHT;
        break;
        case T1::DOWN:
        v = T2::DOWN;
        break;
        case T1::PRINT:
        v = T2::PRINT;
        break;
        case T1::INSERT:
        v = T2::INSERT;
        break;
        case T1::DELETE_KEY:
        v = T2::DELETE_KEY;
        break;
        case T1::NUM_0:
        v = T2::NUM_0;
        break;
        case T1::NUM_1:
        v = T2::NUM_1;
        break;
        case T1::NUM_2:
        v = T2::NUM_2;
        break;
        case T1::NUM_3:
        v = T2::NUM_3;
        break;
        case T1::NUM_4:
        v = T2::NUM_4;
        break;
        case T1::NUM_5:
        v = T2::NUM_5;
        break;
        case T1::NUM_6:
        v = T2::NUM_6;
        break;
        case T1::NUM_7:
        v = T2::NUM_7;
        break;
        case T1::NUM_8:
        v = T2::NUM_8;
        break;
        case T1::NUM_9:
        v = T2::NUM_9;
        break;
        case T1::A:
        v = T2::A;
        break;
        case T1::B:
        v = T2::B;
        break;
        case T1::C:
        v = T2::C;
        break;
        case T1::D:
        v = T2::D;
        break;
        case T1::E:
        v = T2::E;
        break;
        case T1::F:
        v = T2::F;
        break;
        case T1::G:
        v = T2::G;
        break;
        case T1::H:
        v = T2::H;
        break;
        case T1::I:
        v = T2::I;
        break;
        case T1::J:
        v = T2::J;
        break;
        case T1::K:
        v = T2::K;
        break;
        case T1::L:
        v = T2::L;
        break;
        case T1::M:
        v = T2::M;
        break;
        case T1::N:
        v = T2::N;
        break;
        case T1::O:
        v = T2::O;
        break;
        case T1::P:
        v = T2::P;
        break;
        case T1::Q:
        v = T2::Q;
        break;
        case T1::R:
        v = T2::R;
        break;
        case T1::S:
        v = T2::S;
        break;
        case T1::T:
        v = T2::T;
        break;
        case T1::U:
        v = T2::U;
        break;
        case T1::V:
        v = T2::V;
        break;
        case T1::W:
        v = T2::W;
        break;
        case T1::X:
        v = T2::X;
        break;
        case T1::Y:
        v = T2::Y;
        break;
        case T1::Z:
        v = T2::Z;
        break;
        case T1::NUMPAD0:
        v = T2::NUMPAD0;
        break;
        case T1::NUMPAD1:
        v = T2::NUMPAD1;
        break;
        case T1::NUMPAD2:
        v = T2::NUMPAD2;
        break;
        case T1::NUMPAD3:
        v = T2::NUMPAD3;
        break;
        case T1::NUMPAD4:
        v = T2::NUMPAD4;
        break;
        case T1::NUMPAD5:
        v = T2::NUMPAD5;
        break;
        case T1::NUMPAD6:
        v = T2::NUMPAD6;
        break;
        case T1::NUMPAD7:
        v = T2::NUMPAD7;
        break;
        case T1::NUMPAD8:
        v = T2::NUMPAD8;
        break;
        case T1::NUMPAD9:
        v = T2::NUMPAD9;
        break;
        case T1::MULTIPLY:
        v = T2::MULTIPLY;
        break;
        case T1::ADD:
        v = T2::ADD;
        break;
        case T1::SEPARATOR:
        v = T2::SEPARATOR;
        break;
        case T1::SUBTRACT:
        v = T2::SUBTRACT;
        break;
        case T1::DECIMAL:
        v = T2::DECIMAL;
        break;
        case T1::DIVIDE:
        v = T2::DIVIDE;
        break;
        case T1::OEM_1:
        v = T2::OEM_1;
        break;
        case T1::OEM_PLUS:
        v = T2::OEM_PLUS;
        break;
        case T1::OEM_COMMA:
        v = T2::OEM_COMMA;
        break;
        case T1::OEM_MINUS:
        v = T2::OEM_MINUS;
        break;
        case T1::OEM_PERIOD:
        v = T2::OEM_PERIOD;
        break;
        case T1::OEM_2:
        v = T2::OEM_2;
        break;
        case T1::OEM_3:
        v = T2::OEM_3;
        break;
        case T1::OEM_4:
        v = T2::OEM_4;
        break;
        case T1::OEM_5:
        v = T2::OEM_5;
        break;
        case T1::OEM_6:
        v = T2::OEM_6;
        break;
        case T1::OEM_7:
        v = T2::OEM_7;
        break;
        case T1::OEM_8:
        v = T2::OEM_8;
        break;
        default:
        throw std::invalid_argument("Not a known member.");
    } // switch
    return v;
} // convert
#endif