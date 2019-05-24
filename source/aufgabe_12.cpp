#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <vector>
#include <algorithm>
#include <catch.hpp>
#include <cmath>

TEST_CASE("test for v_3")
{
    std::vector<int> v_1{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
    std::vector<int> v_2{9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
    std::vector<int> v_3(9);

    std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), [](int one, int two) {return one + two;});

    REQUIRE(std::all_of(v_3.begin(), v_3.end(), [](int three) {return three == 10;}));
}


int main(int argc, char* argv [])
{
    return Catch::Session().run(argc, argv);
}