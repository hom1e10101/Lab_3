#pragma once

#include <iostream>

#include "Figure.hpp"

class Rhomb : public Figure {
private:
    const size_t points_cnt = 4;
public:
    Rhomb();
    Rhomb(Point, Point, Point, Point);
    Rhomb(const Rhomb&);
    Rhomb(Rhomb&&);

    size_t getPointsCnt() const override;

    ~Rhomb() override;
};
