#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <iostream>
#include "window.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "circle.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {

    if (win.get_key(GLFW_KEY_ESCAPE  ) == GLFW_PRESS) {
      win.close();
    }
    

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    
    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    0.0,1.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    float thickness = 2.5f;
    Vec2 a{50, 50};
    Vec2 b{200, 250};
    rgb light_blue{0.2, 0.8, 0.8};
    rgb red{1.0, 0.0, 0.0};
    Rectangle rec{a, b, light_blue};
    rec.draw(win, rec, light_blue, thickness);

    Vec2 circle_center{550, 300};
    Circle circle{circle_center, 100, red};
    circle.draw(win, red, 3.5);

    Vec2 ist_er_schon_drin{175, 210};
    if(rec.isInside(ist_er_schon_drin) == true){
      win.draw_point(ist_er_schon_drin.x, ist_er_schon_drin.y, 1.0, 0.0, 0.5);
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
  

    win.update();
  }

  return 0;
}
