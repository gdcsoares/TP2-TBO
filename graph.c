#include "graph.h"
#include "node.h"
#include <stdio.h>

struct graph {
    int V; // Número de Vértices
    int E; // Número de Arestas
    Node ** adjLists; // Array de ponteiros para as cabeças das listas de adjacência de cada vértice
}

Graph* graph_create(int V, int E){
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->V = V;
    graph->E = E;

    graph->adjLists = (Node**)malloc(V * sizeof(Node*));

    for(int i = 0; i < V; i++){
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void node_insert(Graph * g, int a, int b, float distance){
    g->adjLists[a] = node_create(b, distance, g->adjLists[a]);
}