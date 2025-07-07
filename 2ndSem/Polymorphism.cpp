// Polymorphismus bedeutet wörtlich „Vielgestaltigkeit“.
// In C++ heißt das: Du kannst über einen Zeiger oder eine Referenz der Basisklasse Objekte von abgeleiteten Klassen ansprechen
// und dabei werden die korrekten Methoden der abgeleiteten Klasse aufgerufen.
// Ohne Polymorphismus ruft C++ die Methode der Klasse auf, von der der Zeigertyp stammt — selbst wenn das Objekt eigentlich von einer Unterklasse ist.

virtual   // declare functions in parent class with virtual

// Example
class Animal {
public:
    virtual ~Animal();               // destructor needs to be virual as well 
    virtual void speak();            // virtual function declaration 
};
void Animal::speak() {               // function definition - no virtual needed
    td::cout << "Animal sound\n";
}

class Dog : public Animal {          // Inheritance
public:
    ~Dog();                  
    void speak() override;           // override: compiler comand to override parent memberfunction
};
void Dog::speak() override {    // override: compiler comand to override parent memberfunction
    std::cout << "Woof!\n";
}

int main() {
    Dog doggo;
    Animal& animal_ref = doggo;    // doggo as animal&
    animal_ref.makeSound();        // ➜  Dog::speak()       if speak() ain't virtual ➜  Animal::speak();
    
    Dog& dog_ref = doggo;          // doggo as dog&
    dog_ref.makeSound();           // ➜  Dog::speak()
 }

// static cast => see below
int main(){
    Dog doggo;
    Animal& animal_ref = doggo;
    Dog& dog_ref = static_cast<Dog&> (animal_ref);
    dog_ref.makeSound();            // ➜  Dog::speak()
 }
// dangerous cast (animal is no dog)
int main(){
    Animal doggo;                    // here's the difference
    Animal& animal_ref = doggo;
    Dog& dog_ref = static_cast<Dog&> (animal_ref);
    dog_ref.makeSound();            // ➜  Animal::speak()
 }


// Example with ptr
int main(){
    Animal* a = new Dog;       // same tbt
    Animal* a = new Dog();     // same tbt

    a->speak();     // because of `virtual`  ➜  Dog::speak()
    delete a;       // if virtual ~Animal(); ain't virual ➜  ~Animal() would be called
}


// *************************** Pure virtual ➜ Abstract Class ***************************
class Animal {
public:
    virtual ~Animal();               // destructor needs to be virual as well 
    virtual void speak() = 0;        // add = 0 ➜ function definition removed! 
};

class Dog : public Animal {          // Inheritance
public:
    ~Dog();                  
    void speak() override;           // override: compiler comand to override parent memberfunction
};
void Dog::speak() override {         // overriding function must be given now
    std::cout << "Woof!\n";
}


// *************************** static / dynamic casting ***************************
for (Animal* animal : animals) {
   Dog* dog = static_cast<Dog*>(animal);        // static
   Cat* cat = dynamic_cast<Cat*>(animal);       // dynamic
   if (dog!=nullptr) dog->wag();
   if (cat!=nullptr) cat->purr();
 }

// static cast
// ➜ happens at compile time
// ➜ checks if typecast is possible

// dynamic cast
// ➜ safe downcasting for polymorphic
// ➜ treating a ptr of the base class as a ptr of the derived class
// ➜ returs a nullptr at runtime, if cast is not possible
