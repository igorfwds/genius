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
            (*head)->len = 1;
        }else{
            (*head)->len += 1;
            (*tail)->next = new;
            *tail = new;
        }
        new->next = NULL;
    }
}

void print_sequence(color *head){
    do{
        printf("%d ", head->color_id);
        head = head->next;
    }while(head != NULL);
}

color *game_init_with_level(int level, color **head, color **tail){
    //fazer logica para  cada level
    if (level == 1){
        for(int i = 0; i < 4; i++){
            color_init(head, tail, (rand() % 4) + 1);
            
        }
        return *head;
    } else if (level == 2){
        for(int i = 0; i < 8; i++){
            color_init(head, tail, (rand() % 4) + 1);
        }
        return *head;
    } else if (level == 3){
        for(int i = 0; i < 12; i++){
            color_init(head, tail, (rand() % 4) + 1);
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

void explain_the_game(){
    printf("\n EXPLICANDO O JOGO...");
    printf("\n[pressione a tecla 'ENTER' para voltar ao menu principal]\n");
}

int compare_input_sequence(color *head_1, color *tail_1, color *head_2, color *tail_2){
    color *aux_1 = head_1;
    color *aux_2 = head_2;
    int is_equal = 1;
    while(aux_1 != NULL && aux_2 != NULL){
        if(aux_1->color_id != aux_2->color_id){
            is_equal = 0;
            return is_equal;
        }
        aux_1 = aux_1->next; 
        aux_2 = aux_2->next; 
    }
    
    return is_equal;
}


void finish_the_game(color *head, color *tail, color *head_input, color *tail_input) {
    int is_equal = compare_input_sequence(head, tail, head_input, tail_input);
    if (is_equal == 1) {
        if (tail_input->len == tail->len) {
            printf("\nParabéns, você ganhou, vamos continuar!\n");
        } else {
            printf("\nSequência incorreta. Tente novamente.\n");
        }
    } else {
        printf("\nSequência incorreta. Tente novamente.\n");
    }
}

