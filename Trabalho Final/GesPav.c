/*
 * GesPav.c
 *
 *  Created on: 02/05/2016
 *      Author: Hugo Pirraca  - 42471
 *     			Miguel Vieira - 46159
 */

#include <stdlib.h>
#include <stdio.h>

#include "iterador.h"
#include "pessoa.h"
#include "fila.h"
#include "dicionario.h"
#include "GesPav.h"

#define MAXFILA 200
#define CAP 1500

struct _pavilhao{
	dicionario pessoas;
	pessoa * trampolins;
	fila trampessoas;
	int s_cafe, s_sumo, s_bolo, maxTrampolim;
	float p_cafe, p_sumo, p_bolo, valor_caixa;
};

pavilhao criaPavilhao(int trampolins, int stock_cafe, int stock_sumo, int stock_bolo, float valor_cafe, float valor_sumo, float valor_bolo){
	int var=0;

	pavilhao p = (pavilhao) malloc(sizeof(struct _pavilhao));
	if(p==NULL)
		return NULL;

	p->trampolins = (pessoa *)malloc(trampolins * sizeof(pessoa));
	if(p->trampolins==NULL){
		free(p);
		return NULL;
	}
	while(var<trampolins){
		p->trampolins[var]=NULL;
		var++;
	}

	p->pessoas = criaDicionario(CAP, 0);
	if(p->pessoas==NULL){
		free(p->trampolins);
		free(p);
		return NULL;
	}
	p->trampessoas = criaFila(MAXFILA);
	if(p->trampessoas==NULL){
		destroiDicionario(p->pessoas);
		free(p->trampolins);
		free(p);
		return NULL;
	}

	p->maxTrampolim = trampolins;
	p->s_cafe = stock_cafe;
	p->s_sumo = stock_sumo;
	p->s_bolo = stock_bolo;
	p->p_cafe = valor_cafe;
	p->p_sumo = valor_sumo;
	p->p_bolo = valor_bolo;

	p->valor_caixa = 0;
	return p;
}

int entraPav(pavilhao p, int contribuinte, int cc, char * nome){
	int entrou = 0;
	pessoa i = criaPessoa(cc, contribuinte, nome);
	entrou = adicionaElemDicionario(p->pessoas, (void *) &cc, (void *) i);
	return entrou;
}

int filaPav(pavilhao p, int cc){

	if(existeElemDicionario(p->pessoas, (void *) &cc)){
	pessoa i = elementoDicionario(p->pessoas, (void *) &cc);
		if(statusFila(i) == 0 && statusTrampolim(i)==0){
			adicionaElemFila(p->trampessoas, (void *) i);
			changeStatusFila(i);
			return 2;
		}
		return 1;
	}
	else return 0;
}

int saltaPav(pavilhao p, int h, int m){
	pessoa i;
	int k=0, n=0, var=0, v=0;

	while(var<p->maxTrampolim){
		i = p->trampolins[var];
		if(i == NULL){
			var ++;
			continue;
		}
		v++;
		var++;
		if(v==p->maxTrampolim)
			return -1;
	}

	while(k<p->maxTrampolim && vaziaFila(p->trampessoas)!=1){
		acresHora(elementoFila(p->trampessoas), h, m);

		if(p->trampolins[k]!=0){
			k++;
			continue;
		}
		pessoa j = removeElemFila(p->trampessoas);
		p->trampolins[k] = j;
		n++;
		k++;
	}
	return n;
}

