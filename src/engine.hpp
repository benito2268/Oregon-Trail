//engine.hpp - defines for the "engine" class representing a simple single threaded game engine
#pragma once
#include<string>

namespace gfx {
    struct WOptions;
    class Window;
    class Renderer;
    class Scene;
}

class GameLogic;

namespace engine {
    class Engine {
    private:
        static inline const int TARGET_UPS = 30;
        GameLogic* g;
        gfx::Renderer* renderer;
        gfx::Window* window;
        gfx::Scene* scene;
        bool running;
        int target_fps;
        int target_ups;

        void run();
        static void resize();
        
    public:
        Engine(std::string winTitle, gfx::WOptions ops, GameLogic& g);
        ~Engine();

        void start();
        void stop();
    };
} 
