class <nameOfChild> : public <nameOfParentClass>      // arg: public, private, protected - use public

// ************************************* example ************** parent class: bankAccount, child class savingsAccount
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

 class SavingsAccount : public BankAccount {    // child class
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
