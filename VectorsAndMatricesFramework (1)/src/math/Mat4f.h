// © 2022, CGVR (https://cgvr.informatik.uni-bremen.de/),
// Author: Andre Mühlenbrock (muehlenb@uni-bremen.de)

// Include this file only once when compiling:
#pragma once

/* Includes the some math functions like std::abs(...), std::max(...), etc.: */
#include <cmath>

/* Includes the std::vector class, which is comparable to an ArrayList in Java.
 * Note that this vector class is NOT meant to be a mathematical vector! */
#include <vector>

/* Include our Vec4f which is meant to be a vector in the mathematical sense */
#include "Vec4f.h"

/**
 * Implementation of a 4x4 Matrix. This matrix class is intended specifically
 * for the transformation of points and vectors. This will be explained in the
 * lecture later on.
 *
 * Note that we use a column-major order to store the values, like OpenGL does.
 * This means, that the first column is stored into data[0], data[1], data[2] and 
 * data[3] and the first row is stored into data[0], data[4], data[8] and data[12].
 */

class Mat4f
{
public:
    /**
     * In this array, all the values of this 4x4 matrix are stored
     * (in column-major order).
     */
    float data[16];

    /**
     * Constructs an identity matrix.
     *
     * The cells on the diagonal of the identity matrix have the value 1, other
     * cells have the value 0.
     */
    Mat4f();

    /**
     * Constructs a matrix with the given data (in column-major order).
     */
    Mat4f(const float data[16]);

    /**
     * Constructs a matrix with the given data (in column-major order).
     *
     * WARNING: This method expects the std::vector to have at least 16 entries,
     * because the first 16 entries will be copied unchecked.
     */
    Mat4f(const std::vector<float> data);

    /**
     * Constructs a transformation matrix which rotates and scales the unit axes 
	 * to the given axis1, axis2 and axis3 and applies the given translation.
	 */
    Mat4f(const Vec4f axis1, const Vec4f axis2, const Vec4f axis3, const Vec4f translation);

    /**
     * Multiplies this matrix by the given matrix and returns the result as a new
     * matrix.
     *
     * It is a normal multiplication of two 4x4 matrices as you know it from school
     * (using all 4 columns and rows).
     */
    Mat4f operator*(const Mat4f matrix) const;

    /**
     * Multiplies this matrix by the given vector and returns the result as a
     * new vector.
     *
     * It is a normal multiplication of a 4x4 matrix with a 4D-vector as you know it
     * from school (using all 4 columns and rows of the matrix and x,y,z AND w of the
     * 4D vector!).
     */
    Vec4f operator*(const Vec4f vector) const;

    /**
     * Returns the position where a point (0,0,0) would be transformed to after
     * applying this transformation matrix.
     */
    Vec4f getPosition() const;
};
