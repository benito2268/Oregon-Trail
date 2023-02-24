#include<iostream>
#include"vec2.hpp"
#include"window.hpp"

int main() {
    gfx::WOptions ops = {60, 30, 1920, 1080, false};
    gfx::Window win(ops, "Oregon Trailblazer", []() -> void {
        //do nothing right now
    });

    //temporary render loop
    while(!win.shouldClose()) {
        win.pollEvents();

        //do some rendering stuff
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        
        win.update();
    }
}