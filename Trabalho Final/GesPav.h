/*
 * GesPav.h
 *
 *  Created on: 02/05/2016
 *      Author: Hugo Pirraca  - 42471
 *     			Miguel Vieira - 46159
 */

#ifndef SRC_GESPAV_H_
#define SRC_GESPAV_H_

typedef struct _pavilhao * pavilhao;

/***********************************************
criaPavilhao - Cria pavilhao. Abre a zona de trampolins, a fila e o bar.
Parametros:
	trampolins - inteiro - numero de trampolins disponiveis
	stock_cafe - inteiro - numero de cafes para consumo
	stock_sumo - inteiro - numero de sumos para consumo
	stock_bolo - inteiro - numero de bolos para consumo
	valor_cafe - float   - preco dos cafes
	valor_sumo - float   - preco dos sumos
	valor_bolo - float   - preco dos bolos
Retorno: NULL- caso nao seja possivel alocar memoria; p- caso tenha sido possivel criar o pavilhao;
Pre-condicoes: trampolins>0; stock_cafe>0; valor_cafe>0; stock_sumo>0; valor_sumo>0; stock_bolo>0; valor_bolo>0
**********************************************/
pavilhao criaPavilhao(int trampolins, int stock_cafe, int stock_sumo, int stock_bolo, float valor_cafe, float valor_sumo, float valor_bolo);

/***********************************************
entraPav - Entrada de pessoa no pavilhao.
Parametros:
	p            - pavilhao - estrutura do pavilhao
	contribuinte - inteiro  - numero de contribuinte
	cc           - inteiro  - numero do cartao do cidadao
	nome         - char *   - nome da pessoa
Retorno: 1 - caso a pessoa tenha entrado no pavilhao; 0 - caso a pessoa já esteja no pavilhao
Pre-condicoes: contribuinte>0; cc>0; nome[0]!='\0'; p!=NULL
**********************************************/
int entraPav(pavilhao p, int contribuinte, int cc, char * nome);

/***********************************************
filaPav - Entrada de pessoa na fila.
Parametros:
	p  - pavilhao - estrutura do pavilhao
	cc - inteiro  - numero do cartao do cidadao
Retorno: 0 - Pessoa nao esta no pavilhao; 1 - Chegada nao autorizada a fila; 2 - Chegada autorizada a fila
Pre-condicoes: cc>0; p!=NULL
**********************************************/
int filaPav(pavilhao p, int cc);

/***********************************************
saltaPav - Entrada das pessoas no trampolim na hora indicada.
Parametros:
	p - pavilhao - estrutura do pavilhao
	h - inteiro  - hora de entrada nos trampolins
	m - inteiro  - minuto de entrada nos trampolins
Retorno: -1 - Trampolins ocupados; 0 - Fila vazia; n - Entrada de "n" pessoas nos trampolins
Pre-condicoes: h>0 && h<=24 && m>=0 && m<60; p!=NULL
**********************************************/
int saltaPav(pavilhao p, int h, int m);

/***********************************************
vendaPav - Venda de produtos (cafe, sumo ou bolo) no bar do pavilhao.
Parametros:
	p          - pavilhao - estrutura do pavilhao
	produto    - char     - tipo do produto
	quantidade - inteiro  - numero de produtos do tipo introduzido que vao ser consumidos
	cc         - inteiro  - numero do cartao do cidadao
Retorno: 0 - Produto escolhido esgotado; 1 - Pessoa nao esta no pavilhao; 2 - Venda nao autorizada; 3 - Venda autorizada
Pre-condicoes: produto=='C' || produto=='S' || produto=='B'; quantidade>0; cc>0 ;statusFila(i)!=1; statusTrampolim(i)!=1; p!=NULL
**********************************************/
int vendaPav(pavilhao p, char produto, int quantidade, int cc);

