/*============================================================
Name        : dataBase.cpp
Author      : marci98p
Version     : 1.1.1
Last edit:  : 15.01.2025
Copyright   : 
Description : C++ nodes
=============================================================*/
#include "header.h"
#pragma once
// ________________________________________________________________________________________________
// ##### Data types ###############################################################################
Data Type               Size (in bytes)     Range
signed char             1                   -128            to 127
unsigned char           1                   0               to 255
short int               2                   -32,768         to 32,767
unsigned short int      2                   0               to 65,535
unsigned int            4                   0               to 4,294,967,295
int                     4                   -2,147,483,648  to 2,147,483,647
long int                4                   -2,147,483,648  to 2,147,483,647
unsigned long int       4                   0               to 4,294,967,295
long long int           8                   -(2^63)         to (2^63)-1
unsigned long long int  8                   0               to 18,446,744,073,709,551,615
float                   4                   In general, 7 decimal digits precision
double                  8                   In general, 15 decimal digits precision
long double             12
wchar_t                 2 or 4              1 wide character

sizeof(int)   = 4
sizeof(long)  = 8

// static, const and extern variables
static int value = 7;      // this global declared variable ist only known in the exact same file (like private)

void function(){
  static int remain = 5;   // static flag in functions case a local variable to remain it's value even if the function is done (lifetime: program run time)
}

const int valueB = 3;      // const values can't be changed
extern int notHere;        // external declared variables can be used but are not declared inside that file
// ________________________________________________________________________________________________
// ##### casting ##################################################################################
// C style
int a_int = 1;
double a_double = a_int;       // implicit casting - argument promotion (no info gets lost)

double b_double = 5.3;
int b_int = b_double;          // also implicit casting - argument coercion (info - dec digits - gets lost)
int b_int = (int)b_double      // explicit conversion / explicit casting - argument coercion

// C++ style
int c_int = 10;
double c_double = static_cast<int>(c_int)  // benefit: you can search for cast in code
// more cast mathods available 

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

// ________________________________________________________________________________________________
// ##### cout: stream operators ###################################################################
#include <iostream>
#include <iomanip>
using namespace std;

cout << endl << "\n";
cout << "\t";
cout << std::left           // changes to left aligned

// sticky stream operators
std::cout << std::hex << num;
std::cout << std::oct << num;
std::cout << std::dec << num;
std::cout << std::fixed << num;
std::cout << std::setprecision(digits);
// non-sticky stream operators (= only relates on the next output)
std::cout << std::setw(width) << outputWithWidth;
std::cout << std::left
std::cout << std::right
// more: https://en.cppreference.com/w/cpp/io/manip

// example to output a string by comparring with ints
cout << ((i % 8 > 0) ? "-" : to_string(i / 8))

// ASCII table
https://alpharithms.s3.amazonaws.com/assets/img/ascii-chart/ascii-table-alpharithms-scaled.jpg

// ________________________________________________________________________________________________
// ##### Arrays ###################################################################################
int n[];
int n[arraySize];
int n[] = {0,1,2,3,4,5 };
int n[10] = {0,1,2,3,4,5};

int arraySize = sizeof(array) / sizeof(usedArrayType);   // to get the size of array => devide by sizeof( used array type);

int arrayA = {0,1,2,3,4,5};
int arrayB = arrayA;    // !!! C-arrays cannot be assigned and cannot be used to init
// ________________________________________________________________________________________________
// ##### Reference ################################################################################
// Only in C++
int x = 3;
int &x_ref;         // !!! not allowed - reference needs to be initializied
int &x_ref = x;     // creates and initializieses reference with adress of variable
int& x_ref = x;     // same

// example
cout << "x = " << x << endl;        // x = 3
cout << "x_ref= "<< x_ref<< endl;   // x_ref = 3
x_ref= 7; 
cout << "x = " << x << endl;        // x = 7
cout << "x_ref= "<< x_ref<< endl;   // x_ref = 7

// function - call by reference (fuction declaration)
void function(int &ref_y);
void function(int& ref_y);    // same
void function(int & ref_y);   // same
void function(int&ref_y);     // same
// useage
void function(int& ref_y){
  cout << ref_y;        // value not mamory adress
  cout << &ref_y;       // 0x7ffcb0935854  
}

// arrays as argument
void function(int array[], int arraySize){    // arrays are always given by reference not by value
  int size = sizeof(array[])                  // !!! does not work for arrays as argument in functions => allways return 8
  cout << array;                              // returns mamory adress

  for (int i = 0; i < arraySize; i++){}       // need to have a second parameter int arraySize
    cout << array[i];                         // returns value at index i
}

