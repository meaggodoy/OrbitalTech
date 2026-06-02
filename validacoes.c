#include <stdio.h>
#include "validacoes.h"

int validarDestino(int d) {
	do {
		if(d < 1 || d > 5) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 5.\n");
			scanf("%d", &d);
		}
	} while (d < 1 || d > 5);
	
	return d;
}

int validarLocal(int l) {
	do {
		if(l < 1 || l > 5) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 5.\n");
			scanf("%d", &l);
		}
	} while (l < 1 || l > 5);
	
	return l;
}

int validarAstronautas(int a) {
	do {
		if(a < 1 || a > 8) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 8.\n");
			scanf("%d", &a);
		}
	} while (a < 1 || a > 8);
	
	return a;
}

int validarDias(int d) {
	do {
		if(d < 1 || d > 1000) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 1000.\n");
			scanf("%d", &d);
		}
	} while (d < 1 || d > 1000);
	
	return d;
}

int validarPrioridade(int p) {
	do {
		if(p < 1 || p > 5) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 5.\n");
			scanf("%d", &p);
		}
	} while (p < 1 || p > 5);
	
	return p;
}

int validarMenuPrincipal(int m) {
	do {
		if(m < 1 || m > 4) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 4.\n");
			scanf("%d", &m);
		}
	} while (m < 1 || m > 4);
	
	return m;
}

int validarGestaoMissoes(int m) {
	do {
		if(m < 1 || m > 5) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 5.\n");
			scanf("%d", &m);
		}
	} while (m < 1 || m > 5);
	
	return m;
}

int validarOperacoesMissao(int m) {
	do {
		if(m < 1 || m > 5) {
			printf("\n[ERRO] Valor invalido. Informe um numero entre 1 e 5.\n");
			scanf("%d", &m);
		}
	} while (m < 1 || m > 5);
	
	return m;
}
