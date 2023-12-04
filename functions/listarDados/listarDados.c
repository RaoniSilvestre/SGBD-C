#include "listarDados.h"


void listarDados()
{
    system("clear");
    FILE *file_list[MAX_FILES];
    char filenames[MAX_FILES][MAX_FILENAME_LEN];
    char input[MAX_LINE_LEN];
    int file_count = 0;

    // Abre cada arquivo TXT na pasta ./tables
    system("ls ./tables/*.txt > temp.txt");
    FILE *file = fopen("temp.txt", "r");
    while (fgets(input, MAX_LINE_LEN, file) != NULL)
    {
        input[strcspn(input, "\n")] = 0; // Remove a quebra de linha
        file_list[file_count] = fopen(input, "r");
        strcpy(filenames[file_count], input);
        file_count++;
    }
    fclose(file);
    system("rm temp.txt");

    // Mostra os arquivos disponíveis ao usuário
    lerTabelas();

    // Pergunta ao usuário qual arquivo abrir pelo nome
    char chosen_filename[MAX_FILENAME_LEN];
    printf("Digite o nome do arquivo que deseja abrir: ");
    scanf("%s", chosen_filename);

    int chosen_file = -1;
    for (int i = 0; i < file_count; ++i)
    {
        // Verifica se o nome digitado corresponde a um dos arquivos disponíveis
        char *filename = strrchr(filenames[i], '/');
        char *dot_txt = strstr(filenames[i], ".txt");
        if (filename != NULL && dot_txt != NULL && dot_txt == filename + strlen(filename) - 4)
        {
            *dot_txt = '\0'; // Remove a extensão .txt
        }
        if (filename != NULL && strcmp(filename + 1, chosen_filename) == 0)
        {
            chosen_file = i;
            break;
        }
        else if (strcmp(filenames[i], chosen_filename) == 0)
        {
            chosen_file = i;
            break;
        }
    }

    if (chosen_file == -1)
    {
        printf("Arquivo '%s' não encontrado.\n", chosen_filename);
        system("read -p \"\nPressione enter para sair\" saindo");
        return;
    }

    // Lê e imprime todas as linhas do arquivo escolhido
    printf("\nConteudo do arquivo %s:\n", chosen_filename);
    char message[MAX_LINE_LEN];
    int counter = 0;
    while (fgets(message, MAX_LINE_LEN, file_list[chosen_file]) != NULL)
    {
        printf("%d - %s", ++counter, message);
    }
    system("read -p \"\nPressione enter para sair\" saindo");
}
