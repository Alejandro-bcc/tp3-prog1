/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/


int valido_r(struct racional *r){

	if(r == NULL || r->den == 0)
		return 0;

	return 1;
}

/* Calcula o Maximo Divisor Comum entre a e b */
/* Utiliza o metodo de Euclides */
long mdc (long a, long b){
	
	long resto;

	while(b != 0){
		resto = a % b;
		a = b;
		b = resto;
	}
	return labs(a); /* retorna o valor absoluto de a */
}				    /* para evitar modificar o sinal dos racionais  */

/* Calcula o Minimo Multiplo Comum entre a e b */
long mmc (long a, long b){

	return (a * b) / mdc(a, b);
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r){
	
	long MDC;

	if(r == NULL || !valido_r(r))
		return 0;
	
	MDC = mdc((*r).num, (*r).den);

	if(MDC != 1){ /* se MMC = 1, ja esta simplificado! */

		(*r).num = (*r).num / MDC;
		(*r).den = (*r).den / MDC;
	}

	if((*r).den < 0){
		(*r).num *= -1;
		(*r).den *= -1;
	}

	return 1;
}

struct racional *cria_r(long num, long den){
	
	struct racional *ptr;
	ptr = malloc(sizeof(struct racional));

	(*ptr).num = num;
	(*ptr).den = den;
	simplifica_r(ptr);
	return ptr;

}

void destroi_r(struct racional *r){
	
	free(r);
}

void imprime_r(struct racional *r){

	if(r == NULL){	
		printf("NULL");
		return;
	}

	if(!valido_r(r)){
		printf("NaN");
		return;
	}

	if((*r).num == 0){
		printf("0");
		return;
	}

	if((*r).den == 1){
		printf("%ld", (*r).num);
		return;
	}

	if((*r).num == (*r).den){
		printf("1");
		return;
	}

	printf("%ld/%ld", (*r).num, (*r).den);
}

int compara_r (struct racional *r1, struct racional *r2){
	
	if(r1 == NULL || r2 == NULL || !valido_r(r1) || !valido_r(r2))
		return -2;

	if((*r1).num * (*r2).den < (*r2).num * (*r1).den)
		return -1;

	if((*r2).num * (*r1).den < (*r1).num * (*r2).den)
		return 1;

	return 0;
}

int soma_r (struct racional *r1, struct racional *r2, struct racional *r3){
	
	long MMC;

	if(!valido_r(r1) || !valido_r(r2) || r3 == NULL)
		return 0;

	MMC = mmc(r1->den, r2->den);
	r3->num = ((MMC / r1->den) * r1->num) + ((MMC / r2->den) * r2->num);
	r3->den = MMC;
	simplifica_r(r3);
	return 1;
}

int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3){
	
	long MMC;

	if(!valido_r(r1) || !valido_r(r2) || r3 == NULL)
		return 0;

	MMC = mmc(r1->den, r2->den);
	r3->num = ((MMC / r1->den) * r1->num) - ((MMC / r2->den) * r2->num);
	r3->den = MMC;
	simplifica_r(r3);
	return 1;
}

int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3){
	
	if(!valido_r(r1) || !valido_r(r2) || r3 == NULL)
		return 0;
	
	r3->num = r1->num * r2->num;  
	r3->den = r1->den * r2->den;  
	simplifica_r(r3);
	return 1;
}

int divide_r (struct racional *r1, struct racional *r2, struct racional *r3){

	/* o ultimo teste evita divisoes por zero */	
	if(!valido_r(r1) || !valido_r(r2) || r3 == NULL || (*r2).num == 0)
		return 0;
	
	(*r3).num = (*r1).num * (*r2).den;  
	(*r3).den = (*r1).den * (*r2).num;  
	simplifica_r(r3);
	return 1;
}
