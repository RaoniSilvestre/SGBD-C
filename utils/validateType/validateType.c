#include "validateType.h"

validateType(char *type)
{
  if (strcmp(type, "INT") == 0)
  {
    return 1;
  }
  else if (strcmp(type, "FLOAT") == 0)
  {
    return 1;
  }
  else if (strcmp(type, "CHAR") == 0)
  {
    return 1;
  }
  else if (strcmp(type, "STRING") == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}