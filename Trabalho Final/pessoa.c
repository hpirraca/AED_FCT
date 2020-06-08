/*
 * pessoa.c
 *
 *  Created on: 02/05/2016
 *      Author: Hugo Pirraca  - 42471
 *              Miguel Vieira - 46159
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "iterador.h"
#include "pessoa.h"
#include "fila.h"
#include "dicionario.h"

struct _pessoa{
	int contribuinte, cc, h_entrada, m_entrada, trampolim, fila;
	char * nome;
	float valorPagar;
};

pessoa criaPessoa(int cc, int contribuinte, char * nome){
	pessoa i = (pessoa) malloc(sizeof(struct _pessoa));
	if (i == NULL)
		return NULL;
	i->cc = cc;
	i->contribuinte = contribuinte;
	i->nome= (char *)malloc(sizeof(char) * strlen(nome)+1);
	if(i->nome==NULL){
		free(i);
		return NULL;
	}
	strcpy(i->nome, nome);
	i->h_entrada = -1;
	i->m_entrada = -1;
	i->valorPagar = 0;
	i->trampolim = 0;  // Variavel de controlo para se saber se a pessoa se encontra ou nao na fila (quando está na fila a variavel e igual a 1)
	i->fila = 0;       // Variavel de controlo para se saber se a pessoa se encontra ou nao no trampolim (quando está no trampolim a variavel e igual a 1)
	return i;
}

void acresConta(pessoa i, float valor){
	i->valorPagar= i->valorPagar + valor;
}

void acresHora(pessoa i, int h, int m){
	i->h_entrada=h;
	i->m_entrada=m;
	i->trampolim=1;
	i->fila=0;
}

float valorPagar(pessoa i){
	if(i->valorPagar == 0)
		i->valorPagar = 5;

	return i->valorPagar;
}

char * retornaNome(pessoa i){
	return i->nome;
}

int retornaCC(pessoa i){
	return i->cc;
}

int retornaHora(pessoa i){
	return i->h_entrada;
}

int retornaMin(pessoa i){
	return i->m_entrada;
}

int statusFila(pessoa i){
	return i->fila;
}

int statusTrampolim(pessoa i){
	return i->trampolim;
}

void changeStatusFila(pessoa i){
	i->fila = 1;
}

void changeStatusTramp(pessoa i){
	i->trampolim = 0;
	i->h_entrada = -1;
	i->m_entrada = -1;
}

void destroiPessoa(pessoa i){
	free(i);
}
