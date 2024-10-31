/**
 * apresenta as linhas onde ocorre no ficheiro DUD_FILENAME
 * a sequência de caracteres lida da consola
 * 
 * Build:
 *      gcc o find_word -Wall find_word.c strutils.c
 */


#include <stdio.h>
#include "strutils.h"

#define MAX_LINE 256
#define MAX_MATCH_SIZE 64

#define DUD_FILENAME "dud_en.txt"

/**
 * procura a sequência "to_find" em "text"
 * Retorna a posição onde a sequência foi encontrada
 * ou -1  caso não tenha sido
 * 
 */
int strsub(char text[], char to_find[]) {
    int i=0;
    while (text[i] != 0) {
        int j = 0;
        while(text[i + j] == to_find[j] && to_find[j] != 0) {
            j++;
        }
        if (to_find[j] == 0) {
            // pattern find
            return i;
        }
        ++i;
    }
    return -1;
}


int main() {
    FILE * f_dud =  fopen(DUD_FILENAME, "r");
    if (f_dud == NULL) {
        printf("error opening file\n");
        return 1;
    }
    char word_to_find[MAX_MATCH_SIZE+1];
    
    printf("word to find? ");
    fgets(word_to_find, MAX_MATCH_SIZE, stdin);
    
    // remove final and initials spaces
    str_trim(word_to_find);
  

    int line_num = 1;
    char line[MAX_LINE + 1];
    while (fgets(line, MAX_LINE, f_dud)) {
        // process line
        if (strsub(line, word_to_find) != -1 ) {
            fprintf(stdout, "%d: %s", line_num, line);
        }
        line_num++;
    }
    fclose(f_dud);
    return 0;
}
