
/**
 * programa que converte em graus fahrenheit uma temperatura lida da 
 * consola em graus celsius.
 * Nesta versão só suporta valores inteiros em graus celsius
 * 
 * build: gcc -o fahren -Wall fahrenheit.c
 */
 
 
#include <stdio.h>

int main() {
	
	int celsius;
	
	printf("Indique o valor em graus celsius: ");
	scanf("%d", &celsius);
	
	printf("10 graus celsius são %f fahrenheit!\n", celsius*(9.0/5) + 32);
	return 0;
	
}
