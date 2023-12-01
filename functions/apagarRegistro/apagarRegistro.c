#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "apagarRegistro.h"

#define MAX_FILES 100
#define MAX_FILENAME_LEN 256
#define MAX_LINE_LEN 100

void apagarRegistro(){
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

    // Pergunta qual linha o usuário deseja remover
    int line_to_remove;
    printf("\nDigite o numero da linha que deseja remover: ");
    scanf("%d", &line_to_remove);

    // Reabre o arquivo para leitura e escrita
    fclose(file_list[chosen_file]);
    file_list[chosen_file] = fopen(filenames[chosen_file], "r+");
    
    // Cria um arquivo temporário para armazenar as linhas não removidas
    FILE *temp_file = fopen("temp.txt", "w");
    rewind(file_list[chosen_file]); // Retorna ao início do arquivo
    counter = 0;
    while (fgets(message, MAX_LINE_LEN, file_list[chosen_file]) != NULL) {
        counter++;
        if (counter != line_to_remove) {
            fputs(message, temp_file);
        }
    }
    fclose(file_list[chosen_file]);
    fclose(temp_file);

    // Sobrescreve o arquivo original com o temporário
    remove(filenames[chosen_file]);
    rename("temp.txt", filenames[chosen_file]);

    printf("Linha removida com sucesso!\n");

    return 0;
}