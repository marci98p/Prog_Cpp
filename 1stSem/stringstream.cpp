string Shape::getShapeInfo() const{
    // "A <name> at position <position>"
    double x = position_.getX();
    double y = position_.getY();
    stringstream ss;                // stringstream needs to be initialisied first
    ss << "A " << name_ << " at position (" << x << "," << y << ")";
    return ss.str();
}
