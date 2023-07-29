#include "utils.h"

int* get_list_from_argv(char* list, int* list_len){

    const char* delim = ",";
    char* context = NULL; // Puntero para mantener el estado del análisis
    char* list_copy = copy_char_array(list);
    *list_len = get_split_len(list_copy, delim);
    
    int* new_list = (int*)malloc(sizeof(int)*(*list_len));

    context = NULL; // Puntero para mantener el estado del análisis
    char* str = (char*)"\0";
    int* new_list_init = new_list;
    int counter = 0;

    while(str != NULL){
        if(counter == 0){
            str = strtok_s(list, delim, &context);
        }
        else{
            str = strtok_s(NULL, delim, &context);
        }
        if(str != NULL){
            *new_list = strtol(str, NULL, 10);
            new_list++;
            counter++;
        }
    }

    new_list = new_list_init;
    
    return new_list;
}

int get_split_len(char* list, const char* delim){
    char* context = NULL; // Puntero para mantener el estado del análisis
    char* str = (char*)"\0";
    int counter = 0;

    while(str != NULL){
        if(counter == 0){
            str = strtok_s(list, delim, &context);
        }
        else{
            str = strtok_s(NULL, delim, &context);
        }
        if(str != NULL){
            //printf("%s\n", str);
            counter++;
        }
    }

    free(list);

    return counter;
}

char* copy_char_array(char* list){

    char* list_init = list;
    char* list_copy = (char*)malloc(sizeof(char)*(strlen(list) + 1));
    char* list_copy_init = list_copy;

    while(*list != '\0'){
        *list_copy = *list;
        list++;
        list_copy++;
    }

    *list_copy = '\0';

    list = list_init; // volvemos a apuntar al primer char
    list_copy = list_copy_init;

    return list_copy;
}