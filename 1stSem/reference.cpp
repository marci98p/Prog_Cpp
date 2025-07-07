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
