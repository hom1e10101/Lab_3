#include <new>
#include <exception>

#include "MyVector.hpp"

void MyVector::pop()
{
    if (sz > 0) sz--;
}

void MyVector::push_back(const Point& n)
{
    if (sz >= capacity) {
        capacity *= 2;
        Point* next = new Point[capacity];
        std::copy(data, data + sz, next);
        delete[] data;
        data = next;
    }
    data[sz] = n;
    sz++;
}

MyVector::MyVector() 
    : sz(0), capacity(1), data(new Point){};

MyVector::MyVector(const size_t& n) 
    : sz(n), capacity(n * 2), data(new Point[n * 2])
{
    for (size_t i = 0; i < n; ++i) {
        data[i].x = 0;
        data[i].y = 0;
    }
};

MyVector::MyVector(const std::initializer_list<Point>& t)
    : sz(t.size()), capacity(t.size() * 2), data(new Point[t.size() * 2])
{
    std::copy(t.begin(), t.end(), data);
    for (size_t i = 0; i < t.size() / 2; ++i) {
        std::swap(data[i], data[sz - i - 1]);
    }
}

MyVector::MyVector(const MyVector& other)
    : sz(other.sz), capacity(other.capacity), data(new Point[other.capacity])
{
    std::copy(other.data, other.data + other.sz, data);
}

MyVector::MyVector(MyVector&& other) noexcept
    : sz(other.sz), capacity(other.capacity), data(new Point[other.capacity])
{
    data = other.data;
    other.data = nullptr;
}

void MyVector::reallocate(size_t newsize) {
    capacity = newsize * 2;
    Point* newdata = new Point[capacity];
    std::copy(data, data + sz, newdata);
    delete[] data;
    data = newdata;
}

void MyVector::resize(size_t newsize) {
    capacity = newsize * 2;
    Point* newdata = new Point[capacity];
    std::copy(data, data + sz, newdata);
    sz = newsize;
    delete[] data;
    data = newdata;
}

Point& MyVector::operator[](size_t ind) {
    if (ind > sz) {
        throw std::out_of_range("ind is bigger then size of MyVector");
    }

    return data[ind];
}

const Point& MyVector::operator[](size_t ind) const {
    if (ind > sz) {
        throw std::out_of_range("ind is bigger then size of MyVector");    
    }

    return data[ind];
}

const size_t MyVector::size() const {
    return sz;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;
    capacity = other.capacity;
    sz = other.sz;
    data = new Point[capacity];
    
    std::copy(other.data, other.data + other.sz, data);

    return *this;
}

MyVector::~MyVector() noexcept
{
    sz = 0;
    capacity = 1;
    delete[] data;
    data = nullptr;
}



