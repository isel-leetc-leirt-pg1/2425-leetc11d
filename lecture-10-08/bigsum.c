/**
 * Este programa ilustra a ocorrência de overflow
 * em operações aritméticas sobre inteiros (int)
 * em virtude do número limitado de bits (32) usado para representar um valor int
 * 
 * execute o programa e observe os resultados
 * Comente o código do programa e descomente o código agora comentado.
 * Execute de novo e observe as diferenças
 * A utilização ddo tipo long (com valores representados em 64 bits)
 * permitiu realizar sem overflow as somas anteriores
 */
 
#include <stdio.h>

// para representar um valor literal longo usa-se um "L" a terminar
// o literal como se mostra no define seguinte
// Em rigor não seria necessário neste programa defini-lo como longo
#define BIG_NUM 1000000000L

int main() {
    
    int big_num2 = BIG_NUM + BIG_NUM;
    
    printf("%ld+%ld=%d\n", BIG_NUM, BIG_NUM,  big_num2);
    
    int big_num4 = big_num2 + big_num2;

    printf("%d+%d=%d\n", big_num2, big_num2,  big_num4);

    return 0;
    
    /*
     
        long big_num2 = BIG_NUM + BIG_NUM;
        printf("%ld+%ld=%ld\n", BIG_NUM, BIG_NUM,  big_num2);
        long big_num4 = big_num2 + big_num2;
        printf("%ld+%ld=%ld\n", big_num2, big_num2,  big_num4);
        return 0;
     */
}
