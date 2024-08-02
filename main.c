#include <stdio.h>
#include <stdlib.h>
#include "source/graph/graph.h"
#include "source/node/node.h"

int main(int agrc, char *argv[]){
    // Abre o arquivo para leitura
    FILE *file = fopen(argv[1], "r");

    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int V, E;
    fscanf(file, "%d %d", &V, &E);

    int S, C, M;
    fscanf(file, "%d %d %d", &S, &C, &M);
    
    int servers[S];
    int clients[C];
    int monitors[M];

    // Lê os servidores
    for (int i = 0; i < S; i++) {
        fscanf(file, "%d", &servers[i]);
    }

    // Lê os clientes
    for (int i = 0; i < C; i++) {
        fscanf(file, "%d", &clients[i]);
    }

    // Lê os monitores
    for (int i = 0; i < M; i++) {
        fscanf(file, "%d", &monitors[i]);
    }

    Graph* graph = graph_create(V, E);

    // Lê as arestas
    for (int i = 0; i < E; i++){
        int x, y;
        float z;
        fscanf(file, "%d %d %f", &x, &y, &z);
        node_insert(graph, x, y, z);
    }

    graph_print(graph);

    graph_destroy(graph);

    fclose(file);

    return 0;
}