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
    int current_color_input;
    int is_equal;

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
            game_init_with_level(level, &head, &tail);
            print_sequence(head);
            sleep(1);
            printf("\nDigite a sequencia atual: ");
            while(1){
                scanf("%d", &current_color_input);
                if(current_color_input == 0){
                    break;
                }
                color_init(&head_input, &tail_input, current_color_input);
                if(head_input->len == head->len){
                    break;
                }
            }
            finish_the_game(head, tail, head_input, tail_input);
            
            getc(stdin); 
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

