#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./utils/openMenu/openMenu.h"

#include "./functions/criarNovaTabela/criarNovaTabela.h"
#include "./functions/lerTabelas/lerTabelas.h"
#include "./functions/inserirDados/inserirDados.h"
#include "./functions/listarDados/listarDados.h"
#include "./functions/apagarTabela/apagarTabela.h"
#include "./functions/apagarRegistro/apagarRegistro.h"


// A main funcionará como um menu para acessar as funcionalidades do SGBD.
// Cada funcionalidade será um arquivo .c separado dentro da pasta functions(São funções principais)
// e será chamado de acordo com a escolha do usuário
int main(int argc, char *argv[])
{
  int choice;
  while (1)
  {
    system("clear");
    openMenu();
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {

    case 1:
      // Acesse a função criarNovaTabela() no arquivo functions/criarNovaTabela/criarNovaTabela.c
      // para entender o que está acontecendo aqui.
      criarNovaTabela();
      break;

    case 2:
      // O mesmo é análogo para todos os outros casos. (Quando tiver terminado de fazer esse código)
      lerTabelas();
      system("read -p \"\nPressione enter para sair\" saindo");
      break;

    case 3:
      printf("Inserir dados\n");
      inserirDados();
      break;

    case 4:
      printf("Listar todos os dados de uma tabela\n");
      break;

    case 5:
      printf("Apagar registro\n");
      break;

    case 6:
      printf("Apagar tabela\n");
      apagarTabela();
      break;

    case 7:
      printf("Clear prompt\n");
      system("clear");
      break;
    case 8:
      
      system("read -p \"\nPressione enter para sair\" saindo");
      system("clear");
      return 0; // Encerra o programa
      break;

    default:
      printf("Opção inválida\n"); // Nada acontece, reinicia o loop
      break;
    }
  }

  return 0;
}
