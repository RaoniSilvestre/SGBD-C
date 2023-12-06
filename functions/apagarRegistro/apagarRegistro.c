#include "apagarRegistro.h"

void apagarRegistro()
{
  system("clear");

  // Mostra os arquivos disponíveis ao usuário
  lerTabelas();

  // Pergunta ao usuário qual arquivo abrir
  char tableName[30];
  printf("\nDigite o NOME do arquivo que deseja abrir: ");
  scanf("%s", tableName);

  // Lê e imprime todas as linhas do arquivo escolhido

  char tablePath[50] = "./tables/";
  strcat(tablePath, tableName);
  strcat(tablePath, ".txt");
  imprimirTabela(tablePath);

  int lineCount = countLines(tablePath);
  printf("\nNumero de linhas: %d\n", lineCount);
  // Pergunta qual linha o usuário deseja remover
  int lineToRemove;
  do
  {
    printf("\nDigite o numero da linha que deseja remover: ");
    scanf("%d", &lineToRemove);
    lineToRemove = lineToRemove + 2;

    if (lineToRemove <= 2 || lineToRemove > lineCount)
    {
      printf("Linha invalida!\n");
    }
  } while (lineToRemove <= 2 || lineToRemove > lineCount);

  // Reabre o arquivo para leitura e escrita
  FILE *file = fopen(tablePath, "r+");

  // Cria um arquivo temporário para armazenar as linhas não removidas
  FILE *temp_file = fopen("temp.txt", "w");

  char line[256];
  int currentLine = 0;

  while (fgets(line, sizeof(line), file))
  {
    currentLine++;
    // Se a linha atual não é a linha a ser removida, escreva no arquivo temporário
    if (currentLine != lineToRemove)
    {
      fputs(line, temp_file);
    }
  }

  // Feche os arquivos
  fclose(file);
  fclose(temp_file);

  // Agora, remova o arquivo original e renomeie o arquivo temporário
  remove(tablePath);
  rename("temp.txt", tablePath);

  printf("Linha removida com sucesso!\n");

  return;
}