/***********************************************
retornaTrampolim - Indica se se encontra alguem no trampolim introduzido.
Parametros:
	p - pavilhao - estrutura do pavilhao
	i - inteiro  - numero identificador do trampolim
Retorno: -1 - Trampolim inexistente; -2 - Trampolim vazio; 0 - Pessoa "nome" esta no trampolim
Pre-condicoes: i>0; p!=NULL
**********************************************/
int retornaTrampolin(pavilhao p, int i);

/***********************************************
nomePessoa - Depois de se garantir que está alguem no trampolim, indica quem está no trampolim.
Parametros:
	p - pavilhao - estrutura do pavilhao
	i - inteiro  - numero identificador do trampolim
Retorno: retornaNome(n) - retorna o nome da pessoa; n - numero de cidadao da pessoa
Pre-condicoes: i>0; p!=NULL
**********************************************/
char * nomePessoa(pavilhao p, int i);

/***********************************************
paraSaltar - Saida de pessoa do trampolim na hora indicada
Parametros:
	p     - pavilhao - estrutura do pavilhao
	cc    - inteiro  - numero do cartao do cidadao
	h_out - inteiro  - hora de saida
	m_out - inteiro  - minuto de saida
Retorno: 0 - Pessoa não esta no pavilhao; 1 Saida trampolim nao autorizada- ; 2 - Saida trampolim autorizada
Pre-condicoes: cc>0 && h_out>0 && h_out<=24 && m_out>=0 && m_out<60; p!=NULL
**********************************************/
int paraSaltar(pavilhao p, int cc, int h_out, int m_out);

/***********************************************
sairPav - Saida de pessoa do pavilhao e pagamento da divida.
Parametros:
	p  - pavilhao - estrutura do pavilhao
	cc - inteiro  - numero do cartao do cidadao
Retorno: -1 - Saida nao autorizada; 0 - Pessoa nao esta no pavilhao; valor - Saida autorizada, valor a pagar "valor" euros
Pre-condicoes: cc>0; p!=NULL
**********************************************/
float sairPav(pavilhao p, int cc);

/***********************************************
fecho - Fecho do pavilhao e saida de todas as pessoas que nele se encontram e pagamento das respetivas dividas.
Parametros:
	p - pavilhao - estrutura do pavilhao
Retorno: Nao retorna nada mas guarda em caixa o valor final depois de todos os clientes terem saido
Pre-condicoes: p!=NULL
**********************************************/
void fecho(pavilhao p);

/***********************************************
destroiTudo - destroi as estruturas e os elementos restantes que estao no pavilhao
Parametros:
	p - pavilhao - estrutura do pavilhao
Retorno:
Pre-condicoes: p!=NULL
**********************************************/
void destroiTudo(pavilhao p);

/***********************************************
stock_cafe - Retorna o stock do cafe
Parametros:
	p - pavilhao - estrutura do pavilhao
Retorno: p->s_cafe - valor do stock do cafe
Pre-condicoes:
**********************************************/
int stock_cafe(pavilhao p);

/***********************************************
stock_sumo - Retorna o stock do sumo
Parametros:
	p - pavilhao - estrutura do pavilhao
Retorno: p->s_sumo - valor do stock do sumo
Pre-condicoes: p!=NULL
**********************************************/
int stock_sumo(pavilhao p);

/***********************************************
stock_bolo - Retorna o stock do bolo
Parametros:
	p - pavilhao - estrutura do pavilhao
Retorno: p->s_bolo - valor do stock do bolo
Pre-condicoes: p!=NULL
**********************************************/
int stock_bolo(pavilhao p);

/***********************************************
valor_caixa - Retorna o valor em caixa
Parametros:
	p - pavilhao - estrutura do pavilhao
Retorno: p->valor_caixa - dinheiro em caixa
Pre-condicoes: p!=NULL
**********************************************/
float valor_caixa(pavilhao p);

#endif /* SRC_GESPAV_H_ */
