#pragma once

#include <iostream>
#include <utility>
#include <vector>

#include "Point.hpp"
#include "MyVector.hpp"

class Figure {
public:
    virtual ~Figure() = default;
    
    Point getCenter() {return CalcCenter(points);}
    long double getArea() {return CalcArea(points);}
    
    void print(std::ostream&) const;
    
    void read(std::istream&);

    friend bool operator==(const Figure&, const Figure&);
    friend bool operator!=(const Figure&, const Figure&);

    virtual size_t getPointsCnt() const = 0;
    MyVector points;
    void sorting(MyVector&);
protected:
    
    long double CalcArea(const MyVector&) const;
    Point CalcCenter(const MyVector&) const;
};

inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    fig.sorting(fig.points);
    return is;
}