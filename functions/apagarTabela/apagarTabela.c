#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "apagarTabela.h"

#include "../lerTabelas/lerTabelas.h"
#include "../../utils/verifyTablesExists/verifyTablesExists.h"
#include "../../utils/countLines/countLines.h"

void apagarTabela()
{

  printf("Tabelas disponíveis: \n");
  lerTabelas();

  printf("\nSelecione a tabela que deseja apagar: \n");

  char tableName[30];
  scanf("%s", tableName);

  if (verifyTableExists(tableName))
  {

    char path[50] = "./tables/";
    strcat(path, tableName);
    strcat(path, ".txt");
    remove(path);

    FILE *heading = fopen("./heading/tables.txt", "r");

    int lines = countLines("./heading/tables.txt");

    char message[lines][30];

    for (int i = 0; i < lines; i++)
    {
      fscanf(heading, "%s", message[i]);
    }

    fclose(heading);

    FILE *newHeading = fopen("./heading/tables.txt", "w");

    for (int i = 0; i < lines; i++)
    {
      if (strcmp(tableName, message[i]) != 0)
      {
        fprintf(newHeading, "%s\n", message[i]);
      }
    }

    fclose(newHeading);

    printf("\nTabela apagada com sucesso!\n");
    system("read -p \"\nPressione enter para sair\" saindo");
  }
  else
  {
    printf("\nErro: Tabela não existe!\n");
    system("read -p \"\nPressione enter para sair\" saindo");
  }
}
