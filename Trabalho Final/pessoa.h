/*
 * pessoa.h
 *
 *  Created on: 02/05/2016
 *      Author: Hugo Pirraca  - 42471
 *     			Miguel Vieira - 46159
 */

#ifndef SRC_PESSOA_H_
#define SRC_PESSOA_H_

typedef struct _pessoa * pessoa;

/***********************************************
criaPessoa - cria a estrutura associada a uma pessoa.
Parametros:
	cc           - inteiro - numero do cartao do cidadao
	contribuinte - inteiro - numero de contribuinte
	nome         - string  - nome da pessoa
Retorno: NULL - se nao conseguir criar a estrutura; i - retorna a estrutura da pessoa
Pre-condicoes: cc>0 && contribuinte>0
**********************************************/
pessoa criaPessoa(int cc, int contribuinte, char * nome);

/***********************************************
acresConta - Acrescenta o valor de consumos que o cliente fez no bar em "valorPagar".
Parametros:
	i     - pessoa  - estrutura da pessoa
	valor - inteiro - valor a acrescentar
Retorno:
Pre-condicoes: i!=NULL
**********************************************/
void acresConta(pessoa i, float valor);

/***********************************************
valorPagar - Retorna o valor que a pessoa tem registado para pagar.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: i->valorPagar - retorna o valor a pagar
Pre-condicoes: i!=NULL
**********************************************/
float valorPagar(pessoa i);

/***********************************************
statusFila - Retorna um valor (0 ou 1) conforme a pessoa se encontra ou nao na fila.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: 0 - Se nao estiver na fila; 1 - Se estiver na fila
Pre-condicoes: i!=NULL
**********************************************/
int statusFila(pessoa i);

/***********************************************
acresHora - Acrescenta o valor da entrada de entrada nos trampolins ao registo da pessoa, e muda as variaveis de controlo (i->fila = 0 - ou seja a pessoa sai da fila; i->trampolim = 1 - ou seja a pessoa está no trampolim)
Parametros:
	i - pessoa  - estrutura da pessoa
	h - inteiro - hora de entrada
	m - inteiro - minuto de entrada
Retorno:
Pre-condicoes: i!=NULL
**********************************************/
void acresHora(pessoa i, int h, int m);

/***********************************************
statusTrampolim - Retorna um valor (0 ou 1) conforme a pessoa se encontra ou nao no trampolim.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: 0 - Se nao estiver no trampolim; 1 - Se estiver no trampolim
Pre-condicoes: i!=NULL
**********************************************/
int statusTrampolim(pessoa i);

/***********************************************
retornaCC - Retorna o numero do cartao do cidadao.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: i->cc - retorna o numero do cartao de cidadao
Pre-condicoes: i!=NULL
**********************************************/
int retornaCC(pessoa i);

/***********************************************
retornaHora - Retorna o valor da hora de entrada no trampolim.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: i->h_entrada - retorna a hora de entrada
Pre-condicoes: i!=NULL
**********************************************/
int retornaHora(pessoa i);

/***********************************************
retornaMin - Retorna o valor dos minutos de entrada no trampolim.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: i->m_entrada - retorna os minutos de entrada
Pre-condicoes: i!=NULL
**********************************************/
int retornaMin(pessoa i);

/***********************************************
retornaNome - Retorna uma string com o nome.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno: i->nome - retorna a string com o nome da pessoa
Pre-condicoes: i!=NULL
**********************************************/
char * retornaNome(pessoa i);

/***********************************************
changeStatusFila - Muda o valor de i->fila de 0 para 1 para indicar que a pessoa está na fila.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno:
Pre-condicoes: i!=NULL
**********************************************/
void changeStatusFila(pessoa i);

/***********************************************
changeStatusTramp - Muda o valor de i->trampolim de 1 para 0 para indicar que a pessoa ja nao se encontra no trampolim e faz reset as horas.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno:
Pre-condicoes: i!=NULL
**********************************************/
void changeStatusTramp(pessoa i);

/***********************************************
destroiPessoa - destroi a estrutura de uma pessoa.
Parametros:
	i - pessoa - estrutura da pessoa
Retorno:
Pre-condicoes: i!=NULL
**********************************************/
void destroiPessoa(pessoa i);

#endif /* SRC_PESSOA_H_ */
