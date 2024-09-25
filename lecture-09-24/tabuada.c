/**
 * Apresenta a tabuada de um número entre e1 e 10
 * 
 * Build: gcc -o tabuada -Wall tabuada.cs
 */

#include <stdio.h>


int main() {
	int n;
	
	printf("indique o número (entre 1 e 10) para calcular a tabuada: ");
	scanf("%d", &n);
	
	// acrescentar código para validar se o número foi 
	// lido com sucesso
	
	int i = 1; // índice do ciclo (multiplicador) 
	while ( i <= 10 ) {
		printf("%2d x %2d = %3d\n", n, i, n*i);
		i = i + 1;
	}
	return 0;
}
