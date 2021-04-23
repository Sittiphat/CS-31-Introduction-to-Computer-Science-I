#include <iostream>
#include <string>
#include <cctype>
#include <assert.h>

using namespace std;

// Helper Functions
void convertLower(string& order);

bool hasLeadingZeros(string order, bool& start_order, int position);

bool isOrderChar(string order, int position);

// Assigned Functions
bool isWellFormedGroceryOrderString(string order);
int pickupCount(string order);
int deliveryCount(string order);
int shipCount(string order);
int inpersonCount(string order);




int main() {

string order = "1D1I"; // 1 Delivery, 1 In-person store is Valid!

if (isWellFormedGroceryOrderString(order)) {
  cout << "True!" << '\n';
  cout << "Running Total is: " << inpersonCount(order) << '\n';
} else {
  cout << "False!" << '\n';
  cout << "Running Total is: " << inpersonCount(order) << '\n';
}

  return 0;
}

// Checks to see which is uppercase to convert to lowercase.
void convertLower(string& order) {
  for (int i = 0; i < order.size(); i++) {
    if (isupper(order[i])) { // Works without the islower() check
      order[i] = tolower(order[i]);
    }
  }
}


// Checks order string syntax
bool isWellFormedGroceryOrderString(string order) {
  // Make everything lowercase automatically
  convertLower(order);

  // On/off switches and order total variables initialized
  bool number_order = true; // when we hit char order->off then back on.
  bool start_order = true; // on/off order switch |after leading zero->off, after order char->on|
  int order_total = 0;
  int running_total = 0;
  int p_running_total = 0;
  int d_running_total = 0;

  // Our first check before the loop is if it is an empty string
  if (order == "") {
    return false;
  }

  size_t position = 0;
  // Position starts at 0 counter and increments up as program checks
  while (position < order.size()) {
    if (number_order) {
      if (hasLeadingZeros(order, start_order, position)) { // Order cannot have any leading zeros
        return false;
      } else if (!isdigit(order.at(position))) { // All order must begin as a digit
        return false;
      } else {
        // If we are on last element stop increment and will later be false.
        while (isdigit(order.at(position)) && (position < (order.size() - 1))) { // Needs to be -1 since at least last letter should be char order type
          int digit = order.at(position) - '0';
          order_total = order_total * 10 + digit; // This equation help calculate using base 10 arithmetic
          position++;
        }
        // Number order has ended now we need to see what char order type
        number_order = false;
      }
    }

    // We dont need this if but to help read, char order type start
    if (!number_order) {
      // Checks to see if it is p,d,s,f and nothing else
      // If there is no order type then it will also return false since
      // in our earlier while loop position did not move so still on number
      if (!isOrderChar(order, position)) {
        return false;
      }
      // Order Total Maximums
      else {
        if (order.at(position) == 'p') {
          p_running_total += order_total;
          if (order_total > 20) {
            return false;
          }
        } else if (order.at(position) == 'd') {
          d_running_total += order_total;
          if (order_total > 10) {
            return false;
          }
        }
      }
    }
    // Running total increments by each order until ends or reaches max
    // We also reset the order total for the next order.
    running_total += order_total;
    order_total = 0;

    // Before looking at the next order number, we need to indicate
    // it is start of order to evaluate leading zeros and number correctness.
    start_order = true;
    number_order = true;

    // Since we will soon be looking at the next order we also need to
    // update our position on the string.
    position++;
  }
  // If it is all true move on with the program as long as we do not
  // exceed a max running order total.
  if (running_total > 99) {
    return false;
  } else if (p_running_total > 20) {
      return false;
  } else if (d_running_total > 20) {
      return false;
  } else {
    return true;
  }

}


// Helper Function that helps see if when the number_order switch is on
// there should be no leading zeros
bool hasLeadingZeros(string order, bool& start_order, int position) {
  if (start_order == true && order.at(position) == '0') {
    // No longer start of order now
    start_order = false;
    return true;
  } else {
    // No longer start of order now
    start_order = false;
    return false;
    }
  }


