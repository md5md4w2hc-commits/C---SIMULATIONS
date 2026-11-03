#include "raylib.h"
#include <cmath>

int main(){
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Circulur Motion");
    SetTargetFPS(60);

    float cx = screenWidth / 2.0f; // centre of the orbit
    float cy = screenHeight / 2.0f;
    float R = 150; // orbit radius
    float angle = 0; // current angle (radians)
    float angularSpeed = 2.0f; // radians per second

    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        // Update
        angle += angularSpeed * dt;

        float x = cx + R * cos(angle);
        float y = cy + R * sin(angle);

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleLines((int)cx, (int)cy, R, DARKGRAY); // The path
        DrawCircle((int)cx, (int)cy, 5, WHITE); // The centre
        DrawLine((int)cx, (int)cy, (int)x, (int)y, GRAY); // The radius
        DrawCircle((int)x, (int)y, 20, RED); // The moving ball
        EndDrawing();
    }
    CloseWindow();
    return 0;
}