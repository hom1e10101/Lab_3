#include "Rhomb.hpp"

Rhomb::Rhomb() {
    points.resize(getPointsCnt());
}

Rhomb::Rhomb(Point p1, Point p2, Point p3, Point p4) {
    points = {p1, p2, p3, p4};
    sorting(points);
}

Rhomb::Rhomb(const Rhomb& other) {
    points = other.points;
    sorting(points);
}

Rhomb::Rhomb(Rhomb&& other) {
    points = std::move(other.points);
    sorting(points);
}

size_t Rhomb::getPointsCnt() const {return points_cnt;}

Rhomb::~Rhomb() {};