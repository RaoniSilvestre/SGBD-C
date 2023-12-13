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
    system("read -p \"\nPressione enter para sair\" saindo");
    return;
  }

  char tablePath[50] = "./tables/";
  strcat(tablePath, tableName);
  strcat(tablePath, ".txt");
  imprimirTabela(tablePath);

  int lineCount = countLines(tablePath);

  printf("\nNumero de linhas: %d\n", lineCount - 2);

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

  int found = 0;

  while (fgets(line, sizeof(line), file))
  {
    strcpy(lineCopy, line);
    field = strtok(line, ",");
    if (strcmp(field, primaryKey) == 0)
    {

      found = 1;
    }
    else
    {
      fputs(lineCopy, temp_file);
    }
  }

  if (!found)
  {
    printf("A chave primária %s não foi encontrada!\n", primaryKey);
    system("read -p \"\nPressione enter para sair\" saindo");
    fclose(file);
    fclose(temp_file);
    remove("./tables/temp.txt");
    return;
  }

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

  system("read -p \"\nPressione enter para sair\" saindo");

  return;
}