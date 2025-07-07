// ##### Data types ###############################################################################
Data Type               Size (in bytes)     Range
signed char             1                  -128            to 127
unsigned char           1                   0               to 255
short int               2                  -32,768         to 32,767
unsigned short int      2                   0               to 65,535
unsigned int            4                   0               to 4,294,967,295
int                     4                  -2,147,483,648  to 2,147,483,647
long int                4                  -2,147,483,648  to 2,147,483,647
unsigned long int       4                   0               to 4,294,967,295
long long int           8                  -(2^63)         to (2^63)-1
unsigned long long int  8                   0               to 18,446,744,073,709,551,615
float                   4                   In general, 7 decimal digits precision
double                  8                   In general, 15 decimal digits precision
long double             12
wchar_t                 2 or 4              1 wide character

sizeof(int)   = 4
sizeof(long)  = 8

// static, const and extern variables
static int value = 7;      // this global declared variable is only known in the exact same file (like private)

void function(){
  static int remain = 5;   // static flag in functions case a local variable to remain it's value even if the function is done (lifetime: program run time)
}

const int valueB = 3;      // const values can't be changed
extern int notHere;        // external declared variables can be used but are not declared inside that file
// ________________________________________________________________________________________________
// ##### casting ##################################################################################
// C style
int a_int = 10;
double a_double = a_int;       // implicit casting - argument promotion (no info gets lost)

double b_double = 5.3;
int b_int = b_double;          // also implicit casting - argument coercion (info - dec digits - gets lost)
int b_int = (int)b_double      // explicit conversion / explicit casting - argument coercion

// C++ style
double c_double = static_cast<int>(a_int)  // benefit: you can search for cast in code
// more cast mathods available 

// Pointer casting 
int* int_ptr = nullptr;
double* double_ptr = nullptr;
double_ptr = int_ptr;           // should be allowed tbc
int_ptr = double_ptr;           // !!! compile error
