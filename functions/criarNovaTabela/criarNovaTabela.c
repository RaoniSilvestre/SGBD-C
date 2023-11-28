#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criarNovaTabela.h"
#include "../../utils/createTable/createTable.h"
#include "../../utils/countLines/countLines.h"
void criarNovaTabela()
{

  int lines = countLines("./heading/tables.txt"); // Conta a quantidade de linhas no arquivo tables.txt

  printf("1. Selecionado.\n"); // Grande parte dos printfs são para entendimento do usuário
  printf("Insira o nome da tabela: ");

  char newTableName[50]; // Variável que armazenará o nome da nova tabela
  scanf("%s", newTableName);

  // O arquivo heading serve para listar todas as tabelas existentes
  FILE *heading;                                // Cria um ponteiro para o arquivo tables.txt
  heading = fopen("./heading/tables.txt", "a"); // Abre o arquivo tables.txt em modo de escrita (append)

  if (heading == NULL)
  {
    printf("Error opening file!\n"); // Verifica se o arquivo foi aberto corretamente
    return;
  }

  if (verifyTableExists(&lines, newTableName) == 1) //Verifica se a tabela já existe
  {
    printf("Tabela já existe\n"); 
    return;
  }

  else //Se não existir, cria a tabela
  {
    printf("Quantidade de colunas: ");
    
    int columns;
    scanf("%d", &columns);
    
    char columnType[30]; // Variável que armazenará o tipo da coluna
    char columnName[30]; // Variável que armazenará o nome da coluna

    char resultNameLine[(columns * 30) + columns - 1];
    memset(resultNameLine, 0, sizeof(resultNameLine)); // Limpa a variável resultNameLine
    
    char resultTypeLine[(columns * 30) + columns - 1];
    memset(resultTypeLine, 0, sizeof(resultTypeLine)); // Limpa a variável resultTypeLine

    for (int i = 0; i < columns; i++) // Loop para inserir o nome e o tipo de cada coluna
    {
      printf("---------------------------\n");
      printf("Coluna %d\n", i + 1);

      printf("Nome: ");
      scanf("%s", columnName);
      strcat(resultNameLine, columnName);

      printf("Tipo: ");
      scanf("%s", columnType);
      strcat(resultTypeLine, columnType);

      if (i < columns - 1)
      {
        strcat(resultTypeLine, ",");
        strcat(resultNameLine, ",");
      }
    }

    //Optei por fazer essa createTable pois o código já estava muito extenso para uma função só.
    //Além disso, essa createTable se preocupa apenas em colocar os dados (caso sejam validados nessa função) no arquivo tables.txt
    createTable(newTableName, resultNameLine, resultTypeLine); // Chama a função createTable para criar a tabela (utils/createTable/createTable.c)
    lines++;
  }

  fclose(heading);
}