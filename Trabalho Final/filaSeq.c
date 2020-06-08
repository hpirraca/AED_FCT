/*
 * filaSeq.c
 */

#include <stdlib.h>

#include "iterador.h"
#include "fila.h"
#include "sequencia.h"

/* Estrutura de dados: fila ---> comportamento â€œPrimeiro a chegar, Primeiro a sairâ€� */
struct _fila{
	sequencia elems;
};

/* Prototipos das funcoes associadas a uma fila */

/***********************************************
criaFila - Criacao da instancia da estrutura associada a uma fila.
Parametros:
     cap - capacidade prevista da fila
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
fila criaFila(int cap){
	fila f = (fila) malloc(sizeof(struct _fila));
	if (f == NULL) return NULL;
	f->elems = criaSequencia(cap);
	if (f->elems == NULL){
			free(f);
			return NULL;
	}
	return f;
}


/*destroiFila - Liberta a memoria ocupada pela instancia da estrutura associada Ã  fila.
Parametros:
	f - fila a destruir
Retorno:
Pre-condicoes: f != NULL
***********************************************/
void destroiFila (fila f ){
	destroiSequencia(f->elems);
	free(f);
}

/***********************************************
destroiFilaEElems - Liberta a memoria ocupada pela instancia da estrutura associada Ã  fila e os elementos.
Parametros:
	f - fila a destruir	destroi - funÃ§Ã£o para destruiÃ§Ã£o os elementos
Retorno:
Pre-condicoes: f != NULL
***********************************************/
void destroiFilaEElems(fila f, void (*destroi)(void *) ){
	destroiSeqElems(f->elems,destroi);
	free(f);
}

/***********************************************
vaziaFila - Indica se a fila estÃ¡ vazia.
Parametros:
	f - fila
Retorno: 1- caso fila vazia; 0 - caso contrÃ¡rio
Pre-condicoes: f != NULL
***********************************************/
int vaziaFila(fila f){
	return vaziaSequencia(f->elems);
}

/***********************************************
tamanhoFila - Consulta o numero de elementos na fila.
Parametros:
	f - fila
Retorno: numero de elementos na fila
Pre-condicoes: f != NULL
***********************************************/
int tamanhoFila(fila f){
	return tamanhoSequencia(f->elems);
}

/***********************************************
elementoFila â€“ Retorna o elemento  Ã  mais tempo na fila.
Parametros:
f â€“ fila
Retorno: retorna o endereco do elemento
Pre-condicoes: f != NULL && tamanhoFila(f) != 0
***********************************************/
void * elementoFila(fila f){
	return elementoPosSequencia(f->elems,1);
}

/***********************************************
adicionaElemFila - Adiciona o elemento dado na fila.
Parametros:
	f â€“ fila
	elem - endereco do elemento
Retorno:
Pre-condicoes: f != NULL
***********************************************/
void adicionaElemFila(fila f, void * elem){
	adicionaPosSequencia(f->elems,elem,tamanhoSequencia(f->elems)+1);
}

/***********************************************
removeElemFila - Remove o elemento Ã  mais tempo na fila.
Parametros:
	f â€“ fila
Retorno: retorna o elemento
Pre-condicoes: f != NULL && vaziaFila(f) != 1
***********************************************/
void * removeElemFila(fila f){
	return removePosSequencia(f->elems,1);
}


