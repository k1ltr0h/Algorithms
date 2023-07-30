#include "../utils.h"

// Compile with: gcc ..\utils.c bubble_sort.c -o bubble_sort

int* bubble_sort(int* list, int size);

int main(int argc, char** argv){

    if(argv[1] == NULL){
        printf("How to use:\nJust call the executable and give it a list of numbers separated by ','.\nSomething like: bubble_sort.exe <3,4,5,...>\nbut without '<' and '>'");
    }

    int list_len;
    int* list = get_list_from_argv(argv[1], &list_len);

    //int list[25] = {2,0,5,1,2,4,7,3,5,4,1,0,9,6,34,56,32,12,56,89,6,35,65,45,19};

    printf("Lista ingresada (desordenada): [");

    for (int i = 0; i < list_len; i++) {
        if(i == list_len - 1){
            printf("%d]", list[i]);
            continue;
        }
        printf("%d, ", list[i]);
    }

    int* sorted_list = bubble_sort(list, list_len);

    printf("\nLista ordenada: [");

    for (int i = 0; i < list_len; i++) {
        if(i == list_len - 1){
            printf("%d]", sorted_list[i]);
            continue;
        }
        printf("%d, ", sorted_list[i]);
    }

    free(list);

    return 0;
}

int* bubble_sort(int* list, int size){

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if(list[j] > list[j+1]){
                int tmp_value = list[j+1];
                list[j+1] = list[j];
                list[j] = tmp_value;
            }
        }
    }

    return list;
}