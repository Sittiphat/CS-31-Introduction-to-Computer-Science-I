#ifndef EBAYBUCKS_H
#define EBAYBUCKS_H


class Auction;

class EBayBucks {

  double earnedAward;


  public:

    EBayBucks();
    void addAuction(Auction a);
    double earnings() const;
    double issueCertificate();

};



#endif
