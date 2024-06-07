#ifndef SPECIAL_HPP
#define SPECIAL_HPP

#include <iostream>

#ifdef _WIN32
#include <conio.h>  // For _getch()
#include <cstdlib>  // For std::system("cls")
#else
#include <unistd.h>  // For read()
#include <termios.h>  // For termios functions
#include <cstdlib>  // For std::system("clear")
#endif

namespace special {

inline void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

inline void waitForKeyPress() {
#ifdef _WIN32
    std::cout << "Press any key to continue..." << std::endl;
    _getch();
#else
    std::cout << "Press any key to continue..." << std::endl;
    
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Set new terminal settings

    char ch;
    read(STDIN_FILENO, &ch, 1);  // Read a single character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore original terminal settings
#endif
}

} // namespace special

#endif // SPECIAL_HPP
