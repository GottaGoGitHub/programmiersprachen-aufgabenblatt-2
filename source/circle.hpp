#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cmath>
#include "vec2.hpp"
#include "color.hpp"

class Circle{
    public:
        Circle():
        center_{1, 1}, radius_{1}, color_{0.5, 0.5, 0.5} {}
        Circle(Vec2 const& a, float const& radius, rgb const& color):
        center_{a}, radius_{radius}, color_{color} {}
    public:
        float circumference(Circle circ){
            float res = 2 * M_PI * circ.radius_;
            return res;
        }
    private:
        float radius_;
        Vec2 center_;
        rgb color_;
};

#endif // CIRCLE_HPP