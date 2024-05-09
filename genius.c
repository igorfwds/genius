#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct color{
    int color_id;
    color *next;
}color;

void color_init(color **head, color **tail,int arg_color);

void color_init(color **head, color **tail,int arg_color){
    color *new = (color*) malloc(sizeof(color));
    if (new != NULL){
        new->color_id = arg_color;
        if(*head == NULL){
            *head = new;
        }else{
            (*tail)->next = new;
        }
        *tail = new;
        new->next = NULL;
    }
}


