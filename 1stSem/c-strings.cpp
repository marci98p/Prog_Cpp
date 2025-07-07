// ##### C-Strings ################################################################################
c-string = array of chars
 '\0'
char c_str[3] = {"one", "two", "three"};
cout << c_str;      // OUTPUT: 0xffffcbec - C-string name (without) subscript == ptr adress to the first element
cout << c_str[1];   // OUTPUT: one

sizeof(c-str)      // tbc: lenght of string including null char '\n'
#include <cstring>
std::stoi(str)              // string to int   
std::stof(str)              // string to float
std::stod(str)              // string to double
std::stol(str)              // string to long   
std::stold(str)             // string to long double
std::stoul(str)             // string to unsigned long   
std::stoll(str)             // string to long long   
std::stoull(str)            // string to unsigned long long
std::strcmp(argv[2],str)    // compares two strings

// String literals / string constant
const char *literal = "This is a literal";
cout << literal;    // OUTPUT: This is a literal

// loop through C-string
void loopC_string(const char* text) {
    int length = 0;
    while(*(text+length)!='\0'){
        length++;
    }
    for(int i=0; i<(length); i++){
        cout << text[i];        // prints all chars but doesnt go beyond \n
    }
