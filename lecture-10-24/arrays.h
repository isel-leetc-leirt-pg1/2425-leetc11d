#include <stdbool.h>

/**
 * Descrição:
 *    Procura o valor "v" no array "nums"
 * Retorna:
 *    a posição onde o valor foi encontrado
 *    -1 caso o valor não exista no array
 */ 
int a_search(int nums[], int size, int v);



/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *     Nesta versão é usada a função search
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove(int vals[], int size, int to_remove);
   
/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *    Nesta versão assume-se que a ordem dos valores no array não se pode alterar
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove_ordered(int vals[], int size, int to_remove);



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
int a_bin_search(int vals[], int size, int to_find);


/**
 * Descrição:
 *  Ordena um arrsy de inteiros usando o algoritmo de Position Sort:
 *  Procura-se o maior elemento que troca de posição com o último elemento
 *  Faz-se o mesmo para todos os subarrays consecutivos
 * Retorno:
 *  Nada
 *  
 */ 
void a_position_sort(int vals[], int size);
   




void a_insertion_sort(int vals[], int size);





