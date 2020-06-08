/*
 * interpretador.c
 *
 *  Created on: 02/05/2016
 *      Author: Hugo Pirraca  - 42471
 *              Miguel Vieira - 46159
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINHA 50
#define MAXNOME 100

#include "GesPav.h"


void interpretador(pavilhao pav);
void entrarPavilhao(pavilhao pav, char * linha);
void chegadaFila(pavilhao pav, char * linha);
void diversao(pavilhao pav, char * linha);
void pessoaTrampolim(pavilhao pav, char * linha);
void pessoaSaiTrampolim(pavilhao pav, char * linha);
void vendaBar (pavilhao pav, char * linha);
void saida(pavilhao pav, char * linha);

int main(void){
	char linha[MAXLINHA];
	int trampolins, stock_cafe, stock_sumo, stock_bolo, check = 0;
	float valor_cafe, valor_sumo, valor_bolo;

	setvbuf(stdout, NULL, _IONBF, 0);

	fgets(linha, MAXLINHA, stdin);
	if(sscanf(linha,"%d", &trampolins)!=1)
		check = 1;
	fgets(linha, MAXLINHA, stdin);
	if(sscanf(linha,"%d %f", &stock_cafe, &valor_cafe)!=2)
		check = 1;
	fgets(linha, MAXLINHA, stdin);
	if(sscanf(linha,"%d %f", &stock_sumo, &valor_sumo)!=2)
		check = 1;
	fgets(linha, MAXLINHA, stdin);
	if(sscanf(linha,"%d %f", &stock_bolo, &valor_bolo)!=2)
		check = 1;

	if(check==1)
		printf("FIM - Dados invalidos.\n");
	else
	if(!(trampolins<=0 || stock_cafe<=0 || valor_cafe<=0 || stock_sumo<=0 || valor_sumo<=0 || stock_bolo<=0 || valor_bolo<=0)){
		pavilhao pav = criaPavilhao(trampolins, stock_cafe, stock_sumo, stock_bolo, valor_cafe, valor_sumo, valor_bolo);

		printf("Abertura pavilhao.\n");

		interpretador(pav);
	}
	else{
		printf("FIM - Dados invalidos.\n");
	}
	return 0;
}

void interpretador(pavilhao pav){
	char linha[MAXLINHA], cmd;
	fgets(linha, MAXLINHA, stdin);
	cmd = toupper(linha[0]);
	while(cmd!='X'){
		switch(cmd){
		case 'E': entrarPavilhao(pav, linha); break;
		case 'F': chegadaFila(pav, linha); break;
		case 'L': diversao(pav, linha); break;
		case 'T': pessoaTrampolim(pav, linha); break;
		case 'S': pessoaSaiTrampolim(pav, linha); break;
		case 'V': vendaBar(pav, linha); break;
		case 'Q': saida(pav, linha); break;
		case 'C': printf("Caixa: %.2f euros\n", valor_caixa(pav)); break;
		default: printf("Comando invalido.\n");
		}
		fgets(linha, MAXLINHA, stdin);
		cmd = toupper(linha[0]);
	}
	fecho(pav);

	printf("Caixa: %.2f euros.\n", valor_caixa(pav));
	printf("Stock cafe: %d.\n", stock_cafe(pav));
	printf("Stock sumo: %d.\n", stock_sumo(pav));
	printf("Stock bolo: %d.\n", stock_bolo(pav));

	destroiTudo(pav);
}

void entrarPavilhao(pavilhao pav, char * linha){
	char car, nome[MAXNOME], linha2[MAXLINHA];

	int contribuinte=-1, cc=-1, check=0;

	nome[0]='\0';

	sscanf(linha,"%c %d %d", &car, &cc, &contribuinte);
	fgets(linha2, MAXLINHA, stdin);
	sscanf(linha2,"%[^\t\n]s", nome);

	if(contribuinte<=0 || cc<=0 || nome[0]=='\0'){
		printf("Dados invalidos.\n");
	}
	else{
		check = entraPav(pav, contribuinte, cc, nome);
		if(check==1)
			printf("Entrada autorizada.\n");
		else
			printf("Pessoa ja no pavilhao.\n");
	}
}

void chegadaFila(pavilhao pav, char * linha){
	char car;
	int cc, check;

	if(sscanf(linha,"%c %d", &car, &cc)!=2 || cc <= 0)
		printf("Dados invalidos.\n");
	else{
	check = filaPav(pav, cc);
	if(check == 0)
		printf("Pessoa nao esta no pavilhao.\n");
	else
	if(check == 1)
		printf("Chegada nao autorizada a fila.\n");
	else
		printf("Chegada autorizada a fila.\n");
	}
}

void diversao(pavilhao pav, char * linha){
	char car, aux;
	int h, m, n;

	if(sscanf(linha, "%c %d %c %d", &car, &h, &aux, &m)!=4 || aux!=':' || (h<=0&&h>24) ||(m<0&&m>=60))
		printf("Dados invalidos.\n");
	else{
		n = saltaPav(pav, h, m);

		if(n==-1)
			printf("Trampolins ocupados.\n");
		else
		if(n==0)
			printf("Fila vazia.\n");
		else
		printf("Entrada de %d pessoas nos trampolins.\n", n);
	}
}

void pessoaTrampolim(pavilhao pav, char * linha){
	char car;
	int n, i;

	if(sscanf(linha,"%c %d", &car, &n)!=2)
		printf("Dados invalidos.\n");
	else
		if(n<=0)
		printf("Dados invalidos.\n");
	else{
		i = retornaTrampolin(pav, n);
		if(i==-1)
			printf("Trampolim inexistente.\n");
		else
		if(i==-2)
			printf("Trampolim vazio.\n");
		else
		if(i==0){
			printf("Pessoa %s esta no trampolim.\n", nomePessoa(pav, n));
		}
	}
}

void pessoaSaiTrampolim(pavilhao pav, char * linha){
	char car;
	int cc, h_out, m_out, check;

	if(sscanf(linha,"%c %d %d:%d", &car, &cc, &h_out, &m_out)!=4 || (h_out<=0&&h_out>24) ||(m_out<0&&m_out>=60))
			printf("Dados invalidos.\n");
	else
		check = paraSaltar(pav, cc, h_out, m_out);

	if(check == 0)
		printf("Pessoa não esta no pavilhao.\n");
	if(check == 1)
		printf("Saida trampolim nao autorizada.\n");
	if(check == 2)
		printf("Saida trampolim autorizada.\n");
}

void vendaBar(pavilhao pav, char * linha){
	char car, produto;
	int quantidade, cc, check;

	if(sscanf(linha,"%c %c %d %d", &car, &produto, &quantidade, &cc)!=4 || quantidade<=0 || cc<=0)
		printf("Dados invalidos.\n");
	else{
		produto = toupper(produto);

		if(!(produto == 'C' || produto == 'S' || produto == 'B'))
			printf("Dados invalidos.\n");
		else{
			check = vendaPav(pav, produto, quantidade, cc);

			if(check == 0)
				printf("Produto %c esgotado.\n", produto);
			else
			if(check == 1)
				printf("Pessoa nao esta no pavilhao.\n");
			else
			if(check == 2)
				printf("Venda nao autorizada.\n");
			else
				printf("Venda autorizada.\n");
		}
	}
}

void saida(pavilhao pav, char * linha){
	char car;
	int cc;
	float valor;

	if(sscanf(linha,"%c %d", &car, &cc)!=2 || cc<=0)
		printf("Dados invalidos.\n");
	else{
		valor = sairPav(pav, cc);

		if(valor==0)
			printf("Pessoa nao esta no pavilhao.\n");
		else
		if(valor == -1)
			printf("Saida nao autorizada.\n");
		else
			printf("Saida autorizada, valor a pagar %.2f euros.\n", valor);
	}
}

