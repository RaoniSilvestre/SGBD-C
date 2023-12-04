#include "countCommas.h"

int countCommas(char *string)
{
  int commas = 0;
  for (int i = 0; i < strlen(string); i++)
  {
    if (string[i] == ',')
    {
      commas++;
    }
  }
  return commas;
}