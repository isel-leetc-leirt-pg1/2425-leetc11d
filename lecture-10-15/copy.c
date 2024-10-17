/**
 * programa que copia o "standard input" 
 * para o "standard output"
 * 
 * build:
 *      gcc -o copy -Wall -g copy.c
 * 
 * Tipicamente o "standard input" é o teclado e o
 * "standard output" é a consola, mas isso pode ser modificado
 * quando invocamos um programa na consola. 
 * Por exemplo, se executarmos na consola o comando:
 * 
 * copy < filein.txt > fileout.txt
 * 
 * o efeito é criar o ficheiro "fileout.txt" como uma cópia 
 * do ficheiro "filein.txt", que terá de existir, naturalmente.
 * 
 **/

#include <stdio.h>

int main() {
    int c;
    
    c = getchar();

    // EOF == -1
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;

}
