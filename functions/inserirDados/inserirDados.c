#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inserirDados.h"

#include "../../utils/verifyTablesExists/verifyTablesExists.h"
#include "../../utils/countCommas/countCommas.h"

void inserirDados()
{
  printf("3. Selecionado.\n");
  printf("Insira o nome da tabela: ");

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

    fprintf(table, "%s", novoRegistro);
    fclose(table);

    return;
  }

  else
  {
    printf("Tabela não encontrada.\n");
    return;
  }
}
