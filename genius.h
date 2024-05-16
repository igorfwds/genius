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

typedef struct player{
    char *name;
    int score;
    struct player *next;
}player;

void color_init(color **head, color **tail, int arg_color);
void game_init_with_level(int level);
int show_menu();
void explain_the_game();
int show_sub_menu();
int compare_input_sequence(color *head_1, color *tail_1, color *tail_2, color *head_2);
void free_list(color *head);
void finish_the_game(color *head, color *tail, color *head_input, color *tail_input);
void print_sequence(color *head);
char *play_game(color **head, color **tail, color **head_input, color **tail_input,int level, int *game_score);
void clear_terminal();
void add_player(player **head,player **tail,char *player_name, int player_score );
void print_player(player *head);
void insertion_sort(player **head);
void read_file_to_list(player **head, player **tail, FILE *file);
void write_list_to_file(player *head, FILE *file);
void handle_game_over(player **head, player **tail, char *filename, char *player_name, int player_score);
void clear_list(player **head);
void show_rank(player *head);
void print_players_from_file(FILE *file);

#endif // GENIUS_H
