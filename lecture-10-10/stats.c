/**
 * ler uma sequência de números e determinar
 * O maior,o menor e a sua média
 *
 * Nesta versão são usados os limites minimo e máximo dos inteiros
 */

#include <stdio.h>
#include <limits.h>

#define MAX_NUMS 100

int main() {
    int greatest = INT_MIN, smallest = INT_MAX;
    int num;
    int sum = 0, total = 0;
    
    // preparação para a determinação de todos os valores maiores do que a média
    int nums[MAX_NUMS];

    printf("indique uma sequência de inteiros terminada por .: ");

    while( total < MAX_NUMS && scanf("%d", &num) == 1 ) {
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
    return 0;

}
