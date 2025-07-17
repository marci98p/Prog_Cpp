// code that works for multiple data types
// Usecases:
// - Function Templates
// - Class Templates
// - Variable Templates (Since C++ 14)
template <typename A, typename B, ...> returnType FunctionTempName(type arguments) { function body }
template <typename T> class ClassTempName { class body };    // class template (member func defined inside class body)
template <class T> returnType ClassName<T>::memberFunctionName(type arguments) { function body }     // member function defined outside class body

// **************************************************** Function template Example  definition
template <typename T> T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << myMax<int>(3, 7) << endl;           // Call myMax for int
    cout << myMax<double>(3.0, 7.0) << endl;    // call myMax for double
    cout << myMax<char>('g', 'e');              // call myMax for char
    return 0;
}

// **************************************************** Class template example
template <typename T> class ClassTemp {
  t x;
  t y;
  public:
    TempClass(T val1, T, val1) : x(val1), y(val2) {}  // constructor
    // Member funcitons - return type T
    T getX() { return x;}
    T getY() { return y;}
};

int main() {
    // Creating objects of Geek with
    Geek<int> intPoint(10, 20);
    Geek<double> doublePoint(3.14, 6.28);

    // Access the templates values
    cout << "Int: (" << intPoint.getX() << ", " << intPoint.getY() << ")\n";             // Out: Int: (10, 20)
  	cout << "Double: (" << doublePoint.getX() << ", " << doublePoint.getY() << ")\n";    // Out: Double: (3.14, 6.28)
}


// **************************************************** multiple Types in class template
template <typename T1, typename T2, typename T3> class Geek {
  T1 x_;
  T2 y_;
  T3 name_;
  public:
    // Constructor to initialization
    Geek(T1 x, T2 y, T3 name) : x_(x), y_(y), name_(name) {}
    // Method to get values
    void getValues() {
        cout << name_ << ": (" << x_ << ", " << y_ << ")\n";
    }
};

int main() {
    Geek<int, int, string> intCoordinates(10, 3, "P1");
    Geek<char, char, bool> charCoordinate('A', '4', true);
    intCoordinates.getValues();
  	charCoordinate.getValues();
}


// **************************************************** Template Variables
template <typename T> constexpr T pi = T(3.14159);
int main()
{
    // Using pi with different types
    cout << "Pi as float: " << pi<float> << endl;
    cout << "Pi as double: " << pi<double>;
    return 0;
}
