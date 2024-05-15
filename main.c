#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "genius.h"

int main(){
    srand(time(NULL));
    color *head = NULL;
    color *tail = NULL;
    color *head_input = NULL;
    color *tail_input = NULL;
    char *player_name = NULL;

    while(1){
        int option = show_menu();
        if(option == '1'){
           int level;
            while(1){
                level = show_sub_menu() - '0';
                if(level == 1 || level == 2 || level == 3){
                    break;
                }
            }
            //game_init_with_level(level, &head, &tail);
            
            player_name = play_game(&head, &tail, &head_input, &tail_input, level);
            getc(stdin);
            sleep(1);
            getc(stdin); 
            FILE *file = fopen("scores.txt", "a");
            if (file == NULL) {
                printf("Não foi possível abrir o arquivo scores.txt\n");
                return 1;
            }

            fprintf(file, "Nome: %s, Pontuação: missing\n", player_name);

            fclose(file);
        }else if(option == '2'){
            explain_the_game();
            if(getchar() == '\n'){
                continue;
            }
        }else if(option == '3'){
            break;
        }
    }    
    return 0;
}