// ________________________________________________________________________________________________
// ##### Pointer ##################################################################################
// The value of a pointer is the memory location of the referenced variable
// pointers can be declared to point to objects of any data type

int y = 42;			  // variable declaration
int* y_ptr;			  // pointer declaration
int *y_ptr;			  // pointer declaration - same
int* y_ptr = &y;	// shorter
y_ptr = &y; 		  // referencing - assign address of variable to ptr
cout << *y_ptr		// 42 - dereferencing pointer (get value of variable)
cout << y_ptr		  // 0xffffcbdc - (get adress of variable)
cout << &y_ptr		// 0xffffcbd0 - (get adress of ptr)
*y_ptr = 4;       // write value of ptr-adress

// Pointer Arithmetic
char v[5] = {a,b,c,d,e};
char *v_ptr = &v[0];

cout << *v_ptr 		  // ouputs 'a'
cout << *v_ptr +2	  // ouputs 'c' - Increasing the pointer by + 1 increases the memory address by 2 = sizeof(char)

// Pointer and Arrays
// an array name (b) can be thought of as a constant pointer
char b[5]; => b (without subscribt) is a (constant) pointer to the first elememt of the array b

int b[5] =  {5,6,7,8,9}
int* b_ptr;
b_ptr = b;      // assign adress of array to ptr (=> b (without subscribt) is a (constant) pointer to the first elememt of the array b)
b_ptr = &b[0];  // same
*b_ptr = 4;     // write value of ptr-adress

cout << &b[3];          // access adress (e.g. 0xffffcbdc) of array element index 3
cout << b_ptr +3;       // same (e.g. 0xffffcbdc)
cout << b[3];           // access array element
cout << b_ptr[3];       // same - access value of array element
cout << *(b_ptr +3);    // same - () must be used because of precedence
cout << (*b_ptr)++      // increase value behind ptr

// Examples (console output):
console: Print b: c-array == ptr => without subscribt [], its the adress of the array
console: b     = 0x7ffd871870c0
console: b_ptr = 0x7ffd871870c0

console: Array subsript notation:
console: b[0] = 5
console: b[1] = 6

console: Pointer subsript notation:
console: b_ptr[0] = 5
console: b_ptr[1] = 6

console: Array name offset notation:
console: *(b + 0) = 5
console: *(b + 1) = 6

console: Pointer offset notation:
console: *(b_ptr + 0) = 5
console: *(b_ptr + 1) = 6

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

// ________________________________________________________________________________________________
// ##### Vectors ##################################################################################
// + dynamic array size
// + no need to know size of array when initializing
// - resizing costs time
// - less efficient than C-arrays

#include<vector>

std:: vector<type> vec;				    // declares a vector as empty vector
std:: vector<type> vec (n);			  // declares a vector with n elements
std:: vector<type> vec (n, val);	// all n elements initialized with val

vec[n];                  // get value of vector with index n
vec.at(n);               // vec[n] but with range check
vec = vector2;           // copy vector
vec.size();              // get array size
vec.capacity();          // get number of elements of vec pondon:"sizeof();"
vec.reserved();          // reserves minimum amount of mememory for n elements
vec.push_back(val);      // adds val to end of vec
vec.pop_back();          // removes last element of vec
vec.front();             // get first value of vec
vec.back();              // get last value of vec
vec.begin();             // get interator to first element (similar to pointer)
vec.end();               // get interator to last element (similar to pointer)
vec.erase(n);            // removes element with iterator n from vec
vec.insert(n, val);      // insert element with val at iterator n
vec.clear();             // removes all element of vec

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
// ________________________________________________________________________________________________
// ##### random seed rand srand ###################################################################
#include <cstdlib>          // contains srand and rand
#include <ctime>
std::srand(std::time(0));  // set current time as seed
using namespace std;
cout << rand() % 6;         // random ints form 0 to 5
cout << rand() % 6 + 1;     // random ints form 1 to 6 - dice

// ________________________________________________________________________________________________
// ##### useful functions #########################################################################
// swap ints
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// sort int array
void bubbleSort(int arr[], int size) {
    int i, ii;
    for (i = 0; i < size-1; i++)
        for (ii = 0; ii < size-i-1; ii++)
            if (arr[ii] > arr[ii+1])
                swap(&arr[ii], &arr[ii+1]);
}



Recursion 
8.2 - Musterlösung
5.3

Pointer
8.1
ÜK 1 - Task 3

Vector
ÜK 1 - Task 3
