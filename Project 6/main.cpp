// slotmachine.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  
// As you finish implementing each TODO: item, remove its TODO: comment.

#include "SlotMachine.h"
#include "Bank.h"
#include "PayTable.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;



int main()
{
    Bank bank;
    SlotMachine s;
    
    using namespace std;
    do
    {
         cout << endl;
         cout << "Move (d#/b#/p/c/q): ";
         string action;
         string message;
         int amount;
         getline(cin,action);
         if (action.size() == 0)
         {
             return( 0 );
         }
         else
         {
             switch (action[0])
             {
                 default:   // if bad move, nothing happens
                     cout << '\a' << endl;  // beep
                     continue;
                 case 'q':
                     return( 0 );
                     break;
                     
                 case 'b':  // get
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                         amount = 1;
                     if (bank.canWager(amount))
                     {
                         bank.setWager(amount);
                         cout << "$" << amount << " Bet Accepted!" << endl;
                     }
                     else
                     {
                         cout << "Invalid Bet" << endl;
                     }
                     break;
                 case 'p':
                     if (bank.getWager() == 0)
                     {
                         cout << "You Must Bet First Before Playing" << endl;
                     }
                     else
                     {
                         s.play( bank );
                     }
                     break;
                 case 'd':
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                     {
                         cout << "Invalid Bank Deposit" << endl;
                     }
                     else
                     {
                         bank.deposit( amount );
                         cout << "$" << bank.balance() << " Available To Bet" << endl;
                     }
                     break;
                 case 'c':
                     amount = bank.cashOut();
                     cout << "$" << amount << " Returned To You!" << endl;
                     amount = 0;
                     break;
             }
         }
         
    } while ( true );
    
    return( 0 );
}

