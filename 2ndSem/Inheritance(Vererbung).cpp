// Inheritance    UML: Arrow points from child to parent
// syntax:
class <nameOfChild> : public <nameOfParentClass>      // arg: public, private, protected - use public

// ************************************* example - reuse of constructor and memberfunc *************************************
class Basse {
    string name_;
    protected:         // sub-class can read
        int amount_;
    public:
        Resources(string n, int am) : name_(n), amount_(a) {};
        void print();
        bool consume(int num);
};

class Child : public Base {
  int regrowthrate_;
  public:
    Child(int a) : Base("Wood", a), regrowthrate_(2) {};      // reuse of constructor of Base-class
    void print();
    bool consume(int num); 
};

// cpp of Child
void Child::print() {
    Base::print();                                            // reuse of Base-Member-Function
    cout << ", RegrowthRate: " << regrowthrate_;
}
bool Child::consume(int num){
    amount_ += regrowthrate_; 
    return Base::consume(num);                                // reuse of Base-Member-Function
} 



// ************************************* example2 *************************************
// parent class: bankAccount      child class: savingsAccount
class BankAccount{                // parent class
   friend ostream& operator<<(ostream& out_ref, const BankAccount& acct_ref);
 private:
   int account_number_;
   float balance_;
 public:
   BankAccount(int account_number = 0, float balance = 0);
   void deposit(float amount) { balance_ += amount; }
   int getAccountNumber() const { return account_number_; }
   float getBalance() const { return balance_; }
   void setBalance(float balance) { balance_ = balance;  }
 };

// Child class
class SavingsAccount : public BankAccount { 
   friend ostream& operator<<(ostream& out_ref, const SavingsAccount& sav_acct_ref);
 private:
   float interest_rate_;
   // int account_number_; // no need to declare
   // float balance_;      // no need to declare
 public:
   SavingsAccount(int nr=0, float bal=0, float interest=0.035);
   void receiveInterestPayment();
   void withdrawMoney(float);
   // void deposit(float amount) { balance_ += amount; }
   // int getAccountNumber() const { return account_number_; }
   // float getBalance() const { return balance_; }
   // void setBalance(float balance) { balance_ = balance;  }
 };

// !!! The member functions getBalance() and setBalance() of the  base class BankAccount need to be called to access private data members from the derived class
 void SavingsAccount::receiveInterestPayment() {
   float balance = BankAccount::getBalance();
   balance += interest_rate_ * balance;
   BankAccount::setBalance(balance);
 }



// *************************************** Multiple Inheritance ***************************************
//      A      // parent class Person
//   B     C   // child classes Faculty and Student
//      D      // grandchild classe TA

class Person {   // parent class
  public:
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
    Person()     { cout << "Person::Person() called" << endl;   }
 };

// child class B
class Faculty : virtual public Person {      // virtual ensures, that TA inherits only once from Person
  public:
    Faculty(int x): Person(x)   { cout << "Faculty::Faculty(int ) called" << endl; }
 };

// child class C
class Student : virtual public Person {      // virtual ensures, that TA inherits only once from Person
  public:
    Student(int x): Person(x) { cout << "Student::Student(int ) called" << endl; }
 };

class TA : public Faculty, public Student  {   // grandchild class D
  public:
    TA(int x): Student(x), Faculty(x)   { cout << "TA::TA(int ) called" << endl; }
 };

 int main()  {
    TA David(30);
 }
// OUTPUT:
// Person::Person(int ) called
// Faculty::Faculty(int ) called
//  Student::Student(int ) called
//  TA::TA(int ) called
