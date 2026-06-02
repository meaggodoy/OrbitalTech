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
