// ************************************** std::sort <algorithm> **************************************
#include <algorithm>  // for std::sort
int main(){ 
  int v[10] = {5, 6, 3, 2, 8, 7, 9, 0, 10, -4};
  sort(begin(v), end(v));              // STD FUNCTION sorts elements in ascending order using the OPERATOR < !!!
  for (int item : v) { cout << ... }   // => -4 0 2 3 5 6 7 8 9 10
};

// **************************************** commen std lip templates ****************************************
#include <utility>   // std::pair
#include <stack>     // std::stack
#include <vector>    // std:vector
#include <unordered_map>  // std::unordered_map
#inlcude <map>       // std::map

// ************************************** template example Pair  **************************************
template <class T, class E> class Pair {  // template class Pair
  private:
      T first_;
      E second_;
  public:
      Pair(const T, const E);
      T getFirst();
      E getSecond();
 };

// class Pair definded of template class Pair
template<class T,class E> Pair<T,E>::Pair(const T first, const E second): first_(first), second_(second) { }
template<class T,class E> T Pair<T,E>::getFirst() {    // member functions from template outside of class body
  return first_;
}
template<class T,class E> E Pair<T,E>::getSecond() {   // member functions from template outside of class body
  return second_;
}

int main() {
  Pair<Person, Person> pair1 { Person(„The Bride",28), Person(„The Man",25) };    // define pair1 as object Pair
  Pair<Person, int> pair2 { Person("Pope Francis",84), 10};                       // define pair2
 
  cout << "Pair1: "<< pair1.getFirst() <<" <-> " << pair1.getSecond() << endl;
  cout << "Pair2: "<< pair2.getFirst() 
