#include <stdio.h>

int main() {
	int exchange;
	
	printf("Qual o troco em cêntimos: ");
	scanf("%d", &exchange);
	
	int nCoins;
	
	nCoins = exchange / 200; // calcular número de moedas de 2 euros
	printf("%d moedas de 2 euros\n", nCoins);
	
	//exchange = exchange - 200 * nCoins; // cálculo do resto
	exchange = exchange % 200; // resto da divisão em C
	
	nCoins = exchange / 100; // calcular número de moedas de 1 euros
	
	if (nCoins > 0) {
		printf("%d moedas de 1 euro\n", nCoins);
	}
	
	
	//exchange = exchange - 100 * nCoins; // cálculo do resto
	exchange = exchange % 100; // resto da divisão em C
	
	nCoins = exchange / 50; // calcular número de moedas de 50 cêntimos
	
	printf("%d moedas de 50 cêntimos\n", nCoins);
	
	exchange = exchange - 50 * nCoins; // cálculo do resto
	
	nCoins = exchange / 20; // calcular número de moedas de 20 cêntimos
	printf("%d moedas de 20 cêntimos\n", nCoins);
	
	exchange = exchange - 20 * nCoins; // cálculo do resto
	
	nCoins = exchange / 10; // calcular número de moedas de 10 cêntimos
	printf("%d moedas de 10 cêntimos\n", nCoins);
	
	exchange = exchange - 10 * nCoins; // cálculo do resto
	
	nCoins = exchange / 5; // calcular número de moedas de 5 cêntimos
	printf("%d moedas de 5 cêntimos\n", nCoins);
	
	exchange = exchange - 5 * nCoins; // cálculo do resto
	
	nCoins = exchange / 2; // calcular número de moedas de 2 cêntimos
	printf("%d moedas de 2 cêntimos\n", nCoins);
	
	exchange = exchange - 2 * nCoins; // cálculo do resto
	
	printf("%d moedas de 1 cêntimos\n", exchange);
	
	return 0;
}
