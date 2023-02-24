//renderer.hpp - defines a rendering class to store graphics data
#pragma once

namespace gfx {

    class Window;
    class Scene;

    class Renderer {
    public:
        void render(Window& window, Scene& scene);
    };
}
