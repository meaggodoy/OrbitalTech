#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "calculos.h"

void zerarDados(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
    int i;
    
    for(i = 0; i < 10; i++) {
        strcpy(n[i], " ");
        dt[i] = 0;
        l[i] = 0;
        a[i] = 0;
        d[i] = 0;
        p[i] = 0;
        c[i] = 0;
        o[i] = 0;
        s[i] = 0;
    }
}

void cadastrarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
    int i, continuarCadastro;
    
    printf("\n=============================================================\n");
    printf("           CADASTRO DE NOVA MISSAO ESPACIAL\n");
    printf("=============================================================\n\n");
    
    for(i = *k; i < 2; i++) {
    	printf("Missao %d", i + 1);
        printf("\nNome da Missao: ");
        scanf("%s", n[i]);
        
        printf("+----+---------------------------+----------------+\n");
        printf("| ID | DESTINO                  | DISTANCIA (KM) |\n");
        printf("+----+---------------------------+----------------+\n");
        printf("| 1  | Orbita Terrestre Baixa   | 400            |\n");
        printf("| 2  | ISS                      | 420            |\n");
        printf("| 3  | Esta??o Lunar            | 384000         |\n");
        printf("| 4  | Lua                      | 384400         |\n");
        printf("| 5  | Marte                    | 225000000      |\n");
        printf("+----+---------------------------+----------------+\n");
        printf("Escolha o destino (1-5): ");
        scanf("%d", &dt[i]);
        dt[i] = validarDestino(dt[i]);
        
        printf("+----+-------------------+------------------+\n");
        printf("| ID | LOCAL             | PAIS             |\n");
        printf("+----+-------------------+------------------+\n");
        printf("| 1  | Alcantara         | Brasil           |\n");
        printf("| 2  | Cabo Canaveral    | EUA              |\n");
        printf("| 3  | Baikonur          | Cazaquistao      |\n");
        printf("| 4  | Kourou            | Guiana Francesa  |\n");
        printf("| 5  | Vandenberg        | EUA              |\n");
        printf("+----+-------------------+------------------+\n");
        printf("Escolha o local de lancamento (1-5): ");
        scanf("%d", &l[i]);
        l[i] = validarLocal(l[i]);
        
        printf("Quantidade de astronautas (1 a 8): ");
        scanf("%d", &a[i]);
        a[i] = validarAstronautas(a[i]);
        
        printf("Previsao de duracao da missao (em dias de 1 a 1000): ");
        scanf("%d", &d[i]);
        d[i] = validarDias(d[i]);
        
        printf("=========================================\n");
        printf("             PRIORIDADE\n");
        printf("=========================================\n");
        printf("1 - Critica\n");
        printf("2 - Alta\n");
        printf("3 - Media\n");
        printf("4 - Baixa\n");
        printf("5 - Muito Baixa\n");
        printf("=========================================\n");
        printf("Escolha a prioridade (1-5): ");
        scanf("%d", &p[i]);
        p[i] = validarPrioridade(p[i]);
    
    	c[i] = calcularCombustivel(c[i], dt[i], a[i], d[i]);
    	o[i] = calcularOrcamento(o[i], c[i], d[i], a[i], dt[i], l[i]);
        
        s[i] = 1;
        
        (*k)++;
    }
}

void listarMissoes(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	int i;
	
	printf("\n");
	printf("====================================================================================================\n");
	printf("| ID | NOME MISSAO     | DESTINO | LOCAL      | AST | DIAS | PRIOR. | STATUS       |\n");
	printf("====================================================================================================\n");
	for(i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0) {
			printf("| %d | %s     | %d     | %d  |  %d  |  %d  |    %d   | %d    |\n", i + 1);
		}
	}
	printf("====================================================================================================\n");
}

