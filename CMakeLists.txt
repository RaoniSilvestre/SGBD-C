cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)

add_library(gcc SHARED ./utils/openMenu/openMenu.c ./utils/createTable/createTable.c ./utils/countLines/countLines.c ./utils/verifyTablesExists/verifyTablesExists.c ./functions/lerTabelas/lerTabelas.c ./functions/criarNovaTabela/criarNovaTabela.c)

add_executable(main main.c)

target_link_libraries(main gcc)

