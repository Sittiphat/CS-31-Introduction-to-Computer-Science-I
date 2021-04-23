//
//  SlotMachine.cpp
//  SlotMachine
//
//


#include <cstdlib>
#include <iostream>
#include <string>
#include "SlotMachine.h"
#include "RandomNumber.h"
#include "Bank.h"
#include "PayTable.h"


SlotMachine::SlotMachine( std::string seq )
   : display( true ), sequence( seq )
{

}

// TODO: force a specific set of wheels to be played and display the screen if requested to do so
void SlotMachine::play( Bank & bank, char w1, char w2, char w3 )  // cheating
{
    // TODO: update the wheel1, wheel2 and wheel3 members from the passed cheating values

    // TODO: Draw the machine by calling spinWheels

    // TODO: Update the bank and display results by calling updateBankFromSpinAndDisplay

    wheel1 = w1;
    wheel2 = w2;
    wheel3 = w3;

    spinWheels();

    updateBankFromSpinAndDisplay(bank);

}

// TODO: randomly spin the wheels and display the screen if requested to do so
void SlotMachine::play( Bank & bank )
{
    // TODO: pick three random letters for the sequence of available letters on this machine
    // TODO: update the wheel1, wheel2 and wheel3 members

    // TODO: Draw the machine by calling spinWheels

    // TODO: Update the bank and display results by calling updateBankFromSpinAndDisplay
    RandomNumber r(0, sequence.size() - 1); // Random index so that it can point to a random char in sequence string
    wheel1 = sequence[r.random()];
    wheel2 = sequence[r.random()];
    wheel3 = sequence[r.random()];


    spinWheels();

    updateBankFromSpinAndDisplay(bank);

}

// spin the wheels
void SlotMachine::spinWheels( )
{
    // Draw the machine
    if (display)
    {
        Screen screen;
        screen.displayScreen(wheel1, wheel2, wheel3, sequence);
    }
}

// show the wager after one round of play
void SlotMachine::displayWager( int wager, int before, int after )
{
    // Show the wager information
    if (display)
    {
        Screen screen;
        screen.displayWager( wager, before, after );
    }
}

// update the bank for one round of play
void SlotMachine::updateBankFromSpinAndDisplay( Bank & b )
{
    int balanceBefore = b.balance();
    int wager = b.getWager( );

    PayTable p( wheel1, wheel2, wheel3 );
    p.manageWager( b );

    int balanceAfter = b.balance();

    // Display the wager lines
    displayWager( wager, balanceBefore, balanceAfter );
}

// trivial getter
char SlotMachine::getWheel1() const
{
    return( wheel1 );
}

// trivial getter
char SlotMachine::getWheel2() const
{
    return( wheel2 );
}

// trivial getter
char SlotMachine::getWheel3() const
{
    return( wheel3 );
}

void SlotMachine::showDisplay()
{
    display = true;
}

void SlotMachine::noDisplay()
{
    display = false;
}
