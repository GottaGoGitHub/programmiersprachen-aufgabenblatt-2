#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include "circle.hpp"

TEST_CASE("sorting for radius"){
    Vec2 center1{250, 300};
    Vec2 center2{450, 75};
    Vec2 center3{50, 470};

    rgb color1{1.0, 0.0, 0.0};
    rgb color2{0.0, 1.0, 0.0};
    rgb color3{0.0, 0.0, 1.0};

    Circle circle1{center1, 100, color1, "Karsten"};
    Circle circle2{center2, 200, color2, "Horst"};
    Circle circle3{center3, 50, color3, "Jochen"};

    std::vector<Circle> sorted{circle1, circle2, circle3};

    std::sort(sorted.begin(), sorted.end(), [](const Circle &one, const Circle &two){
        return one.getRadius() < two.getRadius();
    });

    REQUIRE(std::is_sorted(sorted.begin(), sorted.end()));
}

int main(int argc, char* argv[]){
    return Catch::Session().run(argc, argv);
}