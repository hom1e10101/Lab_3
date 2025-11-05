#include "Vector_figures.hpp"

Vector_figures::Vector_figures() : sz(0), capacity(1), data(new Figure*[capacity]) {}

Vector_figures::Vector_figures(const Vector_figures& other)
    : sz(other.sz), capacity(other.capacity), data(other.data) {}

Vector_figures::Vector_figures(Vector_figures&& other) noexcept
    : sz(other.sz), capacity(other.capacity), data(std::move(other.data)) {}

void Vector_figures::resize(size_t newsize) {
    capacity = newsize;
    Figure** newdata = new Figure*[capacity];
    std::copy(data, data + sz, newdata);
    delete[] data;
    data = newdata;
}

void Vector_figures::push_back(Figure* newfig) {
    if (sz >= capacity) resize(2 * capacity);
    data[sz++] = newfig;
}

void Vector_figures::pop_back() {
    if (!sz) return;
    sz--;
}

void Vector_figures::clear() {
    sz = 0;
    capacity = 1;
    delete[] data;
    data = new Figure*[capacity];
}

void Vector_figures::erase(size_t ind) {
    if (ind > sz) return;

    for (size_t i = ind; i < sz - 1; ++i) {
        data[i] = data[i + 1];
    }
    sz--;
}

Figure* Vector_figures::operator[](size_t ind) {
    return data[ind];
}

size_t Vector_figures::size() const {return sz;}

Vector_figures::~Vector_figures() {
    sz = 0;
    capacity = 1;
    delete[] data;
    data = nullptr;
}
