#include "apagarRegistro.h"

void apagarRegistro()
{
  system("clear");

  // Mostra os arquivos disponíveis ao usuário
  lerTabelas();

  // Pergunta ao usuário qual arquivo abrir
  char tableName[30];
  printf("\nDigite o NOME do arquivo que deseja abrir: ");
  scanf("%s", tableName);

  if (!verifyTableExists(tableName))
  {
    printf("Tabela nao existe!\n");
    return;
  }
  else
  {
    char tablePath[50] = "./tables/";
    strcat(tablePath, tableName);
    strcat(tablePath, ".txt");
    imprimirTabela(tablePath);

    int lineCount = countLines(tablePath);

    printf("\nNumero de linhas: %d\n", lineCount);

    if (lineCount <= 2)
    {
      printf("Nao ha linhas para remover!\n");
      return;
    }

    char primaryKey[30];
    printf("\nDigite a chave primaria do registro que deseja remover: ");
    scanf("%s", primaryKey);

    FILE *file = fopen(tablePath, "r");
    FILE *temp_file = fopen("./tables/temp.txt", "w");

    char line[256];
    char lineCopy[256];
    char *field;

    while (fgets(line, sizeof(line), file))
    {
      strcpy(lineCopy, line); 
      field = strtok(line, ",");
      if (strcmp(field, primaryKey) != 0)
      {
        fputs(lineCopy, temp_file); 
      }
    }

    fclose(file);
    fclose(temp_file);

    remove(tablePath);
    rename("./tables/temp.txt", tablePath);

    printf("Registro removido com sucesso!\n");
  }

  return;
}