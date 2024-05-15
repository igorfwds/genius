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
    printf("\n=> ");
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

char *play_game(color **head, color **tail, color **head_input, color **tail_input,int level) {
    char *name = (char*) malloc(50 * sizeof(char));
    int game_over = 0;
    while (!game_over) {

        int new_color;
        for (int i = 0; i < level; i++) {
            new_color = (rand() % 4) + 1;
            color_init(head, tail, new_color);
        }
        
        print_sequence(*head);
        sleep(1);
        clear_terminal();


        int player_input;
        for(int i = 0; i < (*head)->len; i++){
            scanf("%d", &player_input);
            color_init(head_input, tail_input, player_input);
        }
        getc(stdin);
        if((*head)->len != (*head_input)->len){
            printf("\nSequência incorreta. Fim de jogo.\n");
            printf("Digite seu nome para ser adicionado ao Ranking: ");
            scanf("%s", name);
            sleep(1);
            printf("\n[pressione a tecla 'ENTER' para voltar ao menu principal]\n");
            return name;
        }

        int is_equal = compare_input_sequence(*head, *tail, *head_input, *tail_input);
        if (is_equal == 1 && (*tail_input)->len == (*tail)->len) {
            printf("\nParabéns, você acertou, vamos continuar!\n");
            
        } else {
            printf("\nSequência incorreta. Fim de jogo.\n");
            game_over = 1;  
            printf("Digite seu nome para ser adicionado ao Ranking: ");
            scanf("%s", name);
            sleep(1);
            printf("\n[pressione a tecla 'ENTER' para voltar ao menu principal]\n");
           
        }


        free_list(*head_input);
        *head_input = NULL;
        *tail_input = NULL;
        
    }

    free_list(*head);
    *head = NULL;
    *tail = NULL;
    return name;
}

void clear_terminal() {
    // Verifica se o sistema operacional é Windows
    #ifdef _WIN32
        system("cls");
    // Verifica se o sistema operacional é Unix/Linux
    #else
        system("clear");
    #endif

}
