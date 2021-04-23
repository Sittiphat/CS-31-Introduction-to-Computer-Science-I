#include <iostream>
// #include <string>
#include <cassert>

#include "Auction.h"
#include "EBayBucks.h"

using namespace std;


int main() {
  // sample test code
  Auction auction( "4th Generation iPod", 50.00 );
  EBayBucks bucks;

  assert( auction.numberOfBids( ) == 0 );
  assert( auction.wasSuccessful( ) == false );
  assert( auction.getDescription( ) == "4th Generation iPod" );
  assert( std::to_string( auction.winningBid( ) ) == "-1.000000" );

  // bids don't count if the auction isn't open...
  assert( auction.bid( 100.00 ) == false );
  assert( auction.bid( 200.00 ) == false );
  assert( auction.bid( 300.00 ) == false );
  assert( auction.numberOfBids( ) == 0 );
  assert( auction.wasSuccessful( ) == false );
  assert( std::to_string( auction.winningBid( ) ) == "-1.000000" );

  auction.openAuction( );

  // an auction is not successful if the bids are too low...
  assert( auction.bid( -50.00 ) == false );   // negative bids are ignored
  assert( auction.bid( 1.00 ) == true );
  assert( auction.bid( 2.00 ) == true );
  assert( auction.bid( 3.00 ) == true );
  assert( auction.bid( 1.50 ) == false );     // bids lower than the currentBid value are ignored
  assert( auction.numberOfBids( ) == 3 );
  assert( auction.wasSuccessful( ) == false );
  assert( std::to_string( auction.winningBid( ) ) == "-1.000000" );

  // an auction must be closed to be deemed successful
  assert( auction.bid( 100.00 ) == true );
  assert( auction.numberOfBids( ) == 4 );
  assert( auction.wasSuccessful( ) == false );

  auction.closeAuction( );
  assert( auction.wasSuccessful( ) == true );
  assert( std::to_string( auction.winningBid( ) ) == "100.000000" );

  // bids don't count if the auction is closed...
  assert( auction.bid( 500.00 ) == false );
  assert( auction.bid( 600.00 ) == false );
  assert( auction.numberOfBids( ) == 4 );

  assert( std::to_string( bucks.earnings( ) ) == "0.000000" );
  assert( std::to_string( bucks.issueCertificate( ) ) == "0.000000" );

  bucks.addAuction( auction );
  assert( std::to_string( bucks.earnings( ) ) == "1.000000" );
  assert( std::to_string( bucks.issueCertificate( ) ) == "1.000000" );
  // once a certificate is issued, the earned award gets reset to zero
  assert( std::to_string( bucks.earnings( ) ) == "0.000000" );

  Auction a( "unsuccessful", 10000.00 );
  a.openAuction( );
  assert( a.bid( 100.00 ) == true );
  assert( a.numberOfBids( ) == 1 ); // One bid but not successful
  a.closeAuction( );
  assert( a.wasSuccessful( ) == false );

  // unsuccessful auctions don't raise the earned award
  bucks.addAuction( a );
  assert( std::to_string( bucks.earnings( ) ) == "0.000000" );

  // Jesse Narkmanee's Tests
  Auction bid("Macbook Air", 428.00);
  EBayBucks eBucks;

  // Opening then Closing Auction
  auction.openAuction( );
  auction.closeAuction( );

  assert( bid.bid( 100.00 ) == false );
  assert( bid.bid( 200.00 ) == false );
  assert( bid.bid( 300.00 ) == false );
  assert( bid.numberOfBids( ) == 0 );
  assert( bid.wasSuccessful( ) == false );
  assert( std::to_string( bid.winningBid( ) ) == "-1.000000" );


  bid.openAuction( );
  assert( bid.bid( -50.00 ) == false );
  assert( bid.bid( -100.00 ) == false );
  assert( bid.bid( -1000.00 ) == false );
  assert( bid.bid( 1000.00 ) == true );
  assert( bid.bid( 2000.00 ) == true );
  assert( bid.bid( 4320.00 ) == true ); // Highest Bid
  assert( bid.bid( 4310.00 ) == false );
  assert( bid.numberOfBids( ) == 3 );
  assert( bid.wasSuccessful( ) == false ); // Not yet closed
  assert( std::to_string( bid.winningBid( ) ) == "-1.000000" );

  bid.closeAuction( );
  assert( bid.wasSuccessful( ) == true );
  assert( std::to_string( bid.winningBid( ) ) != "4310.000000" );
  assert( std::to_string( bid.winningBid( ) ) == "4320.000000" );


  assert( bid.bid( 5320.00 ) == false ); // Bids Closed
  assert( bid.bid( 6310.00 ) == false );
  assert( bid.numberOfBids( ) == 3 ); // Unchanged

  eBucks.addAuction( bid );
  // cerr << std::to_string( eBucks.earnings( ) ) << endl;
  assert( std::to_string( eBucks.earnings( ) ) == "43.200000" );
  assert( std::to_string( eBucks.issueCertificate( ) ) == "43.200000" );
  // Resets after issued certificate
  assert( std::to_string( eBucks.earnings( ) ) == "0.000000" );



  cerr << "All tests passed!" << endl;

  return 0;
}
