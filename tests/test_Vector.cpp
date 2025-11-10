#include <gtest/gtest.h>
#include "Vector_figures.hpp"
#include "Rhomb.hpp"

TEST(VectorFiguresMemoryTest, ResizeIncreasesCapacity) {
    Vector_figures vec;
    size_t initial_capacity = 1;
    
    for (int i = 0; i < 5; ++i) {
        vec.push_back(new Rhomb(Point(0,0), Point(i+1,i+1), Point(i+2,0), Point(i+1,-i-1)));
    }
    
    EXPECT_GT(vec.size(), initial_capacity);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_NE(vec[i], nullptr);
    }
}

TEST(VectorFiguresMemoryTest, LargeNumberOfElements) {
    Vector_figures vec;
    const size_t large_number = 100;
    
    for (size_t i = 0; i < large_number; ++i) {
        vec.push_back(new Rhomb(Point(i,i), Point(i+1,i+1), Point(i+2,i), Point(i+1,i-1)));
    }
    
    EXPECT_EQ(vec.size(), large_number);
    for (size_t i = 0; i < large_number; ++i) {
        EXPECT_NE(vec[i], nullptr);
    }
}

TEST(VectorFiguresMemoryTest, ClearResetsSize) {
    Vector_figures vec;
    
    for (int i = 0; i < 3; ++i) {
        vec.push_back(new Rhomb(Point(0,0), Point(1,1), Point(2,0), Point(1,-1)));
    }
    
    EXPECT_EQ(vec.size(), 3);
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
}