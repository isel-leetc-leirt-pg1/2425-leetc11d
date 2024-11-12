/**
 * ilustra inserção ordenada e pesquisa em arrays ordenados.
 * 
 * build:
 *     gcc -o sorted_arrays -Wall sorted_arrays.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/**
 * procura um valor num array ordenado, usando
 * pesquisa binária ou dicotómica
 */
int binary_search(long vals[], int size, long val) {
   int pfirst = 0, plast = size - 1;
   
   while(pfirst <= plast) {
       int pmid = (pfirst + plast) /2;
       if (val > vals[pmid]) {
           pfirst = pmid + 1;
       }
       else if (val < vals[pmid]) {
           plast = pmid -1;
       }
       else {
           return pmid;
       }
   }
   return -1;
}


#define DUPLICATED_VALUE 1
#define FULL_ARRAY       2
#define SUCCESS          0

/**
 * 0 - insertion succeeded
 * 1 - duplicate
 * 2 - no space
 */
int sorted_insertion(long vals[], int size, int capacity, long val) {
    if (size >= capacity) {
        return FULL_ARRAY;
    }
    // FASE1 - procurar a posição onde inserir o novo elemento
    // se este não existir no array
    // usando pesquisa sequencial
    // seria possível usar pesquisa binária neste fase
    // reformulando o valor retornado pela função "binary_search"
    // Como fazê-lo?
    
    int pos = 0;
    while(pos < size && vals[pos] < val) {
        pos++;
    }
    if (pos < size && vals[pos] == val) {
        return DUPLICATED_VALUE;
    }
    
    // FASE 2 - inserir o novo elemento na posição "pos"
    
    for(int i= size -1; i >= pos; --i) {
        vals[i+1] = vals[i];
    }
    
    vals[pos] = val;
    return SUCCESS;
    
}

/**
 * retorna true se o array estiver ordenado
 * por ordem crescente, false caso contrário
 */
bool is_sorted(long vals[], int size) {
    for(int i=0; i < size -1; ++i) {
        if (vals[i] >= vals[i+1]) {
            return false;
        }
    }
    return true;
}


#define CAPACITY 128
int main() {
    long vals[CAPACITY];
    
    // iniciar array com valores pseudo-aleatórios
    // de forma ordenada
    
    int size = 0;
    
    while(size < CAPACITY) {
        long new_val = rand() % 1000;
        
        int res = sorted_insertion(vals, size, CAPACITY, new_val);
        if (res == FULL_ARRAY) {
            printf("bug! full array!\n");
            break;
        }
        else if (res == DUPLICATED_VALUE) {
            printf("%ld duplicated!\n", new_val);
        }
        else {
            size++;
        }
        
    }
    
    // verificar ordenação
    int i;
    for(i=0; i < size -1; ++i) {
        if (vals[i] >= vals[i+1]) {
            printf("bug on sort!\n");
            break;
        }
    }
    
    if (is_sorted(vals, size) ){
        printf("success, sorted array!\n");
    }
    else {
        printf("bug on sort!\n");
    }
            
    // mostrar valores
    for(int i=0; i < size; ++i) {
        printf("vals[%d]=%ld\n", i, vals[i]);
    }
    return 0;
}
    
    
