/*
 * iteraVector.c
 */

#include <stdlib.h>

#include "iterador.h"

/* Estrutura de dados do tipo de dados: iterador */
struct _iterador{
	void ** vector;
	int numElems;
	int corrente;
};

/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaIterador - Criacao da instancia da estrutura associada a um iterador para um vector com n elementos.
Parametros:
	vector - endereco da cópia do vector a iterar
	n - numero de elementos no vector
Retorno: apontador para a  instancia criada
Pre-condicoes:  vector != NULL && n > 0
***********************************************/
iterador criaIterador(void ** vector, int n){
	iterador it = malloc(sizeof(struct _iterador));
	if (it == NULL) return NULL;
	it->vector = vector;
	it->numElems = n;
	it->corrente = 0;
	return it;
}

/***********************************************
destroiIterador - Liberta a memoria ocupada pela instancia da estrutura associada ao iterador.
Parametros:
	it - iterador a destruir
Retorno:
Pre-condicoes: it != NULL
***********************************************/
void destroiIterador (iterador it){
	free(it->vector);
	free(it);
}

/***********************************************
temSeguinteIterador - Indica se existe mais elementos para iterar no iterador.
Parametros:
	it - iterador
Retorno: 1- caso exista mais elementos; 0- caso contrario
Pre-condicoes: it != NULL
***********************************************/
int temSeguinteIterador(iterador it){
	if (it->corrente == it->numElems)
		return 0;
	return 1;
}

/***********************************************
seguinteIterador - Consulta o seguinte elemento no iterador.
Parametros:
	it - iterador
Retorno: endereco do elemento
Pre-condicoes: it != NULL && temSeguinteIterador(it) == 1
***********************************************/
void * seguinteIterador(iterador it){
	return it->vector[it->corrente++];
}


