#include "transcricoes.h"

char* transcricaoDestino(int dt) {
	if (dt == 1) {
		return "Orbita Terrestre Baixa";
	} else if (dt == 2) {
		return "ISS";
	} else if (dt == 3) {
		return "Estacao Lunar";
	} else if (dt == 4) {
		return "Lua";
	} else {
		return "Marte";
	}
}

char* transcricaoLocal(int l) {
	if (l == 1) {
		return "Alcantara - Brasil";
	} else if (l == 2) {
		return "Cabo Canaveral - EUA";
	} else if (l == 3) {
		return "Baikonur - Cazaquistao";
	} else if (l == 4) {
		return "Kourou - Guiana Francesa";
	} else {
		return "Vandenberg - EUA";
	}
}

char* transcricaoPrioridade(int p) {
	if (p == 1) {
		return "Critica";
	} else if (p == 2) {
		return "Alta";
	} else if (p == 3) {
		return "Media";
	} else if (p == 4) {
		return "Baixa";
	} else {
		return "Muito baixa";
	}
}

char* transcricaoStatus(int s) {
	if (s == 1) {
		return "Planejada";
	} else if (s == 2) {
		return "Em andamento";
	} else if (s == 3) {
		return "Concluida";
	} else {
		return "Cancelada";
	}
}
