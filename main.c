#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "calculos.h"
#include "transcricoes.h"

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

void limparSistema() {
	#ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void cadastrarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
	limparSistema();
    int i, continuarCadastro;
    
    if (*k < 10) {
    	for(i = *k; i < 10; i++) {
    		printf("\n=============================================================\n");
		    printf("           CADASTRO DE NOVA MISSAO ESPACIAL\n");
		    printf("=============================================================\n\n");
	    	printf("Missao %02d", i + 1);
	        printf("\nNome da Missao: ");
	        scanf("%s", n[i]);
	        
	        printf("+----+---------------------------+----------------+\n");
	        printf("| ID | DESTINO                  | DISTANCIA (KM) |\n");
	        printf("+----+---------------------------+----------------+\n");
	        printf("| 1  | Orbita Terrestre Baixa   | 400            |\n");
	        printf("| 2  | ISS                      | 420            |\n");
	        printf("| 3  | Estacao Lunar            | 384000         |\n");
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
	        
	        printf("\n");
			printf("====================================================\n");
			printf("            MISSAO REGISTRADA COM SUCESSO\n");
			printf("====================================================\n");
			
	        if (*k < 10) {
	        	printf("Deseja registrar uma nova missao?\n");
				printf("1 - Sim\n2 - Nao\n");
				printf("====================================================\n");
				printf("Escolha uma opcao: ");
				scanf("%d", &continuarCadastro);
				
				limparSistema();
				
				if (continuarCadastro == 2) {
					break;
				}
			} else {
				printf("Limite para cadastro de missões atingido\n");
			}
	    }
	} else {
		printf("Limite para cadastro de missões atingido\n");
	}
    limparSistema();
}

void consultarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int menuConsulta, buscaInt, i, quantidadeResultados = 0;
	char buscaStr[50];
		
	do {
		printf("\n");
		printf("====================================================\n");
		printf("              CONSULTA DE MISSOES\n");
		printf("====================================================\n");
		printf("1 - Consultar por ID\n");
		printf("2 - Consultar por Nome\n");
		printf("3 - Consultar por Status\n");
		printf("4 - Consultar por Prioridade\n");
		printf("5 - Consultar por Destino\n");
		printf("6 - Consultar por Local de Lancamento\n");
		printf("7 - Voltar\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuConsulta);
		menuConsulta = validarConsulta(menuConsulta);
		
		switch (menuConsulta) {
			case 1:
				quantidadeResultados = 0;
				limparSistema();
				
				printf("\n");
				printf("====================================================\n");
				printf("              CONSULTA POR ID\n");
				printf("====================================================\n");
				printf("Informe o ID da missao.\n");
				printf("====================================================\n");
				printf("ID: ");
				scanf("%d", &buscaInt);
				
				printf("\n");
				printf("======================================================================================================================\n");
				printf("| ID | NOME                     | DESTINO      | LOCAL        | AST | DIAS | PRI | STATUS        |\n");
				printf("======================================================================================================================\n");
				for(i = 0; i < 10; i++) {
					if(strcmp(n[i], " ") != 0 && buscaInt == i + 1) {
						printf("| %-2d | %-24s | %-24s | %-20s | %-3d | %-4d | %-7s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
						printf("\n----------------------------------------------------------------------------------------------------\n");
						quantidadeResultados++;
					}
				}
				printf("======================================================================================================================\n");
				printf("Resultados encontrados: %d\n", quantidadeResultados);
				break;
			case 2:
				quantidadeResultados = 0;
				limparSistema();
				
				printf("\n");
				printf("====================================================\n");
				printf("             CONSULTA POR NOME\n");
				printf("====================================================\n");
				printf("Informe o nome da missao.\n");
				printf("====================================================\n");
				printf("Nome: ");
				scanf("%s", buscaStr);
				
				printf("\n");
				printf("======================================================================================================================\n");
				printf("| ID | NOME                     | DESTINO      | LOCAL        | AST | DIAS | PRI | STATUS        |\n");
				printf("======================================================================================================================\n");
				for(i = 0; i < 10; i++) {
					if(strcmp(n[i], " ") != 0 && strcmp(strlwr(buscaStr), strlwr(n[i])) == 0) {
						printf("| %-2d | %-24s | %-24s | %-20s | %-3d | %-4d | %-7s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
						printf("\n----------------------------------------------------------------------------------------------------\n");
						quantidadeResultados++;
					}
				}
				printf("======================================================================================================================\n");
				printf("Resultados encontrados: %d\n", quantidadeResultados);
				break;
			case 3:
				quantidadeResultados = 0;
				limparSistema();
				
				printf("\n");
				printf("====================================================\n");
				printf("            CONSULTA POR STATUS\n");
				printf("====================================================\n");
				printf("1 - Planejada\n");
				printf("2 - Em Andamento\n");
				printf("3 - Concluida\n");
				printf("4 - Cancelada\n");
				printf("====================================================\n");
				printf("Escolha um status: ");
				scanf("%d", &buscaInt);
				
				printf("\n");
				printf("======================================================================================================================\n");
				printf("| ID | NOME                     | DESTINO      | LOCAL        | AST | DIAS | PRI | STATUS        |\n");
				printf("======================================================================================================================\n");
				for(i = 0; i < 10; i++) {
					if(strcmp(n[i], " ") != 0 && buscaInt == s[i]) {
						printf("| %-2d | %-24s | %-24s | %-20s | %-3d | %-4d | %-7s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
						printf("\n----------------------------------------------------------------------------------------------------\n");
						quantidadeResultados++;
					}
				}
				printf("======================================================================================================================\n");
				printf("Resultados encontrados: %d\n", quantidadeResultados);
				break;
			case 4:
				quantidadeResultados = 0;
				limparSistema();
				
				printf("\n");
				printf("====================================================\n");
				printf("          CONSULTA POR PRIORIDADE\n");
				printf("====================================================\n");
				printf("1 - Critica\n");
				printf("2 - Alta\n");
				printf("3 - Media\n");
				printf("4 - Baixa\n");
				printf("5 - Muito Baixa\n");
				printf("====================================================\n");
				printf("Escolha uma prioridade: ");
				scanf("%d", &buscaInt);
				
				printf("\n");
				printf("======================================================================================================================\n");
				printf("| ID | NOME                     | DESTINO      | LOCAL        | AST | DIAS | PRI | STATUS        |\n");
				printf("======================================================================================================================\n");
				for(i = 0; i < 10; i++) {
					if(strcmp(n[i], " ") != 0 && buscaInt == p[i]) {
						printf("| %-2d | %-24s | %-24s | %-20s | %-3d | %-4d | %-7s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
						printf("\n----------------------------------------------------------------------------------------------------\n");
						quantidadeResultados++;
					}
				}
				printf("======================================================================================================================\n");
				printf("Resultados encontrados: %d\n", quantidadeResultados);
				break;
			case 5:
				quantidadeResultados = 0;
				limparSistema();
				
				printf("\n");
				printf("====================================================\n");
				printf("            CONSULTA POR DESTINO\n");
				printf("====================================================\n");
				printf("1 - Orbita Terrestre Baixa\n");
				printf("2 - ISS\n");
				printf("3 - Estacao Lunar\n");
				printf("4 - Lua\n");
				printf("5 - Marte\n");
				printf("====================================================\n");
				printf("Escolha um destino: ");
				scanf("%d", &buscaInt);
				
				printf("\n");
				printf("======================================================================================================================\n");
				printf("| ID | NOME                     | DESTINO      | LOCAL        | AST | DIAS | PRI | STATUS        |\n");
				printf("======================================================================================================================\n");
				for(i = 0; i < 10; i++) {
					if(strcmp(n[i], " ") != 0 && buscaInt == dt[i]) {
						printf("| %-2d | %-24s | %-24s | %-20s | %-3d | %-4d | %-7s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
						printf("\n----------------------------------------------------------------------------------------------------\n");
						quantidadeResultados++;
					}
				}
				printf("======================================================================================================================\n");
				printf("Resultados encontrados: %d\n", quantidadeResultados);
				break;
			case 6:
				quantidadeResultados = 0;
				limparSistema();
				
				printf("\n");
				printf("====================================================\n");
				printf("       CONSULTA POR LOCAL DE LANCAMENTO\n");
				printf("====================================================\n");
				printf("1 - Alcantara\n");
				printf("2 - Cabo Canaveral\n");
				printf("3 - Baikonur\n");
				printf("4 - Kourou\n");
				printf("5 - Vandenberg\n");
				printf("6 - Voltar\n");
				printf("====================================================\n");
				printf("Escolha um local: ");
				scanf("%d", &buscaInt);
				
				printf("\n");
				printf("======================================================================================================================\n");
				printf("| ID | NOME                     | DESTINO      | LOCAL        | AST | DIAS | PRI | STATUS        |\n");
				printf("======================================================================================================================\n");
				for(i = 0; i < 10; i++) {
					if(strcmp(n[i], " ") != 0 && buscaInt == l[i]) {
						printf("| %-2d | %-24s | %-24s | %-20s | %-3d | %-4d | %-7s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
						printf("\n----------------------------------------------------------------------------------------------------\n");
						quantidadeResultados++;
					}
				}
				printf("======================================================================================================================\n");
				printf("Resultados encontrados: %d\n", quantidadeResultados);
				break;
		}
	} while (menuConsulta != 7);
}

void listarMissoes(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int i, j = 0;
	float orcamentoTotal = 0;
	
	printf("\n");
	printf("======================================================================================================================\n");
	printf("                                         MISSOES CADASTRADAS\n");
	printf("==================================================================================================================================================================\n");
	printf("| ID | NOME                     | DESTINO                  | LOCAL                     | AST | DIAS | PRI         | STATUS        | COMB.(t) | ORCAMENTO (M US$) |");
	printf("\n==================================================================================================================================================================\n");
	for(i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0) {
			printf("| %-2d | %-24s | %-24s | %-25s | %-3d | %-4d | %-11s | %-13s | %8.2f | %17.2f |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]), c[i], o[i]);
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			j++;
			orcamentoTotal += o[i];
		}
	}
	printf("====================================================================================================\n");
	printf("\nTotal de missoes cadastradas: %d\n", j);
	printf("Orcamento total investido: %.2f milhoes\n", orcamentoTotal);
}

void atualizarDados(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int i, id, j = 0, menuAtualizar;
	
	printf("\n");
	printf("\n======================================================================================================================\n");
	printf("                                          ATUALIZACAO DE MISSAO\n");
	printf("\n======================================================================================================================\n");
	printf("| ID | NOME                     | DESTINO                  | LOCAL                     | AST | DIAS | PRI         | STATUS        |");
	printf("\n======================================================================================================================\n");
	for(i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0) {
			printf("| %-2d | %-24s | %-24s | %-25s | %-3d | %-4d | %-10s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
			j++;
		}
	}
	printf("====================================================\n");
	printf("Informe o ID da missao que deseja atualizar.\n");
	printf("Digite 0 para retornar.\n");
	printf("====================================================\n");
	printf("ID da missao: ");
	scanf("%d", &id);
	id = validarIndice(id, j);
	
	do {
		printf("\n");
		printf("====================================================\n");
		printf("            DADOS DISPONIVEIS PARA EDICAO\n");
		printf("====================================================\n");
		printf("1 - Quantidade de Astronautas\n");
		printf("2 - Duracao Prevista da Missao\n");
		printf("3 - Prioridade\n");
		printf("4 - Atualizar Todos os Campos Permitidos\n");
		printf("5 - Voltar\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuAtualizar);
		menuAtualizar = validarAtualizar(menuAtualizar);
		
		switch (menuAtualizar) {
			case 1:
				limparSistema();
				printf("\n");
				printf("====================================================\n");
				printf("         ATUALIZACAO DE TRIPULACAO\n");
				printf("====================================================\n");
				printf("Quantidade atual: %d\n", a[id-1]);
				printf("Informe a nova quantidade (1 a 8): ");
				scanf("%d", &a[id-1]);
				break;
			case 2:
				limparSistema();
				printf("\n");
				printf("====================================================\n");
				printf("         ATUALIZACAO DA DURACAO\n");
				printf("====================================================\n");
				printf("Duracao atual: %d dias\n", d[id-1]);
				printf("Informe a nova duracao prevista: ");
				scanf("%d", &d[id-1]);
				break;
			case 3:
				limparSistema();
				printf("\n");
				printf("====================================================\n");
				printf("         ATUALIZACAO DE PRIORIDADE\n");
				printf("====================================================\n");
				printf("1 - Critica\n");
				printf("2 - Alta\n");
				printf("3 - Media\n");
				printf("4 - Baixa\n");
				printf("5 - Muito Baixa\n");
				printf("====================================================\n");
				printf("Nova prioridade: ");
				scanf("%d", &p[id-1]);
				break;
			case 4:
				limparSistema();
				printf("\n");
				printf("====================================================\n");
				printf("         ATUALIZACAO DE TRIPULACAO\n");
				printf("====================================================\n");
				printf("Quantidade atual: %d\n", a[id-1]);
				printf("Informe a nova quantidade (1 a 8): ");
				scanf("%d", &a[id-1]);
				printf("\n");
				printf("====================================================\n");
				printf("         ATUALIZACAO DA DURACAO\n");
				printf("====================================================\n");
				printf("Duracao atual: %d dias\n", d[id-1]);
				printf("Informe a nova duracao prevista: ");
				scanf("%d", &d[id-1]);
				printf("\n");
				printf("====================================================\n");
				printf("         ATUALIZACAO DE PRIORIDADE\n");
				printf("====================================================\n");
				printf("1 - Critica\n");
				printf("2 - Alta\n");
				printf("3 - Media\n");
				printf("4 - Baixa\n");
				printf("5 - Muito Baixa\n");
				printf("====================================================\n");
				printf("Nova prioridade: ");
				scanf("%d", &p[id-1]);
				break;
		}
		limparSistema();
		printf("\n");
		printf("====================================================\n");
		printf("      DADOS DA MISSAO ATUALIZADOS COM SUCESSO\n");
		printf("====================================================\n");
		printf("Os calculos de combustivel e orcamento foram\n");
		printf("reprocessados conforme os novos parametros.\n");
		printf("====================================================\n");
	} while (menuAtualizar != 5);
}

void gestaoMissoes(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s, int *k) {
	limparSistema();
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
				consultarMissao(n, dt, l, a, d, p, c, o, s);
				break;
			case 3:
				listarMissoes(n, dt, l, a, d, p, c, o, s);
				break;
			case 4:
				atualizarDados(n, dt, l, a, d, p, c, o, s);
				break;
		}
	} while (menuGestao != 5);
	limparSistema();
}

void iniciarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int i, id;
	
	printf("\n");
	printf("======================================================================================================================\n");
	printf("                                         MISSOES CADASTRADAS\n");
	printf("======================================================================================================================\n");
	printf("| ID | NOME                     | DESTINO                  | LOCAL                     | AST | DIAS | PRI         | STATUS        |");
	printf("\n======================================================================================================================\n");
	for(i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0 && s[i] == 1) {
			printf("| %-2d | %-24s | %-24s | %-25s | %-3d | %-4d | %-10s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
		}
	}
	printf("====================================================================================================\n");
	printf("Informe o ID da missao.\n");
	printf("====================================================\n");
	printf("ID: ");
	scanf("%d", &id);
	
	s[id-1] = 2;
	
	printf("\n");
	printf("====================================================\n");
	printf("            MISSAO INICIADA COM SUCESSO\n");
	printf("====================================================\n");
	printf("Novo status: EM ANDAMENTO\n");
	printf("A tripulacao recebeu autorizacao para decolagem.\n");
	printf("====================================================\n");
}

void finalizarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int i, id;
	
	printf("\n");
	printf("======================================================================================================================\n");
	printf("                                         MISSOES CADASTRADAS\n");
	printf("======================================================================================================================\n");
	printf("| ID | NOME                     | DESTINO                  | LOCAL                     | AST | DIAS | PRI         | STATUS        |");
	printf("\n======================================================================================================================\n");
	for(i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0 && s[i] == 2) {
			printf("| %-2d | %-24s | %-24s | %-25s | %-3d | %-4d | %-10s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
		}
	}
	printf("====================================================================================================\n");
	printf("Informe o ID da missao.\n");
	printf("====================================================\n");
	printf("ID: ");
	scanf("%d", &id);
	
	s[id-1] = 3;
	
	printf("\n");
	printf("====================================================\n");
	printf("           MISSAO CONCLUIDA COM SUCESSO\n");
	printf("====================================================\n");
	printf("Novo status: CONCLUIDA\n");
	printf("Todos os procedimentos foram encerrados.\n");
	printf("Dados operacionais registrados no sistema.\n");
	printf("====================================================\n");
}

void cancelarMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int i, id;
	
	printf("\n");
	printf("======================================================================================================================\n");
	printf("                                         MISSOES CADASTRADAS\n");
	printf("======================================================================================================================\n");
	printf("| ID | NOME                     | DESTINO                  | LOCAL                     | AST | DIAS | PRI         | STATUS        |");
	printf("\n======================================================================================================================\n");
	for(i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0 && s[i] == 1 || s[i] == 2) {
			printf("| %-2d | %-24s | %-24s | %-25s | %-3d | %-4d | %-10s | %-13s |", i + 1, n[i], transcricaoDestino(dt[i]), transcricaoLocal(l[i]), a[i], d[i], transcricaoPrioridade(p[i]), transcricaoStatus(s[i]));
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
		}
	}
	printf("====================================================================================================\n");
	printf("Informe o ID da missao.\n");
	printf("====================================================\n");
	printf("ID: ");
	scanf("%d", &id);
	
	s[id-1] = 4;
	
	printf("\n");
	printf("====================================================\n");
	printf("            MISSAO CANCELADA\n");
	printf("====================================================\n");
	printf("Novo status: CANCELADA\n");
	printf("A operacao foi interrompida e arquivada.\n");
	printf("====================================================\n");
}

void operacoesMissao(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int menuOperacoes;
	
	do {
		printf("\n");
		printf("====================================================\n");
		printf("             OPERACOES DA MISSAO\n");
		printf("====================================================\n");
		printf("1 - Iniciar Missao\n");
		printf("2 - Finalizar Missao\n");
		printf("3 - Cancelar Missao\n");
		printf("4 - Voltar ao Menu Principal\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuOperacoes);
		menuOperacoes = validarOperacoesMissao(menuOperacoes);
		
		switch (menuOperacoes) {
			case 1:
				iniciarMissao(n, dt, l, a, d, p, c, o, s);
				break;
			case 2: 
				finalizarMissao(n, dt, l, a, d, p, c, o, s);
				break;
			case 3:
				cancelarMissao(n, dt, l, a, d, p, c, o, s);
				break;
		}
	} while (menuOperacoes != 4);
	limparSistema();
}

void indicadorFinanceiro(char n[][50], float *o) {
	limparSistema();
	
	int i, t = 0, relatorio;
	float mediaOrcamento = 0, totalOrcamento = 0, maiorOrcamento = 0, menorOrcamento = 0;
	char nomeMaior[50], nomeMenor[50];
	
	for (i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0) {
			t++;
			totalOrcamento += o[i];
			
			if (i == 0) {
				maiorOrcamento = o[i];
				menorOrcamento = o[i];
				strcpy(nomeMaior, n[i]);
				strcpy(nomeMenor, n[i]);
			}
			
			if (o[i] > maiorOrcamento) {
				maiorOrcamento = o[i];
				strcpy(nomeMaior, n[i]);
			}
			
			if (o[i] < menorOrcamento) {
				menorOrcamento = o[i];
				strcpy(nomeMenor, n[i]);
			}
		}
	}
	
	mediaOrcamento = totalOrcamento / t;
	
	printf("\n");
	printf("====================================================\n");
	printf("            INDICADORES FINANCEIROS\n");
	printf("====================================================\n");
	printf("Orcamento medio das missoes : US$ %.2f milhoes\n", mediaOrcamento);
	printf("Orcamento total investido   : US$ %.2f milhoes\n", totalOrcamento);
	printf("Missao mais cara            : %s\n", nomeMaior);
	printf("Maior orcamento             : US$ %.2f milhoes\n", maiorOrcamento);
	printf("Missao mais economica       : %s\n", nomeMenor);
	printf("Menor orcamento             : US$ %.2f milhoes\n", menorOrcamento);
	printf("====================================================\n");
	
	printf("\n");
	printf("Deseja emitir o relatorio?\n");
	printf("1 - Sim\n2 - Nao\n");
	printf("====================================================\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &relatorio);
	relatorio = validarRelatorio(relatorio);
	
	if (relatorio == 1) {
		FILE *relatorio;
		relatorio = fopen("IndicadorFinanceiro.txt", "a");
		
		fprintf(relatorio, "====================================================\n");
		fprintf(relatorio, "            INDICADORES FINANCEIROS\n");
		fprintf(relatorio, "====================================================\n");
		fprintf(relatorio, "Orcamento medio das missoes : US$ %.2f milhoes\n", mediaOrcamento);
		fprintf(relatorio, "Orcamento total investido   : US$ %.2f milhoes\n", totalOrcamento);
		fprintf(relatorio, "Missao mais cara            : %s\n", nomeMaior);
		fprintf(relatorio, "Maior orcamento             : US$ %.2f milhoes\n", maiorOrcamento);
		fprintf(relatorio, "Missao mais economica       : %s\n", nomeMenor);
		fprintf(relatorio, "Menor orcamento             : US$ %.2f milhoes\n", menorOrcamento);
		fprintf(relatorio, "====================================================\n");
		
		fclose(relatorio);
		
		printf("Relatorio emitido com sucesso!");
	}
}

void indicadorOperacional(char n[][50], int *s) {
	limparSistema();
	
	int i, totalMissoes = 0, qtdPlanejadas = 0, qtdAndamento = 0, qtdConcluidas = 0, qtdCanceladas = 0, relatorio;
	float taxaSucesso;
	
	for (i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0) {
			totalMissoes++;
			
			if (s[i] == 1) {
				qtdPlanejadas++;
			} else if (s[i] == 2) {
				qtdAndamento++;
			} else if(s[i] == 3) {
				qtdConcluidas++;
			} else {
				qtdCanceladas++;
			}
		}
	}
	
	taxaSucesso = (float)qtdConcluidas / totalMissoes * 100;
	
	printf("\n");
	printf("====================================================\n");
	printf("           INDICADORES OPERACIONAIS\n");
	printf("====================================================\n");
	printf("Total de missoes cadastradas : %d\n", totalMissoes);
	printf("Missoes planejadas           : %d\n", qtdPlanejadas);
	printf("Missoes em andamento         : %d\n", qtdAndamento);
	printf("Missoes concluidas           : %d\n", qtdConcluidas);
	printf("Missoes canceladas           : %d\n", qtdCanceladas);
	printf("Taxa de sucesso              : %.2f %%\n", taxaSucesso);
	printf("====================================================\n");
	
	printf("\n");
	printf("Deseja emitir o relatorio?\n");
	printf("1 - Sim\n2 - Nao\n");
	printf("====================================================\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &relatorio);
	relatorio = validarRelatorio(relatorio);
	
	if (relatorio == 1) {
		FILE *relatorio;
		relatorio = fopen("IndicadorOperacional.txt", "a");
		
		fprintf(relatorio, "====================================================\n");
		fprintf(relatorio, "           INDICADORES OPERACIONAIS\n");
		fprintf(relatorio, "====================================================\n");
		fprintf(relatorio, "Total de missoes cadastradas : %d\n", totalMissoes);
		fprintf(relatorio, "Missoes planejadas           : %d\n", qtdPlanejadas);
		fprintf(relatorio, "Missoes em andamento         : %d\n", qtdAndamento);
		fprintf(relatorio, "Missoes concluidas           : %d\n", qtdConcluidas);
		fprintf(relatorio, "Missoes canceladas           : %d\n", qtdCanceladas);
		fprintf(relatorio, "Taxa de sucesso              : %.2f %%\n", taxaSucesso);
		fprintf(relatorio, "====================================================\n");
		
		fclose(relatorio);
		
		printf("Relatorio emitido com sucesso!");
	}
}

void indicadorRecurso(char n[][50], float *c) {
	limparSistema();
	
	int i, t = 0, relatorio;
	float mediaCombustivel = 0, totalCombustivel = 0, maiorCombustivel = 0, menorCombustivel = 0;
	char nomeMaior[50], nomeMenor[50];
	
	for (i = 0; i < 10; i++) {
		if(strcmp(n[i], " ") != 0) {
			t++;
			totalCombustivel += c[i];
			
			if (i == 0) {
				maiorCombustivel = c[i];
				menorCombustivel = c[i];
				strcpy(nomeMaior, n[i]);
				strcpy(nomeMenor, n[i]);
			}
			
			if (c[i] > maiorCombustivel) {
				maiorCombustivel = c[i];
				strcpy(nomeMaior, n[i]);
			}
			
			if (c[i] < menorCombustivel) {
				menorCombustivel = c[i];
				strcpy(nomeMenor, n[i]);
			}
		}
	}
	
	mediaCombustivel = totalCombustivel / t;
	
	printf("\n");
	printf("====================================================\n");
	printf("            INDICADORES DE RECURSOS\n");
	printf("====================================================\n");
	printf("Combustivel medio             : %.2f toneladas\n", mediaCombustivel);
	printf("Combustivel total utilizado   : %.2f toneladas\n", totalCombustivel);
	printf("Maior consumo registrado      : %.2f toneladas\n", maiorCombustivel);
	printf("Missao correspondente         : %s\n", nomeMaior);
	printf("Menor consumo registrado      : %.2f toneladas\n", menorCombustivel);
	printf("Missao correspondente         : %s\n", nomeMenor);
	printf("====================================================\n");
	
	printf("\n");
	printf("Deseja emitir o relatorio?\n");
	printf("1 - Sim\n2 - Nao\n");
	printf("====================================================\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &relatorio);
	relatorio = validarRelatorio(relatorio);
	
	if (relatorio == 1) {
		FILE *relatorio;
		relatorio = fopen("IndicadorRecurso.txt", "a");
		
		fprintf(relatorio, "====================================================\n");
		fprintf(relatorio, "            INDICADORES DE RECURSOS\n");
		fprintf(relatorio, "====================================================\n");
		fprintf(relatorio, "Combustivel medio             : %.2f toneladas\n", mediaCombustivel);
		fprintf(relatorio, "Combustivel total utilizado   : %.2f toneladas\n", totalCombustivel);
		fprintf(relatorio, "Maior consumo registrado      : %.2f toneladas\n", maiorCombustivel);
		fprintf(relatorio, "Missao correspondente         : %s\n", nomeMaior);
		fprintf(relatorio, "Menor consumo registrado      : %.2f toneladas\n", menorCombustivel);
		fprintf(relatorio, "Missao correspondente         : %s\n", nomeMenor);
		fprintf(relatorio, "====================================================\n");
		
		fclose(relatorio);
		
		printf("Relatorio emitido com sucesso!");
	}
}

void analisesRelatorios(char n[][50], int *dt, int *l, int *a, int *d, int *p, float *c, float *o, int *s) {
	limparSistema();
	int menuRelatorios;
	
	do {
		printf("\n");
		printf("====================================================\n");
		printf("          ANALISES E RELATORIOS\n");
		printf("====================================================\n");
		printf("1 - Indicadores Financeiros\n");
		printf("2 - Indicadores Operacionais\n");
		printf("3 - Indicadores de Recursos\n");
		printf("4 - Voltar ao Menu Principal\n");
		printf("====================================================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menuRelatorios);
		menuRelatorios = validarAnalisesRelatorios(menuRelatorios);
		
		switch (menuRelatorios) {
			case 1:
				indicadorFinanceiro(n, o);
				break;
			case 2: 
				indicadorOperacional(n, s);
				break;
			case 3:
				indicadorRecurso(n, c);
				break;
		}
	} while (menuRelatorios != 4);
	limparSistema();
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
				operacoesMissao(n, dt, l, a, d, p, c, o, s);
				break;
			case 3: 
				analisesRelatorios(n, dt, l, a, d, p, c, o, s);
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
    
    int comecar;
    
    printf("Acessar menu?\n1 - Sim\n2 - Nao\n");
    scanf("%d", &comecar);
    
    if (comecar == 1) {
	    limparSistema();
	    menuPrincipal(n, dt, l, a, d, p, c, o, s, k);
	} else {
		printf("====================================================\n");
		printf("          ENCERRANDO O SISTEMA\n");
		printf("====================================================\n");
	}
}

int main() {
    char nomeMissao[10][50];
    int destino[10], localLancamento[10], astronautas[10], dias[10], prioridade[10], status[10], k = 0;
    float combustivel[10], orcamento[10];
    
    zerarDados(nomeMissao, destino, localLancamento, astronautas, dias, prioridade, combustivel, orcamento, status);
    mensagemInicial(nomeMissao, destino, localLancamento, astronautas, dias, prioridade, combustivel, orcamento, status, &k);
    
    return 0;
}
