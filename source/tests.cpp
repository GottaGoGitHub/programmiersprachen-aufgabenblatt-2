#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "vec2.cpp"


Vec2 a; 
Vec2 b{5.1f, -9.3f};

TEST_CASE("test_for_init", "[vec2]"){
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3 == Approx(b.y));
}


TEST_CASE("test_for_plus", "[plus]"){
  //init test vectors
  Vec2 op_test_plus{1.3f, 4.0f};
  Vec2 op_test_plus2{3.6f, 1.1f};
  op_test_plus += op_test_plus2;
  REQUIRE(op_test_plus.x == Approx(4.9f));
  REQUIRE(op_test_plus.y == Approx(5.1f));
}
TEST_CASE("test_for_minus", "[minus]"){
  Vec2 op_test_minus{4.0f , 3.0f};
  Vec2 op_test_minus2{2.5f, 1.0f};
  op_test_minus -= op_test_minus2;
  REQUIRE(op_test_minus.x == Approx(1.5f));
  REQUIRE(op_test_minus.y == Approx(2.0f));
}
TEST_CASE("test_for_mult", "[mult]"){
  Vec2 op_test_mult{4.0f , 3.0f};
  float s = 2.5f;
  op_test_mult *= s;
  REQUIRE(op_test_mult.x == Approx(10.0f));
  REQUIRE(op_test_mult.y == Approx(7.5f));
}
TEST_CASE("test_for_div", "[div]"){
  Vec2 op_test_div{4.0f , 3.0f};
  float s = 2.0f;
  op_test_div /= s;
  REQUIRE(op_test_div.x == Approx(2.0f));
  REQUIRE(op_test_div.y == Approx(1.5f));
}
TEST_CASE("test_free_add", "[add]"){
  Vec2 a{1.4f, 2.6f};
  Vec2 b{-4.2f, 5.6f};
  Vec2 res = a + b;
  REQUIRE(res.x == Approx(-2.8f));
  REQUIRE(res.y == Approx(8.2f));
}
TEST_CASE("test_free_sub", "[sub]"){
  Vec2 a{1.4f, 2.6f};
  Vec2 b{-4.2f, 5.6f};
  Vec2 res = a - b;
  REQUIRE(res.x == Approx(5.6f));
  REQUIRE(res.y == Approx(-3.0f));
}
TEST_CASE("test_free_mult", "[mult_free]"){
  Vec2 a{4.0f, 3.0f};
  float s = 2.5f;
  Vec2 res = a * s;
  REQUIRE(res.x == Approx(10.0f));
  REQUIRE(res.y == Approx(7.5f));
}
TEST_CASE("test_free_mult_reverse", "[mult_free_reverse]"){
  Vec2 a{4.0f, 3.0f};
  float s = 2.5f;
  Vec2 res = s * a;
  REQUIRE(res.x == Approx(10.0f));
  REQUIRE(res.y == Approx(7.5f));
}
TEST_CASE("test_free_div", "[div_free]"){
  Vec2 a{4.0f, 3.0f};
  float s = 2.0f;
  Vec2 res = a / s;
  REQUIRE(res.x == Approx(2.0f));
  REQUIRE(res.y == Approx(1.5f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
