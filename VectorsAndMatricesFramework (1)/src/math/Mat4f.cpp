#include "Mat4f.h"

// Include memcpy (if you wish to use it):
#include <cstring>

Mat4f::Mat4f(){
    // Set all values to zero, except for the diagonal of the matrix:
    for(int i=0; i < 16; ++i){
        data[i] = i%5 == 0 ? 1.f : 0.f;
    }
}

Mat4f::Mat4f(const Vec4f axis1, const Vec4f axis2, const Vec4f axis3, const Vec4f translation){
    // Copy the first axis to the first four float values of the data-array:
    memcpy(&data[0], &axis1.x, sizeof(float) * 4);

    // Copy the second axis to the next four float values of the data-array:
    memcpy(&data[4], &axis2.x, sizeof(float) * 4);

    // Copy the third axis to the next four float values of the data-array:
    memcpy(&data[8], &axis3.x, sizeof(float) * 4);

    // Copy the translation to the next four float values of the data-array:
    memcpy(&data[12], &translation.x, sizeof(float) * 4);
}

Mat4f::Mat4f(const float pData[16]){
    // Just copy all values of the given array into the data-array:
    memcpy(data, pData, sizeof(float) * 16);
}

Mat4f::Mat4f(const std::vector<float> pData){
    // Just copy the first 16 values of the given array into the data-array:
    memcpy(data, &pData[0], sizeof(float) * 16);
}

Mat4f Mat4f::operator*(const Mat4f m) const{
    float result[16] = {};

    //TODO: Implementation of matrix multiplication where
    //       the result is stored in the result array defined
    //       above (see Mat4f.h for details).


    return Mat4f(result);
}

Vec4f Mat4f::operator*(const Vec4f v) const{
    float dest[4] = {};

    // TODO: Implementation of matrix * vector multiplication
    //       where the result is stored in the result array
    //       defined above (see Mat4f.h for details).


    return Vec4f(dest);
}

Vec4f Mat4f::getPosition() const{
    return Vec4f(data[12], data[13], data[14]);
}
