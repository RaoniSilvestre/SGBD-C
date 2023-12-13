# Sistema Gerenciador de Banco de Dados em C

Este projeto é um Sistema Gerenciador de Banco de Dados (SGBD) desenvolvido em linguagem C como parte da disciplina de Introdução às Técnicas de Programação. O objetivo principal é aplicar os conceitos aprendidos ao longo do curso, utilizando apenas as bibliotecas básicas da linguagem C.

## Funcionalidades Principais

O sistema funciona como um menu interativo, permitindo ao usuário escolher entre diversas funcionalidades, cada uma implementada em um arquivo `.c` separado dentro da pasta `functions`.

1. **Criar Nova Tabela**
   - Função: `criarNovaTabela()`
   - Descrição: Permite ao usuário criar uma nova tabela no banco de dados.

2. **Listar Tabelas Existentes**
   - Função: `lerTabelas()`
   - Descrição: Apresenta ao usuário a lista de tabelas existentes no banco de dados.

3. **Inserir Dados em uma Tabela**
   - Função: `inserirDados()`
   - Descrição: Permite a inserção de dados em uma tabela existente.

4. **Listar Dados de uma Tabela**
   - Função: `listarDados()`
   - Descrição: Exibe os dados de uma tabela específica, com opção de pesquisar por chave primária.

5. **Apagar Registro**
   - Função: `apagarRegistro()`
   - Descrição: Remove um registro específico de uma tabela por meio da chave primária.

6. **Apagar Tabela**
   - Função: `apagarTabela()`
   - Descrição: Permite ao usuário apagar uma tabela existente no banco de dados.


## Estrutura do Projeto

Este projeto é organizado de forma clara e modular, dividido principalmente em três pastas: `utils`, `functions` e `tables`. Cada uma dessas pastas desempenha um papel específico na estrutura do programa.

### Pasta `utils`

A pasta `utils` contém scripts utilitários essenciais para o funcionamento do programa.

### Pasta `functions`

A pasta `functions` abriga as funcionalidades principais do sistema. Cada funcionalidade é implementada em um arquivo separado dentro desta pasta. Quando o usuário escolhe uma opção no menu principal, o script no arquivo `main.c` chama a função correspondente nesta pasta. Isso promove uma organização modular, facilitando a manutenção e a expansão do código.

### Pasta `tables`

A pasta `tables` é reservada para armazenar arquivos relacionados às tabelas do banco de dados, se necessário. Essa organização facilita a localização e a gestão de recursos específicos das tabelas.



## Como Executar

1. Certifique-se de ter um ambiente C com CMAKE configurado.
2. Crie uma pasta chamada build para que o script funcione corretamente. 
3. Compile o projeto usando o script criado na pasta `r`:


```bash
bash ./r/runC.sh
```

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests.

## Autores

Raoni Marti Silvestre Silva

Hélio Lima Carvalho
