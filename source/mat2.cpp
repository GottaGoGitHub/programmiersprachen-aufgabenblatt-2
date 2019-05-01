#include <cmath>
#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m){
    float e_00_temp = e_00;
    float e_10_temp = e_10;
    float e_01_temp = e_01;
    float e_11_temp = e_11;

    e_00_temp = e_00 * m.e_00 + e_10 * m.e_01;
    e_10_temp = e_00 * m.e_10 + e_10 * m.e_11;
    e_01_temp = e_01 * m.e_00 + e_11 * m.e_01;
    e_11_temp = e_01 * m.e_10 + e_11 * m.e_11;

    e_00 = e_00_temp;
    e_10 = e_10_temp;
    e_01 = e_01_temp;
    e_11 = e_11_temp;

    return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 res;
    res.e_00 = m1.e_00 * m2.e_00 + m1.e_10 * m2.e_01;
    res.e_10 = m1.e_00 * m2.e_10 + m1.e_10 * m2.e_11;
    res.e_01 = m1.e_01 * m2.e_00 + m1.e_11 * m2.e_01;
    res.e_11 = m1.e_01 * m2.e_10 + m1.e_11 * m2.e_11;

    return res;
}