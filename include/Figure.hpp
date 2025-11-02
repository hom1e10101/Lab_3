#pragma once

#include <iostream>
#include <utility>
#include <vector>

#include "Point.hpp"

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
    std::vector<Point> points;
protected:
    
    long double CalcArea(const std::vector<Point>&) const;
    Point CalcCenter(const std::vector<Point>&) const;
    void sorting(std::vector<Point>&);
};

inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}