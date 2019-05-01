#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "vec2.cpp"
#include "mat2.hpp"
#include "mat2.cpp"




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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