// Only posibilities are car pickup, delivery, shipped, and in-store pickup options.
bool isOrderChar(string order, int position) {
  if (order.at(position) == 'p' || order.at(position) == 'd' || order.at(position) == 's' || order.at(position) == 'i') {
    return true;
  } else {
    return false;
  }
}


// Helper Void Function that helps reuse code to calculate running-total
// of specific order type determined by the const char order_type parameter
void orderType(string order, const char order_type, int& running_total) {

  // Position and order total counters (this will be reset after every order)
  int position = 0;
  int order_total = 0;

  // Similar to the function that checks string syntax that adds total order up,
  // this is more specified.
  while (position < order.size()) {
    if (isdigit(order.at(position)) && (position < (order.size() - 1))) { // Needs to be -1 since at least last letter should be char order type
      int digit = order.at(position) - '0';
      order_total = order_total * 10 + digit;
      position++;
    } else if (order.at(position) == order_type) {
      running_total += order_total;
      order_total = 0; //"1D1P4d4p"
      position++;
    } else {
      order_total = 0;
      position++;
    }
  }
}


// Calculates pickup running total or if wrong syntax returns -1.
int pickupCount(string order) {
  // Make everything lowercase automatically
  convertLower(order);

  // Running total counter which will be passed by reference
  // Char Order type differs by function which is a parameter which chooses
  // what kind of running total
  char order_type = 'p';
  int running_total = 0;

  // If it is not well formed, return -1
  // Else call the orderType function which depending on which char parameter,
  // will give the running total of a specific order type of a whole order string.
  if (!isWellFormedGroceryOrderString(order)) {
    return -1;
  } else {
    orderType(order, order_type, running_total);
  }
  // Takes the running total from orderType helper function which does all calculations
  return running_total;
}

// Calculates delivery running total or if wrong syntax returns -1.
int deliveryCount(string order) {
  // Make everything lowercase automatically
  convertLower(order);

  // Running total counter which will be passed by reference
  // Char Order type differs by function which is a parameter which chooses
  // what kind of running total
  char order_type = 'd';
  int running_total = 0;

  // If it is not well formed, return -1
  // Else call the orderType function which depending on which char parameter,
  // will give the running total of a specific order type of a whole order string.
  if (!isWellFormedGroceryOrderString(order)) {
    return -1;
  } else {
    orderType(order, order_type, running_total);
  }
  // Takes the running total from orderType helper function which does all calculations
  return running_total;
}


// Calculates shipping running total or if wrong syntax returns -1.
int shipCount(string order) {
  // Make everything lowercase automatically
  convertLower(order);

  // Running total counter which will be passed by reference
  // Char Order type differs by function which is a parameter which chooses
  // what kind of running total
  char order_type = 's';
  int running_total = 0;

  // If it is not well formed, return -1
  // Else call the orderType function which depending on which char parameter,
  // will give the running total of a specific order type of a whole order string.
  if (!isWellFormedGroceryOrderString(order)) {
    return -1;
  } else {
    orderType(order, order_type, running_total);
  }
  // Takes the running total from orderType helper function which does all calculations
  return running_total;
}


// Calculates in person running total or if wrong syntax returns -1.
int inpersonCount(string order) {
  // Make everything lowercase automatically
  convertLower(order);

  // Running total counter which will be passed by reference
  // Char Order type differs by function which is a parameter which chooses
  // what kind of running total
  char order_type = 'i';
  int running_total = 0;

  // If it is not well formed, return -1
  // Else call the orderType function which depending on which char parameter,
  // will give the running total of a specific order type of a whole order string.
  if (!isWellFormedGroceryOrderString(order)) {
    return -1;
  } else {
    orderType(order, order_type, running_total);
  }
  // Takes the running total from orderType helper function which does all calculations
  return running_total;
}
