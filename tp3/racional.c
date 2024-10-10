/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

struct racional *cria_r(long num, long den){
	
	struct racional *ptr;
	prt = malloc(sizeof(struct racional));

	(*ptr).num = num;
	(*prt).den = den;

	return ptr;

}

int valido_r(struct racional *r){

	if(r == NULL || (*r).den == 0)
		return 0;

	return 1;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b){
	
	long resto;

	while(b != 0){
		resto = a % b;
		a = b;
		b = resto;
	}
	return labs(a) /* retorna o valor absoluto de a */
}				   /* para evitar modificar o sinal dos racionais  */

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r){
	
	long MMC;

	if(r == NULL || !valido_r(r))
		return 0;
	
	MMC = mmc((*r).num, (*r).den);

	if(MMC != 1){ /* se MMC = 1, ja esta simplificado! */

		(*r).num = (*r).num / MMC;
		(*r).den = (*r).den / MMC;
	}

	if((*r).den < 0){
		(*r).num *= -1;
		(*r).den *= -1;
	}

	return 1;
}

void imprime_r(struct racional *r){

	if(r == NULL){
		printf("NULL");

	} else if(!valido_r(r)){
		printf("NaN");

	} else if((*r).num == 0){
		printf("0");

	} else if((*r).den == 1){
		printf("%ld", num);

	} else if((*r).num == (*r).den){
		printf("1");

	} else {
		printf("%ld/%ld", (*r).num, (*r).den);
	}
		
	
}

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
long mdc (long a, long b)
{
  /* implemente aqui */
}


/* implemente as demais funções de racional.h aqui */
