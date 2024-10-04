#include <stdio.h>
#include <stdbool.h>


/**
 * retorna true caso o ano "year" seja bissexto,
 * false caso contrário
 */
bool year_leap(int year) {
    /*
    if (year % 4 == 0) {
        return true;
    }
    return false;
    */
    
    // código equivalente ao comentado atrás
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    
}


/**
 * retorna o número de dias do ano
 * (366 ou 365, consoate seja ou não bissexto)
 */
int year_days(int year) {
    if (leap_year(year)) return 366;
    else return 365;
}



/**
 * retorna o número de dias do mês "month" no ano "year"
 * (o ano é relevante para o cáluco de dias do fevereiro)
 */
int month_days(int month, int year) {
    int md;
    // supõe-se que "month" é um mês válido (1 a 12)
    switch(month) {
        case 4: case 6: case 9: case 11: 
            md = 30;
            break;
        case 2:
            if (year_leap(year)) md = 29;
            else md = 28;
            break;
        default:
            // todos os outros meses
            md = 31;
            break;
    }
    return md;
}

/**
 * Apresenta na consola o no dia da semana,
 * dado o seu código (0 a 6)
 */
void wd_print(int wd) {
   // supõe-se que "wd" é um códia válida (0 a )
    /**
    ĩf (wd == 0) {
        printf("domingo");
    }
    else if (wd == 1) {
        printf("segunda-feira");
    }
    else if (wd == 2) {
        printf("terça-feira");
    }
    else if (wd == 3) {
        printf("quarta-feira");
    }
    else if (wd == 4) {
        printf("quinta-feira");
    }
    else if (wd == 5) {
        printf("sexta-feira");
    }
    else {
       printf("sábado");
    }
    */
    
    // o mesmo, usando a instrução switch
    switch(wd) {
        case 0: printf("domingo");
                break;
        case 1: printf("segunda-feira");
                break;
        case 2: printf("terça-feira");
                break;
        case 3: printf("quarta-feira");
                break;
        case 4: printf("quinta-feira");
                break;
        case 5: printf("sexta-feira");
                break;
        case 6: printf("sábado");
                break;
        default:
                // nada a fazer no default
                break;
    }
    
        
}

/**
 * retorna true se a data d/m/y for válida,
 * false caso contrário
 * Considera-se que a data é válida se o ano for igual 
 * ou superior a 1600, o mês entre 1 e 12 e o dia entre 
 * 1 e o número de dias do mês
 */
bool date_valid(int d, int m, int y) {
    return (y >= 1600 &&
        (m >= 1 && m <= 12)
       && (d >= 1 && d <= month_days(m, y)));
}


/**
 * retorna o total de dias desde o início do ano da 
 * data recebida por parâmetro
 * 
 * ex: 2/2/XXXX dá 33 dias (31 de janeiro  mais 2 de fevereiro)
 */
int days_from_jan1(int d, int m, int y) {
    // TO IMPLEMENT
    return 0;
}

/**
 * retorna o total de dias que faltam até ao fim do 
 * ano data
 * 
 * ex: 25/11/XXXX dá 36 dias (5 de novembro  mais 31 de dezembro)
 *     31/12/XXXX dá 0 dias (já estamos o último dia do mês)
 */
int days_to_dez31(int day, int month, int  year) {
    // TO IMPLEMENT
    return 0;
}

/**
 * retorna a diferença em dias entre as datas d1/m1/y1 e d2/m2/y2
 * utiliza as funções days_to_dez31, days_from_jan1 e year_days
 * como auxiliares para a realização do cálculo.
 */
int date_diff_days(int d1, int m1, int y1, int d2, int m2, int y2) {
    // TO IMPLEMENT
    return 3;
}


/**
 * devolve o código (0 - domingo até 6 - sábado)
 * do dia da semana correspondente à data day/month/year
 */
int date_weekday(int day, int month, int year) {
    int dr = 1;
    int mr = 1;
    int yr = 1900;
    int wdr = 1; // segunda-feira
    
    int ndays = date_diff_days(dr, mr, yr, day, month, year);
    
    return (ndays + wdr) % 7;
}

        
int main() {
    int d, m, y;
    
    printf("data (d/m/a)? ");
    scanf("%d/%d/%d", &d, &m, &y);
    if (!date_valid(d, m, y)) {
        printf("data inválida!\n");
        return 1;
    }
    
    int wd = date_weekday(d, m, y);
    
    printf("o dia da semana da data indicada é ");
    wd_print(wd);
    printf("\n");
    return 0;
}


