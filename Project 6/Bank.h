//
//  Bank.hpp
//  SlotMachine
//
//

#ifndef Bank_h
#define Bank_h

// TODO: CS 31 Students need to complete some of the public methods of this class
// The purpose of this class is to implement a bank of funds and a wager than can be won or lost
class Bank
{
public:
    Bank( int amount = 0 );
    
    // TODO: adjust the bank balance for the amount won or lost
    void win( int amount );
    void lose( int amount );
    
    // TODO: adjust the bank balance for the amount being added to the bank
    void deposit( int amount );
    // trivial getter
    int balance() const;
    // TODO: return the bank balance and set it bank to zero
    int cashOut( );
    // TODO: can the amount be wagered??
    bool canWager( int amount ) const;
    // trivial setter
    void setWager( int amount );
    // trivial getter
    int getWager() const;
    
private:
    int bankAmount;  // the current bank balance
    int wager;       // what is currently being wagered in this round of play
    
};


#endif
