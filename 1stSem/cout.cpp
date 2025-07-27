// ##### cout: stream operators ###################################################################
#include <iostream>
#include <iomanip>
using namespace std;

// non-sticky stream operators (= only relates on the next output)
cout << std::setw(width) << outputWithWidth;
cout << std::left      // left aligned
cout << std::right     // right aligned
cout << endl << "\n";  // new line (endl flushes stream)
cout << "\t";          // tab

// sticky stream operators
cout << std::hex << num;            // hex
cout << std::oct << num;            // oct
cout << std::dec << num;            // dec
cout << std::fixed << num;          // fixed
cout << std::setprecision(digits);  // precision

// more: https://en.cppreference.com/w/cpp/io/manip

// example to output a string by comparring with ints
cout << (true? "1" : to_string(false));
cout << ((i % 8 > 0) ? "-" : to_string(i / 8))

// ASCII table
https://alpharithms.s3.amazonaws.com/assets/img/ascii-chart/ascii-table-alpharithms-scaled.jpg
