#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./utils/createTable/createTable.h"

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
int lines = countLines("./heading/tables.txt");
  while (1)
  {
    scanf("%s", message);
    if (strcmp(message, "-1") == 0)
    {
      break;
    }
    createTable(message, "nome,idade", &lines);
    fprintf(heading, "%s\n", message);
  }

  
  fclose(heading);
  
  printf("\nQuantidade de linhas: %d\n", lines);

  readTables();
  return 0;
}