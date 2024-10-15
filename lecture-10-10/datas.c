/**
 * Versão com implementação completa de cálculo do dia da semana de uma data, 
 * 
 * à data de referência (1 de janeiro de 1900)
 */

#include <stdio.h>
#include <stdbool.h>


#define FIRST_VALID_YEAR 1600

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
    if (year_leap(year)) return 366;
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
    return (y >= FIRST_VALID_YEAR &&
        (m >= 1 && m <= 12)
       && (d >= 1 && d <= month_days(m, y)));
}


/**
 * retorna o total de dias desde o início do ano da 
 * data recebida por parâmetro
 * 
 * ex: 2/2/XXXX dá 33 dias (31 de janeiro  mais 2 de fevereiro)
 */
int days_from_jan1(int day, int month, int year) {
  int ndays = 0;

  /*
  int m = 1;
  while (m < month) {
    ndays = ndays + month_days(m, year);
    m = m +1;
  }
  */

  for(int m = 1; m < month; m = m +1) {
    ndays = ndays + month_days(m, year);
  }

  return ndays + day;
}

/**
 * retorna o total de dias que faltam até ao fim do 
 * ano da data
 * 
 * ex: 25/11/XXXX dá 36 dias (5 de novembro  mais 31 de dezembro)
 *     31/12/XXXX dá 0 dias (já estamos o último dia do mês)
 */
int days_to_dez31(int day, int month, int  year) {
   int ndays = month_days(month, year) - day;

   int m = month + 1;

   while (m <= 12) {
     ndays = ndays + month_days(m, year);
     m = m+1;
   }
   return ndays;
 
}

/**
 * compara duas datas e retorna:
 * 
 * < 0 se a peimeira for menor do que a seguda
 * 0   se as datas forem iguais
 * > 0  se a primeira for maior do que a segunda
 */
int date_cmp(int d1, int m1, int y1, int d2, int m2, int y2) {
    /*
    if (y1 < y2) {
        return -1;
    }
    if (y1 > y2) {
        return 1;
    }
    if (m1 < m2) {
        return -1;
    }
    if (m1 > m2) {
        return 1;
    }
    return d1 - d2;
    */

    int diff = y1 - y2;
    if (diff != 0) {
        return diff;
    }
    diff = m1 - m2;
    if (diff != 0) {
        return diff;
    }
    return d1 - d2;
}

/**
 * retorna a diferença em dias entre as datas d1/m1/y1 e d2/m2/y2
 * utiliza as funções days_to_dez31, days_from_jan1 e year_days
 * como auxiliares para a realização do cálculo.
 */
int date_diff_days(int d1, int m1, int y1, int d2, int m2, int y2) {
    int ndays = 0;
    int signal = 1;

    // garantir que a primeira data é menor do que a segunda, eventualmente
    // trocando as duas datas e invertendo o sinal do resultado
    if (date_cmp(d1,m1,y1, d2, m2, y2) > 0) {
        // trocar dias
        int tmp = d1;
        d1 = d2;
        d2 = tmp;

        // trocar meses
        tmp = m1;
        m1 = m2;
        m2 = tmp;

        // trocar anos
        tmp = y1;
        y1 = y2;
        y2 = tmp;

        signal = -1;

    }

    // se as duas datas estiverem no mesmo ano
    // o cáluclo da diferença de dias é diferente
    if (y1 == y2) {
        ndays = days_from_jan1(d2,m2,y2) - 
                days_from_jan1(d1,m1,y1);
        return ndays*signal;
    }
    
    ndays = ndays + days_to_dez31(d1,m1,y1);

    for(int y = y1 + 1; y < y2; y++ /* ++y */ ) {
        // ndays = ndays + year_days(y);
        ndays += year_days(y);
    }

    ndays += days_from_jan1(d2,m2,y2);
    return ndays * signal;
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
    
    int wd =  (ndays + wdr) % 7;
    
    // o resto é negativo se a data a pesquisar for menor 
    // do que a data de refrência
    if (wd < 0) {
        wd += 7;
    }
    return wd;
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


