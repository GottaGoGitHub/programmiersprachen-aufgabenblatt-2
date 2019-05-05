#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle{
    public:
        Circle():
        center_{1, 1}, radius_{1} {}
        Circle(Vec2 const& a, float const& radius):
        center_{a}, radius_{radius} {}
    public:

    private:
        float diameter, radius_;
        Vec2 center_;
};

#endif // CIRCLE_HPP