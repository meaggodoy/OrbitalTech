# 🚀 OrbitalTech: Sistema de Gestão e Análise de Missões Espaciais

Trabalho final da disciplina de Linguagem de Programação I - Instituto Federal de São Paulo (IFSP)

## 📖 Sobre o Projeto

A **OrbitalTech** é uma empresa fictícia do setor aeroespacial responsável pelo planejamento e gerenciamento de missões espaciais.

O projeto foi desenvolvido em linguagem C com o objetivo de simular a gestão operacional, financeira e logística de missões espaciais, permitindo o cadastro, monitoramento e análise dos recursos envolvidos em cada operação.

---

## 📦 Estrutura do Sistema

```text
Sistema OrbitalTech

├── Gestão de Missões
├── Operações da Missão
├── Análises e Indicadores
└── Relatórios
```

---

# 📋 Gestão de Missões

Módulo responsável pelo gerenciamento das missões cadastradas.

```text
├── Gestão de Missões
│ ├── Cadastrar
│ ├── Consultar
│ ├── Listar
│ └── Atualizar
```

### Funcionalidades

* Cadastro de missões;
* Consulta por diferentes filtros;
* Listagem das missões cadastradas;
* Atualização de dados;
* Validação das entradas do usuário.

---

# 🚀 Operações da Missão

Módulo responsável pelo controle do ciclo de vida das missões.

```text
├── Operações da Missão
│ ├── Iniciar
│ ├── Finalizar
│ └── Cancelar
```

### Regras de negócio

As missões podem assumir os seguintes estados:

```text
Planejada
    ↓
Em andamento
    ↓
Concluída

ou

Planejada
    ↓
Cancelada
```

---

# 📊 Análises e Indicadores

Módulo responsável pela geração de indicadores e métricas.

```text
├── Análises e Indicadores
│ ├── Financeiros
│ ├── Operacionais
│ └── Recursos
```

### Indicadores financeiros

* Orçamento médio;
* Orçamento total;
* Maior orçamento;
* Menor orçamento.

### Indicadores operacionais

* Total de missões;
* Missões concluídas;
* Missões canceladas;
* Taxa de sucesso.

### Indicadores de recursos

* Consumo médio de combustível;
* Maior consumo;
* Menor consumo.

---

# 📄 Relatórios

Módulo responsável pela geração automática de relatórios em arquivos `.txt`.

Os relatórios apresentam:

* Indicadores financeiros;
* Indicadores operacionais;
* Indicadores de recursos;
* Lista das missões cadastradas;
* Informações consolidadas do sistema.

---

# 🛠️ Conceitos Utilizados

Durante o desenvolvimento do projeto foram utilizados:

* Vetores;
* Ponteiros;
* Funções;
* Modularização;
* Laços de repetição;
* Estruturas condicionais;
* Manipulação de strings (`string.h`);
* Manipulação de arquivos;
* Validação de dados;
* Cálculos e indicadores.

---

# 📂 Organização do Código

A função `main()` é utilizada apenas para inicialização do sistema e criação das variáveis principais.

As funcionalidades foram separadas em módulos responsáveis por:

* Validações;
* Cálculos;
* Transcrições para arquivos;
* Operações das missões;
* Indicadores;
* Relatórios.

Também foi implementada a função `zerarDados()`, utilizada para inicializar corretamente os vetores e evitar inconsistências durante o preenchimento das estruturas.

Além disso, a função `limparSistema()` foi criada para manter a saída do terminal mais organizada e legível.

---

# 💡 Objetivo do Projeto

Além de aplicar conceitos fundamentais da linguagem C, este projeto foi desenvolvido com o objetivo de simular um sistema real de gestão de missões espaciais e servir como base para futuros projetos voltados para análise de dados.

---

## 👩‍💻 Autora

**Maria Eduarda Antunes Godoy**

Instituto Federal de São Paulo - IFSP

Junho/2026
