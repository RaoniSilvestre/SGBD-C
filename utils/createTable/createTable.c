#include "createTable.h"

void createTable(char *tableName, char *typeLine, char *nameLine)
{
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
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  fprintf(table, "%s\n", nameLine);
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  fprintf(table, "%s\n", typeLine);
  fclose(table);
}
