// operators that can be overloaded
+  -  *  /  %  ^  &  |  ~  !  =  <  >
+=  -=  *=  /=  %=  ^=  &= |=  <<  >>  <<=  >>=  ==  !=  <=  >=
&&  ||  ++  --  ->*  ,  ->  []  ()  new  delete  new[]  delet[]

// ******************************** 2 ways to overload overload ********************************
  // 1. As a member function of class => prefered
  // 2. as global friend funciton => cin / cout / mixed types / arg class type on right hand side

 // C++ Syntax for Operator Overloading
 <return type> operator<op-symbol>(argument list)

// example - member function vs global friend function
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

// global friend function definition
Fraction operator+( const Fraction& f1_ref, const Fraction& f2_ref ) {
  Fraction sum;
  ...
  return sum;
}


// ******************************** mixed types ********************************
// use only when member function not working
// => for cin / cout / mixed types / arg class type on right hand side
