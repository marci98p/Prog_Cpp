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

