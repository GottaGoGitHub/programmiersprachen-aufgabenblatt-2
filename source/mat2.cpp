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

//2.6
Vec2 operator*(Mat2 const& m, Vec2 const& v){
    Vec2 res;
    res.x = m.e_00 * v.x + m.e_10 * v.y;
    res.y = m.e_01 * v.x + m.e_11 * v.y;

    return res;
}
Vec2 operator*(Vec2 const& v, Mat2 const& m){
    //not possible
    return v;
}
Mat2 inverse(Mat2 const& m){
    float factor = 1/(m.e_00 * m.e_11 - m.e_10 * m.e_01);
    //without implementing float * mat2:
    Mat2 res{factor * m.e_11, factor * -m.e_10, factor * -m.e_01, factor * m.e_00};
    return res;
}
Mat2 transpose(Mat2 const& m){
    Mat2 res{m.e_00, m.e_01, m.e_10, m.e_11};
    return res;
}
Mat2 make_rotation_mat2(float phi){
    //angle phi between 0 and 1
    Mat2 res{cos(phi), -sin(phi), sin(phi), cos(phi)};
    return res;
}

float det(Mat2 a){
    return a.e_00 * a.e_11 - a.e_10 * a.e_01;
}
