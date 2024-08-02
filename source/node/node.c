#include "node.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura de dados para armazenar uma Aresta
struct node {
   int vertex;  // Vértice Destino da Aresta
   float distance;  // Peso da Aresta 
   struct node* next;  // Próximo nó(aresta) na lista de adjacência
};

Node* node_create(int vertex, float distance, Node* next){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->distance = distance;
    newNode->next = next;
    return newNode;
}

int return_vertex(Node * node){
   return node->vertex;
}

float return_distance(Node * node){
   return node->distance;
}

Node * return_next(Node * node){
   return node->next;
}

void node_destroy(Node * node){
    free(node);
}