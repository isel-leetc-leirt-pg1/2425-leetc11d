#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// para usar a função time
#include <time.h>



#define MAX_SIZE 1000000 

// constroi o array com valores aleatórios entre 1 e lim
void array_build(int a[], int size, int lim) {
    for (int i=0; i < size; ++i) {
        a[i] = abs(rand()) % lim + 1;
    }
}

void show_array(int a[], int size) {
    printf("[");
   
    if (size > 0) {
        printf("%d", a[0]);
        // o resto...
        for(int i=1; i < size; ++i) {
            printf(", %d", a[i]);
        }
    }
    
    printf("]\n");
    
}


bool a_is_sorted(int a[], int size) {
    for(int i = 0; i < size - 1; ++i) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}


void array_copy(int dst_a[], int src_a[], int size) {
    for (int i=0; i < size; ++i) {
        dst_a[i] = src_a[i];
    }
}

int cmp_int(const void *v1, const void *v2) {
    int i1 = *((int *) v1);
    int i2 = *((int *) v2);
    return i1 - i2;
}


void quick_sort(int vals[], int size) {
    qsort(vals, size, sizeof(int), cmp_int);
}


int main() {
#define CURR_SIZE 1000000
    int v[MAX_SIZE], v1[MAX_SIZE];
    
    // iniciar o gerador pseudo-aleatório
    // a função time retorna o número de segundos desde 1/1/1970
    srand(time(NULL));
    
    array_build(v, CURR_SIZE, 100);
    array_copy(v1, v, CURR_SIZE);
    
    if (CURR_SIZE <= 100) {
        show_array(v, CURR_SIZE);
    }
    
    printf("start quicksort...\n");
    quick_sort(v, CURR_SIZE);
    printf("end quicksort...\n");
    if (a_is_sorted(v, CURR_SIZE)) {
        printf("quicksort OK!\n");
        if (CURR_SIZE <= 100) {
            show_array(v, CURR_SIZE);
        }
    }
    else {
        printf("quicksort fail!\n");
    }
    
    printf("start position sort...\n");
    a_position_sort(v1, CURR_SIZE);
    printf("end position sort....\n");
    if (a_is_sorted(v1, CURR_SIZE)) {
        printf("position sort OK!\n");
        if (CURR_SIZE <= 100) {
            show_array(v1, CURR_SIZE);
        }
    }
    else {
        printf("position sort fail!\n");
    }
    
    return 0;
}

