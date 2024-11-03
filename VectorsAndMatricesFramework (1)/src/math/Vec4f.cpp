#include "Vec4f.h"
#include <stdexcept>

Vec4f::Vec4f()
    : x(0), y(0), z(0), w(1){}

Vec4f::Vec4f(float pData[4])
    : x(pData[0]), y(pData[1]), z(pData[2]), w(pData[3]){}

Vec4f::Vec4f(float pX, float pY, float pZ)
    : x(pX), y(pY), z(pZ), w(1){}

Vec4f::Vec4f(float pX, float pY, float pZ, float pW)
    : x(pX), y(pY), z(pZ), w(pW){}


float Vec4f::length() const{
    // TODO: Return the correct length.
    return 0;
}

float Vec4f::squaredLength() const{
    // TODO: Return the correct squared length.
    return 0;
}

float Vec4f::distanceTo(const Vec4f v) const{
    // TODO: Return the correct distance to the given vector v.
    return 0;
}

float Vec4f::dot(const Vec4f v) const{
    // TODO: Return the correct dot product with v.
    return 0;
}

Vec4f Vec4f::cross(const Vec4f v) const{
    // TODO: Return the correct cross product with v.
    return Vec4f();
}

Vec4f Vec4f::normalized() const{
    // TODO: Return the normalized vector of this vector:
    return Vec4f();
}

bool Vec4f::operator==(const Vec4f v) const{
    // TODO: Return only true, if all components are equal enough to the
    // corresponding components of the given vector v.
    return true;
}

bool Vec4f::operator!=(Vec4f v) const{
    // TODO: Return the correct result.
    return true;
}

Vec4f Vec4f::operator-() const{
    // TODO: Return the correct result.
    return Vec4f();
}

Vec4f Vec4f::operator+(const Vec4f v) const{
    // TODO: Return the correct result.
    return Vec4f();
}

Vec4f Vec4f::operator-(const Vec4f v) const{
    // TODO: Return the correct result.
    return Vec4f();
}

Vec4f Vec4f::operator*(float scalar) const{
    // TODO: Return the correct result.
    return Vec4f();
}

Vec4f Vec4f::operator/(float s) const{
    // TODO: Return the correct result.
    return Vec4f();
}

float& Vec4f::operator[](int i){
    if (i < 0 && i >= 4)
        throw std::invalid_argument( "The index i has to be between 0 and 3!" );

    return *(&x + i);
}

float Vec4f::operator[](int i) const{
    if (i < 0 && i >= 4)
        throw std::invalid_argument( "The index i has to be between 0 and 3!" );

    return *(&x + i);
}

bool Vec4f::valid() const {
    return !std::isnan(x) && !std::isnan(y) && !std::isnan(z) && !std::isnan(w);
}
