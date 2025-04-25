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
    Time();                                                             // default constructor
    Time(int hh = 0, int mm = 0, int ss = 0) {}                         // user defined default constructor
    Time() {setTime(0,0,0)}                                             // same with member function
    Time() : hour_(0), min_(0), sec_(0) {}                              // same with init list - tbt: init lists are able to change const member variables 

    // user defined constructors - declaration and definition 
    Time(int hh) : Time() { hour_ = hh; }                               // constructor delegation and init list (init lists must be used for classes inside classes)
    Time(int hh, int mm) : Time() { hour_ = hh; min_ = mm; }            // constructor delegation and init list
    Time(int hh, int mm, int ss) : hour_(hh), min_(mm), sec_(ss) {}     // constructor only  w/ init list

    // deconstructor (must be public)        // release amnually allocated momory, delete objects created with new, release system resources, close network connections
    ~Time();

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


// Validating Member-data with member functions:
Validation::Validation( string toProof ) { // default constructor      
    setSomething(toProof);               // calls set function   
 } 

void Lecture::setSomething( string tbp ) {     // set function to always have valid member data - can be used with constructor or standalone
   if ( tbp.size() <= 25 ) something_ = tbp;
   if ( tbp.size() > 25 )
   {
      // fall back: set something_ to first 25 characters
      something_ = tbp.substr(0,25); 
      cerr << "Input exceeds maximum length => cut to 25 characters " << endl;
   }
 } 

// Using Pointers to a Class
 class Employee {
 private:
   string name_;
   double salary_;
   Employee *manager_;        // Aggregation

 public:
   Employee();
   Employee(string name, double salary, Employee *manager);      // manager is ptr
   string getName() const;
   Employee* getManager() const;
   double getSalary() const;
 };


 Employee::Employee(): salary_(0), manager_(nullptr) {}
 Employee::Employee(string name, double salary, Employee* manager): name_(name), salary_(salary), manager_(manager) {}

 Employee* Employee::getManager() const{
   return manager_;
 }

cout << "Manager: " << dept1Person1.getManager()->getName() << endl;            // getName of pointer
cout << "Manager: " << (*dept1Person1.getManager()).getName() << endl;          // same


// ########################################## struct ##########################################
// in C structs were present before classes existed
// in C++ is a struct a class but member are public by default
  
