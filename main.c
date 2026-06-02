#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"

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

void mensagemInicial() {
    printf("====================================================\n");
    printf("   SISTEMA DE ANÁLISE DE MISSÕES ESPACIAIS\n");
    printf("====================================================\n\n");
    
    printf("Bem-vindo(a) ao Sistema de Gerenciamento e Análise\nde Missões Espaciais da agência OrbitalTech.\n\n");
    printf("Este sistema permite registrar, monitorar e analisar\nmissões espaciais, acompanhando informações como\ndestino, local de lançamento, combustível estimado,\norçamento e status operacional.\n\n");
    printf("Além do gerenciamento das missões, o sistema gera\nindicadores e relatórios que auxiliam na investigação\ndos fatores que impactam os custos das operações\nespaciais.\n\n");
    printf("====================================================\n");
    
    //Só para conseguir visualizar a inicialização, se for melhor depois muda
    int comecar;
    
    printf("Vamos comecar?\n1 - Sim\n2 - Nao\n");
    scanf("%d", &comecar);
    
    if (comecar == 1) {
	    #ifdef _WIN32
	        system("cls");
	    #else
	        system("clear");
	    #endif
	}
    
    
}

void cadastrarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
    int i, continuarCadastro;
    
    printf("\n=============================================================\n");
    printf("           CADASTRO DE NOVA MISSAO ESPACIAL\n");
    printf("=============================================================\n\n");
    
    for(i = *k; i < 10; i++) {
        printf("Nome da Missao: ");
        scanf("%s\n", &n[i]);
        
        printf("+----+---------------------------+----------------+\n");
        printf("| ID | DESTINO                  | DISTANCIA (KM) |\n");
        printf("+----+---------------------------+----------------+\n");
        printf("| 1  | Orbita Terrestre Baixa   | 400            |\n");
        printf("| 2  | ISS                      | 420            |\n");
        printf("| 3  | Estação Lunar            | 384000         |\n");
        printf("| 4  | Lua                      | 384400         |\n");
        printf("| 5  | Marte                    | 225000000      |\n");
        printf("+----+---------------------------+----------------+\n");
        printf("Escolha o destino (1-5): ");
        scanf("%d\n", &dt[i]);
        
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
        scanf("%d\n", &l[i]);
        
        printf("Quantidade de astronautas (1 a 8): ");
        scanf("%d\n", &a[i]);
        
        printf("Previsao de duracao da missao (em dias de 1 a 1000): ");
        scanf("%d\n", &d[i]);
        
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
    
    	
        
        s[i] = 1;
        
        (*k)++;
    }
}

int main()
{
    char nomeMissao[10][50];
    int destino[10], localLancamento[10], astronautas[10], dias[10], prioridade[10], status[10], k = 0;
    float combustivel[10], orcamento[10];
    
    zerarDados(nomeMissao, destino, localLancamento, astronautas, dias, prioridade, combustivel, orcamento, status);
    
    mensagemInicial();
    
    cadastrarMissao(nomeMissao, destino, localLancamento, astronautas, dias, prioridade, combustivel, orcamento, status, &k);

    return 0;
}
