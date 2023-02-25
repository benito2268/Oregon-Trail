//main.cpp ~ the program's main class
#include<iostream>
#include"engine.hpp"
#include"window.hpp"
#include"funcs.hpp"

class Main : public GameLogic {
public:

    Main() = default;

    ~Main() override {

    }

    void init(gfx::Window& w, gfx::Scene& s, gfx::Renderer& r) override {

    }

    void input(gfx::Window& w, gfx::Scene& s, point_t diffTimeMillis) override {

    }

    void update(gfx::Window& w, gfx::Scene& s, point_t diffTimeMillis) override {

    }

    friend int main();
};


int main() {
    //create a game engine
    Main m;
    gfx::WOptions ops = {60, 30, 1280, 720, false};
    engine::Engine e("Oregon Trail", ops, m);
    e.start();
}
