//engine.cpp - implementation of a single thread, 2d, very simple one file game engine
#include<chrono>
#include<iostream>
#include"engine.hpp"
#include"funcs.hpp"
#include"window.hpp"
#include"renderer.hpp"
#include"scene.hpp"

namespace engine {
    //constructor
    Engine::Engine(std::string winTitle, gfx::WOptions ops, GameLogic& g) {
        window = new gfx::Window(ops, "Oregon Trailblazer", []() -> void {
            //possibly fix this?
            Engine::resize();
        });

        target_fps = ops.fps;
        target_ups = ops.ups;
        this->g = &g;
        renderer = new gfx::Renderer();
        scene = new gfx::Scene();

        this->g->init(*window, *scene, *renderer);
        running = true;
    }

    //destructor
    Engine::~Engine() {
        delete this->scene;
        delete this->renderer;
        delete this->window;
    }

    void Engine::run() {
        using namespace std::chrono;
        auto time_init = high_resolution_clock::now();
        float time_u = 1000.f / target_ups;
        float time_r = target_fps > 0 ? 1000.0f / target_fps : 0;
        float deltaUpdate;
        float deltaFps;

        auto update_time = time_init;
        while(running && !window->shouldClose()) {
            window->pollEvents();

            auto now = high_resolution_clock::now();
            deltaUpdate += (duration_cast<milliseconds>(now - time_init).count()) / time_u;
            deltaFps += (duration_cast<milliseconds>(now - time_init).count()) / time_r;

            if(target_fps <= 0 || deltaFps >= 1) {
                this->g->input(*window, *scene, duration_cast<milliseconds>(now - time_init));
            }

            if(deltaUpdate >= 1) {
                duration<float, std::milli> diffTime = duration_cast<milliseconds>(now - update_time);
                this->g->update(*window, *scene, diffTime);
                update_time = now;
                deltaUpdate--;
            }

            if(target_fps <= 0 || deltaFps >= 1) {
                //render time
                renderer->render(*window, *scene);
                deltaFps--;
                window->update();
            }
            time_init = now;
        }
    }

    void Engine::resize() {
        //nothing yet
    }

    void Engine::start() {
        running = true;
        run();
    }

    void Engine::stop() {
        running = false;
    }
}
