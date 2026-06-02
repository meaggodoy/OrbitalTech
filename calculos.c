#include "calculos.h"

int distanciaDestino(int dt) {
	if(dt == 1) {
		return 400;
	} else if(dt == 2) {
		return 420;
	} else if(dt == 3) {
		return 384000;
	} else if(dt == 4) {
		return 384400;
	} else {
		return 225000000;
	}
}

float fatorDestino(int dt) {
	if(dt == 1) {
		return 1;
	} else if(dt == 2) {
		return 1.2;
	} else if(dt == 3) {
		return 2;
	} else if(dt == 4) {
		return 2.2;
	} else {
		return 4;
	}
}

float fatorLocal(int l) {
	if(l == 1) {
		return 0.9;
	} else if(l == 2) {
		return 1.1;
	} else if(l == 3) {
		return 1;
	} else if(l == 4) {
		return 1.05;
	} else {
		return 1.15;
	}
}

float calcularCombustivel(float c, int dt, int a, int d) {
	c = (distanciaDestino(dt) * 0.00001) + (a * 50) + (d * 10);
	return c;
}

float calcularOrcamento(float o, float c, int d, int a, int dt, int l) {
	o = (1000 + (c * 0.5) + (d * 2) + (a * 20)) * fatorDestino(dt) * fatorLocal(l);
	return o;
}
