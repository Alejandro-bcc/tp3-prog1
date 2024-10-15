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
		imprime_r(v_ptr[i]);
		if(i < n-1)
			printf(" ");
	}
	printf("\n");
}

void elimina_invalidos(struct racional *v_ptr[], int *n){
	
	int i;
	i = 0;

	while(i < *n){
		if(!valido_r(v_ptr[i])){
			*v_ptr[i] = *v_ptr[(*n)-1];
			destroi_r(v_ptr[(*n)-1]);
			v_ptr[(*n)-1] = NULL;
			(*n)--;
		} else {
			i++;
		}
	}
}

/* Ordena um vetor de racionais de maneira crescente */
/* Utiliza o algoritmo de bubble sort  */
void ordena_vetor(struct racional *v_ptr[], int n){

	struct racional *ptr_aux;
	int i, j;
	for(i = n-1; i > 0; i--)
		for(j = 0; j < i; j++)
			if((compara_r(v_ptr[j], v_ptr[j+1])) == 1){
				ptr_aux = v_ptr[j];
				v_ptr[j] = v_ptr[j+1];
				v_ptr[j+1] = ptr_aux;
			}
	ptr_aux = NULL;
}

void soma_vetor(struct racional *v_ptr[], int n, struct racional *soma){
	
	int i;
	for(i = 0; i < n; i++)
		soma_r(soma, v_ptr[i], soma);	
}

void libera_racionais(struct racional *v_ptr[], int n){
	
	int i;
	for(i = 0; i < n; i++){
		destroi_r(v_ptr[i]);
		v_ptr[i] = NULL;
	}
}

/* programa principal */
int main (){

	struct racional **v_ptr;
	struct racional *soma;
	int n;
	scanf("%d", &n);

	v_ptr = malloc(sizeof(struct racional *)*n);

	prenche_vetor(v_ptr, n);

	printf("VETOR = ");
	imprime_vetor(v_ptr, n);

	elimina_invalidos(v_ptr, &n);

	printf("VETOR = ");
	imprime_vetor(v_ptr, n);
	
	ordena_vetor(v_ptr, n);
	
	printf("VETOR = ");
	imprime_vetor(v_ptr, n);
	
	soma = cria_r(0, 1);
	soma_vetor(v_ptr, n, soma);
	printf("SOMA = ");
	imprime_r(soma);
	printf("\n");

	libera_racionais(v_ptr, n);	

	printf("VETOR = ");
	imprime_vetor(v_ptr, n);

	free(v_ptr);
	v_ptr = NULL;

	free(soma);
	soma = NULL;

	return (0) ;
}

