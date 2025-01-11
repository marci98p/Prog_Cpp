// ________________________________________________________________________________________________
// ##### Data types ###############################################################################
Data Type               Size (in bytes)     Range
short int               2                   -32,768         to 32,767
unsigned short int      2                   0               to 65,535
unsigned int            4                   0               to 4,294,967,295
int                     4                   -2,147,483,648  to 2,147,483,647
long int                4                   -2,147,483,648  to 2,147,483,647
unsigned long int       4                   0               to 4,294,967,295
long long int           8                   -(2^63)         to (2^63)-1
unsigned long long int  8                   0               to 18,446,744,073,709,551,615
signed char             1                   -128            to 127
unsigned char           1                   0               to 255
float                   4                   In general, 7 decimal digits precision
double                  8                   In general, 15 decimal digits precision
long double             12
wchar_t                 2 or 4              1 wide character

sizeof(int)   =4
sizeof(long)  =8

// ________________________________________________________________________________________________
// ##### casting ##################################################################################

// Pointer casting 
int* int_ptr= nullptr;
double* double_ptr = nullptr;
double_ptr = int_ptr;           // should be allowed tbc
int_ptr = double_ptr;           // !!! compile error
void* void_ptr = nullptr;
void_ptr = int_ptr;             // allowed

// ________________________________________________________________________________________________
// ##### cin ######################################################################################
#include <iostream>
using namespace std;

cin >> input;
getline (cin, inputLine);       // get entire line
cin >> name >> ag               // get multiple inputs separated by " "
cin.get(input, size);           // read up to size-1 chars (-1 because last char null)
cin >> setw(size) >> input      // max input lengh = size-1

// more: https://www.geeksforgeeks.org/cin-in-c/


// ________________________________________________________________________________________________
// ##### cout: stream operators ###################################################################
#include <iostream>
#include <iomanip>
using namespace std;

cout << endl << "\n";
cout << "\t";
cout << std::left           // changes to left aligned
cout << 

// sticky stream operators
std::cout << std::hex << num;
std::cout << std::oct << num;
std::cout << std::dec << num;
std::cout << std::fixed << num;
std::cout << std::setPrecision(digits);

// non-sticky stream operators (= only relates on the next output)
std::cout << std::setw(width) << outputWithWidth;

// more: https://en.cppreference.com/w/cpp/io/manip

// ________________________________________________________________________________________________
// ##### Reference ################################################################################
// Only in C++

int x;
int &ref_x;         // !!! not allowed - reference needs to be initializied
int &ref_x = x;     // creates and initializieses reference with adress of variable
int& ref_x = x;     // same


// ________________________________________________________________________________________________
// ##### Pointer ##################################################################################
// The value of a pointer is the memory location of the referenced variable
// pointers can be declared to point to objects of any data type

int y = 42;			// variable declaration
int* y_ptr;			// pointer declaration
int *y_ptr;			// pointer declaration - same
int* y_ptr = &y;	// shorter
y_ptr = &y; 		// referencing - assign address of variable to ptr
cout << *y_ptr		// 42 - dereferencing pointer (get value of variable)
cout << y_ptr		// 0xffffcbdc - (get adress of variable)
cout << &y_ptr		// 0xffffcbd0 - (get adress of ptr)

// Pointer Arithmetic
char v[5] = {a,b,c,d,e};
char *v_ptr = &v[0];

cout << *v_ptr 		// ouputs 'a'
cout << *v_ptr +2	// ouputs 'c' - Increasing the pointer by + 1 increases the memory address by 2 = sizeof(char)

// Pointer and Arrays
// an array name (b) can be thought of as a constant pointer
char b[5]; => b (without subscribt) is a (constant) pointer to the first elememt of the array b

int b[5] =  {5,6,7,8,9}
int* b_ptr;
b_ptr = b;      // assign adress of array to ptr (=> b (without subscribt) is a (constant) pointer to the first elememt of the array b)
b_ptr = &b[0];  // same

cout << &b[3];          // access adress (e.g. 0xffffcbdc) of array element index 3
cout << b_ptr +3;       // same (e.g. 0xffffcbdc)
cout << b[3];           // access array element
cout << b_ptr[3];       // same - access value of array element
cout << *(b_ptr +3);    // same - () must be used because of precedence

