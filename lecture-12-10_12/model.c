/*----------------------------------------
 * contem as operações básicas sobre códigos:
 * avaliar o código de uma jogada, criar um código aleatório
 */

#include <stdlib.h>
#include "mmind.h"
#include "utils.h"

/**
 * função auxiliar para copiar as "cores" de um código para outro
 */
void copy_code(code_t dst, code_t src) {
    for (int i= 0; i < CODE_SZ; ++i) {
        dst[i] = src[i];
    }
}

/**
 * função  para gerar aleatoriamente um código 
 * como eventuais repetições
 */
void code_gen(code_t secret) {
    for (int i= 0; i < CODE_SZ; ++i) {
        secret[i] = rand_in_range(MIN_CLR, MAX_CLR);
    }
}

void code_gen_no_reps(code_t secret) {
    // TO IMPLEMENT
}

 
/**
 * avalia o código de uma jogada, retornando o resultado
 */
result_t code_check(code_t _secret, code_t _try) {
    result_t res = { .blacks = 0, .whites= 0};
    code_t secret, try;

    copy_code(secret, _secret);
    copy_code(try, _try);
    // casas pretas
    for(int i= 0; i < CODE_SZ; ++i) {
        if (secret[i] == try[i]) {
            res.blacks++;
            secret[i] = NONE_CLR;
            try[i] = NONE_CLR;
        }
    }
    // casas brancas
    for(int i= 0; i < CODE_SZ; ++i) {
        if (secret[i] != NONE_CLR) {
            for(int j = 0; j < CODE_SZ; ++j) {
                if (secret[i] == try[j]) {
                    res.whites++;
                    try[j] = NONE_CLR;
                    break;
                }
            }
        }
    }
    return res;
}
