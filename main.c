#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./utils/createTable/createTable.h"

int verifyTableExists()
{
  return 0;
}

void readTables()
{
  char message[100];
  FILE *inputs;
  inputs = fopen("./heading/tables.txt", "rb");
  if (inputs == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  while (fgets(message, 100, inputs) != NULL)
  {
    printf("%s", message);
  }
  fclose(inputs);
}

int countLines(char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error opening file!\n");
    return -1;
  }
  int count = 0;
  char ch;
  while ((ch = fgetc(file)) != EOF)
  {
    if (ch == '\n')
    {
      count++;
    }
  }

  fclose(file);

  return count;
}

int main(int argc, char *argv[])
{

  int choice;
  int lines = countLines("./heading/tables.txt");
  while (1)
  {
    printf("---------------------------\n");
    printf("\nSGBD em C\n\n");
    printf("1. Criar tabela\n");
    printf("2. Listar tabelas\n");
    printf("3. Inserir dados\n");
    printf("4. Listar todos os dados de uma tabela\n");
    printf("5. Apagar registro\n");
    printf("6. Apagar tabela\n");
    printf("7. Sair\n\n");
    printf("---------------------------\n");
    printf("Escolha: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 1:
      printf("1. Selecionado.\n");
      printf("Insira o nome da tabela: ");
      char newTableName[50];
      scanf("%s", newTableName);
      FILE *heading;
      heading = fopen("./heading/tables.txt", "a");
      if (heading == NULL)
      {
        printf("Error opening file!\n");
        return 1;
      }
      if (verifyTableExists(newTableName) == 1)
      {
        printf("Tabela já existe\n");
        break;
      }
      else
      {
        printf("Quantidade de colunas: ");
        int columns;
        scanf("%d", &columns);
        char columnName[columns][30];
        char columnType[columns][30];

        for (int i = 0; i < columns; i++)
        {
          printf("Nome da coluna: ");
          char columnName[30];
          scanf("%s", columnName);
          printf("Tipo da coluna: ");
          char columnType[30];
          scanf("%s", columnType);
        }
        fprintf(heading, "%s\n", newTableName);
        createTable(newTableName,"cavalo,caralho", &lines);
      }

      fclose(heading);
      break;
    case 2:
      printf("Listar tabelas\n");
      break;
    case 3:
      printf("Inserir dados\n");
      break;
    case 4:
      printf("Listar todos os dados de uma tabela\n");
      break;
    case 5:
      printf("Apagar registro\n");
      break;
    case 6:
      printf("Apagar tabela\n");
      break;
    case 7:
      printf("Sair\n");
      return 0;
      break;
    default:
      printf("Opção inválida\n");
      return 1;
      break;
    }
  }

  char message[100];
  while (1)
  {
    scanf("%s", message);
    if (strcmp(message, "-1") == 0)
    {
      break;
    }
    createTable(message, "nome,idade", &lines);
  }

  readTables();
  return 0;
}