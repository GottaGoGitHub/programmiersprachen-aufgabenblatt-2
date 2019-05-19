#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include "vec2.hpp"
#include "circle.hpp"
#include "mat2.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

TEST_CASE ("Sorted") {

    Vec2 center1{250, 300};
    Vec2 center2{450, 75};
    Vec2 center3{50, 470};

    rgb color1{1.0, 0.0, 0.0};
    rgb color2{0.0, 1.0, 0.0};
    rgb color3{0.0, 0.0, 1.0};

    Circle circle1{center1, 100, color1, "Karsten"};
    Circle circle2{center2, 200, color2, "Horst"};
    Circle circle3{center3, 50, color3, "Jochen"};

    std::vector<Circle> sorted_circles{circle1, circle2, circle3};
    std::sort(sorted_circles.begin(), sorted_circles.end());

    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}