// best for strings only
return (firstname_ + " " + lastname_);  



// best for multiple types (no casting neccessary - type converting via << )
stringstream ss;                // stringstream needs to be initialisied first
ss << "A " << name_ << " at position (" << x << "," << y << ")";
return ss.str();

