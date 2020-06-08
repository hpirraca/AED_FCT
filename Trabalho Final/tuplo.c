/*
 * tuplo.c
 *
 */


#include <stdlib.h>
#include <string.h>
#include "tuplo.h"

/* Tipo do TAD tuplo */
struct _tuplo {
	void * priElem;
	void * segElem;
};

/* Protótipos das funções associadas a um tuplo - TAD tuplo */
/***********************************************
criaTuplo - Criação da instância da estrutura associada a um tuplo.
Parâmetros:
	tipoPri – 0 – inteiro, 1 - string
	pri - primeiro elemento a guardar no tuplo (void *)
	seg - segundo elemento a guardar no tuplo (void *)
Retorno: apontador para a instância criada
Pré-condições:
***********************************************/
tuplo criaTuplo(int tipoPri, void * pri, void * seg){
	tuplo aux = (tuplo) malloc(sizeof(struct _tuplo));
		if (aux == NULL)
			return NULL;
		if (tipoPri == 0){
			aux->priElem = (int *) malloc(sizeof(int));
			* ((int *)(aux->priElem)) = *((int*)pri);
		}
		else{
			aux->priElem = (char *) malloc((strlen((char*)pri)+1)*sizeof(char));
			strcpy(aux->priElem,pri);
		}
		aux-> segElem = seg;
		return aux;
	}

/***********************************************
destroiTuplo - Liberta a memória ocupada pela instância da estrutura associada ao tuplo.
Parâmetros:
	t - tuplo a destruir
Retorno:
Pré-condições: t != NULL
***********************************************/
void destroiTuplo(tuplo t){
	free(t->priElem);
	free(t);
}

/***********************************************
priTuplo - Retorna o primeiro elemento no tuplo dado.
Parâmetros:
	t - tuplo
Retorno: elemento (void *)
Pré-condições: t != NULL
***********************************************/
void * priTuplo(tuplo t){
	return t->priElem;
}

/***********************************************
segTuplo - Retorna o segundo elemento no tuplo dado.
Parâmetros:
	t - tuplo
Retorno: elemento (void *)
Pré-condições: t != NULL
***********************************************/
void * segTuplo(tuplo t){
	return t->segElem;
}


