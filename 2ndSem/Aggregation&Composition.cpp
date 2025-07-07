// Composition (UML: solid diamond)
    // Composition forms an exclusive “has a" relationship (part of)
    // Complex objects usually consist of smaller and simple objects
    //  Car consists of tires, engine, seats, ...
    //  In C++ typically realized as an attribute (non-pointer)
class Person {
  string first_name_;
  string last_name_;
  Date birthday_;       // composition (automatic allocation)
 public:
 …
};

// Aggregation  (UML: unfilled diamond)
    // It represents not an inclusive “has a" relationship
    // Parts have an independent life cycle
    // Part members live on and are not destroyed when the aggregation is destroyed
    // Part members are also not automatically created when the aggregation is created
class Employee {
   string name_;
   double salary_;
   Employee* manager_;       // aggregation data meber is ptr (musst be deallocate manually)
 public:
   Employee(string name, double salary, Employee *manager);      // manager is ptr
 …
};


// Example Aggregation 
class Customer {
    const string firstName_;
    const string lastName_;
  public:
    Customer(string fn, string ln) : firstName_(fn), lastName_(ln) {};
    string getName() const;
};

class Bank {
    ~Bank();
    std::vector<const Customer*> clients_;
  public:
    void addClient(const Customer* client_ptr);
    const Customer* getClient(int i) const;
};
void Bank::addClient(const Customer* client_ptr) {
  clients_.push_back(client_ptr);
}
const Customer* Bank::getClient(int i) const {
  return client_[i];
}



// Stack and Heap
int main(){
  Employee deptManager("Hansi Baer", 6000, nullptr);      // on stack
  Employee deptWorker("Udo Bruno", 4200, &deptManager);   // on stack

  Employee* heapManager = new Employee("Hubsi Heap", 60000, nullptr);  // on heap - needs to be deallocate
  delete heapManager;    // deallocate

  // dynamic mamory allocation of arrays
  Date* date_ptr = new Date[10]; 
  Date** date_ptr = new Date*[10];
 …
};
