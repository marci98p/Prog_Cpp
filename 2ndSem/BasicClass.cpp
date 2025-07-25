// ########################################## classes ##########################################
// ------------------------------------------- Header ------------------------------------------
#pragma once

class Time{
  int hour_;
  const int min_;    // can not be modified once initilized

  public:
    Time(int hh = 0, int mm = 0) {}                            // parametized constructor
        // implicitly creates signitures:
        Time();                                                // default constructor
        Time(int hh);
        Time(int hh, int mm);
    Time() {setTime(0,0)}                                      // same with member function
    Time() : hour_(0), min_(0) {}                              // init list - prefered because no default const is used

    // user defined constructors - declaration and definition 
    Time(int hh) : Time() { hour_ = hh; }                       // constructor delegation and init list (init lists must be used for classes inside classes)
    Time(int hh, int mm) : Time() { hour_ = hh; min_ = mm; }    // constructor delegation and init list

    ~Time();  // destructor (must be public)  - release amnually allocated momory, delete objects created with new, release system resources, close network connections

    // member function declaration
    void setTime(int hh, int mm);
    int getHour() const;
    int getMinute() const;
    Time getTime() const;    
    void printTime() const;
};

// ------------------------------------------- class.cpp ------------------------------------------
#include "time.h"
#include <iostream>
#include <iomanip>
using namespace std;

// member functions
void Time::setTime(int hh, int mm){
    hour_ = hh;
    min_ = mm;
}
Time Time::getTime() const {
    return *this;                // return dereferenced ptr
}
int Time::getHour() const{
    return hour_;
}
int Time::getMinute() const{
    return min_;
}
void Time::printTime() const {
    cout << setfill('0') << setw(2) << hour_ << ":" << setw(2) << min_ << endl;
}
