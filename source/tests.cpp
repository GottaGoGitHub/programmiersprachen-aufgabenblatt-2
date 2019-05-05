#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "vec2.cpp"
#include "mat2.hpp"
#include "mat2.cpp"
#include "color.hpp"
#include "rectangle.hpp"


TEST_CASE("test_for_init", "[vec2]"){
  Vec2 a; 
  Vec2 b{5.1f, -9.3f};
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3 == Approx(b.y));
}

//vec2 += vec2
TEST_CASE("test_for_plus", "[plus]"){
  //init test vectors
  Vec2 op_test_plus{1.3f, 4.0f};
  Vec2 op_test_plus2{3.6f, 1.1f};
  op_test_plus += op_test_plus2;
  REQUIRE(op_test_plus.x == Approx(4.9f));
  REQUIRE(op_test_plus.y == Approx(5.1f));
}
//vec2 -= vec2
TEST_CASE("test_for_minus", "[minus]"){
  Vec2 op_test_minus{4.0f , 3.0f};
  Vec2 op_test_minus2{2.5f, 1.0f};
  op_test_minus -= op_test_minus2;
  REQUIRE(op_test_minus.x == Approx(1.5f));
  REQUIRE(op_test_minus.y == Approx(2.0f));
}
//vec2 *= float
TEST_CASE("test_for_mult", "[mult]"){
  Vec2 op_test_mult{4.0f , 3.0f};
  float s = 2.5f;
  op_test_mult *= s;
  REQUIRE(op_test_mult.x == Approx(10.0f));
  REQUIRE(op_test_mult.y == Approx(7.5f));
}
//vec2 /= float
TEST_CASE("test_for_div", "[div]"){
  Vec2 op_test_div{4.0f , 3.0f};
  float s = 2.0f;
  op_test_div /= s;
  REQUIRE(op_test_div.x == Approx(2.0f));
  REQUIRE(op_test_div.y == Approx(1.5f));
}
//vec2 + vec2
TEST_CASE("test_free_add", "[add]"){
  Vec2 a{1.4f, 2.6f};
  Vec2 b{-4.2f, 5.6f};
  Vec2 res = a + b;
  REQUIRE(res.x == Approx(-2.8f));
  REQUIRE(res.y == Approx(8.2f));
}
//vec2 - vec2
TEST_CASE("test_free_sub", "[sub]"){
  Vec2 a{1.4f, 2.6f};
  Vec2 b{-4.2f, 5.6f};
  Vec2 res = a - b;
  REQUIRE(res.x == Approx(5.6f));
  REQUIRE(res.y == Approx(-3.0f));
}
//vec2 * float
TEST_CASE("test_free_mult", "[mult_free]"){
  Vec2 a{4.0f, 3.0f};
  float s = 2.5f;
  Vec2 res = a * s;
  REQUIRE(res.x == Approx(10.0f));
  REQUIRE(res.y == Approx(7.5f));
}
//float * vec2
TEST_CASE("test_free_mult_reverse", "[mult_free_reverse]"){
  Vec2 a{4.0f, 3.0f};
  float s = 2.5f;
  Vec2 res = s * a;
  REQUIRE(res.x == Approx(10.0f));
  REQUIRE(res.y == Approx(7.5f));
}
//vec2 / float
TEST_CASE("test_free_div", "[div_free]"){
  Vec2 a{4.0f, 3.0f};
  float s = 2.0f;
  Vec2 res = a / s;
  REQUIRE(res.x == Approx(2.0f));
  REQUIRE(res.y == Approx(1.5f));
}

//mat2
TEST_CASE("test_for_mat_init", "[mat2]"){
  Mat2 a;
  Mat2 b{1.2f, 3.4f, 1.3f, 4.1f};
  REQUIRE(a.e_00 == Approx(1.0f));
  REQUIRE(a.e_10 == Approx(0.0f));
  REQUIRE(a.e_01 == Approx(0.0f));
  REQUIRE(a.e_11 == Approx(1.0f));
  REQUIRE(1.2f == Approx(b.e_00));
  REQUIRE(3.4f == Approx(b.e_10));
  REQUIRE(1.3f == Approx(b.e_01));
  REQUIRE(4.1f == Approx(b.e_11));
}

