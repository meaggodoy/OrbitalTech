# OrbitalTech: Sistema de Gestão e Análise de Missões Espaciais
Trabalho final da disciplina de Linguagem de Programação 01

---
## Do projeto
Projeto desenvolvido com o objetivo de simular a gestão operacional, financeira e logística de missões espaciais, permitindo o cadastro, monitoramento e análise dos recursos envolvidos em cada operação.
Em um primeiro momento, desenvolvido em linguagem C com funcionalidades simples.
### 1. Gestão de Missões: 
Módulo para cadastrar, atualizar e consultar as missões cadastradas.
├── Gestão de Missões
│ ├── Cadastrar
│ ├── Consultar
│ ├── Listar
│ └── Atualizar
### 2. Operações de Missões: 
Módulo para alterar o status das missões cadastradas conforme a regra de negócio.
├── Operacoes da Missao
│ ├── Iniciar
│ ├── Finalizar
│ └── Cancelar
### 3. Análises e Indicadores: 
Módulo responsável para apresentar valores e medidas com base nas atividades dos outros módulos.
├── Analises e Relatorios
│ ├── Financeiros
│ ├── Operacionais
│ └── Recursos

---
## No código
O projeto foi desenvolvido em linguagem C usando vetores, funções, módulos, loops, bibliotecas e condicionais.
<img width="1121" height="202" alt="image" src="https://github.com/user-attachments/assets/2dc64af8-b1fe-49ee-8be5-28c497ae6442" />
A função main foi usada apenas para iniciar as interações do código e para a criação das variáveis.
- *Por motivos de segurança e cuidado com o uso indevido, foram usadas apenas variáveis locais. E para garantir que fossem constantes, elas foram maniuladas como ponteiros.*
- *A função de zerarDados(), foi usada para evitar que os vetores não fossem corretamente preenchidos, permitindo que eu pudesse manejar conforme os módulos.*
<img width="1124" height="288" alt="image" src="https://github.com/user-attachments/assets/a4e8bf93-987a-4a97-aaf6-7741b0ffe4bb" />
Esse mesmo tipo de manipulação com strings foi usado para a comparação dos cadastros nos indicadores e relatórios.


As funções escritas na main foram todas usadas como *void*, enquanto as funções dos módulos externos, retornavam valores.
Para manter a saída do código limpa e legível, foi usada a função limparSistema(), que com um caminho de comandos, limpa a saída painel.

### Gestão de Missões
<img width="1128" height="614" alt="image" src="https://github.com/user-attachments/assets/a50fef3c-47c1-4d1a-abab-a19d1d38a6d8" />
- A função para o cadastro das missões foi organizada para que fosse possível o usuário adicionar quantas missões quisesse => k como variável memória.
- Todas as saídas de menus e com limites, são verificadas no módulo externo *validacoes.c e .h*.


