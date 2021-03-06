//include guards
#ifndef MAT2_HPP
#define MAT2_HPP

#include <array>
#include "vec2.hpp"

struct Mat2{
    /* Matrix Layout
    e_00    e_10
    e_01    e_11
    */
   float e_00 = 1.0f;
   float e_10 = 0.0f;
   float e_01 = 0.0f;
   float e_11 = 1.0f;

   Mat2& operator*=(Mat2 const& m);
   float det(Mat2 a) const;
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

//2.6
Vec2 operator*(Mat2 const& m, Vec2 const& v);
Vec2 operator*(Vec2 const& v, Mat2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif
