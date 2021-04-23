#include "Auction.h"

using namespace std;

Auction::Auction(std::string description, double minprice)
  : mDescription(description), mMinimumPrice(minprice), mCurrentBid(0.0), mTotalNumberOfBids(0), mAuctionIsOpen(false) {}

void Auction::openAuction() {
    mAuctionIsOpen = true;
}

bool Auction::bid(double amount) {
  if (mAuctionIsOpen) {
    if (amount > mCurrentBid) {
      mCurrentBid = amount; // mCurrentBid is highest bid so far
      mTotalNumberOfBids++; // If we change the mCurrentBid then we increment # of bids
      return true;
    }
  }

  return false;
}

int Auction::numberOfBids() const {
  return mTotalNumberOfBids;
}

void Auction::closeAuction() {
  mAuctionIsOpen = false;
}

// Once an Auction is closed, the Auction will be deemed "successful" if the last bid
//received is larger than the minimum price originally established when the Auction was created.
bool Auction::wasSuccessful() const {
  if ((!mAuctionIsOpen) && (mCurrentBid > mMinimumPrice)) {
    return true;
  } else
    return false;
}

// That highest bid value gets returned when .winningBid( ) is called.
// If there are no bids at all or no bids large enough to win the auction,
// then return -1 as the value for .winningBid( ).
double Auction::winningBid() const {
  if (wasSuccessful()) {
    return mCurrentBid;
  } else
    return -1;
}

std::string Auction::getDescription() const {
  return mDescription;
}
