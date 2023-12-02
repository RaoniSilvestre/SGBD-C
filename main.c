#include "functions.h"

// A main funcionará como um menu para acessar as funcionalidades do SGBD.
// Cada funcionalidade será um arquivo .c separado dentro da pasta functions(São funções principais)
// e será chamado de acordo com a escolha do usuário
int main(int argc, char *argv[])
{

    const char* nome_diretorio = "./tables";
    // Verifica se o diretório existe
    struct stat st = {0};
    if (stat(nome_diretorio, &st) == -1) {
        // Se o diretório não existir, cria-o
        if (mkdir(nome_diretorio, 0700) != 0) {
            printf("Erro ao criar o diretório.\n");
            return;
        } 
    }

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
      system("clear");
      lerTabelas();
      system("read -p \"\nPressione enter para sair\" saindo");
      break;

    case 3:
      printf("Inserir dados\n");
      inserirDados();
      break;

    case 4:
      printf("Listar todos os dados de uma tabela\n");
      listarDados();
      break;

    case 5:
      printf("Apagar registro\n");
      apagarRegistro();
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
