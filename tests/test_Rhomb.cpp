#include <gtest/gtest.h>
#include "Rhomb.hpp"

TEST(RhombTest, DefaultConstructor) {
    Rhomb rhomb;
    EXPECT_EQ(rhomb.getPointsCnt(), 4);
    EXPECT_NO_THROW(rhomb.getArea());
    EXPECT_NO_THROW(rhomb.getCenter());
}

TEST(RhombTest, ParameterizedConstructor) {
    Point p1(0, 0), p2(2, 2), p3(4, 0), p4(2, -2);
    Rhomb rhomb(p1, p2, p3, p4);
    
    EXPECT_EQ(rhomb.getPointsCnt(), 4);
    EXPECT_NEAR(rhomb.getArea(), 8.0, 1e-6);
    
    Point center = rhomb.getCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 0.0, 1e-6);
}

TEST(RhombTest, CopyConstructor) {
    Point p1(0, 0), p2(1, 1), p3(2, 0), p4(1, -1);
    Rhomb rhomb1(p1, p2, p3, p4);
    Rhomb rhomb2(rhomb1);
    
    EXPECT_EQ(rhomb2.getPointsCnt(), 4);
    EXPECT_NEAR(rhomb2.getArea(), rhomb1.getArea(), 1e-6);
}

TEST(RhombTest, MoveConstructor) {
    Point p1(0, 0), p2(3, 3), p3(6, 0), p4(3, -3);
    Rhomb rhomb1(p1, p2, p3, p4);
    double area = rhomb1.getArea();
    
    Rhomb rhomb2(std::move(rhomb1));
    
    EXPECT_EQ(rhomb2.getPointsCnt(), 4);
    EXPECT_NEAR(rhomb2.getArea(), area, 1e-6);
}

TEST(RhombTest, SquareRhombArea) {
    Point p1(0, 0), p2(0, 2), p3(2, 2), p4(2, 0);
    Rhomb rhomb(p1, p2, p3, p4);
    
    EXPECT_NEAR(rhomb.getArea(), 4.0, 1e-6);
}

TEST(RhombTest, StreamOperations) {
    Point p1(0, 0), p2(1, 1), p3(2, 0), p4(1, -1);
    Rhomb rhomb(p1, p2, p3, p4);
    
    std::stringstream ss;
    rhomb.print(ss);
    EXPECT_FALSE(ss.str().empty());
}