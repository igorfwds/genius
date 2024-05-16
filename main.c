#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "genius.h"

int main()
{
    srand(time(NULL));
    color *head = NULL;
    color *tail = NULL;
    color *head_input = NULL;
    color *tail_input = NULL;
    player *head_player = NULL;
    player *tail_player = NULL;
    char *player_name = NULL;
    
    while (1)
    {
        int option = show_menu();
        if (option == '1')
        {
            int level;
            int score;
            while (1)
            {
                level = show_sub_menu() - '0';
                if (level == 1 || level == 2 || level == 3)
                {
                    break;
                }
            }
            player_name = play_game(&head, &tail, &head_input, &tail_input, level, &score);

            FILE *file = fopen("scores.txt", "r");

            if (file == NULL)
            {
                file = fopen("scores.txt", "a");
            }

            fclose(file);


            handle_game_over(&head_player, &tail_player, "scores.txt", player_name, score);

            getc(stdin);
            sleep(1);
            getc(stdin);
        }
        else if (option == '2')
        {
            explain_the_game();
            if (getchar() == '\n')
            {
                continue;
            }
        }else if(option == '3'){
            show_rank(head_player);
            if (getchar() == '\n')
            {
                continue;
            }
        }
        else if (option == '4')
        {
            break;
        }
    }

    return 0;
}