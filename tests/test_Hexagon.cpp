#include <gtest/gtest.h>
#include "Hexagon.hpp"

TEST(HexagonTest, DefaultConstructor) {
    Hexagon hexagon;
    EXPECT_EQ(hexagon.getPointsCnt(), 6);
}

TEST(HexagonTest, RegularHexagonArea) {
    Point p1(1, 0);
    Point p2(0.5, 0.866);
    Point p3(-0.5, 0.866);
    Point p4(-1, 0);
    Point p5(-0.5, -0.866);
    Point p6(0.5, -0.866);
    
    Hexagon hexagon(p1, p2, p3, p4, p5, p6);
    
    EXPECT_EQ(hexagon.getPointsCnt(), 6);
    EXPECT_NEAR(hexagon.getArea(), 2.598, 0.01);
    
    Point center = hexagon.getCenter();
    EXPECT_NEAR(center.x, 0.0, 1e-3);
    EXPECT_NEAR(center.y, 0.0, 1e-3);
}