#include <stdlib.h>
#include <time.h>

#include "game.h"

int main(void)
{
    srandom(time(NULL));

    InitWindow(WIDTH, HEIGHT, "Aimlab 2D");
    SetTargetFPS(-1);

    init_target_pos();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);

        draw_targets();

        Vector2 mouse_pos = GetMousePosition();

        if (mouse_was_pressed(mouse_pos)) {
            int target_index = get_target_index(mouse_pos);
            change_pos(target_index);
        }

        show_score();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
