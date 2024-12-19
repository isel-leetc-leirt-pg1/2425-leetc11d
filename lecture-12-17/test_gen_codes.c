#include <stdio.h>
#include "utils.h"
#include "mmind.h"

/**
 * mostrar o código recebido na consola
 */
void code_show(code_t code) {
   for(int i=0; i < CODE_SZ; ++i) {
      printf("%d ", code[i]);
   }
   printf("\n");
}


void test_code_generation() {
    code_t code;

    for(int i=0; i < 10; ++i) {
        code_gen_no_reps_opt(code);
        code_show(code);
        printf("\n");
    }
}

int main() {
    rand_init();
    test_code_generation();
    return 0;
}
