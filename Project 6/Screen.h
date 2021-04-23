//
//  Screen.h
//  SlotMachine
//
//

#ifndef SCREEN_H
#define SCREEN_H

#include <string>

// This class is completely finished and there is nothing for a CS 31 student to do here.
// The purpose of this class is to handle display tasks.
class Screen
{
public:
    Screen();
    
    // show the rotating slot machine wheels, ending on each character specified
    void displayScreen( char one, char two, char three, std::string sequence );
    // show bank balance information, typically after a round of play
    void displayWager( int wager, int balanceBefore, int balanceAfter );
    // clear the screen
    void clearScreen();
    // pause the screen
    void pauseScreen();
private:
    
};

#endif 
