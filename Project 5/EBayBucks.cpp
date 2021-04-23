#include "EBayBucks.h"
#include "Auction.h"

using namespace std;

EBayBucks::EBayBucks()
  : earnedAward(0.0) {}

// That award amount should be increased by 1% of all the successful Auction winningBid
// values from all the Auctions passed to the .addAuction( ... ) operation.
void EBayBucks::addAuction(Auction a) {
  double bonus;
  if (a.winningBid() == -1) { // If the program is not successful then winningBid() returns -1
    bonus = 0; // Bonus would therefore be 0 since there was no winning bid
  } else
    bonus = 0.01 * a.winningBid(); // If it is successful and there was a winning bid

  earnedAward += bonus; // We add up the earnedAward
}

// The current award amount can be retrieved by calling .earnings( ).
double EBayBucks::earnings() const {
  return earnedAward;
}

// The operation .issueCertificate( ) also returns the earned amount
// and then resets the earnedAward back to zero for later use.
double EBayBucks::issueCertificate() {
  double issuedAward = earnedAward; // Placeholder assignment
  earnedAward = 0.0; // To reset eBay Bucks

  return issuedAward;
}
