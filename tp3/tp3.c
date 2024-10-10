/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

void prenche_vetor(struct racional *v_ptr[], int n){
	
	long num, den;
	int i;

	for(i = 0; i < n; i ++){
		scanf("%ld", &num);
		scanf("%ld", &den);
		v_ptr[i] = cria_r(num, den);
	}
}

void imprime_vetor(struct racional *v_ptr[], int n){

	int i;

	for(i = 0; i < n; i++){
		imprime_r(*v_ptr);
	}
}

/* programa principal */
int main (){

	struct racional *v_ptr[];

	int n;
	scanf("%d", &n);

	v_ptr = malloc(sizeof(struct racional *)*n);

	prenche_vetor(v_ptr, n);

	printf("VETOR = ");
	imprime_vetor(v_ptr, n);
	

	return (0) ;
}

