#include "Hexagon.hpp"

Hexagon::Hexagon() {
    points.resize(getPointsCnt());
}

Hexagon::Hexagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6) {
    points = {p1, p2, p3, p4, p5, p6};
    sorting(points);
}

Hexagon::Hexagon(const Hexagon& other) {
    points = other.points;
    sorting(points);
}

Hexagon::Hexagon(Hexagon&& other) {
    points = std::move(other.points);
    sorting(points);
}

size_t Hexagon::getPointsCnt() const {return points_cnt;}

Hexagon::~Hexagon() {};
