#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main() {

  // Input for User IO
  string filing_status;
  int income;
  int dependents;

  // Variables for calculations
  int full_stimulus;
  int full_payment;
  int reduction;
  int stimulus_check;

  // User IO
  cout << "What is your filing status? ";
  getline(cin, filing_status);

  cout << "What is your adjusted gross income? ";
  cin >> income;

  cout << "How many children under the age of 17 did you claim as a dependent? ";
  cin >> dependents;


  // User Input Error Checks
  // Checks to see if filing status is correct. If one of below listed is correct it proceeds, else sends error message all the way below.
  if (filing_status == "Single" || filing_status == "Married" || filing_status == "Head of Household") {
    // After initial correct filing status, checks to see if income value is valid.
    if (income < 0) {
      cout << "Error - Invalid income." << endl;
      return -1;
      // After income value is valid, checks to see if dependents value is valid.
    } else if (dependents < 0) {
      cout << "Error - Invalid number of dependents." << endl;
      return -1;
      // If all three inputs are valid, program proceeds to assign appropriate variables for calculations based on filing status.
      // Full stimulus is the amount a person/persons will receive, assuming there are both dependents nor reductions.
      // Full payment determines the baseline amount of how to determine until what maximum income reduction must occur.
    } else {
      if (filing_status == "Single") {
        full_stimulus = 1200;
        full_payment = 75000;
      } else if (filing_status == "Married") {
        full_stimulus = 2400;
        full_payment = 150000;
      } else if (filing_status == "Head of Household") {
        full_stimulus = 1200;
        full_payment = 112500;
      }


      // Stimulus Check Calculations
      // Taking the assigned calculation variables above, we check the proper reduction based on income.
      // If less than full payment then there is no reduction.
      if (income >= (full_payment + 100)) {
        reduction = 5 * ((income - full_payment) / 100);
      } else {
        reduction = 0;
      }

      // After calculating reduction, we add the dependent bonus then minus the reduction to
      // calculate the stimulus check's total amount.
      stimulus_check = (full_stimulus + 500 * dependents) - reduction;

      // If less than 0, which indicates we pass the threshold of max income, person/persons receives nothing.
      if (stimulus_check < 0) {
        stimulus_check = 0;
      }

      // Final output of stimulus check total after calculations.
      cout << "Your stimulus check is $" << stimulus_check << "." << endl;


    }
  } else {
    cout << "Error - Invalid filing status." << endl; // Error for invalid filing status (look top).
    return -1;
  }


  return 0;
}
