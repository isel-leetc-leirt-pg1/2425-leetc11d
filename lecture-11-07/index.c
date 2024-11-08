#include <stdio.h>
#include "strutils.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "db_index.h"


#define DUD_NAME "dud_en.txt"

/**
 * retira não letras do início e do fim da string
 * Pode produzir uma string vazia caso a string recebida não tenha letras
 */
void normalize(char str[]) {
     int start, end;
     
     start = 0;
     // descarta os caracteres iniciais não letra
     while(!isalpha(str[start]) && str[start] != 0) {
         start++;
     }
     end = strlen(str);
     
     // descarta os caracteres finais não letra
     while(!isalpha(str[end-1]) &&  end > start) {
         end--;
     }
     
     int size = end - start;
     
     for(int i=0; i < size; ++i) {
         // converte as letras para minusculas
         // colocando-as na posição final
         str[i] = tolower(str[start + i]);
     }
     str[size] = 0;
     
}


/**
 * atualiza o index com todas as palavras da linha "line"
 * de número "line_num"
 * retorna:
 *      PARTS_OVERFLOW se a linha contém un número de palavras
 *      superior a MAX_WORDS_IN_LINE
 *      OCORRS_OVERFLOW ou INDEX_OVERFLOW caso não tenha disso
 *      possível atualizar "db_index"
 *      OK em caso de sucesso
 */
int process_line(const char line[], int line_num) {
    spart_t parts[MAX_WORDS_IN_LINE];
    
    int nparts = str_split(line, parts, MAX_WORDS_IN_LINE, ' ');
    if (nparts == -MAX_WORDS_IN_LINE) {
        return PARTS_OVERFLOW;
    }
    
    
    for(int i=0; i < nparts; ++i) {
        normalize(parts[i]);
        if (strlen(parts[i]) > 0) {
            int err = db_index_add_or_update(parts[i], line_num);
            if (err != OK) {
                return err;
            }
        }
    }
    return OK;
}


int main() {
    FILE * f_dud =  fopen(DUD_NAME, "r");
    if (f_dud == NULL) {
        printf("error opening file\n");
        return 1;
    }
  
    db_index_init();
    
    int line_num = 1;
    char line[MAX_LINE + 1];
    
    while (fgets(line, MAX_LINE, f_dud) != NULL) {
       
       int status = process_line(line, line_num);
       if (status != OK) {
           printf("error processing line %d: %d\n", line_num, status);
           break;
       }
       line_num++;
    }
    fclose(f_dud);
    
    // show db_index
    
    db_index_show();
    return 0;
}
