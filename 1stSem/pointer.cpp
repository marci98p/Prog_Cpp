// ##### Pointer ##################################################################################
int y = 42;			  // variable declaration
int* y_ptr;			  // pointer declaration
y_ptr = &y; 		  // referencing - assign address of variable to ptr
int* y_ptr = &y;	// shorter

*y_ptr = 4;       // change ptr value

cout << *y_ptr;		// 42 - dereferencing pointer (get value of variable)
cout << y_ptr;	  // 0xffffcbdc - (get adress of variable)
cout << &y_ptr;		// 0xffffcbd0 - (get adress of ptr)


// ****************************** Pointer and Arrays ******************************
int* ptr_adr, ptr_val;
int b[4] = {2, 3, 4, 5};
ptr_adr = b;        // ptr to adress
ptr_val = b[0];     // ptr to value

// int array
int* int_ptr;
int array[4] = {4, 6, 7, 9};
int_ptr = array;
cout  << int_ptr << endl      // OUTPUT: adress
      << *int_ptr << endl     // OUTPUT: 4
      << int_ptr[0] << endl   // OUTPUT: 4
      << *(int_ptr+1) << endl;// OUTPUT: 6 

// char array (C-String)  
char* ch_ptr;
char array[4] = {'a', 'b', 'c'}; // = "abc\0"
ch_ptr = array;
cout  << ch_ptr << endl        // OUTPUT: abc (special case char array (= C-String))
      << *ch_ptr << endl       // OUTPUT: a
      << ch_ptr[0] << endl     // OUTPUT: a
      << *(ch_ptr+1) << endl;  // OUTPUT: b
  
// special case C-Strings
    int i[5] = {1, 4, 2, 8};
    int* i_ptr = &i[0];    // ptr to first value
    cout << i[3];          // access array element: 8
    cout << *i_ptr;	   // OUTPUT: 1
    cout << *(i_ptr+2);	   // OUTPUT 2
    cout << i_ptr[3];      // OUTPUT: 8
    cout << &i_ptr[3];     // OUTPUT 0x7ffd537cf90c
    cout << i_ptr +3;      // OUTPUT 0x7ffd537cf90c
    cout << *(i_ptr +3);   // OUTPUT 8
    cout << ++(*i_ptr);    // OUTPUt 2
    
    char v[5] = {'a', 'b', 'c', 'd'};
    char* v_ptr = &v[0];    // ptr to first value
    cout << v[3];           // access array element: d
    cout << *v_ptr;	    // OUTPUT: a
    cout << *(v_ptr+2);	    // OUTPUT c
    cout << v_ptr[3];       // OUTPUT: d
    cout << &v_ptr[3];      // OUTPUT d (special case bcs of char (C-String))
    cout << v_ptr +3;       // OUTPUT d (special case bcs of char (C-String))
    cout << *(v_ptr +3);    // OUTPUT d
    cout << ++(*v_ptr);     // OUTPUt b

// ****************************** Pointer Arithmetic ******************************
char a[5] = {'a','z','g','t'};
char* a_ptr = &a[0];
cout << *a_ptr ;	       // OUTPUT: a
cout << *(a_ptr + 2);    // OUTPUT: g - Increasing the pointer by + 1 increases the memory address by 2 = sizeof(char)
cout << *( ++a_ptr );    // OUTPUT: z


// ****************************** const with pointers ******************************
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
