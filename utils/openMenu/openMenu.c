#include <stdio.h>
#include "openMenu.h"

// Criei para facilitar a visualização do menu e não poluir a main.c

void openMenu()
{
  printf("---------------------------\n");
  printf("\nSGBD em C\n\n");
  printf("1. Criar tabela\n");
  printf("2. Listar tabelas\n");
  printf("3. Inserir dados\n");
  printf("4. Listar dados de uma tabela\n");
  printf("5. Apagar registro\n");
  printf("6. Apagar tabela\n");
  printf("7. Limpar prompt\n");;
  printf("8. Sair\n\n");
  printf("---------------------------\n");
  printf("Escolha: ");
}