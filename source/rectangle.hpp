#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{
    public: //constructor
        Rectangle(): //default
        min_{1, 1}, max_{2, 2}, color_{0.8, 0.2, 0.3} {}

        Rectangle(Vec2 const& a, Vec2 const& b, rgb const& color): //member
        min_{a}, max_{a + b}, color_{color} {}

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
        rgb color_;
        
};

#endif // RECTANGLE.HPP
