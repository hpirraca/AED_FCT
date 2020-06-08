/*
 * chaves.h
 */

#ifndef _H_CHAVES
#define _H_CHAVES

/***********************************************
igualChaves - Indica se duas chaves de um dado tipo são iguais.
Parâmetros:
	ch1 - chave (void *)
	ch2 - chave (void *)
	tipo - 0 - inteiro; 1- string
Retorno: 1 - caso as chaves sejam iguais; 0- caso contrário
Pré-condições: a1 != NULL && a2 != NULL
**********************************************/
int igualChaves (void * ch1, void * ch2, int tipo);

/***********************************************
dispersão - Retorna o valor associado à função de dispersão
aplicada à chave dada do tipo dado, numa tabela de dispersão
com dimensão dada.
Parâmetros:
	chave - endereço da chave (void *)
	tamV - dimensão da tabela de dispersão
	tipoChave - 0 - inteiro; 1- string
Retorno: valor da função de dispersão (posição na tabela dedispersão)
Pré-condições: chave != NULL
**********************************************/
int dispersao(void * chave, int tamV,int tipoChave);

#endif /* CHAVES_H_ */
