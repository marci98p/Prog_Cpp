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
    // constructor declaration and definition 
    Time() : hour_(0), min_(0), sec_(0) {}                              // default constructor
    Time(int hh) : Time() { hour_ = hh; }                               // constructor delegation and init list
    Time(int hh, int mm) : Time() { hour_ = hh; min_ = mm; }            // constructor delegation and init list
    Time(int hh, int mm, int ss) : hour_(hh), min_(mm), sec_(ss) {}     // constructor only  w/ init list
    
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
    

  
