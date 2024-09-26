#include <stdio.h>

// o include seguinte é necessário para utlizar funções da biblioteca matemática
#include <math.h>

/**
 * para fazer build do programa "circarea" usar o comando:
 * 
 * > gcc -o circarea -Wall circarea.c -lm
 */

#define PI 3.1415926

// utilização de uma variável const para 
// guardar a constante garantindo que o programa não a pode alterar
// desnecesssário neste caso, pode ser usado o "define" anterior
// const float PI=3.1415926;


/**
 * calcula a área de um círculo usando a operação "pow" da biblioteca
 * matemática, apenas para ilustrar a utilização de funções da biblioteca
 * O mesmo efeito podia ser obtido usando a expressão radius * radius
 */
float circle_area(float radius) {
	return PI * pow(radius, 2);
}
	
	

int main() {
	float r;
	
	printf("raio? ");
	scanf("%f", &r);
	
	printf("A área do circulo de raio %.2f é %.3f\n", r, circle_area(r));
	
	return 0;
}




	
	
	
	
