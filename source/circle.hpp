#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cmath>
#include "vec2.hpp"

class Circle{
    public:
        Circle():
        center_{1, 1}, radius_{1} {}
        Circle(Vec2 const& a, float const& radius):
        center_{a}, radius_{radius} {}
    public:
        float circumference(Circle circ){
            float res = 2 * M_PI * circ.radius_;
            return res;
        }
    private:
        float radius_;
        Vec2 center_;
};

#endif // CIRCLE_HPP