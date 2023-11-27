#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createTable.h"


void createTable(char *tableName, char *colums, int *qntLines)
{
  int flag = 0;
  FILE *tables = fopen("./heading/tables.txt", "r");
  if (tables == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  char message[100];

  for (int i = 0; i < *qntLines; i++)
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
    fprintf(table, "%s\n", colums);
    fclose(table);
    *qntLines++;
  }
}
