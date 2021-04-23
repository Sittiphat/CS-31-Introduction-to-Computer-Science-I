#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

// Assigned Functions
int locateMinimum( const string array[ ], int n );
int countPunctuation( const string array[ ], int  n );
bool hasReverse( const string array[ ], int n );
char highestOccurredCharacter( const string array[ ], int n, int index );
bool isInIncreasingOrder( const string array[ ], int  n );
char firstNonRepeatedCharacter( const string array[ ], int n, int index );
bool isOnlyDigits( const string array[ ], int n );


int main() {

  string array[5] = { "abcdef", "ghijkgghk", "12345", "lpmpnopop", "54321" };
  // People
  string array2[5] = {  "jon", "mamabbcc!", "samwell,", "daenerys.", "tyrion" };
  string array3[6] = { "123", "456", "789", "gamma", "beta", "delta" };
  // Folks
  string array4[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "llewmas", "noj"};
  string array5[6] = { "123", "456", "789", "234", "23424", "32423" };
  string array6[6] = { "10000", "1000", "10000", "1000000", "1000000000", "100000000000" };
  // Empty Strings
  string array7[2] = {"", ""};
  string array8[2] = {"a", "a"};
  // cerr << highestOccurredCharacter(array, 5, 1) << endl;
  // cerr << locateMinimum(array2, 5) << endl;
  // cerr << countPunctuation(array2, 5) << endl;

  assert(locateMinimum(array6, 6) == 1);
  assert(locateMinimum(array2, 5) == 3);
  assert(countPunctuation(array2, 5) == 3);
  assert(countPunctuation(array2, 1) == 0);
  assert(hasReverse( array4, 5 ) == false);
  assert(hasReverse( array2, 5 ) == false);
  assert(hasReverse( array4, 8 ) == true);
  assert(highestOccurredCharacter( array2, 5, 0 ) == 'j');
  assert(highestOccurredCharacter( array2, 5, 2 ) == 'l');
  assert(highestOccurredCharacter( array2, 0, 2 ) == '\0');
  assert(isInIncreasingOrder( array2, 5 ) == false);
  assert(isInIncreasingOrder( array2, 3 ) == true);
  assert(firstNonRepeatedCharacter( array2, 5, 1 ) == '!');
  assert(firstNonRepeatedCharacter( array2, 5, 0 ) == 'j');
  assert(firstNonRepeatedCharacter( array2, 0, 0 ) == '\0');
  assert(isOnlyDigits(array3, 6 ) == false);
  assert(isOnlyDigits(array3, 3 ) == true);
  assert(isOnlyDigits(array3, 0 ) == false);

  // Empty String Tests
  assert(locateMinimum(array7, 2) == 0); // Pass
  assert(countPunctuation(array7, 2) == 0); // Pass
  assert(hasReverse( array7, 2 ) == true); // Pass
  assert(hasReverse( array8, 2 ) == true); // Pass
  assert(highestOccurredCharacter(array7, 2, 0) == '\0'); // Pass
  assert(isInIncreasingOrder(array7, 2) == false); // Pass
  assert(firstNonRepeatedCharacter( array7, 2, 0 ) == '\0'); // Pass
  assert(isOnlyDigits( array7, 2 ) == false); // Pass
  assert(isOnlyDigits( array8, 2 ) == false); // Pass


  cerr << "All tests succeeded!" << endl;

  return 0;
}


int locateMinimum( const string array[ ], int n ) {
  // If n is less than or equal to 0 return -1 as per specs
  if (n <= 0) {
    return -1;
  }
  // We assume that the first element and index is the minimum until
  // we find so otherwise in the later for loop
  string comp_string = array[0];
  int index = 0;

  // Through iterating through the array if we find something
  // less that the string we are comparing with, that is our new minimum.
  for (size_t i = 0; i < n; i++) {
    if (array[i] < comp_string) {
      comp_string = array[i];
      index = i;
    }
  }
  return index;
}

int countPunctuation( const string array[ ], int  n ) {
  // If n is less than or equal to 0 return -1 as per specs
  if (n <= 0) {
    return -1;
  }

  // We initialize our punctuation counter to 0
  int count = 0;
  // Outer loop loops through each element of strings
  for (size_t i = 0; i < n; i++) {
    // In each element, we now loop through each char of the string
    // to count how many punctuations.
    for (size_t j = 0; j < array[i].size(); j++) {
      if (ispunct(array[i].at(j))) {
        count++;
      }
    }
  }
  return count;
}

bool hasReverse( const string array[ ], int n ) {
  // If n is less than or equal to 0 return false as per specs
  if (n <= 0) {
    return false;
  }

  // First loop increments forward which chooses first string element to compare
  for (size_t i = 0; i < n; i++) {
    // Second loop increments backwards which chooses second string element to compare
    for (size_t j = (n - 1); j > i; j--) {
      // Combined loop that only analyzes two string elements
      // that are equal in length. If they are equal in length then it has a chance
      // of being a palindrome.
      if (array[i].size() == array[j].size()) {
        // If both strings are empty strings, they are reverse of each other
        if (array[i] == "" && array[j] == "") {
          return true;
        }
        // Combine for loop analyzes two same length strings forward and backwards,
        // to see if they are indeed just a reverse of each other.
        bool isPalindrome = true; // Assume it is true until found else otherwise
        for (size_t k = 0, l = (array[j].size() - 1); k < (array[i].size() - 1) && l >= 0; k++, l--) {
          if (array[i].at(k) != array[j].at(l)) { // If it is false, we break early.
            isPalindrome = false;
            break;
          }
        }
        if (isPalindrome == true) {
          return true;
        }
      }
    }
  }
  return false;
}

