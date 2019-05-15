#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <GLFW/glfw3.h>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Rectangle{
    public: //constructor
        Rectangle(): //default
        min_{1, 1}, max_{2, 2}, color_{0.8, 0.2, 0.3} {}

        Rectangle(Vec2 const& a, Vec2 const& b, rgb const& color): //member
        min_{a.x, a.y}, max_{a.x + b.x, a.y + b.y}, color_{color} {}

    public: //methods
        float circumference(Rectangle rec){
            float a = rec.max_.x - rec.min_.x;
            float b = rec.max_.y - rec.min_.y;
            float res = 2 * a * b;
            return res;
        }
        void draw(Window const& win, Rectangle rec, rgb color){
            win.draw_line(rec.min_.x, rec.min_.y, rec.max_.x, rec.min_.y, color.r, color.g, color.b, 1.0f);
            win.draw_line(rec.max_.x, rec.min_.y, rec.max_.x, rec.max_.y, color.r, color.g, color.b, 1.0f);
            win.draw_line(rec.min_.x, rec.min_.y, rec.min_.x, rec.max_.y, color.r, color.g, color.b, 1.0f);
            win.draw_line(rec.min_.x, rec.max_.y, rec.max_.x, rec.max_.y, color.r, color.g, color.b, 1.0f);
            return;
        }
        void draw(Window const& win, Rectangle rec, rgb color, float thickness){
            win.draw_line(rec.min_.x, rec.min_.y, rec.max_.x, rec.min_.y, color.r, color.g, color.b, thickness);
            win.draw_line(rec.max_.x, rec.min_.y, rec.max_.x, rec.max_.y, color.r, color.g, color.b, thickness);
            win.draw_line(rec.min_.x, rec.min_.y, rec.min_.x, rec.max_.y, color.r, color.g, color.b, thickness);
            win.draw_line(rec.min_.x, rec.max_.y, rec.max_.x, rec.max_.y, color.r, color.g, color.b, thickness);
            return;
        }
        bool isInside(Vec2 a){
            if(a.x > min_.x && a.x < max_.x){
                if(a.y > min_.y && a.y < max_.y){
                    return true;
                }
            }
            else{
                return false;
            }
        }
    private:
        float length, height;
        Vec2 min_, max_, center;
        rgb color_;
        
};

#endif // RECTANGLE.HPP
