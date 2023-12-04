
#include "apagarTabela.h"

void apagarTabela()
{
  system("clear");
  printf("6. Apagar tabela\n\n");
  lerTabelas();

  printf("\nDigite o nome da tabela que deseja apagar: \n");

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
  }
  else
  {
    printf("\nErro: Tabela não existe!\n");
  }
  system("read -p \"\nPressione enter para sair\" saindo");
}
