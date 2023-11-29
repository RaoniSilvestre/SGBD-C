#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lerTabelas.h"

void lerTabelas()
{
  system("clear");
  printf("Tabelas disponíveis: \n");
  char message[100];
  FILE *inputs;
  inputs = fopen("./heading/tables.txt", "r");
  if (inputs == NULL)
  {
    printf("Error opening file! ERRO EM LER TABELAS\n");
    return;
  }
  int contador = 0;
  while (fgets(message, 100, inputs) != NULL)
  { 
    printf("------\n");
    printf("%d - %s", ++contador,message);
  }
  fclose(inputs);
}
