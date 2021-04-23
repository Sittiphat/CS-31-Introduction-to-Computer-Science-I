// Code for Project 1

// COVID-19
#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
    int totalTests;
    int positives, falsePositives;
    int negatives, falseNegatives;

    cout << "How many tests for COVID-19 were run? ";
    cin >> totalTests;
    cout << "How many of these were positive for COVID-19? ";
    cin >> positives;
    cout << "How many of these were false positives? ";
    cin >> falsePositives;
    cout << "How many of these were negative for COVID-19? ";
    cin >> negatives;
    cout << "How many of these were false negatives? ";
    cin >> falseNegatives;

    double pctPos = (1.0 * positives - falsePositives) / positives * 100.0;
    double pctNeg = (1.0 * negatives - falseNegatives) / negatives * 100.0;

    cout.setf(ios::fixed);  // see pp. 30-31 in Savitch book
    cout.precision(1);

    cout << endl;
    cout << pctPos << "% of the " << positives << " positive tests were actually positive." << endl;
    cout << pctNeg << "% of the " << negatives << " negative tests were actually negative." << endl;
    cout << endl;

    if (positives + negatives != totalTests)
    {
        cout << "Looks like some of these data values don't make sense." << endl;
    }

    return(0);

}
