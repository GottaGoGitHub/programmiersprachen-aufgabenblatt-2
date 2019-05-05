#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"

class Rectangle{
    public: //constructor
        Rectangle(): //default
        min_{1, 1}, max_{2, 2} {}

        Rectangle(Vec2 const& a, Vec2 const& b): //member
        min_{a}, max_{a + b} {}

    public: //methods
        float circumference(Rectangle rec){
            float a = rec.max_.x - rec.min_.x;
            float b = rec.max_.y - rec.min_.y;
            float res = 2 * a * b;
            return res;
        }
    private:
        float length, height;
        Vec2 min_, max_, center;
        
};

#endif // RECTANGLE.HPP
