#pragma once

#include <iostream>

class Point{
public:
    double x, y;

    Point();
    Point(double, double);
    Point(const Point&);
    Point(Point&&);
    Point& operator=(const Point&);

    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);

    friend std::istream& operator>>(std::istream&, Point&);
    friend std::ostream& operator<<(std::ostream&, const Point&);

    ~Point() = default;
};
