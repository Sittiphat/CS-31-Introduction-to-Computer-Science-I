//
//  Screen.cpp
//  SlotMachine
//
//

#include "Screen.h"
#include "RandomNumber.h"
#include <iostream>

Screen::Screen()
{
    
}

// show the rotating slot machine wheels, ending on each character specified
void Screen::displayScreen( char one, char two, char three, std::string sequence )
{
    using namespace std;
    // Draw the machine
    int z = 0;
    RandomNumber r( 0, static_cast<int>( sequence.length()-1 ) );
    // spin one wheel
    for (int i=0; i <= static_cast<int>( sequence.length()-1 ); i++)
    {
        clearScreen();
        z = r.random();
        cout << endl;
        cout << sequence[ z ] << endl;
        cout << endl;
        pauseScreen( );
    }
    clearScreen();
    // end on the character specified
    cout << one << endl;
    // spin a second wheel
    for (int j=0; j <= static_cast<int>( sequence.length()-1 ); j++)
    {
        clearScreen();
        z = r.random();
        cout << endl;
        cout << one << " " << sequence[ z ] << endl;
        cout << endl;
        pauseScreen( );
    }
    clearScreen( );
    // end on the character specified
    cout << one << " " << two << endl;
    // spin a third wheel
    for (int k=0; k <= static_cast<int>( sequence.length()-1 ); k++)
    {
        clearScreen();
        z = r.random();
        cout << endl;
        cout << one << " " << two << " " << sequence[ z ] << endl;
        cout << endl;
        pauseScreen( );
    }
    clearScreen( );
    cout << endl;
    // end on the character specified
    cout << one << " " << two << " " << three << endl;
}

// show bank balance information, typically after a round of play
// wager is what was bet
// balanceBefore is the bank balance before the round of play
// balanceAfter is the bank balance after the round of play
void Screen::displayWager( int wager, int balanceBefore, int balanceAfter )
{
    using namespace std;
    
    if (balanceBefore > balanceAfter)
    {
        cout << "Lost $" << wager << endl;
    }
    else
    {
        cout << "Won $" << balanceAfter - balanceBefore << endl;
    }
    cout << "$" << balanceAfter << " Available To Bet" << endl;
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen and pause implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

// clear the screen
void Screen::clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

// pause for a short while
void Screen::pauseScreen()
{
    Sleep(200);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>
#include <thread>
#include <chrono>

// clear the screen
void Screen::clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
        cout << endl;
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

// pause for a short while
void Screen::pauseScreen()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

#endif
