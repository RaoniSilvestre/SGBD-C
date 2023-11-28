#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verifyTablesExists.h"

#include "../countLines/countLines.h"
// Função que verifica se a tabela já existe
// Retorna 1 se a tabela já existe
// Retorna 0 se a tabela não existe
// Retorna 2 se houve algum erro ao abrir o arquivo


int verifyTableExists(char *tableName)
{
  FILE *tables = fopen("./heading/tables.txt", "r");
  if (tables == NULL)
  {
    printf("Error opening file!\n");
    return 2;
  }
  char message[30];

  int lines = countLines("./heading/tables.txt");

  for (int i = 0; i < lines; i++)
  {
    fscanf(tables, "%s", message);
    if (strcmp(tableName, message) == 0)
    { // Se a tabela já existir, retorna 1
      return 1;
      break;
    }
  }
  // Se a tabela não existir, retorna 0
  return 0;
  fclose(tables);
}
