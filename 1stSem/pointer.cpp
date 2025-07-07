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
