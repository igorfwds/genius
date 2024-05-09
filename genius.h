#ifndef GENIUS_H
#define GENIUS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct color{
    int color_id;
    struct color *next;
} color;

void color_init(color **head, color **tail, int arg_color);
color *game_init_with_level(int level, color **head, color **tail);
int show_menu();

#endif // GENIUS_H
