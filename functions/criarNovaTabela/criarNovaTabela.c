#include "criarNovaTabela.h"

void criarNovaTabela()
{
  system("clear");
  printf("1. Criar nova tabela.\n"); // Grande parte dos printfs são para entendimento do usuário
  printf("Insira o nome da tabela: ");

  char newTableName[50]; // Variável que armazenará o nome da nova tabela

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }

  scanf("%[^\n]", newTableName);

  if (verifyTableExists(newTableName) == 1) // Verifica se a tabela já existe
  {
    printf("---------------------------\n");
    printf("Erro: Tabela já existe!\n");
    return;
  }

  else // Se não existir, cria a tabela
  {
    printf("Quantidade de colunas: ");

    int columns;
    scanf("%d", &columns);
    printf("---------------------------\n");
    printf("Tipos de colunas disponíveis:\n");
    printf("-----\n");
    printf("INT\n");
    printf("-----\n");
    printf("FLOAT\n");
    printf("-----\n");
    printf("CHAR\n");
    printf("-----\n");
    printf("STRING\n");

    char columnType[30]; // Variável que armazenará o tipo da coluna
    char columnName[30]; // Variável que armazenará o nome da coluna

    char resultNameLine[(columns * 30) + columns - 1];
    memset(resultNameLine, 0, sizeof(resultNameLine)); // Limpa a variável resultNameLine

    char resultTypeLine[(columns * 30) + columns - 1];
    memset(resultTypeLine, 0, sizeof(resultTypeLine)); // Limpa a variável resultTypeLine

    for (int i = 0; i < columns; i++) // Loop para inserir o nome e o tipo de cada coluna
    {
      do
      {
        if (i == 0)
        {
          printf("---------------------------\n");
          printf("Essa coluna será a chave primária do tipo INT.\n");
          printf("Coluna %d\n", i + 1);

          printf("Nome: ");
          while ((c = getchar()) != '\n' && c != EOF)
          {
          }
          scanf("%[^\n]", columnName);

          strcpy(columnType, "INT");
        }
        else
        {
          printf("---------------------------\n");
          printf("Coluna %d\n", i + 1);

          printf("Nome: ");
          while ((c = getchar()) != '\n' && c != EOF)
          {
          }
          scanf("%[^\n]", columnName);

          printf("Tipo: ");
          while ((c = getchar()) != '\n' && c != EOF)
          {
          }

          scanf("%[^\n]", columnType);
        }

        if (validateType(columnType) == 0) // Verifica se o tipo inserido é válido
        {
          printf("\nNome inválido\n");

          system("read -p \"\nPressione ENTER para retornar\" saindo");
          return;
        }
        else // Adiciona o nome e o tipo da coluna na variável result
        {
          strcat(resultNameLine, columnName);
          strcat(resultTypeLine, columnType);
          break;
        }

      } while (1);

      if (i < columns - 1)
      {
        strcat(resultTypeLine, ",");
        strcat(resultNameLine, ",");
      }
    }

    // Optei por fazer essa createTable pois o código já estava muito extenso para uma função só.
    // Além disso, essa createTable se preocupa apenas em colocar os dados (caso sejam validados nessa função) no arquivo tables.txt
    createTable(newTableName, resultNameLine, resultTypeLine); // Chama a função createTable para criar a tabela (utils/createTable/createTable.c)
  }
}