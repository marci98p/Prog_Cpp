#include <stdexcept>
try {}
throw <data type>(value)
catch (<data type> variableName)

// Example 1 ***************************************************
void Date::setValues(int day, int month, in year) {
  try {
    setYear(year);      // throw inside functions
    setMonth(month);
    setDay(day);
  } catch (string errorMessage) {
    cerr << errorMessage << endl;
  }
 }

// Example 2 ***************************************************
#include <iostream>
#include <stdexcept>

try {
     throw std::invalid_argument("Something went wrong");
}
catch (const std::invalid_argument& errMsg) {
      std::cout << errMsg.what() << std::endl;
}


// Example 3 ***************************************************
try {
   ....
   throw string("An unexpected error occured");
   ....
 } catch (string errorMessage) {
  cerr << errorMessage << endl;
 }

// Example 4 ***************************************************
int main() {
   try{
      initializeDate();
   } catch (const string& string_ref) {
      cout << "Caught exception: " << string_ref;
   }
   return 0;
 }

void initializeDate(){
   setDate(14,20);
   cout << "Date successfully initialized!"<<endl;
 }

void setDate(int month, int day) {
    if (month<1 || month>12) {
      throw string("month must be between 1 and 12");
    }
    if (day<0 || day >31) {
      throw string("day must be between 1 and 31");
    }
    cout << "Date successfully set!"<<endl;
 }
