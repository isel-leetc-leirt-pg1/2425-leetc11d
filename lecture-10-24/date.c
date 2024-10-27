#include "date.h"
#include <time.h>


/**
 * a função retorna "true" se a data (d-m-a) passada por paràmetro é válida,
 * ou "false" caso contrário
 */

bool date_valid(int d, int m, int y) {
    return (y >= 1600) &&
           (m >= 1 && m <= 12) &&
           d >= 1 && d <= month_days(m, y);
}

/**
 * lê uma data do standard input no formato d-m-a
 */
date_t date_read() {
    // TO IMPLEMENT
}
    
date_t date_from_str(char str_date[]) {
    date_t dt = { .day = -1 };
    // TO IMPLEMENT
    return dt;
}


/**
 * apresenta a data no standard output
 */
void date_show(date_t d) {
    // TO IMPLEMENT
}

/**
 * retorna a data correspondente ao dia seguinte à data "d"
 */
date_t date_next(date_t d) {
    // TO IMPLEMENT
    
}
     
date_t date_today() {
	time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    
    date_t today = { .day   = tm.tm_mday, 
                     .month = tm.tm_mon+1,  
                     .year = tm.tm_year + 1900
                 };
            
    return today;
}


int date_cmp(date_t d1, date_t d2)  {
    int r = d1.year - d2.year;
    if (r != 0) return r;
    r = d1.month - d2.month;
    if (r != 0) return r;
    return d1.day - d2.day;
}
 
/**
 * Retorna true se o ano "y" for bissexto
 */
bool leap_year(int y) {
   return  y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0);
}

/**
 * A função já recebe um mês e ano válidos
 * Retorna o número de dias do mês "m"
 */
int month_days(int m, int y) {
    int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int dm = mdays[m]; 
    if (m == 2 && leap_year(y)) dm++;
    
    return dm;
}

