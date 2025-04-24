
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
