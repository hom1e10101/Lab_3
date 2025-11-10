#pragma once

#include <iostream>
#include <vector>

#include "Figure.hpp"

class Vector_figures{
private:
    size_t sz;
    size_t capacity;
    Figure** data;
public:
    Vector_figures();
    Vector_figures(const Vector_figures&);
    Vector_figures(Vector_figures&&) noexcept;

    void resize(size_t);
    void push_back(Figure*);
    void pop_back();
    void clear();

    void erase(size_t);

    size_t size() const;

    Figure* operator[](size_t ind);

    ~Vector_figures();
};
