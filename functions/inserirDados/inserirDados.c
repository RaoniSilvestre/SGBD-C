#include "inserirDados.h"

void inserirDados()
{
  system("clear");
  printf("3. Inserir dados.\n\n");
  lerTabelas();
  printf("\nInsira o nome da tabela: ");

  char tableName[50];
  scanf("%s", tableName);

  if (verifyTableExists(tableName) == 1)
  {
    printf("Tabela encontrada!\n");
    char tablePath[50] = "./tables/";
    strcat(tablePath, tableName);
    strcat(tablePath, ".txt");

    FILE *table = fopen(tablePath, "r");

    char linha[150];

    fgets(linha, sizeof(linha), table);

    int qntCampos = countCommas(linha) + 1;

    rewind(table);

    char tipos[qntCampos][30];
    char campos[qntCampos][30];
    memset(tipos, 0, sizeof(tipos));
    memset(campos, 0, sizeof(campos));

    for (int j = 0; j < 2; j++)
    {
      for (int i = 0; i < qntCampos; i++)
      {
        if (j == 0)
        {
          fscanf(table, "%30[^,\n]", tipos[i]);
          fseek(table, 1, SEEK_CUR);
        }
        else
        {
          fscanf(table, "%[^,\n]", campos[i]);
          fseek(table, 1, SEEK_CUR);
        }
      }
    }

    fclose(table);

    FILE *table2 = fopen(tablePath, "a");

    char novoCampo[30];
    memset(novoCampo, 0, sizeof(novoCampo));

    char novoRegistro[(qntCampos + 1) * 30];
    memset(novoRegistro, 0, sizeof(novoRegistro));

    for (int i = 0; i < qntCampos; i++)
    {
      printf("Insira o valor para o campo %s do tipo %s: ", campos[i], tipos[i]);

      scanf("%s", novoCampo);

      while (i == 0 && verifyPK(novoCampo, tablePath) == 0)
      {
        printf("\nChave primária repetida, tente novamente...\n");
        printf("Insira o valor para o campo %s do tipo %s: ", campos[i], tipos[i]);
        scanf("%s", novoCampo);
      }

      strcat(novoRegistro, novoCampo);
      if (i == qntCampos - 1)
      {
        strcat(novoRegistro, "\n");
      }
      else
      {
        strcat(novoRegistro, ",");
      }
    }

    fprintf(table2, "%s", novoRegistro);
    fclose(table2);

    return;
  }

  else
  {
    printf("\nTabela não encontrada.\n");
    system("sleep 2");
    return;
  }
}

int verifyPK(char *newKey, char *tablePath)
{
  FILE *file = fopen(tablePath, "r");

  int lines = countLines(tablePath);
  char linha[200];
  char pkLida[30];

  for (int i = 0; i < lines; i++)
  {
    fgets(linha, 200, file);
    strcpy(pkLida, strtok(linha, ","));

    if (i > 1 && strcmp(pkLida, newKey) == 0)
    {
      return 0; // chave inválida
    }
  }

  fclose(file);
  return 1;
}