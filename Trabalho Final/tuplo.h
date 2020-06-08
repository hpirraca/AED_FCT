/*
 * tuplo.h
 *
 */

#ifndef TUPLO_H_
#define TUPLO_H_

/* Tipo do TAD tuplo */
typedef struct _tuplo * tuplo;

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
tuplo criaTuplo(int tipoPri, void * pri, void * seg);

/***********************************************
destroiTuplo - Liberta a memória ocupada pela instância da estrutura associada ao tuplo.
Parâmetros:
	t - tuplo a destruir
Retorno:
Pré-condições: t != NULL
***********************************************/
void destroiTuplo(tuplo t);

/***********************************************
priTuplo - Retorna o primeiro elemento no tuplo dado.
Parâmetros:
	t - tuplo
Retorno: elemento (void *)
Pré-condições: t != NULL
***********************************************/
void * priTuplo(tuplo t);

/***********************************************
segTuplo - Retorna o segundo elemento no tuplo dado.
Parâmetros:
	t - tuplo
Retorno: elemento (void *)
Pré-condições: t != NULL
***********************************************/
void * segTuplo(tuplo t);

#endif /* TUPLO_H_ */
