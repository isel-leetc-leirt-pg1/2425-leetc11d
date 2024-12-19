
/*-----------------------------------------------------------------
 * ficheiro "main" do jogo do master mind
 * Contém as funções relacionadas com a interação com o utilizador:
 * ler código, mostrar código, jogar e mostrar resultado
 * build:
 *      gcc -o mmind -Wall mmind.c model.c utils.c
 *-----------------------------------------------------------------*/
  
#include <stdio.h>
#include "mmind.h"
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

/**
 * mostrar o código recebido na consola
 */
void code_show(code_t code) {
   for(int i=0; i < CODE_SZ; ++i) {
      printf("%d ", code[i]);
   }
   printf("\n");
}


/**
 * recolher o código sem validações :(
 */
void code_read(code_t code, int try_num) {
   printf("tentativa %d: ", try_num);
   for(int i=0; i < CODE_SZ; ++i) {
      scanf("%d", &code[i]);
   }
}

/**
 * mostrar o resultado da jogada
 */
void result_show(result_t res) {
   printf("casas pretas: %d\n", res.blacks);
   printf("casas brancas: %d\n\n", res.whites);
}




/**
 * ciclo que permite jogar ao master mind
 * contra o computador
 */
int play() {
   code_t secret, try;
   
   code_gen_no_reps(secret);
  
   int ntries = 1;

   while(ntries <= MAX_TRIES) {
    /**
     * descomentar para debug
     * printf("segredo: "); 
     * code_show(secret);
     */
      
      
      code_read(try, ntries);
      /**
       *  descomentar para debug
       *  printf("código: "); 
       *  code_show(try);
       **/
     
      // obter o resultado da jogada
      result_t res = code_check(secret, try);
      result_show(res);
      
     
      if (res.blacks == CODE_SZ) {
        // tudo certo, vitória!
         return ntries;
      }
      ntries++;
   }
   printf("segredo: "); 
   code_show(secret);
   return 0;
}
 

int main() {
    // para ter sequências aleatórias diferentes
   rand_init();
 
   int ntries = play();
   if (ntries != 0) {
      printf("parabéns, venceu em %d tentativas\n", ntries);
   }
   else {
      printf("perdeu, melhor para a prõxima!\n");
   }
}
