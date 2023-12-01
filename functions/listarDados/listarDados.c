#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "listarDados.h"

void listarArquivosTxt() {
    DIR *dir;
    struct dirent *ent;

    dir = opendir("./tables");
    if (dir != NULL) {
        printf("Arquivos .txt encontrados:\n");
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".txt") != NULL) {
                printf("%s\n", ent->d_name);
            }
        }
        closedir(dir);
    } else {
        printf("Erro ao abrir o diretório.\n");
    }
}

void listarConteudoArquivo(char *nomeArquivo) {
    char path[100] = "./tables/";
    strcat(path, nomeArquivo);

    FILE *file = fopen(path, "r");
    if (file != NULL) {
        printf("Conteúdo do arquivo %s:\n", nomeArquivo);
        char linha[1000];
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%s", linha);
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    }
}

void listarDados() {
    listarArquivosTxt();

    char nomeArquivo[50];
    printf("Digite o nome do arquivo que deseja listar os dados: ");
    scanf("%s", nomeArquivo);

    listarConteudoArquivo(nomeArquivo);
}