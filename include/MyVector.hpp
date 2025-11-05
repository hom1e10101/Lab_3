#pragma once

#include <iostream>

#include "Point.hpp"

class MyVector
{
public:
    size_t sz;
    size_t capacity;
    Point* data;

    MyVector();
    MyVector(const size_t& n);
    MyVector(const std::initializer_list<Point>& t);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other) noexcept;

    void pop();
    void push_back(const Point& n);
    void resize(size_t);
    void reallocate(size_t);
    const size_t size() const;

    Point& operator[](size_t ind);
    const Point& operator[](size_t ind) const;

    MyVector& operator=(const MyVector&);

    virtual ~MyVector() noexcept;
    unsigned char get(size_t ind) const;
};
