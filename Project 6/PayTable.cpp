//
//  PayTable.cpp
//  SlotMachine
//
//

#include "PayTable.h"


PayTable::PayTable( char wheel1, char wheel2, char wheel3 )
{
    mWheel1 = wheel1;
    mWheel2 = wheel2;
    mWheel3 = wheel3;
}

// TODO:  For the wheel combination, determine the pay multiplier
PayTable::Multiplier PayTable::calculateMultiplier( )
{
    /*// For now...
    Multiplier result = ZERO;

    return( result );*/

    Multiplier result = ZERO;

    if (mWheel1 == 'A' && mWheel2 == 'A' && mWheel3 == 'A') { // If all are aces
        result = TENTIME; // Earlier we autoinitialized it in the header file
    }
    else if ((mWheel1 == mWheel2) && (mWheel2 == mWheel3) && (mWheel3 == mWheel1) && (mWheel1 != 'A')) { // If all are same except Aces
        result = SEVENTIME;
    }
    else if ((mWheel1 == 'A' && mWheel2 == 'A') || (mWheel2 == 'A' && mWheel3 == 'A') || (mWheel3 == 'A' && mWheel1 == 'A')) { // If two are aces
        result = FIVETIME;
    }
    else if ((mWheel1 == 'A' && mWheel2 == 'K' && mWheel3 == 'Q') || (mWheel1 == 'K' && mWheel2 == 'A' && mWheel3 == 'Q') ||
    (mWheel1 == 'Q' && mWheel2 == 'K' && mWheel3 == 'A') || (mWheel1 == 'K' && mWheel2 == 'Q' && mWheel3 == 'A') ||
    (mWheel1 == 'Q' && mWheel2 == 'A' && mWheel3 == 'K') || (mWheel1 == 'A' && mWheel2 == 'Q' && mWheel3 == 'K')) { // All permutations of AKQ
        result = FIVETIME;
    }
    else if ((mWheel1 == mWheel2 && mWheel3 == 'A') || (mWheel2 == mWheel3 && mWheel1 == 'A') || (mWheel3 == mWheel1 && mWheel2 == 'A')) { // High pair
        result = FOURTIME;
    }
    else if (mWheel1 == mWheel2 || mWheel2 == mWheel3 || mWheel3 == mWheel1) { // Regular Pair
        result = THREETIME;
    }
    else if (mWheel1 == 'A' || mWheel2 == 'A' || mWheel3 == 'A') { // At least one Ace conditional
        result = ONETIME;
    }
    else {
        result = ZERO; // Not needed but helps to be explicit since already initialized from the beginning
    }


    /*
    string wheel = mWheel1 + mWheel1 + mWheel3;


    if (mWheel1 == 'A' && mWheel2 == 'A' && mWheel1 == 'A') {
        result = TENTIME;
    }
    else if ((mWheel1 == mWheel2) && (mWheel2 == mWheel3) && (mWheel3 == mWheel1) && (mWheel1 != 'A')) {
        result = SEVENTIME;
    }
    else if ((mWheel1 == 'A' && mWheel2 == 'A') || (mWheel2 == 'A' && mWheel3 == 'A') || (mWheel3 == 'A' && mWheel1 == 'A')) {
        result = FIVETIME;
    }
    else if ((mWheel1 == 'A' && mWheel2 == 'K' && mWheel3 == 'Q') || (mWheel1 == 'K' && mWheel2 == 'A' && mWheel3 == 'Q') ||
        (mWheel1 == 'Q' && mWheel2 == 'K' && mWheel3 == 'A') || (mWheel1 == 'K' && mWheel2 == 'Q' && mWheel3 == 'A') ||
        (mWheel1 == 'Q' && mWheel2 == 'A' && mWheel3 == 'K') || (mWheel1 == 'A' && mWheel2 == 'Q' && mWheel3 == 'K')) {
        result = FIVETIME;
    }
    else if ((mWheel1 == mWheel2 && mWheel3 == 'A') || (mWheel2 == mWheel3 && mWheel1 == 'A') || (mWheel3 == mWheel1 && mWheel2 == 'A')) { // Not checked
        result = FOURTIME;
    }
    else if (mWheel1 == mWheel2 || mWheel2 == mWheel3 || mWheel3 == mWheel1) { // Not checked
        result = THREETIME;
    }
    else if (mWheel1 == 'A' || mWheel2 == 'A' || mWheel3 == 'A') {
        result = ONETIME;
    }
    else {
        result = ZERO;
    } */


    /*switch (result) {
    case 0:
        return result;
        break;
    case 1:
        return result;
        break;
    case 3:
        return result;
        break;
    case 4:
        return result;
        break;
    case 5:
        return result;
        break;
    case 7:
        return result;
        break;
    default:
        return result;
    } */

    return result;
}

// TODO: For the wheel combination and wager of the passed Bank, update the Bank's balance
void PayTable::manageWager( Bank & bank )
{
    // for the wager, adjust the Bank balance based on the pay multiplier
    double amount = bank.getWager();
    Multiplier multiplier = calculateMultiplier();

    // TODO: adjust the bank balance accordingly...
    if (multiplier == ZERO) { // If this returns ZERO, then we call lose else win
        bank.lose(bank.getWager());
    } else
      bank.win(multiplier * bank.getWager());
}
