#include <stdio.h>

/**
 * retorna o código de validação
 * do cartão de cidadão número "cc"
 */
int cc_validation_code(int cc) {
	 
	int w = 2;
	int wsum = 0;
	
	while (cc > 0) {
		wsum = wsum + w * (cc % 10);
		w = w + 1;
		cc = cc / 10;
	}  
	return 11 - (wsum % 11);
}


int main() {
	int cc_num;
	printf("número do cartão de cidadão? ");
	scanf("%d", &cc_num);
	
	int vc = cc_validation_code(cc_num);
	
	printf("o código de verificação do cartão %d é: %d\n", cc_num, vc);
	return 0;
}
