/**
 * Este programa ilustra a utilização do valor retornado
 * pela função "scanf" para garantir que a leutura do valor (ou valores)
 * foi realizada com sucesso
 * Pretende-se ler um byte (um valor entre 0 e 255) garantindo 
 * que apenas um múmero válido é introduzido pelo utilizador
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int b = 10;
    
    /*
    printf("byte ? ");
    scanf("%d", &b);

    while (b < 0 || b > 255) {
        printf("byte ? ");
        scanf("%d", &b);
    }
    */
    int res;
    do {
        printf("byte ? ");
        
        // caso o scanf leia com sucesso um inteiro retorna 1
        // caso contrário retorna zero. Em geral retorna o número de valores lidos com sucesso
        // por exemplo, na leitura de uma data temos as variáveis inteiras d, m e y
        // int res = scanf("%d/%d/%d", &d, &m, &y);
        // se o input foi 2/10/2000 (ou 32/13/3000)
        // o scanf retorna 3 pois conseguiu ler os três inteiros
        // Mas se o input foi 3/a/2000
        // o scanf retorna 1, pois só conseguiu ler 1 valor com sucesso
        // Neste caso, todo o input do "a" para a frente não foi consumido pelo scanf
        res = scanf("%d", &b); 
       
        /*
         * Estamos a assumir que por cada linha introduzida queremos ler um único valor inteiro
         * Qualquer caracter a mais na linha é considerado um erro
         * Apenas se admitem espaços iniciais
         */
         
        int countchars = 0;
     
        while (getchar() != '\n') {
            countchars = countchars + 1;
        }
        if (countchars > 0) {
            // marcar caracteres a mais na linha como erro
            res = 0;
        }
         
    } while(  res == 0 || b < 0 || b > 255);
    
    printf("read byte is %d\n", b);
    return 0;
}
