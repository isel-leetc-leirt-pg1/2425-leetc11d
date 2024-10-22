#include <stdio.h>
#include <stdbool.h>



int my_strlen(char str[]) {
    int i=0;
    while(str[i] != 0) {
        ++i;
    }
    return i;
}

void my_strcpy(char dst[], char src[]) {
    int i=0;
    while(src[i] != 0) {
        dst[i] = src[i];
        ++i;
    }
    dst[i] = 0;
}

void my_strcpy2(char dst[], char src[]) {
    int i=0;
    while( (dst[i] = src[i]) != 0) {
        ++i;
    }
}

int my_strcmp(char str1[], char str2[]) {
    int i=0;
    while(str1[i] == str2[i] && str1[i] != 0) {
        ++i;
    }
    return str1[i] - str2[i];
}

// concatenate string "src"to string "dst"
void my_strcat(char dst[], char src[]) {
    int i= my_strlen(dst);
    int j = 0;
    
    while(src[j] != 0) {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = 0;
}


// ler uma linha do input standard
// retorna o total de carateres lidos
int read_line(char line[], int capacity) {
    // TO IMPLEMENT
    return 0;
}

// procura a string "toFind" dentro da string "text"
// retorna o índice em text da string encontrada ou -1 se não existir 
int my_strstr(char text[], char toFind[]) {
    // TO IMPLEMENT
    return -1;
}


        
        
