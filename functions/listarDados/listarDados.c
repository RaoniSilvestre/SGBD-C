#include "listarDados.h"

void listarDados()
{
  system("clear");
  char filenames[30];
  // Mostra os arquivos disponíveis ao usuário
  lerTabelas();

  // Pergunta ao usuário qual arquivo abrir pelo nome
  char tableName[MAX_FILENAME_LEN];

  printf("\nDigite o nome do arquivo que deseja abrir: ");
  scanf("%s", tableName);

  if (verifyTableExists(tableName) == 0)
  {
    printf("A tabela %s não existe.\n", tableName);
    system("read -p \"Pressione enter para sair\" saindo");
    return;
  }
  else
  {
    char tablePath[50] = "./tables/";
    strcat(tablePath, tableName);
    strcat(tablePath, ".txt");
    int metodo;
    system("clear");
    printf("Pesquisar por chave?\n\n1-sim\n\n2-não\n\nDigite o numero da opção: ");
    scanf("%d", &metodo);
    system("clear");
    if (metodo==1) searchByChave(tablePath);
    if (metodo==2) imprimirTabela(tablePath);
    system("read -p \"\nPressione ENTER para retornar\" saindo");
  }
}

void imprimirTabela(char *tablePath)
{
  char linha[200];
  char formatar[40];
  int qtdLinhas = countLines(tablePath);
  int qtdColunas = countCommas(tablePath);

  FILE *table = fopen(tablePath, "r");
  printf("\n");
  for (int i = 0; i < qtdLinhas; i++)
  {
    fgets(linha, 200, table);
    if (i == 1)
    {
      printf("%10s |", "Linha");
    }

    if (i > 1)
    {
      printf("%10d |", i - 1);
    }
    if (i >= 1)
    {
      strcpy(formatar, strtok(linha, ","));
      printf("%10s |", formatar);
      for (int j = 0; j < qtdColunas + 1; j++)
      {
        strcpy(formatar, strtok(NULL, ","));
        printf("%10s |", formatar);
      }
      strcpy(formatar, strtok(NULL, ","));
      printf("%10s ", formatar);
      printf("\n");
    }
  }

  printf("\n");
  
  fclose(table);
}

void searchByChave(char *tablePath) {
    char linha[200];
    char formatar[40];
    int qtdLinhas = countLines(tablePath);
    int qtdColunas = countCommas(tablePath);
    int pesquisa;
    printf("Qual metodo você deseja ultilizar?\n\n1- Pesquisar pela linha com a chave\n\n2- Pesquisar pelas linhas com valores maiores que a chave\n\n3- Pesquisar pelas linhas com valores menores que a chave\n\nDigite o numero correspondente: ");
    scanf("%d", &pesquisa);
    int chave;
    system("clear");
    printf("Digite o numero da chave: ");
    scanf("%d", &chave);
    FILE *table = fopen(tablePath, "r");
    printf("\n");

    if (pesquisa == 1) {
      imprimirSegundaLinha(tablePath);
       int linhaEncontrada = 0;
        for (int i = 0; i < qtdLinhas; i++) {
            fgets(linha, 200, table);
            if (i >= 1) {
                int currentChave;
                sscanf(linha, "%d", &currentChave);
                if (currentChave == chave) {
                    linhaEncontrada = 1;
                    printTokens(linha);
                    printf("\n");
                    break;
                }
            }
        }
        if (!linhaEncontrada) {
            printf("Chave '%d' não encontrada.\n", chave);
        }
    } 

  else if (pesquisa == 2) {

    imprimirSegundaLinha(tablePath);

    for (int i = 0; i < qtdLinhas; i++) {
            fgets(linha, 200, table);
            if (i >= 1) {
                int currentChave;
                sscanf(linha, "%d", &currentChave);
                if (currentChave > chave) {
                     printTokens(linha);
                    printf("\n");
                }
            }
    }
  }

 else if (pesquisa==3) {

        for (int i = 0; i < qtdLinhas; i++) {
            fgets(linha, 200, table);
            if (i >= 1) {
                int currentChave;
                sscanf(linha, "%d", &currentChave);
                if (currentChave < chave) {
                     printTokens(linha);
                    printf("\n");
                }
            }
        }
    }
    printf("\n");

    close(table);
}

void imprimirSegundaLinha(char *tablePath) {
    FILE *file = fopen(tablePath, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    int contador = 0;
    while (fgets(linha, sizeof(linha), file) != NULL) {
        contador++;
        if (contador == 2) {
             printTokens(linha);
            printf("\n");

            break;
        }
    }

    fclose(file);
}

void printTokens(char *line) {
    char *token = strtok(line, ",");
    while (token != NULL) {
        printf("%10s", token);
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf(" |");
        }
    }
}

