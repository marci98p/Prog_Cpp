// ##### cin ######################################################################################
#include <iostream>
#include <iomanip>
using namespace std;

cin >> input;
cin >> name >> ag               // get multiple inputs separated by " "
cin.get(input, size);           // read up to size-1 chars (-1 because last char null)
cin >> setw(size) >> input      // max input lengh = size-1

#include <string>
getline (cin, inputLine);       // get entire line
// more: https://www.geeksforgeeks.org/cin-in-c/

// check cin for right type 
cout << "Enter only numbers: ";
int input;
do{
  cin >> setw(10) >> input;
} while (cin)
cin.clear();
cin.ignore(1000, '\n');

// read input - another example - with ptr
do {
  // as long as cin OK and i not bigger than max_i
  cout << "*(a_ptr + "<< *i <<"): ";
} while (cin >> a[(*i)++] && (*i) <= max_i);    // breaks out when cin failed or index reached
