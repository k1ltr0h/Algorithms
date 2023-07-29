#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* selection_sort(int* list, int size);
int* get_list_from_argv(char* list, int* list_len);
int get_split_len(char* list, const char* delim);
char* copy_char_array(char* list);

int main(int argc, char** argv){

    int list_len;
    int* list = get_list_from_argv(argv[1], &list_len);

    //int list[25] = {2, 0, 5, 1, 2, 4, 7, 3, 5, 4, 1, 0, 9, 6, 34, 56, 32, 12, 56, 89, 6, 35, 65, 45, 19};

    printf("Lista ingresada (desordenada): [");

    for (int i = 0; i < list_len; i++) {
        if(i == list_len - 1){
            printf("%d]", list[i]);
            continue;
        }
        printf("%d, ", list[i]);
    }

    int* sorted_list = selection_sort(list, list_len);

    printf("\nLista ordenada: [");

    for (int i = 0; i < list_len; i++) {
        if(i == list_len - 1){
            printf("%d]", sorted_list[i]);
            continue;
        }
        printf("%d, ", sorted_list[i]);
    }

    return 0;
}

int* selection_sort(int* list, int size){

    int min_value_index = 0;

    for (int i = 0; i < size; i++) {
        min_value_index = i;
        for (int j = i; j < size; j++) {
            if(list[min_value_index] > list[j]){
                min_value_index = j;
            }
        }

        int tmp_value = list[i];
        list[i] = list[min_value_index];
        list[min_value_index] = tmp_value;
    }

    return list;
}

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
