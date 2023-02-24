//window.hpp - represents a GLFW render window
#pragma once
#include<glad/glad.h>
#include<glfw/glfw3.h>

namespace utils { template<typename T> struct vec2; }

namespace gfx {
    typedef void function_t(void);

    struct WOptions {
        int fps;
        int ups;
        int width;
        int height;
        bool compat;
    };

    class Window {
    private:
        WOptions ops;
        GLFWwindow* handle;
        function_t* resizeFunc;
        int width;
        int height;

    public:
        Window(WOptions& ops, const char* title, function_t* resizeFunc);
        ~Window();

        utils::vec2<int> getSize();
        bool isKeyPressed(GLuint keyCode);
        void pollEvents();
        void resized(utils::vec2<int> newSize);
        void update();
        bool shouldClose();
    };
}
