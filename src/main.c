#include <raylib.h>
#include <stdio.h>
#include "logic.h"
#include "graphics.h"

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Aimlab 2D");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        draw_targets();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
