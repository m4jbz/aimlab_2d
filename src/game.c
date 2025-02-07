#include "game.h"

Target targets[4];
int points = 0;

void get_random_pos(Vector2* pos)
{
    int lower = RADIUS;

    long x = random() % (WIDTH - (2*lower) + 1) + lower;
    long y = random() % (HEIGHT - (2*lower) + 1) + lower;

    pos->x = (float)x;
    pos->y = (float)y;
}

void init_target_pos(void)
{
    int targets_overlap;

    for (int i = 0; i < 4; i++) {
        do {
            targets_overlap = 0;
            get_random_pos(&targets[i].center);

            for (int j = 0; j < i; j++) {
                if (j == i) continue;

                if (CheckCollisionCircles(targets[i].center, RADIUS, targets[j].center, RADIUS)) {
                    targets_overlap = 1;
                    break;
                }
            }
        } while (targets_overlap);
    }
}

void draw_targets()
{
    for (int i = 0; i < 4; i++) {
        DrawCircleV(targets[i].center, RADIUS, BLUE);
    }
}

int mouse_was_pressed(Vector2 mouse_pos)
{
    int is_mouse_over = 0;

    for (int i = 0; i < 4; i++) {
        is_mouse_over = CheckCollisionPointCircle(mouse_pos, targets[i].center, RADIUS) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (is_mouse_over) {
            points++;
            break;
        }
    }

    return is_mouse_over;
}

int get_target_index(Vector2 mouse_pos)
{
    int index = 0;
    int is_mouse_over = 0;

    for (int i = 0; i < 4; i++) {
        is_mouse_over = CheckCollisionPointCircle(mouse_pos, targets[i].center, RADIUS);

        if (is_mouse_over) {
            index = i;
            break;
        }
    }

    return index;
}

void change_pos(int target_index)
{
    int targets_overlap;

    do {
        targets_overlap = 0;
        get_random_pos(&targets[target_index].center);

        for (int i = 0; i < 4; i++) {
            if (i == target_index) continue;

            if (CheckCollisionCircles(targets[target_index].center, RADIUS, targets[i].center, RADIUS)) {
                targets_overlap = 1;
                break;
            }
        }
    } while (targets_overlap);
}

void show_score(void)
{
    char* score = malloc(128);
    snprintf(score, 128, "score = %d\n", points);

    DrawText(score, WIDTH-150, 10, 25, RED);

    free(score);
}
