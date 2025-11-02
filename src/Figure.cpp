#include <cmath>
#include <algorithm>

#include "Figure.hpp"

void Figure::print(std::ostream& os) const {
    for (size_t i = 0; i < getPointsCnt(); ++i) {
        Point kek = points[i];
        os << kek << " ";
    }
}

void Figure::read(std::istream& is) {
    points.resize(getPointsCnt());
    for (size_t i = 0; i < getPointsCnt(); ++i) {
        is >> points[i];
    }
}

void Figure::sorting(std::vector<Point>& v) {
    Point center = getCenter();

    std::sort(points.begin(), points.end(), [&center](const Point& a, const Point& b) {
        double angleA = atan2(a.y - center.y, a.x - center.x);
        double angleB = atan2(b.y - center.y, b.x - center.x);
        return angleA > angleB;
    });
}

long double Figure::CalcArea(const std::vector<Point>& v) const {
    long double res{0.0};

    for (size_t i = 0; i < v.size(); ++i) {
        res += (long double)v[i].x * v[(i + 1) % v.size()].y;
        res -= (long double)v[(i + 1) % v.size()].x * v[i].y;
    }

    return std::abs(res / 2);
}


Point Figure::CalcCenter(const std::vector<Point>& t) const {
    double x = 0, y = 0;
    
    for (size_t i = 0; i < t.size(); ++i) {
        x += t[i].x;
        y += t[i].y;
    }

    return Point(x / t.size(), y / t.size());
}

bool operator==(const Figure& a, const Figure& b) {
    if (a.points.size() != b.points.size()) {
        return 0;
    }
    for (size_t i = 0; i < a.points.size(); ++i) {
        if (a.points[i] != b.points[i]) {
            return 0;
        }
    }
    return 1;
}

bool operator!=(const Figure& a, const Figure& b) { return !(a == b); }
