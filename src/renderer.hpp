//renderer.hpp - defines a rendering class to store graphics data
#pragma once

namespace gfx {

    class Window;
    class Scene;

    class Renderer {
    public:
        Renderer();
        ~Renderer();
        void render(Window& window, Scene& scene);
    };
}
