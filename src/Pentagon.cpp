#include "Pentagon.hpp"

Pentagon::Pentagon() {
    points.resize(getPointsCnt());
}

Pentagon::Pentagon(Point p1, Point p2, Point p3, Point p4, Point p5) {
    points = {p1, p2, p3, p4, p5};
    sorting(points);
}

Pentagon::Pentagon(const Pentagon& other) {
    points = other.points;
    sorting(points);
}

Pentagon::Pentagon(Pentagon&& other) {
    points = std::move(other.points);
    sorting(points);
}

size_t Pentagon::getPointsCnt() const {return points_cnt;}

Pentagon::~Pentagon() {};
