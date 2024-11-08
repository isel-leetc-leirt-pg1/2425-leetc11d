 
#define MAX_LINE             256
#define MAX_WORDS_IN_LINE    64
#define MAX_ENTRIES          1024
#define MAX_WORD_SIZE        32 
#define MAX_WORD_OCORRS      200

#define DUD_NAME "dud_en.txt"


#define OCCORS_OVERFLOW -1
#define INDEX_OVERFLOW  -2
#define PARTS_OVERFLOW  -3
#define OK               0

typedef struct {
    char word[MAX_WORD_SIZE+1];
    int ocorrs[MAX_WORD_OCORRS];
    int nocorrs;
} word_entry_t;


/**
 * coloca o index vazio
 */
void db_index_init();


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
int db_index_add_or_update(const char word[],int line_num);
   

/**
 * apresenta na consola o index
 */
void db_index_show();
    

