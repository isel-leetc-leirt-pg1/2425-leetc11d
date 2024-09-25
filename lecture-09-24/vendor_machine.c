#include <stdio.h>
#include <stdbool.h>


int main() {
	int exchange;
	bool opened = true;
	
	while( opened ) {
		
		// alterar para em vez de ler o troco, ler
		// o valor da compra e o valor pago, para calcular o troco,
		// validando o valor pago e o valor da compra
		printf("Qual o troco em cêntimos: ");
		scanf("%d", &exchange);
		
		int nCoins;
		
		// 2 euros
		nCoins = exchange / 200; // calcular número de moedas de 2 euros
		
		if (nCoins > 0) {
			printf("%d moedas de 2 euros\n", nCoins);
		}
		
		//exchange = exchange - 200 * nCoins; // cálculo do resto
		exchange = exchange % 200; // resto da divisão em C
		
		// 1 euro
		
		nCoins = exchange / 100; // calcular número de moedas de 1 euros
		
		if (nCoins > 0) {
			printf("%d moedas de 1 euro\n", nCoins);
		}
		 
		exchange = exchange % 100; // resto da divisão em C
		
		// 50 cêntimos
		nCoins = exchange / 50; // calcular número de moedas de 50 cêntimos
		
		if (nCoins > 0) {
			printf("%d moedas de 50 cêntimos\n", nCoins);
		}
		
		exchange = exchange % 50;   // cálculo do resto
		
		
		// 20 cêntimos
		nCoins = exchange / 20; // calcular número de moedas de 20 cêntimos
		
		if (nCoins > 0) {
			printf("%d moedas de 20 cêntimos\n", nCoins);
		}
		
		exchange = exchange % 20; // cálculo do resto
		
		// 10 cêntimos  
		
		nCoins = exchange / 10; // calcular número de moedas de 10 cêntimos
		
		if (nCoins > 0) {
			printf("%d moedas de 10 cêntimos\n", nCoins);
		}
		
		exchange = exchange % 10; // cálculo do resto
		
		// 5 cêntimos
		
		nCoins = exchange / 5; // calcular número de moedas de 5 cêntimos
		
		if (nCoins > 0) {
			printf("%d moedas de 5 cêntimos\n", nCoins);
		}
		
		exchange = exchange % 5; // cálculo do resto
		
		
		// 2 cêntimos
		
		nCoins = exchange / 2; // calcular número de moedas de 2 cêntimos
		
		if (nCoins > 0) {
			printf("%d moedas de 2 cêntimos\n", nCoins);
		}
		
		exchange = exchange % 2; // cálculo do resto
		
		if (exchange > 0) {
			printf("%d moedas de 1 cêntimos\n", exchange);
		}
		
		
		printf("continuar ligado (s/n)? ");
		char c = '\0';
		// remover todos os caracters pendentes até à mudança de linha
		
		while (c != '\n') {
			scanf("%c", &c);
		}
		
		scanf("%c", &c);
		
		if (c != 's') {
			opened = false;
		}
	}
	
	printf("\nLoja encerrada!\n");
	return 0;
}
