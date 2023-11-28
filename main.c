#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./utils/createTable/createTable.h"
#include "./utils/countLines/countLines.h"
#include "./functions/criarNovaTabela/criarNovaTabela.h"
#include "./functions/lerTabelas/lerTabelas.h"



int main(int argc, char *argv[])
{
  // A main funcionará como um menu para acessar as funcionalidades do SGBD.
  // Cada funcionalidade será um arquivo .c separado dentro da pasta functions(São funções principais) 
  // e será chamado de acordo com a escolha do usuário
  int choice;
  while (1)
  {
    printf("---------------------------\n");
    printf("\nSGBD em C\n\n");
    printf("1. Criar tabela\n");
    printf("2. Listar tabelas\n");
    printf("3. Inserir dados\n");
    printf("4. Listar todos os dados de uma tabela\n");
    printf("5. Apagar registro\n");
    printf("6. Apagar tabela\n");
    printf("7. Sair\n\n");
    printf("---------------------------\n");
    printf("Escolha: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
      
    case 1:
      //Acesse a função criarNovaTabela() no arquivo functions/criarNovaTabela/criarNovaTabela.c
      //para entender o que está acontecendo aqui.
      criarNovaTabela();
      break;


    case 2:
      //O mesmo é análogo para todos os outros casos. (Quando tiver terminado de fazer esse código)
      printf("Tabelas disponíveis: \n");
      lerTabelas();
      break;


    case 3:
      printf("Inserir dados\n");
      break;


    case 4:
      printf("Listar todos os dados de uma tabela\n");
      break;


    case 5:
      printf("Apagar registro\n");
      break;


    case 6:
      printf("Apagar tabela\n");
      break;


    case 7:
      printf("Sair\n");
      return 0; //Encerra o programa
      break;


    default:
      printf("Opção inválida\n"); //Nada acontece, reinicia o loop
      break;
    }
  }

  return 0;
}