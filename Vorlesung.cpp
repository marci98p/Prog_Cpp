// Using Pointers to a Class
 class Employee {
 private:
   string name_;
   double salary_;
   Employee *manager_;

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


// 14.04.25 - Classes and Pointer
cout << "Name: " << dept1Person1.getName() << endl;
cout << "Salary: " << dept1Person1.getSalary() << endl;
cout << "Manager: " << dept1Person1.getManager()->getName() << endl << endl;            // getName of pointer
cout << "Name: " << dept2Person1.getName() << endl;
cout << "Salary: " << dept2Person1.getSalary() << endl;
cout << "Manager: " << (*dept2Person1.getManager()).getName() << endl;                  // same

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
