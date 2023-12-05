#include "listarDados.h"

void listarDados()
{
  system("clear");
  char filenames[30];
  // Mostra os arquivos disponíveis ao usuário
  lerTabelas();

  // Pergunta ao usuário qual arquivo abrir pelo nome
  char tableName[MAX_FILENAME_LEN];

  printf("\nDigite o nome do arquivo que deseja abrir: ");
  scanf("%s", tableName);

  if (verifyTableExists(tableName) == 0)
  {
    printf("A tabela %s não existe.\n", tableName);
    system("read -p \"Pressione enter para sair\" saindo");
    return;
  }
  else
  {
    char tablePath[50] = "./tables/";
    strcat(tablePath, tableName);
    strcat(tablePath, ".txt");

    imprimirTabela(tablePath);
    system("read -p \"\nPressione ENTER para retornar\" saindo");
  }
}

void imprimirTabela(char *tablePath)
{
  char linha[200];
  char formatar[40];
  int qtdLinhas = countLines(tablePath);
  int qtdColunas = countCommas(tablePath);

  FILE *table = fopen(tablePath, "r");
  printf("\n");
  for (int i = 0; i < qtdLinhas; i++)
  {
    fgets(linha, 200, table);
    if (i == 1)
    {
      printf("%10s |", "Linha");
    }

    if (i > 1)
    {
      printf("%10d |", i - 1);
    }
    if (i >= 1)
    {
      strcpy(formatar, strtok(linha, ","));
      printf("%10s |", formatar);
      for (int j = 0; j < qtdColunas + 1; j++)
      {
        strcpy(formatar, strtok(NULL, ","));
        printf("%10s |", formatar);
      }
      strcpy(formatar, strtok(NULL, ","));
      printf("%10s ", formatar);
      printf("\n");
    }
  }

  printf("\n");
  
  fclose(table);
}
