// ##### C-Strings ################################################################################
c-string = array of chars; terminates with '\0' NOT '\n'
char c_str[3] = {'o','n','e'};
cout << c_str[1];       // OUTPUT: n
cout << c_str;          // OUTPUT: one

// String literals
const char* literal = "This is a literal";
const char* lit_arr[3] = {"one", "two", "three"};
cout << lit_arr[1];   // OUTPUT: two
cout << lit_arr;      // OUTPUT: ptr adress to the first element

// Strings for comparisson
string str[] = {"one", "two", "three"};
str.c_str();                // string to c-string

#include <cstring>
char* strncpy(char* dest, const char* source, size_t num );  // Copies the first num characters of source to destination
char* strncpy(charArray, str.c_str(), n);  // copy str to const char array
char* strcpy (char* dest, const char* source ); // Copies the C string pointed by source into the array pointed by destination
char* strncat(char* dest, const char* source, size_t num );  // Appends the first num characters of source to destination 
int strcmp (const char* str1, const char* str2);    // compares two strings 0:equal

sizeof(c-str)     // lenght of string including '\0' (+1)
sizeof(char) = 1
sizeof(int) = 4

// loop through C-string
void loopC_string(const char* text) {
    int length = 0;
    while(*(text+length)!='\0'){
        length++;
    }
    for(int i=0; i<(length); i++){
        cout << text[i];        // prints all chars but doesnt go beyond \n
    }

// string to number data types
std::stoi(str)              // string to int   
std::stof(str)              // string to float
std::stod(str)              // string to double
std::stol(str)              // string to long   
std::stold(str)             // string to long double
std::stoul(str)             // string to unsigned long   
std::stoll(str)             // string to long long   
std::stoull(str)            // string to unsigned long long
