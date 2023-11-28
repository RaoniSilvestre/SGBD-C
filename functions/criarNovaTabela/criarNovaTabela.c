#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criarNovaTabela.h"

#include "../../utils/createTable/createTable.h"
#include "../../utils/countLines/countLines.h"
#include "../../utils/validateType/validateType.h"
#include "../../utils/verifyTablesExists/verifyTablesExists.h"

void criarNovaTabela()
{
  printf("1. Selecionado.\n"); // Grande parte dos printfs são para entendimento do usuário
  printf("Insira o nome da tabela: ");

  char newTableName[50]; // Variável que armazenará o nome da nova tabela
  scanf("%s", newTableName);

  // O arquivo heading serve para listar todas as tabelas existentes
  FILE *heading;
  heading = fopen("./heading/tables.txt", "a");

  if (heading == NULL)
  {
    printf("Error opening file!\n"); // Verifica se o arquivo foi aberto corretamente
    return;
  }

  if (verifyTableExists(newTableName) == 1) // Verifica se a tabela já existe
  {
    printf("---------------------------\n");
    printf("Erro: Tabela já existe!\n");
    return;
  }

  else // Se não existir, cria a tabela
  {
    printf("Quantidade de colunas: ");

    int columns;
    scanf("%d", &columns);
    printf("---------------------------\n");
    printf("Tipos de colunas disponíveis:\n");
    printf("-----\n");
    printf("INT\n");
    printf("-----\n");
    printf("FLOAT\n");
    printf("-----\n");
    printf("CHAR\n");
    printf("-----\n");
    printf("STRING\n");

    char columnType[30]; // Variável que armazenará o tipo da coluna
    char columnName[30]; // Variável que armazenará o nome da coluna

    char resultNameLine[(columns * 30) + columns - 1];
    memset(resultNameLine, 0, sizeof(resultNameLine)); // Limpa a variável resultNameLine

    char resultTypeLine[(columns * 30) + columns - 1];
    memset(resultTypeLine, 0, sizeof(resultTypeLine)); // Limpa a variável resultTypeLine

    for (int i = 0; i < columns; i++) // Loop para inserir o nome e o tipo de cada coluna
    {
      do
      {
        printf("---------------------------\n");
        printf("Coluna %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", columnName);

        printf("Tipo: ");
        scanf("%s", columnType);

        if (validateType(columnType) == 0) // Verifica se o tipo inserido é válido
        {
          printf("Nome inválido\n");
          return;
        }
        else // Adiciona o nome e o tipo da coluna na variável result
        {
          strcat(resultNameLine, columnName);
          strcat(resultTypeLine, columnType);
          break;
        }
        /* code here */
      } while (1);

      if (i < columns - 1)
      {
        strcat(resultTypeLine, ",");
        strcat(resultNameLine, ",");
      }
    }

    // Optei por fazer essa createTable pois o código já estava muito extenso para uma função só.
    // Além disso, essa createTable se preocupa apenas em colocar os dados (caso sejam validados nessa função) no arquivo tables.txt
    createTable(newTableName, resultNameLine, resultTypeLine); // Chama a função createTable para criar a tabela (utils/createTable/createTable.c)
  }

  fclose(heading);
}