#ifndef GENIUS_H
#define GENIUS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct color{
    int color_id;
    int len;
    struct color *next;
} color;

void color_init(color **head, color **tail, int arg_color);
color *game_init_with_level(int level, color **head, color **tail);
int show_menu();
int compare_input_sequence(color *head_1, color *tail_1, color *tail_2, color *head_2);
void finish_the_game(color *head, color *tail, color *head_input, color *tail_input);

#endif // GENIUS_H
