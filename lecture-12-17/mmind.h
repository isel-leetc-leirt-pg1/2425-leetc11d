#include <stdbool.h>



#define MIN_CLR     1       // primeira cor
#define MAX_CLR     100     // última cor

#define NCOLORS (MAX_CLR-MIN_CLR+1)       // total de cores
#define NONE_CLR    0       // desmarcada
 
#define CODE_SZ     100     // dimensão do código

#define MAX_TRIES   8

// para amarzenar um códifo
typedef int code_t[CODE_SZ];    

// para armazenar o resultado da jogada
typedef struct {
    int blacks, whites;
} result_t;


result_t code_check(code_t secret_c, code_t try_c);
void code_gen(code_t secret);
void code_gen_no_reps(code_t secret);
void code_gen_no_reps_opt(code_t secret);
