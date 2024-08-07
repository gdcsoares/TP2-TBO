#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

Graph* read_input_file(const char *filename, int *V, int *E, int **servers, int *S, int **clients, int *C, int **monitors, int *M) {
    FILE *file = fopen(filename, "r");

    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê V e E
    fscanf(file, "%d %d", V, E);

    // Lê S, C e M
    fscanf(file, "%d %d %d", S, C, M);

    // Aloca memória para os arrays
    *servers = malloc(*S * sizeof(int));
    *clients = malloc(*C * sizeof(int));
    *monitors = malloc(*M * sizeof(int));

    // Lê os servidores
    for (int i = 0; i < *S; i++) {
        fscanf(file, "%d", &(*servers)[i]);
    }

    // Lê os clientes
    for (int i = 0; i < *C; i++) {
        fscanf(file, "%d", &(*clients)[i]);
    }

    // Lê os monitores
    for (int i = 0; i < *M; i++) {
        fscanf(file, "%d", &(*monitors)[i]);
    }

    // Cria o grafo
    Graph* graph = graph_create(*V, *E);

    // Lê as arestas
    for (int i = 0; i < *E; i++) {
        int x, y;
        double z;
        fscanf(file, "%d %d %lf", &x, &y, &z);
        node_insert(graph, x, y, z);
    }

    fclose(file);
    return graph;
}