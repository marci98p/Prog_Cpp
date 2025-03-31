// ########################################## classes ##########################################
// ------------------------------------------- Header ------------------------------------------
#pragma once
//import std;
#include <iostream>
#include <iomanip>

class Time{
  int hour_;
  int min_;
  int sec_;

  public:
    // default constructors
    Time(){}                                                            // default constructor
    Time(int hh = 0, int mm = 0, int ss = 0) {}                         // user defined default constructor
    Time() {setTime(0,0,0)}                                             // same with member function
    Time() : hour_(0), min_(0), sec_(0) {}                              // same with init list

    // user defined constructors - declaration and definition 
    Time(int hh) : Time() { hour_ = hh; }                               // constructor delegation and init list (init lists must be used for classes inside classes)
    Time(int hh, int mm) : Time() { hour_ = hh; min_ = mm; }            // constructor delegation and init list
    Time(int hh, int mm, int ss) : hour_(hh), min_(mm), sec_(ss) {}     // constructor only  w/ init list

    // deconstructor (must be public)        // release amnually allocated momory, delete objects created with new, release system resources, close network connections
    ~Time()

    // member function declaration
    void setTime(int hh, int mm, int ss);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    Time getTime() const;    
    void printTime() const;
};

// ------------------------------------------- class.cpp ------------------------------------------
#include "time.h"
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

// member functions
void Time::setTime(int hh, int mm, int ss){
    hour_ = hh;
    min_ = mm;
    sec_ = ss;
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
int Time::getSecond() const{
    return sec_;
}
void Time::printTime() const {
    cout << setfill('0') << setw(2) << hour_ << ":" << setw(2) << min_ << ":" << setw(2) << sec_ << endl;
}


// ########################################## struct ##########################################
// in C structs were present before classes existed
// in C++ is a struct a class but member are public by default
  