int vendaPav(pavilhao p, char produto, int quantidade, int cc){
	pessoa i;
	float valor = 0;

	if(existeElemDicionario(p->pessoas, &cc)){
		i = (pessoa) elementoDicionario(p->pessoas, &cc);

		if(statusFila(i)==1 || statusTrampolim(i)==1)
			return 2;

		if(produto=='C'){
			if(quantidade <= p->s_cafe){
				valor = p->p_cafe*quantidade;
				p->s_cafe = p->s_cafe - quantidade;
			}
			else return 0;
		}
		if(produto=='S'){
			if(quantidade <= p->s_sumo){
				valor = p->p_sumo*quantidade;
				p->s_sumo = p->s_sumo - quantidade;
			}
			else return 0;
		}
		if(produto=='B'){
			if(quantidade <= p->s_bolo){
				valor = p->p_bolo*quantidade;
				p->s_bolo = p->s_bolo - quantidade;
			}
			else return 0;
		}

		acresConta(i, valor);

		return 3;
	}
	return 1;
}

int retornaTrampolin(pavilhao p, int i){
	if(i > p->maxTrampolim)
		return -1;

	if(p->trampolins[i-1]!=NULL){
		pessoa n = p->trampolins[i-1];
		if(n==NULL)
			return -2;
		return 0;
	}
	return -2;
}

pessoa retornaPessoa(pavilhao p, int i){
	pessoa n = p->trampolins[i-1];
	return n;
}

char * nomePessoa(pavilhao p, int i){
	pessoa n = retornaPessoa(p, i);
	return retornaNome(n);
}

int paraSaltar(pavilhao p, int cc, int h_out, int m_out){
	int var=0;
    float preco_pagar, tempo;
    pessoa i;

    while(var<p->maxTrampolim){
		i = p->trampolins[var];
		if(i == NULL){
			var ++;
			continue;
		}
		if(retornaCC(i) != cc){
			if(var+1 == p->maxTrampolim)
				return 1;
			if(existeElemDicionario(p->pessoas, &cc)==0)
				return 0;
		}
		else
			break;
		var++;
	}
	if(h_out < retornaHora(i) || (retornaHora(i)==h_out && retornaMin(i)>m_out) || (retornaHora(i)==h_out && retornaMin(i)==m_out))
		return 1;
	else{
		tempo = (h_out - retornaHora(i))*60 + (m_out - retornaMin(i));
		tempo = tempo/30;
		if(tempo > (int)tempo)
			tempo = (int) tempo + 1;
		changeStatusTramp(i);
		preco_pagar = tempo * 5;
		acresConta(i, preco_pagar);
		p->trampolins[var]=NULL;
		return 2;
	}
}

float sairPav(pavilhao p, int cc){
	pessoa i;
	float valor;

	if(existeElemDicionario(p->pessoas, &cc)){
		i = (pessoa) elementoDicionario(p->pessoas, &cc);
		if(statusFila(i)==1 || statusTrampolim(i)==1)
			return -1;

		i = (pessoa) removeElemDicionario(p->pessoas, &cc);
		p->valor_caixa = p->valor_caixa + valorPagar(i);
		valor = valorPagar(i);
		destroiPessoa(i);
		return valor;
	}
	else return 0;
}

void fecho(pavilhao p){
	pessoa i;
	iterador it;
	int var=0, h_out=24, m_out=0;

	while(var<p->maxTrampolim){
		i = p->trampolins[var];
		if(i == NULL){
			var ++;
			continue;
		}
		paraSaltar(p, retornaCC(i), h_out, m_out);
		var++;
	}

	it = iteradorChaveDicionario(p->pessoas);

	while(temSeguinteIterador(it)!=0){
		i = (pessoa) removeElemDicionario(p->pessoas, seguinteIterador(it));
		p->valor_caixa = p->valor_caixa + valorPagar(i);
		destroiPessoa(i);
	}

	destroiIterador(it);
}

void destroiTudo(pavilhao p){
	destroiFila(p->trampessoas);
	destroiDicionario(p->pessoas);
	free(p->trampolins);
	free(p);
}


int stock_cafe(pavilhao p){
	return p->s_cafe;
}

int stock_sumo(pavilhao p){
	return p->s_sumo;
}

int stock_bolo(pavilhao p){
	return p->s_bolo;
}

float valor_caixa(pavilhao p){
	return p->valor_caixa;
}
