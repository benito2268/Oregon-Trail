//funcs.hpp - implementable logic for main class
//note: this is an abstract class
#pragma once
#include<chrono>

namespace gfx {
    class Window;
    class Renderer;
    class Scene;
}

namespace engine { class Engine; }

typedef std::chrono::duration<float, std::milli> point_t;

class GameLogic { //no cleanup func use destructor
protected:
    virtual void init(gfx::Window& w, gfx::Scene& s, gfx::Renderer& r) = 0;
    virtual void input(gfx::Window& w, gfx::Scene& s, point_t diffTimeMillis) = 0;
    virtual void update(gfx::Window& w, gfx::Scene& s, point_t diffTimeMillis) = 0;
    virtual ~GameLogic() {};

    friend class engine::Engine;
};
