#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lerTabelas.h"

void lerTabelas()
{
  char message[100];
  FILE *inputs;
  inputs = fopen("./heading/tables.txt", "r");
  if (inputs == NULL)
  {
    printf("Error opening file! ERRO EM LER TABELAS\n");
    return;
  }
  while (fgets(message, 100, inputs) != NULL)
  {
    printf("%s", message);
  }
  fclose(inputs);
}
