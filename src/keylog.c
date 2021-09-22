#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif // macros defined by cpp (C prprocessor)
#ifdef __unix__ 
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#endif

int main() {
    #ifdef __unix__
    /*struct termios old, new;
    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );*/
    printf("UNIX\n");
    #elif __WIN32 || __CYGWIN
    printf("Windows\r\n");
    #endif
}