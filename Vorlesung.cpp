// 07.04.25 - Aggregation and Composition
// Validating Member-data with member functions:

Lecture::Lecture( string name ) { // default constructor      
    setCourseName(name);          // calls set function   
 } 

void Lecture::setCourseName( string name ) {     // set function to always have valid member data - can be used with constructor or standalone
   if ( name.size() <= 25 )      
  courseName_ = name;
   if ( name.size() > 25 )
   {
       // set courseName_ to first 25 characters
   courseName_ = name.substr(0,25); 
      cerr << "course name exceeds maximum length " << endl;
   }
 } 


// Using Pointers to a Class
 class Employee {
 public:
   Employee();
   Employee(string name, double salary);
   Employee(string name, double salary, Employee *manager);      // manager is ptr
   string getName() const;
 Employee* getManager() const;
   double getSalary() const;
 private:
   string name_;
   double salary_;
   Employee *manager_;
 };


 Employee::Employee(): salary_(0), manager_(nullptr) {
 }
 Employee::Employee(string name, double salary, Employee* 
manager)
 : name_(name), salary_(salary), manager_(manager) { }
 double Employee::getSalary() const{
   return salary_;
 }
 string Employee::getName() const{
   return name_;
 }
 Employee* Employee::getManager() const{
   return manager_;
 }
