#pragma once

#include <iostream>

#include "Figure.hpp"

class Pentagon : public Figure {
private:
    const size_t points_cnt = 5;
public:
    Pentagon();
    Pentagon(Point, Point, Point, Point, Point);
    Pentagon(const Pentagon&);
    Pentagon(Pentagon&&);

    size_t getPointsCnt() const override;

    ~Pentagon() override;
};