char highestOccurredCharacter( const string array[ ], int n, int index ) {
  // As per spec instructions
  if (n <= 0 || index >= n || index < 0 || array[index] == "") {
    return '\0';
  }

  // Create array with same size as target string array
  // this will reflect each element's repeat amount.
  int* word = new int[array[index].size()];

  for (size_t i = 0; i < array[index].size(); i++) {
    // Here is our target char we will be comparing with
    // inner loop. As we encounter repeats, we increment the counter.
    char target = array[index].at(i);
    // We initially initialize to zero in preparation to start
    // and reset for moving on to new target elements.
    int count = 0;
    for (size_t j = 0; j < array[index].size(); j++) {
      if (target == array[index].at(j)) {
        count++;
      }
    }
    // Here is the counter array we made earlier, a reflection of our given array.
    word[i] = count;
  }
  // The counter array is complete and all have to examine which index contains the
  // maximum first then use that index position to return the correct char.
  // First we assume that the first element has the maximum value then change as we encounter others.
  int max = word[0];
  int position = 0;

  for (size_t i = 0; i < array[index].size(); i++) {
    if (max < word[i]) {
      max = word[i];
      position = i;
    }
  }

  delete [] word; // Deleting word array from the heap

  // Now after finding the maximum occurance count and its index, we return original string
  // array's element at that index.
  return array[index].at(position);




// Flawed Design (similar to below)
/*  char target = array[index].at(0);
  int counter = 1;

  for (size_t i = 1; i < array[index].size(); i++) {
    if (array[index].at(i) == target) {
      counter++;
    }
    array[index].at(i)
  }*/
}

bool isInIncreasingOrder( const string array[ ], int  n ) {
  // If n is less than or equal to 0 return false as per specs
  if (n <= 0) {
    return false;
  }

  // A combined for loop that uses inspiration from insertion sort
  // in evaluating two consecutive elements and incrementing simultaneously.
  for (size_t i = 0, j = 1; (i < (n - 1)) && j < n; i++, j++) {
    if (array[i] >= array[j]) {
      return false;
    }
  }
  return true;
}

char firstNonRepeatedCharacter( const string array[ ], int n, int index ) {
  // As per spec instructions
  if (n <= 0 || index >= n || index < 0) {
    return '\0';
  }

  // Create array with same size as target string array
  // this will reflect each element's repeat amount.
  int* word = new int[array[index].size()];

  for (size_t i = 0; i < array[index].size(); i++) {
    // Here is our target char we will be comparing with
    // inner loop. As we encounter repeats, we increment the counter.
    char target = array[index].at(i);
    // We initially initialize to zero in preparation to start
    // and reset for moving on to new target elements.
    int count = 0;
    for (size_t j = 0; j < array[index].size(); j++) {
      if (target == array[index].at(j)) {
        count++;
      }
    }
    // Here is the counter array we made earlier, a reflection of our given array.
    word[i] = count;
  }
  // The counter array is complete and all have to examine how is the first element
  // to only have just 1 count (since it would have counted itself), then return that
  // index of the original array
  for (size_t i = 0; i < array[index].size(); i++) {
    if (word[i] == 1) {

      delete [] word; // Deleting word array from the heap
      return array[index].at(i);
    }
  }



// Flawed Design when character repeated before and last element is not a repeat!
/*  // Assume that first char element is non-repeating and change
  // if otherwise
  char target;
  bool true_false = true;

  // First loop chooses the char element to compare
  for (size_t i = 0; i < (array[index].size() - 1); i++) {
    // We assume our target is the chosen char element
    // and compare by iterating through the rest of the string array
    target = array[index].at(i);
    for (size_t j = i + 1; j < array[index].size(); j++) {
      // If we find this target character has a repeat, we end the loop
      // early and choose our next target. If the character does
      // repeat then we keep true and return this target char.
      if (target == array[index].at(j)) {
        true_false = false;
        break;
      }
    }
    // If the target char has no matches it is consecutive
    if (true_false) {
      return target;
    }
  }*/

  delete [] word;
  return '\0';
}

bool isOnlyDigits( const string array[ ], int n ) {
  bool true_false = true;

  // If n is less than or equal to 0 return false as per specs
  if (n <= 0) {
    return false;
  }

  // Check for empty string, we append all the string elements
  // Then if the string sum after appendage is still empty string
  // Then there is no string and therefore no digit
  string string_sum = "";
  for (size_t i = 0; i < n; i++) {
    string_sum += array[i];
  }
  if (string_sum == "") {
    return false;
  }

  // Outer loop chooses string element in array
  for (size_t i = 0; i < n; i++) {
    // Inner loop loops through each char in selected element
    // If we fund something that is not a digit, we return false.
    for (size_t j = 0; j < array[i].size(); j++) {
      if (!isdigit(array[i].at(j))) {
        true_false = false;
      }
    }
  }
  return true_false; // I don't really need this
}