void gestaoMissoes(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
	int menuGestao;
	
	do {
		printf("\n");
		printf("====================================================\n");
		printf("              GESTAO DE MISSOES\n");
		printf("====================================================\n");
		printf("1 - Cadastrar Missao\n");
		printf("2 - Consultar Missao\n");
		printf("3 - Listar Todas as Missoes\n");
		printf("4 - Atualizar Dados da Missao\n");
		printf("5 - Voltar ao Menu Principal\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuGestao);
		menuGestao = validarGestaoMissoes(menuGestao);
		
		switch (menuGestao) {
			case 1:
				cadastrarMissao(n, dt, l, a, d, p, c, o, s, k);
				break;
			case 2:
				//consultarMissao();
				break;
			case 3:
				listarMissoes(n, dt, l, a, d, p, c, o, s);
				break;
		}
	} while (menuGestao != 5);
}

void operacoesMissao() {
	int menuOperacoes;
	
	do {
		printf("\n");
		printf("====================================================\n");
		printf("             OPERACOES DA MISSAO\n");
		printf("====================================================\n");
		printf("1 - Iniciar Missao\n");
		printf("2 - Finalizar Missao\n");
		printf("3 - Cancelar Missao\n");
		printf("4 - Consultar Status da Missao\n");
		printf("5 - Voltar ao Menu Principal\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuOperacoes);
		menuOperacoes = validarOperacoesMissao(menuOperacoes);
	} while (menuOperacoes != 5);
}

void analisesRelatorios() {
	int menuRelatorios;
	
	do {
		printf("\n");
		printf("====================================================\n");
		printf("          ANALISES E RELATORIOS\n");
		printf("====================================================\n");
		printf("1 - Indicadores Financeiros\n");
		printf("2 - Indicadores Operacionais\n");
		printf("3 - Indicadores de Recursos\n");
		printf("4 - Relatorios\n");
		printf("5 - Central de Pesquisa\n");
		printf("6 - Voltar ao Menu Principal\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuRelatorios);
		menuRelatorios = validarAnalisesRelatorios(menuRelatorios);
	} while (menuRelatorios != 6);
}

void menuPrincipal(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
	int menu;
	
	do {
		printf("====================================================\n");
		printf("      SISTEMA DE MISSOES ESPACIAIS ORBITALTECH\n");
		printf("====================================================\n");
		printf("1 - Gestao de Missoes\n");
		printf("2 - Operacoes da Missao\n");
		printf("3 - Analises e Relatorios\n");
		printf("4 - Encerrar Sistema\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menu);
		menu = validarMenuPrincipal(menu);
		
		switch(menu) {
			case 1:
				gestaoMissoes(n, dt, l, a, d, p, c, o, s, k);
				break;
			case 2:
				operacoesMissao();
				break;
			case 3: 
				analisesRelatorios();
				break;
			case 4:
				printf("\n");
				printf("====================================================\n");
				printf("          ENCERRANDO O SISTEMA\n");
				printf("====================================================\n");
				printf("Obrigado por utilizar o Sistema OrbitalTech.\n");
				printf("Todos os dados foram processados com sucesso.\n");
				printf("Ate a proxima missao.\n");
				printf("====================================================\n");
				break;
		}
	} while (menu != 4);
}

void mensagemInicial(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
    printf("====================================================\n");
    printf("   SISTEMA DE ANALISE DE MISSOES ESPACIAIS\n");
    printf("====================================================\n\n");
    printf("Bem-vindo(a) ao Sistema de Gerenciamento e Analise\nde Missoes Espaciais da agencia OrbitalTech.\n\n");
    printf("Este sistema permite registrar, monitorar e analisar\nmissoes espaciais, acompanhando informacoes como\ndestino, local de lancamento, combustivel estimado,\norcamento e status operacional.\n\n");
    printf("Alem do gerenciamento das missoes, o sistema gera\nindicadores e relatorios que auxiliam na investigacao\ndos fatores que impactam os custos das operacoes\nespaciais.\n\n");
    printf("====================================================\n");
    
    //So para conseguir visualizar a inicializacao, se for melhor depois muda
    int comecar;
    
    printf("Acessar menu?\n1 - Sim\n2 - Nao\n");
    scanf("%d", &comecar);
    
    if (comecar == 1) {
	    #ifdef _WIN32
	        system("cls");
	    #else
	        system("clear");
	    #endif
	    menuPrincipal(n, dt, l, a, d, p, c, o, s, k);
	}  
}

int main()
{
    char nomeMissao[10][50];
    int destino[10], localLancamento[10], astronautas[10], dias[10], prioridade[10], status[10], k = 0;
    float combustivel[10], orcamento[10];
    
    zerarDados(nomeMissao, destino, localLancamento, astronautas, dias, prioridade, combustivel, orcamento, status);
    mensagemInicial(nomeMissao, destino, localLancamento, astronautas, dias, prioridade, combustivel, orcamento, status, &k);
    
    return 0;
}
