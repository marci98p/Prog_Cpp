// ************************* Friends ************************* 
friend <function prototype>;    // friend function inside a class (used for operator overloading)
friend void setX( Count& c_ref, int val );  // Example - friend function ins not a member function

friend <ClassName>;     // friend class can access private and public class elements
friend Doctor;          // Example 



// ************************* Operator Overloading ************************* 
// operators that can be overloaded
+  -  *  /  %  ^  &  |  ~  !  =  <  >
+=  -=  *=  /=  %=  ^=  &= |=  <<  >>  <<=  >>=  ==  !=  <=  >=
&&  ||  ++  --  ->*  ,  ->  []  ()  new  delete  new[]  delet[]

// ******************************** 2 ways to overload overload ********************************
  // 1. As a member function of class => prefered
  // 2. as global friend funciton => cin / cout / mixed types / arg class type on right hand side

 // C++ Syntax for Operator Overloading
 <return type> operator<operatorSymbol>(argument list)

// *********************************************************************************************
// example - member function vs global friend function
// prefered way: as member functions
class Fraction {
 friend Fraction operator+(const Fraction& f1_ref, const Fraction& f2_ref );  // as friend function
 public:
   Fraction operator-(const Fraction& f_ref) const;                           // as member function
  }

// member function definition
Fraction Fraction::operator-(const Fraction& f_ref) const {
  Fraction diff;
  ...
  return diff;
}

// global friend function definition - use only if member function not feasible
Fraction operator+( const Fraction& f1_ref, const Fraction& f2_ref ) {
  Fraction sum;
  ...
  return sum;
}


// ******************************** mixed types **************************************************
 Fraction a(1,2), b;
 b = a + 2;   // this can be overloaded with a member function
 b = 2 + a;   // this can just be overloaded with a global

class Fraction  {
  friend Fraction operator+( const int& i_ref, const Fraction& f_ref );    // class type on rhs as global friend
  public:
   Fraction operator+( const int& i_ref ) const;                           // class type on lhs as member func


// ************************** stream insertion & extraction operators ********************************
// cin / cout / cerr / clog must be friend functions
friend ostream& operator<<(ostream& out_ref, const ClassType& class_ref);    // in class declaration
friend istream& operator>>(istream& in_ref, ClassType& class_ref);           // in class declaration 

ostream&  operator<< (ostream& out_ref,  const Fraction& f_ref) {            // definition
  out_ref << f_ref.getNumerator() << "/" << f_ref.getDenominator();
  return out_ref;
}

 istream& operator>>(istream& input_ref, Fraction& f_ref) {                  // definition
   input_ref >> f_ref.num_;
   input_ref.ignore(1); // skip '/' 
   input_ref >> f_ref.den_;
   input_ref.ignore(1); // skip \n caused by RETURN key
   return input_ref;
 }

// std::print  ostream
ostream& BMI::print(ostream &stream) {
    for ( auto person : people_ ){
        stream  << person.getName()
                << " has a BMI of "
                << calculateBMI(person)
                << ", thats "
                << ( hasNormalWeight(person) ? "normal weight" : "no normal weight" )      // brackets !
                << endl;
    }
    return stream ;
}

// ******************************** Unary Operators **************************************************
-  !  ++  --
// also preferred as member function
// overloading the ++prefix increment operator
 Fraction& Fraction::operator++() {
   dataMember_ += step;      // += operator must be overloaded as well
   return *this;
 }
// overloading the postfix-- decrement operator 
Fraction Fraction::operator--(int) {
   Fraction temp = *this;     // save a copy of *this before decrement
   dataMember_ -= step;       // -= operator must be overloaded as well
   return temp;               // return saved *this 
}
