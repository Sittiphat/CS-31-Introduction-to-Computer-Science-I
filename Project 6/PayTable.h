//
//  PayTable.hpp
//  SlotMachine
//
//  Created by Howard Stahl on 4/25/20.
//  Copyright © 2020 Howard Stahl. All rights reserved.
//

#ifndef PayTable_H
#define PayTable_H

#include "Bank.h"

// TODO: CS 31 Students need to complete both of the public methods of this class
// The purpose of this class is to implement the paylines of a SlotMachine for the wheel values provided
class PayTable
{
public:
    PayTable( char wheel1, char wheel2, char wheel3 );
    
    // a pay multiplier which represents how to handle the
    enum Multiplier { ZERO, ONETIME, TWOTIME, THREETIME, FOURTIME, FIVETIME, SIXTIME, SEVENTIME, TENTIME = 10};
    
    // TODO: For the wheel combination, determine the pay multiplier
    Multiplier calculateMultiplier( );
    
    // TODO: For the wheel combination and wager of the passed Bank, update the Bank's balance
    void manageWager( Bank & bank );

private:
    char mWheel1, mWheel2, mWheel3;
};

#endif
