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

    int option = show_menu();
    if(option == '1'){
        game_init_with_level(1, &head, &tail);
        print_sequence(head);
        // depois de exibir as cores, limpa  tudo pro usuario não ter cola.
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
    }
    
    return 0;
}
