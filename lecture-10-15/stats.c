/**
 * ler uma sequência de números e determinar
 * O maior,o menor e a sua média
 *
 * Nesta versão são usados os limites minimo e máximo dos inteiros
 */

#include <stdio.h>
#include <limits.h>

// másximo de valores que podem ser lidos da consola
#define MAX_NUMS 100

/**
 * esta função apresenta na consola (standard output)
 * todos os valores do array "vals", de dimensão "size",
 * que sejam superiores à média "mean"
 *
 */
void show_greater_than_mean(double mean, int vals[], int size) {
    printf("maiores do que a média\n");
    for(int i=0; i < size; ++i) {
        if (vals[i] > mean) {
            printf("%d\n", vals[i]);
        }
    }
}

/**
 * Esta função apresenta na consola (standard output)
 * todos os valores presentes no array  vals, de dimensão "size"
 */
void show_array(int vals[], int size) {
    for(int i= 0; i < size; ++i) {
        printf("vals[%d] = %d\n", i, vals[i]);
    }
}

/**
 * Esta função copia para as primeiras posições consecutivas
 * do array "result", de dimensão "res_size", todos os valores
 * presentes no array "vals", de dimensão "size", que sejam maiores 
 * do que a média recebida
 * 
 * A função retorna o total de valores copiados
 */
int copy_greater_than_mean(double mean, 
                            int vals[], int size,
                            int result[], int res_size) {
    int ncopied = 0;
    for(int i=0; i < size; ++i) {
        if (vals[i] > mean) {
            result[ncopied++] = vals[i];
        }
    }
    return ncopied;
}

int main() {
    int greatest = INT_MIN, smallest = INT_MAX;
    int num;
    int sum = 0, total = 0;
    
    // preparação para a determinação de todos os valores maiores do que a média
    int nums[MAX_NUMS];
   
    printf("indique uma sequência de inteiros terminada por .: ");

    while( total < MAX_NUMS && scanf("%d", &num) == 1 ) {
        // guardar o valor lido no array "nums"
        nums[total] = num;
        sum += num;
        total++;
        if (num > greatest) {
            greatest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
    }
 
    //double totald = total;
    // utilização de um cast explícito para realizar a divisão real
    double mean = sum / (double) total;
    
    printf("média=%lf\n", mean);
    printf("menor=%d\n", smallest);
    printf("maior=%d\n", greatest);
    
    int greater_nums[MAX_NUMS];
    
    // preencher o array "greater_nums" com os valores maiores que a média
    // presentes no array "nums"
     
    printf("valores maiores do que a média:\n");
    int res = copy_greater_than_mean(mean, nums, total,
                                 greater_nums,MAX_NUMS );

    // mostrar todos os elementos do array "greater_nums"
    show_array( greater_nums, res);
    return 0;

}
