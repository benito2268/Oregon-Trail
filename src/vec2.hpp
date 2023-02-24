//vec2.hpp - represents a 2-vector of any type
#pragma once

namespace utils {
    template<typename T>
    struct vec2 {
        T x;
        T y;

        vec2(T x, T y) {
            this->x = x;
            this->y = y;
        }

        vec2 operator+ (const vec2& other) {
            vec2 sum(0, 0);
            sum.x = this->x + other.x;
            sum.y = this->y + other.y;
            return sum;
        }

        bool operator== (const vec2& other) {
            if(this->x == other.x && this->y == other.y) {
                return true;
            } else {
                return false;
            }
        }
    };
}