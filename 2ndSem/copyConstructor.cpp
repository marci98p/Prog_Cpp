// ************************* Copy Constructor *************************
// makes a copy of existing object
// creates an object by initializing it with an object of the same class

Point::Point(const Point& p2_ref)  // explicit copy constructor - if not defined default copy const is created

Date date1( 7, 4, 2004 );    // original object
Date date2(date1);           // calls copy constructor - copy of date1

print(date1);                // call by value (argument is a copy of date1)
return date1;                // returns copy
