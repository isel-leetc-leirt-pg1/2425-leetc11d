#include "db_index.h"
#include <string.h>
#include <stdio.h>

// globals
word_entry_t db_index[MAX_ENTRIES];
int  db_index_size;


/**
 * coloca "db_index" vazio
 */
void db_index_init() {
    db_index_size = 0;
}

/**
 * procura "word" em "db_index"
 * retorna:
 *      a posição (índice) da word_entry_t
 *      com o a palavra "word"
 *      -1 caso "word não exista em "db_index"
 */
int db_index_search(const char word[]) {
    for(int i=0; i < db_index_size; ++i) {
        if (strcmp(word, db_index[i].word) == 0) {
            return i;
        }
    }
    return -1;
}


/**
 * se "word ainda não existe no index, cria uma nova entrada com
 * o número de linha "line_num"
 * Caso "word" já exista adiciona "line_num" às ocorrências de "word"
 * 
 * retorna:
 *      OK se a operação foi realizada com sucesso
 *      OCORRS_OVERFLOW se não é possível a ocorrência a word
 *      INDEX_OVERFLOW se o indice está cheio
 */
int db_index_add_or_update(const char word[], int line_num) {
    int pos = db_index_search(word);
    if (pos == -1) { // a new word
        if (db_index_size == MAX_ENTRIES)  {
            return INDEX_OVERFLOW;
        }
        // copy word to new entry of db_index
        strcpy(db_index[db_index_size].word, word);
        // put the first line ocurrence in ocorrs array
        db_index[db_index_size].ocorrs[0] = line_num;
        db_index[db_index_size].nocorrs = 1;
        
        // increment db_index_size
        db_index_size++;
    }
    else {
        // update the entry ocorrences
        int nocorrs = db_index[pos].nocorrs;
        if (nocorrs == MAX_WORD_OCORRS) {
            return OCCORS_OVERFLOW;
        }
        db_index[pos].ocorrs[nocorrs] = line_num;
        db_index[pos].nocorrs++;
    }
    return OK;
}

void db_index_show() {
   printf("db_index_show is not implemented!\n");
} 
