#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verifyTablesExists.h"

// Função que verifica se a tabela já existe
// Retorna 1 se a tabela já existe
// Retorna 0 se a tabela não existe
// Retorna 2 se houve algum erro ao abrir o arquivo


int verifyTableExists(int *qntLines, char *tableName)
{
  FILE *tables = fopen("./heading/tables.txt", "r");
  if (tables == NULL)
  {
    printf("Error opening file!\n");
    return 2;
  }
  char message[30];

  for (int i = 0; i < *qntLines; i++)
  {
    fscanf(tables, "%s", message);
    if (strcmp(tableName, message) == 0)
    {
      return 1;
      printf("Tabela já existe!\n");
      break;
    }
  }

  return 0;
  fclose(tables);
}
