#include "raylib.h"
#include <cmath>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pendulum Physics Lab");
    SetTargetFPS(60);

    Vector2 origin = { (float)screenWidth / 2, 100.0f };
    float length = 250.0f;
    float angle = PI / 4; 
    float aVelocity = 0.0f;
    float aAcceleration = 0.1f;
    float gravity = 1.5f; 

    while (!WindowShouldClose()) {
        aAcceleration = (-gravity / length) * sin(angle);
        aVelocity += aAcceleration;
        angle += aVelocity;
        aVelocity *= 0.995f; 

        Vector2 bob;
        bob.x = origin.x + length * sin(angle);
        bob.y = origin.y + length * cos(angle);

        BeginDrawing();
        ClearBackground(BLACK); 
        DrawLineEx(origin, bob, 2.0f, GREEN); 
        DrawCircleV(bob, 20.0f, DARKGREEN);   
        DrawCircleV(origin, 5.0f, GREEN);     
        DrawText("Pendulum Kinematics", 10, 10, 20, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
