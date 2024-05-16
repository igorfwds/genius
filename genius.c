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
        new->next = NULL; 
        
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

void add_player(player **head,player **tail,char *player_name, int player_score ){
    player *new = (player*) malloc(sizeof(player));
    if (new!= NULL){
        new->name = player_name;
        new->score = player_score;
        new->next = NULL; 
        
        if(*head == NULL){
            *head = new;
            *tail = new;
        }else{
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
void print_player(player *head){
    do{
        printf("\n%s=> %d ", head->name, head->score);
        head = head->next;
    }while(head != NULL);
}


int show_menu(){
    int option;
    while(1){
        clear_terminal();
        printf("\n Aproveite o Genius!");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\nDigite [1] para jogar!");
        printf("\nDigite [2] para entender o jogo!");
        printf("\nDigite [3] para ver o ranking!");
        printf("\nDigite [4] para sair do jogo!\n=> ");
        option = getchar();
        getc(stdin);
        if(option != '1' && option != '2' && option != '3' && option != '4'){
            printf("\n\t-----------------------");
            printf("\n\t|ERRO! Opção inválida!|");
            printf("\n\t-----------------------");
        }else{
            return option;
        }
    }
}

void explain_the_game(){
    clear_terminal();
    printf("\n EXPLICANDO O JOGO...");
    printf("\n --------------------\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------------");
    printf("\n|Genius é um jogo de memória.Primeiramente você irá selecionar o nivel que vai jogar.                                      |\n|O nivelamento funciona da seguinte forma:                                                                                 |\n|No nivel 1 ele disponibilizara 1 cor a cada round para você acertar.                                                      |\n|No nivel 2, 2 cores cada round                                                                                            |\n|No 3º nivel 3 cores por round.                                                                                            |\n|Após a sequência de cores que será exibida na tela, sua tarefa é lembrar e repetir essa sequência.                        |\n|O jogo continua até que você erre a sequência.                                                                            |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n--------------\n");
    printf("|BOA SORTE...|");
    printf("\n--------------\n");
    printf("\n[pressione a tecla 'ENTER' para voltar ao menu principal]\n");
}

int show_sub_menu(){
    int option;
    while(1){
        clear_terminal();
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


    free_list(head_input);
    free_list(head);
}

char *play_game(color **head, color **tail, color **head_input, color **tail_input,int level, int *game_score) {
    char *name = (char*) malloc(50 * sizeof(char));
    int game_over = 0;
    *game_score = 0;
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
            *game_score += level;
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

    #ifdef _WIN32
        system("cls");

    #else
        system("clear");
    #endif

}

void insertion_sort(player **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    player *sorted = NULL;
    player *current = *head;
    while (current != NULL) {
        player *next = current->next;

        if (sorted == NULL || sorted->score < current->score) {
            current->next = sorted;
            sorted = current;
        } else {
            player *temp = sorted;
            while (temp != NULL) {
                if (temp->next == NULL || temp->next->score < current->score) {
                    current->next = temp->next;
                    temp->next = current;
                    break;
                }
                temp = temp->next;
            }
        }
        current = next;
    }
    *head = sorted;
}


void read_file_to_list(player **head, player **tail, FILE *file) {
    char name[50];
    int score;
    while (fscanf(file, "%s %d", name, &score) != EOF) {
        char *player_name = malloc(strlen(name) + 1);
        if (player_name != NULL) {
            strcpy(player_name, name);
            add_player(head, tail, player_name, score);
        }
    }
}

void write_list_to_file(player *head, FILE *file) {
    player *current = head;
    while (current != NULL) {
        fprintf(file, "%s %d\n", current->name, current->score);
        current = current->next;
    }
}

void handle_game_over(player **head, player **tail, char *filename, char *player_name, int player_score) {
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }
    clear_list(head);
    read_file_to_list(head, tail, file);
    
    fclose(file);
    remove(filename);
 

    add_player(head, tail, player_name, player_score);
    insertion_sort(head);

    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    
    write_list_to_file(*head, file);

    
    fclose(file);
}
void clear_list(player **head) {
    player *current = *head;
    while (current != NULL) {
        player *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void show_rank(player *head){
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", "scores.txt");
        return;
    }
    clear_terminal();
    print_players_from_file(file);
    fclose(file);
    printf("\n[pressione a tecla 'ENTER' para voltar ao menu principal]\n");
}

void print_players_from_file(FILE *file) {
    char name[50];
    int score;
    int place = 1;

    printf("RANKING DOS GENIUS:\n");
    printf("-------------------\n");
    while (fscanf(file, "%s %d", name, &score) != EOF) {
        printf("%d) %s => %d pontos\n", place, name, score);
        place++;
    }
}