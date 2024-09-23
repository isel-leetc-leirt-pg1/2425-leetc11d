
/**
 * programa que converte em graus fahrenheit uma temperatura lida da 
 * consola em graus celsius.
 * Nesta versão só suporta valores inteiros em graus celsius
 * 
 * build: gcc -o fahren -Wall fahrenheit.c
 */
 
 
#include <stdio.h>

int main() {
	
	
	int celsius; // contém o valor de uma temperatura em graus celsius
	
	printf("Indique o valor em graus celsius: ");
	scanf("%d", &celsius);
	
	printf("%d graus celsius são %f fahrenheit!\n", celsius, celsius*(9.0/5) + 32);
	return 0;
	
}
