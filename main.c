#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "genius.h"

int main(){
    srand(time(NULL));
    color *head = NULL;
    color *tail = NULL;
    int option = show_menu();
    if(option == '1'){
        game_init_with_level(1, &head, &tail);

    }
    
    return 0;
}
