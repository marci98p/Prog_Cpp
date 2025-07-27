// ##### cin ######################################################################################
#include <iostream>
#include <iomanip>

cin >> stream1 >> stream2       // multiple inputs separated by " " or '\n'
cin.get(char);                  // reads sinlge char

char char_buffer[100];          // char_buffer[100] = '\n'
cin.get(char_buffer, 100);      // stream including ' ', '\t'; terminate '\n'
cin.get(char_buffer, 100, ';'); // reads until `;` or 99 symbols

cin.get(input, size);           // read up to size-1 chars (-1 because last char '\0')
cin >> setw(size) >> input      // read size-1 char; char[size] = '\n' 

getline (cin, stream);          // get entire line

cin.clear();
cin.ignore(1000, '\n');
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
