#ifndef AUCTION_H
#define AUCTION_H


#include <string>

class Auction {

  std::string mDescription;
  double mMinimumPrice;
  double mCurrentBid;
  int mTotalNumberOfBids;
  bool mAuctionIsOpen;


  public:

    Auction(std::string description, double minprice);
    void openAuction();
    bool bid(double amount);
    int numberOfBids() const;
    void closeAuction();
    bool wasSuccessful() const;
    double winningBid() const;
    std::string getDescription() const;

};



#endif
