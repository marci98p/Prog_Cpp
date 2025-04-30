
// safe data to heap
Employee* departmentManager1 = new Employee("Michael Mouse", 60000, nullptr);        // wiht new
// must be deleted after use
delete departmentManger1;        // Caling delete on a pointer to an object runs the destructor!


// this pointer - example
class Test {
  public:
    int x = 12;
    void print();
 };
 void Test::print() {
  cout << "x         =" << x          << endl;        // option 1
  cout << "(*this).x =" << (*this).x  << endl;        // option 2
  cout << "this->x   =" << this->x    << endl;        // option 3



// ************************** 30.04.******************************

// new & delete
 int main() {
   Employee* manager = new Employee("Michael Mouse", 60000, nullptr);    // allocate a new employee; new returns ptr ! therefore employee must be a ptr adress
   … 
  // deallocate the Employee
   delete manager;
   // the pointer still points to the memory address
   Employee worker("Dorith Duck", 40000, manager);
   
   return 0;
   //pointer manager automatically deallocated at end of main function
 }

// this ptr
// returs the ptr-adrs of current object

// *this returns current object
class Calc {
 public:
    Calc() { value_ = 0; }
    Calc& addValue(int value);
    Calc& subValue(int value);
    Calc& multValue(int value);
    int getValue() { return value_; }
 private:
    int value_;
 };

Calc& Calc::addValue(int value)  {
   value_ += value;
   return *this;
 }
 Calc& Calc::subValue(int value) {
   value_ -= value;
   return *this;
 }
 Calc& Calc::multValue(int value) {
   value_ *= value;
   return *this;
 }
// to do something like this => member function chain
calc.addValue(5).subValue(3).getValue()


// ************************  friend ************************** 
//can access public and private data of class
 class Count {
  friend void setX( Count& c_ref, int val ); // friend declaration
  private:
    int x_; // data member
  public:

 };  

