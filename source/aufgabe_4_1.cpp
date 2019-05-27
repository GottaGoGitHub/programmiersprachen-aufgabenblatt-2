#include <iostream>
#include <set>

#include "circle.hpp"
#include "color.hpp"
#include "vec2.hpp"

bool insert(std::set<Circle>& set, Circle const& circle){
    bool value = true;
    for(Circle reference: set){
        if(circle.getName() == reference.getName()){
            value = false;
        }
    }
    if(value){
        set.insert(circle);
    }
    else{
        std::cout << "This circle already exists." << std::endl;
    }

}

Circle check_name(std::string name, std::set<Circle> set){
    if(name == ""){
        std::cout << "Please enter at least 1 character." << std::endl;
    }
    else{
        for(Circle i: set){
            if(i.getName() == name){
                std::cout << i << std::endl;
            }
        }
    }
}

int main(){
    Vec2 center1{250, 300};
    Vec2 center2{450, 75};
    Vec2 center3{50, 470};

    rgb color1{1.0, 0.0, 0.0};
    rgb color2{0.0, 1.0, 0.0};
    rgb color3{0.0, 0.0, 1.0};

    Circle circle1{center1, 100, color1, "Karsten"};
    Circle circle2{center2, 200, color2, "Horst"};
    Circle circle3{center3, 50, color3, "Jochen"};

    std::cout << circle1 << std::endl;
    std::cout << circle2 << std::endl;
    std::cout << circle3 << std::endl;

    std::set<Circle> circle_list;

    insert(circle_list, circle1);
    insert(circle_list, circle2);
    insert(circle_list, circle3);
    
    std::string name;
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;

    check_name(name, circle_list);

    return 0;
}






