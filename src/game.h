#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>

#define WIDTH 2000
#define HEIGHT 1125
#define RADIUS 30

typedef struct {
    Vector2 center;
} Target;

void init_target_pos(void);
void draw_targets();
int mouse_was_pressed(Vector2 mouse_pos);
int get_target_index(Vector2 mouse_pos);
void change_pos(int target_index);
void show_score(void);

#endif // GAME_H
