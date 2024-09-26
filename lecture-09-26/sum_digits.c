#include <stdio.h>


/**
 * retorna a soma ddos dígitos do número 
 * inteiro passado por parâmetro
 */
int sum_digits(int n) {
	int sum = 0;
	while (n > 0) {
		sum = sum + (n % 10);
		n = n / 10;
	}
	return sum;
}

int main() {
	int n1;
	
	printf("n? ");
	scanf("%d", &n1);
	
	int s = sum_digits(n1);
	
	printf("a soma dos dígitos de %d é: %d\n", n1, s);
	return 0;
}
