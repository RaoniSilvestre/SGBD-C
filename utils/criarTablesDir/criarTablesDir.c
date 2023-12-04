#include "criarTablesDir.h"

void criarTablesDir() {
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
}