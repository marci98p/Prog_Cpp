// Polymorphismus bedeutet wörtlich „Vielgestaltigkeit“.
// In C++ heißt das: Du kannst über einen Zeiger oder eine Referenz der Basisklasse Objekte von abgeleiteten Klassen ansprechen
// und dabei werden die korrekten Methoden der abgeleiteten Klasse aufgerufen.
// Ohne Polymorphismus ruft C++ die Methode der Klasse auf, von der der Zeigertyp stammt — selbst wenn das Objekt eigentlich von einer Unterklasse ist.

virtual   // declare functions in parent class with virtual

// Example
class Animal {
public:
    virtual ~Animal();               // destructor needs to be virual as well 
    virtual void speak() const {
        std::cout << "Animal sound\n";
    }
};

class Dog : public Animal {          // Inheritance
public:
    ~Dog();                  
    void speak() const override {    // override: compiler comand to override parent memberfunction
        std::cout << "Woof!\n";
    }
};

int main(){
  Animal* a = new Dog(); 
  a->speak();  // because of `virtual`  ➜  Dog::speak()

  delete a;       // if virtual ~Animal(); ain't virual ➜  ~Animal() would be called
}

