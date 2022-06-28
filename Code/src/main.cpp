#include <iostream>
#include <raylib.h>

#include "Math.hpp"

Math::Vec2<int> windowSize;
int main() {
    while (true) {
        std::cout << "Welcome to chess!\n";


        while (true) {
            if (WindowShouldClose()) goto endGame;
            BeginDrawing();
                ClearBackground(BLACK);
            EndDrawing();
        }
endGame:
        CloseWindow();
    }

exit:
    CloseWindow();
    return 0;
}