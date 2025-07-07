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
