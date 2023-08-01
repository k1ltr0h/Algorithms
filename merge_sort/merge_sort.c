#include "../utils.h"

// Compile with: gcc ..\utils.c merge_sort.c -o merge_sort

int* merge_sort(int* list, int size);
int* merge(int* list_a, int* list_b, int list_a_len, int list_b_len);

int main(int argc, char** argv){

    if(argv[1] == NULL){
        printf("How to use:\nJust call the executable and give it a list of numbers separated by ','.\nSomething like: merge_sort.exe <3,4,5,...>\nbut without '<' and '>'");
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

    int* sorted_list = merge_sort(list, list_len);

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

int* merge_sort(int* list, int size){
    if(size <= 1){
        int* new_list = (int*)malloc(sizeof(int));
        *new_list = *list; 
        return new_list;
    }
    
    int left_size = size/2;
    int right_size = size - left_size;

    int left[left_size];
    int right[right_size];

    for(int i=0; i < left_size; i++){
        left[i] = *list++;
    }

    for(int i=0; i < right_size; i++){
        right[i] = *list++;
    }

    int* list_a = merge_sort(left, left_size);
    int* list_b = merge_sort(right, right_size);

    int* result = merge(list_a, list_b, left_size, right_size);
    
    free(list_a);
    free(list_b);

    return result;
}

int* merge(int* list_a, int* list_b, int list_a_len, int list_b_len){

    int result_len = list_a_len + list_b_len;

    int* result = (int*)malloc(sizeof(int)*result_len);
    int *result_init = result;

    int list_a_counter = 0;
    int list_b_counter = 0;

    for(int i=0; i<result_len; i++){
        if(list_a_counter >= list_a_len)
            *result = *list_b++;
        else if(list_b_counter >= list_b_len)
            *result = *list_a++;

        else if(*list_a <= *list_b){
            *result = *list_a++;
            list_a_counter++;
        }
        else{
            *result = *list_b++;
            list_b_counter++;
        }

        result++;
    }

    result = result_init;

    return result;
}