//mat2 * mat2
TEST_CASE("test_for_free_mat_mult", "[mat2_mult_free]"){
  Mat2 a{1, 2, 3, 4};
  Mat2 b{2, 3, 4, 1};
  Mat2 c;
  Mat2 res1 = a * b;
  REQUIRE(res1.e_00 == 10);
  REQUIRE(res1.e_10 == 5);
  REQUIRE(res1.e_01 == 22);
  REQUIRE(res1.e_11 == 13);
  Mat2 res2 = a * c;
  REQUIRE(res2.e_00 == a.e_00);
  REQUIRE(res2.e_10 == a.e_10);
  REQUIRE(res2.e_01 == a.e_01);
  REQUIRE(res2.e_11 == a.e_11);
}
//mat2 *= mat2
TEST_CASE("test_for_mat_mult", "[mat2_mult]"){
  Mat2 a{1, 2, 3, 4};
  Mat2 b{2, 3, 4, 1};
  a *= b;
  REQUIRE(a.e_00 == 10);
  REQUIRE(a.e_10 == 5);
  REQUIRE(a.e_01 == 22);
  REQUIRE(a.e_11 == 13);
}

//determinant
TEST_CASE("test_det", "[det]"){
  Mat2 a{1, 2, 3, 4};
  float res = det(a);
  REQUIRE(res == -2);
}
//mat2 * vec2
TEST_CASE("test_mat_multwith_vec", "[matmult]"){
  Mat2 a{1, 2, 3, 4};
  Vec2 b{2, -2};
  Vec2 res = a * b;
  REQUIRE(res.x == -2);
  REQUIRE(res.y == -2);
}
TEST_CASE("test_vec_multwith_mat", "[vecmatmult]"){
  //not possible alwys returns input vec2
  Mat2 a{1, 2, 3, 4};
  Vec2 b{2, -2};
  Vec2 res = b * a;
  REQUIRE(res.x == b.x);
  REQUIRE(res.y == b.y);
}
//inversion
TEST_CASE("test_for_inversion", "[inverse]"){
  Mat2 a{2, -3, 1, 5};
  Mat2 res = inverse(a);
  REQUIRE(res.e_00 == Approx(0.3846153846153f));
  REQUIRE(res.e_10 == Approx(0.2307692307692f));
  REQUIRE(res.e_01 == Approx(-0.076923076923f));
  REQUIRE(res.e_11 == Approx(0.1538461538461f));
}
//transpose
TEST_CASE("test_for_transposion", "[transpose]"){
  Mat2 a{1, 2, 3, 4};
  Mat2 res = transpose(a);
  REQUIRE(res.e_00 == a.e_00);
  REQUIRE(res.e_10 == a.e_01);
  REQUIRE(res.e_01 == a.e_10);
  REQUIRE(res.e_11 == a.e_11);
}
//rotation
TEST_CASE("test_for_rotation", "[rotation]"){
  float phi = 0.5;
  Mat2 rot = make_rotation_mat2(phi);
  REQUIRE(rot.e_00 == Approx(cos(0.5)));
  REQUIRE(rot.e_10 == Approx(-sin(0.5)));
  REQUIRE(rot.e_01 == Approx(sin(0.5)));
  REQUIRE(rot.e_11 == Approx(cos(0.5)));
}
//rgb 
TEST_CASE("test_rgb", "[rgb]"){
  rgb a;
  rgb b{0.2, 0.5, 0.65};
  REQUIRE(a.r == Approx(0.5f));
  REQUIRE(a.g == Approx(0.5f));
  REQUIRE(a.b== Approx(0.5f));
  REQUIRE(b.r == Approx(0.2));
  REQUIRE(b.g == Approx(0.5));
  REQUIRE(b.b == Approx(0.65));
}
//according to 2.8 no tests for rec and circ init needed


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
