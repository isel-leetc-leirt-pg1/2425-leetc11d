#include <stdbool.h>

#define NCOLORS 6       // total de cores

#define MIN_CLR 1       // primeira cor
#define MAX_CLR 6       // última cor

 
#define CODE_SZ 4       // dimensão do código


// para amarzenar um códifo
typedef int code_t[CODE_SZ];    

// para armazenar o resultado da jogada
typedef struct {
    int blacks, whites;
} result_t;


result_t mm_check(code_t secret_c, code_t try_c);
