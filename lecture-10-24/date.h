#include <stdio.h>
#include <stdbool.h>

typedef struct  {
    int day, month, year;
} date_t;


date_t date_read();


date_t date_from_str(char str_date[]);

date_t date_next(date_t d);

void date_show(date_t d);
    
date_t date_today();


int date_cmp(date_t d1, date_t d2);
    


// pré declaração da função 
int year_remaining_days(date_t d);


/**
 * Retorna true se o ano "y" for bissexto
 */
bool leap_year(int y);


/**
 * A função já recebe um mês e ano válidos
 * Retorna o número de dias do mês "m"
 */
int month_days(int m, int y);
     

/**
 * Assume que o ano é válido.
 * A função retorna o número de dias do ano "y".
 */
int year_days(int y);

/**
 * a função retorna "true" se a data (d/m/y) passada por paràmetro é válida,
 * ou "false" caso contrário
 */

bool date_valid(int d, int m, int y);
    

 
    
