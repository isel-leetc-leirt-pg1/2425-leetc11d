#include <stdio.h>

/**
 * função que recebe 2 números inteiros
 * e retorna o maior.
 */
int max(int i1, int i2) {
	if (i1 > i2) {
		return i1;
	}
	return i2;
}

/**
 * versão pior para determinar o
 * maior de 3 números inteiros
 */
int max3_bad(int i1, int i2, int i3) {
	if (i1 > i2 && i1 > i3) {
		return i1;
	}
	else if (i2 > i1 && i2 > i3) {
		return i2;
	}
	return i3;
}


/**
 * algoritmo correto para determinar o maior
 * de 3 números usando 2 comparações,
 * valor suficiente para determinar o maior de 3 números.
 * Em geral para determinar o maior de "n" números de uma 
 * sequência aleatória bastam "n" - 1 comparações
 */
int max3_better(int i1, int i2, int i3) {
	int m = i1;
	if (i2 > m) {
		m = i2;
	}
	if (i3 > m) {
		m = i3;
	}
	return m;
}

/**
 * determina o maior de 3 números usando a função que
 * determina o maior de 2.
 * Também se fazem duas comparações
 */
int max3_ok(int i1, int i2, int i3) {
	return max(i1, max(i2, i3));
}


int main() {
	int n1, n2, n3;
	
	printf("indique 3 valores inteiros:");
	scanf("%d%d%d", &n1, &n2, &n3);
	
	printf("o maior número é: %d\n", max3_ok(n1, n2, n3));
	return 0;
}
