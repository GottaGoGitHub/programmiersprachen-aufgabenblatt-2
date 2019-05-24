#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

bool is_even(int i){
    return i % 2 == 0;
}

template<typename container, typename condition>
std::vector<int> filter(container &cont, condition cond){
    for(int i = 0; i < cont.size(); i++){
        if(cond(cont.at(i)) == false){
            cont.erase(cont.begin()+i);
        }
    }
    return cont;
}

TEST_CASE("test for filter"){
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    std::vector<int> all_even = filter(vec, is_even);

    REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
}

int main(int argc, char* argv []){
    return Catch::Session().run(argc, argv);
}

