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
        new->len = 0; 
        new->next = NULL; // Garanta que o próximo nó seja inicializado como NULL
        
        if(*head == NULL){
            *head = new;
            *tail = new;
            (*head)->len = 1;
        }else{
            (*head)->len += 1;
            (*tail)->next = new;
            *tail = new;
        }
    }
}



void print_sequence(color *head){
    do{
        printf("%d ", head->color_id);
        head = head->next;
    }while(head != NULL);
}

void game_init_with_level(int level, color **head, color **tail){
    // Liberar memória se já estiver alocada
    if (*head != NULL) {
        // Implemente a função de liberação de memória adequada
        // Por exemplo, uma função chamada free_list que libera todos os elementos da lista
        free_list(*head);
        *head = NULL;
    }
    if (*tail != NULL) {
        free_list(*tail);
        *tail = NULL;
    }

    // Lógica para cada nível
    if (level == 1){
        for(int i = 0; i < 4; i++){
            color_init(head, tail, (rand() % 4) + 1);
            
        }
    } else if (level == 2){
        for(int i = 0; i < 8; i++){
            color_init(head, tail, (rand() % 4) + 1);
        }
    } else if (level == 3){
        for(int i = 0; i < 12; i++){
            color_init(head, tail, (rand() % 4) + 1);
        }
    }
}


int show_menu(){
    int option;
    while(1){
        printf("\n Aproveite o Genius!");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\nDigite [1] para jogar!");
        printf("\nDigite [2] para entender o jogo!");
        printf("\nDigite [3] para sair do jogo!\n=> ");
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

int show_sub_menu(){
    int option;
    while(1){
        printf("\n ESCOLHA O NIVEL DO JOGO!");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\nDigite [1] para começar o level 1!");
        printf("\nDigite [2] para começar o level 2!");
        printf("\nDigite [3] para começar o level 3!\n=> ");
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

void free_list(color *head) {
    color *current = head;
    color *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
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

    // Liberar memória alocada para as sequências de entrada
    free_list(head_input);
    free_list(head);
}

