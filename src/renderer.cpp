//renderer.cpp - implements a simple 2d (or maybe 3d) renderer
#include"renderer.hpp"
#include<glad/glad.h>

namespace gfx {

    Renderer::Renderer() {

    }

    Renderer::~Renderer() {

    }

    void Renderer::render(Window& window, Scene& scene) {
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    }

}