// Examples (console output):
Print b: c-array == ptr => without subscribt [], its the adress of the array
b     = 0x7ffd871870c0
b_ptr = 0x7ffd871870c0

Array subsript notation:
b[0] = 5
b[1] = 6

Pointer subsript notation:
b_ptr[0] = 5
b_ptr[1] = 6

Array name offset notation:
*(b + 0) = 5
*(b + 1) = 6

Pointer offset notation:
*(b_ptr + 0) = 5
*(b_ptr + 1) = 6

// const with pointers
char* c_ptr1 = nullptr;             // nonconstant ptr to nonconstant data
                                    // - data can be changed
                                    // - pointer can be changed (reseated) to another data

const char* c_ptr2 = "*";           // nonconstant ptr to constant data
                                    // - data can not be changed using this ptr
                                    // - pointer can be reseated

char* const c_ptr3 = text2;         // constant ptr to non-const data
                                    // - pointer always points on the same mamory location and can not be reseated
                                    // - data can be changed via ptr
                                    // - must be initializied during declaration
                                    // - conceptually very similar to reference

const char* const c_ptr4 = text2;   // constant ptr and constant data
                                    // - ptr always points the same mamory location
                                    // - data cannot be changed using this ptr

// pointer arrays
// - each element cities points to char* (C-String)
// - the C-array has a fixed size (3 ptrs with each 8 bytes each), but the C-strings could have arbitary length 
const char* cities[3] = {"London", "Buenos Aires", "Tokio"};
for (int i = 0; i < 3; i++){
    cout << cities[i] << ", ";      // OUTPUT: London, Buenos Aires, Tokio
}


// ________________________________________________________________________________________________
// ##### C-Strings ################################################################################
c-string = array of chars
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

// ________________________________________________________________________________________________
// ##### Vectors ##################################################################################
// + dynamic array size
// + no need to know size of array when initializing
// - resizing costs time
// - less efficient than C-arrays

#include<vector>

std:: vector<type> vec;				// declares a vector as empty vector
std:: vector<type> vec (n);			// declares a vector with n elements
std:: vector<type> vec (n, val);	// all n elements initialized with val

vec[n]; 							// get value of vector with index n
vec.at(n);							// vec[n] but with range check
vec = vector2;						// copy vector
vec.size();							// get array size
vec.capacity();						// get number of elements of vec pondon:"sizeof();"
vec.reserved();						// reserves minimum amount of mememory for n elements
vec.push_back(val);					// adds val to end of vec
vec.pop_back();						// removes last element of vec
vec.front();						// get first value of vec
vec.back();							// get last value of vec
vec.begin();						// get interator to first element (similar to pointer)
vec.end();							// get interator to last element (similar to pointer)
vec.erase(n);						// removes element n from vec
vec.insert(n, val);					// insert element with val
vec.clear();						// removes all element of vec

// ________________________________________________________________________________________________
// ##### Functions ################################################################################
// call by value / pass by value

// call by reference / pass by reference
void swap(int& i1_ref, int& i2_ref){
    int temp = i1_ref;
    i1_ref = i2_ref;
    i2_ref = temp;
}

// call by adress / pass by adress
void swap(int* i1_ptr, int* i2_ptr){
    // !!! check for nullprt: dereferencing a nullptr leads to crash
    if (i1_ptr == nullptr || i2_ptr == nullptr){
        std::cout << "Error: pointer is a nullptr!";
        return;
    }
    int temp = *i1_ptr;
    *i1_ptr = *i2_ptr;
    *i2_ptr = temp; 
}

// ________________________________________________________________________________________________
// ##### Command line arguments ###################################################################
// cmd => test.exe argument 5
int main(int argc, char **argv){
    cout << argc;           // OUTPUT: 2 (= int that holds the number of arguments (at least 1 because prgram name couts as well))
    cout << argv;           // OUTPUT: ptr adress - argv = C-array of char*
    cout << argv[0];        // "test.exe" => program name
    cout << argv[1];        // "argument" => first arg
    cout << argv[2];        // "5" => arg number as C-string - needs to be converted => see C-strings
    cout << argv[argc-1];   // last arg
}
