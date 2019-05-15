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
        void draw(Window const& window, rgb const& color_) const{
	        for (int i = 0; i < 360; i++){
		        // Grad zu Bogenmaß
		        float grad1 = i * M_PI / 180.0f;
		        float grad2 = (i + 1) * M_PI / 180.0f;

		        window.draw_line(center_.x + (radius_*sin(grad1)), center_.y + (radius_*cos(grad1)), center_.x + (radius_*sin(grad2)), center_.y + (radius_*cos(grad2)), color_.r, color_.g, color_.b);
	        }
        }
    private:
        float radius_;
        Vec2 center_;
        rgb color_;
};

#endif // CIRCLE_HPP