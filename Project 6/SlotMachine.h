//
//  SlotMachine.hpp
//  SlotMachine
//
//

#ifndef SlotMachine_h
#define SlotMachine_h

#include "Bank.h"
#include "Screen.h"
#include <string>

// TODO: CS 31 Students need to complete some of the public methods of this class
// The purpose of this class is to implement a SlotMachine game
class SlotMachine
{
public:
    SlotMachine( std::string seq="AKQJ9876" );
    
    // TODO: randomly spin the wheels and display the screen if requested to do so
    void play( Bank & bank );
    // TODO: force a specific set of wheels to be played and display the screen if requested to do so
    void play( Bank & bank, char wheel1, char wheel2, char wheel3 );  // cheating...
    
    // trivial getters
    char getWheel1() const;
    char getWheel2() const;
    char getWheel3() const;
    
    void showDisplay();
    void noDisplay();

private:
    char        wheel1, wheel2, wheel3;    // the three wheels of this machine
    std::string sequence;                  // the total set of values to show when these wheels are spun
    bool        display;                   // is generated output desired for each round of play?
    
    // spin the wheels
    void spinWheels(  );
    // show the wager after one round of play
    void displayWager( int wager, int before, int after );
    // update the bank for one round of play
    void updateBankFromSpinAndDisplay( Bank & b );

};


#endif
