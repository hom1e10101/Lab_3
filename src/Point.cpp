#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(double x_, double y_) : x(x_), y(y_) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(Point&& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;

    return *this;
}

bool operator==(const Point& a, const Point& b) {
    return (a.x == b.x) && (a.y == b.y);
}

bool operator!=(const Point& a, const Point& b) {
    return !(a == b);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
