/**
 * este programa testa a operação módulo
 * na linguagem C
 * experimente-se com dividendos e/ou divisores negativos
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    while(true) {
        int D, d;
        
        printf("dividendo? ");
        scanf("%d", &D);
        printf("divisor? ");
        scanf("%d", &d);
        
        printf("%d / %d= %d\n", D, d, D / d);
        printf("%d mod %d= %d\n", D, d, D % d);
    }
    return 0;
}
