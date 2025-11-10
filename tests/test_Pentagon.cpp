#include <gtest/gtest.h>

#include "Pentagon.hpp"

TEST(PentagonTest, DefaultConstructor) {
    Pentagon pentagon;
    EXPECT_EQ(pentagon.getPointsCnt(), 5);
}

TEST(PentagonTest, RegularPentagonArea) {
    Point p1(1, 0);
    Point p2(0.309, -0.951);
    Point p3(-0.809, -0.588);
    Point p4(-0.809, 0.588);
    Point p5(0.309, 0.951);
    
    Pentagon pentagon(p1, p2, p3, p4, p5);
    EXPECT_EQ(pentagon.getPointsCnt(), 5);
    EXPECT_NEAR(pentagon.getArea(), 2.377, 0.01);
    
    Point center = pentagon.getCenter();
    EXPECT_NEAR(center.x, 0.0, 1e-3);
    EXPECT_NEAR(center.y, 0.0, 1e-3);
}

TEST(PentagonTest, CopyOperations) {
    Point p1(0, 0), p2(1, 0), p3(2, 1), p4(1, 2), p5(0, 1);
    Pentagon pentagon1(p1, p2, p3, p4, p5);
    Pentagon pentagon2(pentagon1);
    
    EXPECT_EQ(pentagon2.getPointsCnt(), 5);
    EXPECT_NEAR(pentagon2.getArea(), pentagon1.getArea(), 1e-6);
}