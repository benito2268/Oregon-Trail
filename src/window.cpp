//window.cpp - represents a GLFW window
#include<iostream>
#include<stdexcept>
#include"window.hpp"
#include"vec2.hpp"

namespace gfx {
    //construct and initailize the window
    Window::Window(WOptions& ops, const char* title, function_t* resizeFunc) {
        //initialize glfw and set window hints
        if(!glfwInit()) {
            std::cerr << "[error] glfw window initialization failed";
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //opengl version 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        if(ops.compat) {
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        } else {
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        }

        //set gl profile
        if(ops.width > 0 && ops.height > 0) {
            this->width = ops.width;
            this->height = ops.height;
        } else {
            glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
            GLFWvidmode* vidMode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
            width = vidMode->width;
            height = vidMode->height;
        }
        
        //create window and set callbacks
        handle = glfwCreateWindow(this->width, this->height, title, nullptr, nullptr);
        if(handle == NULL) {
            throw std::runtime_error("[fatal] glfw window creation failed");
        }

        //set window pointer so we can recover the this ptr to use in lambdas
        glfwSetWindowUserPointer(handle, static_cast<void*>(this));

        glfwMakeContextCurrent(handle);
        glfwSetFramebufferSizeCallback(handle, [](GLFWwindow* handle, int w, int h) -> void {
            auto self = static_cast<Window*>(glfwGetWindowUserPointer(handle));
            self->resized(utils::vec2<int>(w, h));
        });

        //load opengl function ptrs
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("[fatal] could not load opengl function pointers");
        }
    }

    //clear up all of the pointers
    Window::~Window() {
        glfwTerminate();
    }

    utils::vec2<int> Window::getSize() {
        return utils::vec2<int>(this->width, this->height);
    }

    bool Window::isKeyPressed(GLuint keyCode) {
        return glfwGetKey(this->handle, keyCode) == GLFW_PRESS;
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    void Window::resized(utils::vec2<int> newSize) {
        this->width = newSize.x;
        this->height = newSize.y;
        try {
            resizeFunc();
        } catch(const std::exception& e) {
            std::cerr << "glfw resize call failed: " << e.what();
        }
    }

    void Window::update() {
        glfwSwapBuffers(handle);
    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(this->handle);
    }
}