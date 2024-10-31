#include <stdio.h>
#include "strutils.h"

#define MAX_LINE 256
#define MAX_MATCH_SIZE 64

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

#define DUD_NAME "dud_en.txt"
int main() {
    FILE * f_dud =  fopen(DUD_NAME, "r");
    if (f_dud == NULL) {
        printf("error opening file\n");
        return 1;
    }
    char word_to_find[MAX_MATCH_SIZE+1];
    
    printf("word to find? ");
    fgets(word_to_find, MAX_MATCH_SIZE, stdin);
    str_trim(word_to_find);
    
    printf("'%s'", word_to_find);
  

    int line_num = 1;
    char line[MAX_LINE + 1];
    while (fgets(line, MAX_LINE, f_dud)) {
        // process line
        // fputs(line, stdout);
        if (strsub(line, word_to_find) != -1 ) {
            fprintf(stdout, "%d: %s", line_num, line);
            //fputs(line, stdout);
        }
        line_num++;
    }
    fclose(f_dud);
    return 0;
}