#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countLines.h"

// Função que conta a quantidade de linhas em um arquivo
// Optei por criar essa função pois me parece um jeito facil de saber a quantidade de tabelas existentes
// (Cada "Line" é um \n no arquivo heading, que é o arquivo com todas as tabelas existentes)

int countLines(char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error opening file! COUNTLINES ERROR\n");
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