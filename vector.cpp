// ##### Vectors ##################################################################################
// + dynamic array size
// + no need to know size of array when initializing
// - resizing costs time
// - less efficient than C-arrays

#include<vector>

std:: vector<type> vec;				    // declares a vector as empty vector
std:: vector<type> vec (n);			  // declares a vector with n elements
std:: vector<type> vec (n, val);	// all n elements initialized with val

vec[n];                        // get value of vector with index n
vec.at(n);                     // vec[n] but with range check
vec = vector2;                 // copy vector
vec.size();                    // get array size
vec.push_back(val);            // adds val to end of vec
vec.begin();                   // get interator to first element (similar to pointer)
vec.insert(vec.begin(), val);  // insert item on first place
vec.insert(n, val);            // insert element with val at iterator n
vec.capacity();                // get number of elements of vec pondon:"sizeof();"
vec.reserved();                // reserves minimum amount of mememory for n elements
vec.pop_back();                // removes last element of vec
vec.front();                   // get first value of vec
vec.back();                    // get last value of vec
vec.end();                     // get interator to last element (similar to pointer)
vec.erase(n);                  // removes element with iterator n from vec
vec.clear();                   // removes all element of vec

for (const auto& item : vec){
  // loop throw each item
  // be careful! use auto* to edit class member (because item is a copy instead)
}
