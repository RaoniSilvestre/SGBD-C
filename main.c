#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void createTable(char *tableName, char *columns, int qntLines)
{
  int flag = 0;
  FILE *tables = fopen("./heading/tables.txt", "r");
  if (tables == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  char message[100];

  for (int i = 0; i < qntLines; i++)
  {
    fscanf(tables,"%s", message);
    if(strcmp(tableName, message) == 0){
      flag = 1;
      printf("Tabela já existe!\n");
      break;
    }
  }
  fclose(tables);


  if(flag == 0){
    FILE *inputs;
    inputs = fopen("./heading/tables.txt", "a");
    if (inputs == NULL)
    {
      printf("Error opening file!\n");
      return;
    }
    fprintf(inputs, "%s\n", tableName);
    fclose(inputs);

    char path[100] = "./tables/";
    strcat(path, tableName);
    strcat(path, ".txt");
    FILE *table = fopen(path, "w");
    if (table == NULL)
    {
      printf("Error opening file!\n");
      return;
    }
    fprintf(table, "%s\n", columns);
    fclose(table);
  }
}

int countLines(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    int count = 0;
    char ch;
    while((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);

    return count;
}

int main(int argc, char *argv[])
{
  FILE *heading;
  heading = fopen("./heading/tables.txt", "a");
  if (heading == NULL)
  {
    printf("Error opening file!\n");
    return 1;
  }
  
  char message[100];
  scanf("%s", message);


  // while (1)
  // {
  //   scanf("%s", message);
  //   if (strcmp(message, "-1") == 0)
  //   {
  //     break;
  //   }
  //   fprintf(heading, "%s\n", message);
  // }

  
  fclose(heading);
  readTables();
  int lines = countLines("./heading/tables.txt");
  printf("\nQuantidade de linhas: %d\n", lines);
  createTable("teste", "nome, idade", lines);

  return 0;
}