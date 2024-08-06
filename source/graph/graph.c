#include "graph.h"
#include "../node/node.h"
#include <stdio.h>
#include <stdlib.h>

struct graph {
    int V; // Número de Vértices
    int E; // Número de Arestas
    Node ** adjLists; // Array de ponteiros para as cabeças das listas de adjacência de cada vértice
};

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

void graph_print(Graph* graph){
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjLists[i];
        printf("\n Lista de adjacência do vértice %d\n ", i);
        while (temp) {
            printf("%d:%f -> ", return_vertex(temp),return_distance(temp));
            temp = return_next(temp);
        }
        printf("NULL\n");
    }
}

void graph_destroy(Graph * graph){
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = return_next(temp);
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

int return_vertices(Graph * graph){
    return graph->V;
}

Node ** return_adjLists(Graph * graph){
    return graph->adjLists;
}