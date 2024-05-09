#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "genius.h"

void color_init(color **head, color **tail, int arg_color){
    color *new = (color*) malloc(sizeof(color));
    if (new!= NULL){
        new->color_id = arg_color;
        if(*head == NULL){
            *head = new;
            *tail = new;
        }else{
            (*tail)->next = new;
            *tail = new;
        }
        new->next = NULL;
        printf("\n%d\n", arg_color );
    }
}

color *game_init_with_level(int level, color **head, color **tail){
    if (level == 1){
        for(int i = 0; i < 4; i++){
            color_init(head, tail, rand() % 4);
            sleep(1);
        }
        return *head;
    }
    return NULL;
}

int show_menu(){
    int option;
    while(1){
        printf("\n Aproveite o Genius!");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\nDigite [1] para jogar!");
        printf("\nDigite [2] para jogar!");
        printf("\nDigite [3] para sair do jogo!");
        option = getchar();
        getc(stdin);
        if(option != '1' && option != '2' && option != '3'){
            printf("\n\t-----------------------");
            printf("\n\t|ERRO! Opção inválida!|");
            printf("\n\t-----------------------");
        }else{
            return option;
        }
    }
}
