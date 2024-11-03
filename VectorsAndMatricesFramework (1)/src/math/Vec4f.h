// © 2022, CGVR (https://cgvr.informatik.uni-bremen.de/),
// Author: Andre Mühlenbrock (muehlenb@uni-bremen.de)

// Include this file only once when compiling:
#pragma once

/* Defines PI with float precision if this is not already defined: */
#ifndef M_PI
#define M_PI          3.14159265f
#endif

/* Defines the threshold to which the difference between two components should be considered as equal: */
#define COMPARE_DELTA 0.0001f

/* Includes the some math functions like abs(...), max(...), etc.: */
#include <cmath>
#include <cfloat>

/**
 * This class defines a 3D vector or point, depending on the
 * forth attribute 'w':
 *
 *  - If w == 0, then it is a vector.
 *  - If w == 1, then it is a point.
 */

class Vec4f
{
public:
    /** The x component of the vector */
    float x;

    /** The y component of the vector */
    float y;

    /** The z component of the vector */
    float z;

    /** The w component of the vector (w=0 for vectors, w=1 for points) */
    float w;

    /**
     * Constructor which creates a *point* at (0,0,0).
     */
    Vec4f();

    /**
     * Constructor which creates a *point* with the given parameters (x, y, z).
     */
    Vec4f(float x, float y, float z);

    /**
     * Constructor which creates a Vec4 with (x, y, z, w), which can be a point
     * or a vector depending on the chosen w value.
     */
    Vec4f(float x, float y, float z, float w);

    /**
     * Constructor which creates a Vec4 with (data[0], data[1], data[2], data[3]).
     */
    Vec4f(float data[4]);

    /**
     * Returns the length of this vector.
     *
     * Note: Ignore the w coordinate and only use the x,y and z coordinate!
     */
    float length() const;

    /**
     * Returns the squared length of this vector.
     *
     * Note: Ignore the w coordinate and only use the x,y and z coordinate!
     */
    float squaredLength() const;

    /**
     * Return the Euclidean distance from this point to the given point.
     *
     * NOTE: Since we use this function only with points, only use the
     * (x,y,z) coordinate to calculate the distance, NOT the w-coordinate!
     */
    float distanceTo(const Vec4f points) const;

    /**
     * Returns the dot product of this vector with the given vector
     *
     * NOTE: Use only x,y and z coordinates, NOT the w-coordinate!
     */
    float dot(const Vec4f vector) const;

    /**
     * Returns the cross product of this vector with the given vector
     *
     * NOTE: Use only x,y and z coordinates, not the w-coordinate and
     * return a vector with w = 0!
     */
    Vec4f cross(const Vec4f vector) const;

    /**
     * Returns a normalized Vector of this vector, so that the length
     * is 1. (Note that normalization only makes sense for vectors, not
     * for points, so you can assume that w=0).
     */

    Vec4f normalized() const;

    /**
     * Checks that all components are similar enough for both vectors to be
     * considered equal.
     *
     * NOTE: Use 'COMPARE_DELTA' to check whether the difference is small
     * enough.
     */

    bool operator==(const Vec4f vector) const;

    /**
     * Checks if at least one component has a higher difference than
     * 'COMPARE_DELTA' when comparing this vector to the given one.
     */

    bool operator!=(const Vec4f vector) const;

    /**
     * Returns this vector negated.
     */
    Vec4f operator-() const;

    /**
     * Returns a vector where each component of this vector is added by the
     * respective component of the given vector (also the w component!).
     */
    Vec4f operator+(const Vec4f vector) const;

    /**
     * Returns a new vector where each component of this vector is subtracted
     * by the respective component of the given vector (also the w component!).
     */
    Vec4f operator-(const Vec4f vector) const;

    /**
     * Returns a new vector where the x, y and z components of this vector are
     * multiplicated by the given scalar (note that w should NOT be scaled!)
     */
    Vec4f operator*(const float scalar) const;

    /**
     * Returns a new vector where the x, y and z components of this vector are
     * divided by the given scalar (note that w should NOT be scaled!).
     */
    Vec4f operator/(const float scalar) const;

    /**
     * Allows access to individual components via indices as with arrays,
     * where x is at idx 0, y at idx 1, and so on.
     *
     * The returned value is a reference so that it can be written to it.
     */
    float& operator[](int i);

    /**
     * Allows access to individual components via indices as with arrays,
     * where x is at idx 0, y at idx 1, and so on.
     *
     * This is the const implementation to be able to access the values
     * via [] on a const vector too.
     */
    float operator[](int i) const;

    /**
     * Returns whether this vector is valid, which means that every
     * component is valid (and not NAN).
     */
    bool valid() const;
};
