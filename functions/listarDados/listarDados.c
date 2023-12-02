#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "listarDados.h"

#define MAX_FILES 100
#define MAX_FILENAME_LEN 256
#define MAX_LINE_LEN 100

void listarDados() {
    FILE *file_list[MAX_FILES];
    char filenames[MAX_FILES][MAX_FILENAME_LEN];
    char input[MAX_LINE_LEN];
    int file_count = 0;

    // Abre cada arquivo TXT na pasta ./tables
    system("ls ./tables/*.txt > temp.txt");
    FILE *file = fopen("temp.txt", "r");
    while (fgets(input, MAX_LINE_LEN, file) != NULL) {
        input[strcspn(input, "\n")] = 0; // Remove a quebra de linha
        file_list[file_count] = fopen(input, "r");
        strcpy(filenames[file_count], input);
        file_count++;
    }
    fclose(file);
    system("rm temp.txt");

    // Mostra os arquivos disponíveis ao usuário
    printf("Arquivos disponiveis para abertura:\n");
    for (int i = 0; i < file_count; ++i) {
        printf("%d - %s\n", i + 1, filenames[i]);
    }

    // Pergunta ao usuário qual arquivo abrir
    int chosen_file;
    printf("Digite o numero do arquivo que deseja abrir: ");
    scanf("%d", &chosen_file);
    chosen_file--; // Ajusta o índice para o array

    // Lê e imprime todas as linhas do arquivo escolhido
    printf("\nConteudo do arquivo %s:\n", filenames[chosen_file]);
    char message[MAX_LINE_LEN];
    int counter = 0;
    while (fgets(message, MAX_LINE_LEN, file_list[chosen_file]) != NULL) {
        printf("%d - %s", ++counter, message);
    }
    system("read -p \"\nPressione enter para sair\" saindo");
}