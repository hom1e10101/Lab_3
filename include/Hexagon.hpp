#pragma once

#include <iostream>

#include "Figure.hpp"

class Hexagon : public Figure {
private:
    const size_t points_cnt = 6;
public:
    Hexagon();
    Hexagon(Point, Point, Point, Point, Point, Point);
    Hexagon(const Hexagon&);
    Hexagon(Hexagon&&);

    size_t getPointsCnt() const override;

    ~Hexagon() override;
};
