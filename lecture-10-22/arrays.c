
#include <stdio.h>
#include <stdbool.h>
 
 

/**
 * Descrição:
 *    Procura o valor "v" no array "nums"
 * Retorna:
 *    a posição onde o valor foi encontrado
 *    -1 caso o valor não exista no array
 */ 
int a_search(int nums[], int size, int v) {
    for(int i=0; i < size; ++i) {
        if (nums[i] == v) {
            return i;
        }
    }
    return -1;
}

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove(int vals[], int size, int to_remove) {
    int res = a_search(vals, size, to_remove);
    if (res == -1) {
        return false;
    }
    vals[res] = vals[size-1];
    return true;
}


/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *    Nesta versão assume-se que a ordem dos valores no array não se pode alterar
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove_ordered(int vals[], int size, int to_remove) {
    // TO IMPLEMENT
    return false;
}



/**
 * Descrição:
 *  Ordena um array de inteiros usando o algoritmo de Position Sort:
 *  Procura-se o maior elemento que troca de posição com o último elemento
 *  Faz-se o mesmo para todos os subarrays consecutivos
 * Retorno:
 *  Nada
 *  
 */ 
void a_position_sort(int vals[], int size) {
     for(int end = size -1; end > 0; --end) {
         
         int greatest = vals[0];
         int greatest_idx = 0;
         for(int start = 1; start <= end; ++start) {
             if (vals[start] > greatest) {
                 greatest = vals[start];
                 greatest_idx = start;
             }
         }
         // trocar maior com a última posição
         vals[greatest_idx] = vals[end];
         vals[end] = greatest;
     }
}


void a_insertion_sort(int vals[], int size) {
    // TO IMPLEMENT
}


/**
 * Descrição:
 *      Procura o valor "to_find" no array "vals", de dimensão "size", usando o algoritmo da pesquisa dicotómica (ou binária)
 *      Neste método o array original é "partido" ao meio e o elemento central é comparado
 *      com a valor aa encontrar. Se o elemento do meio não corresponde ao valor a aencontrar então
 *      continua-se a pesquisa na metade inferior ou superior, consoante o elemento a encontrar seja inferior
 *      ou superior ao elemento do "meio"
 * Retorno:
 *    a posição onde o valor foi encontrado,
 *    ou -1 caso o valor "to_find" não exista no array
 */
int a_bin_search(int vals[], int size, int to_find) {
    // TO IMPLEMENT
    return -1;
}
















