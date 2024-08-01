#include "node.h"

// Estrutura de dados para armazenar uma Aresta
 struct node {
    int vertex;  // Vértice Destino da Aresta
    float distance;  // Peso da Aresta 
    struct Node* next;  // Próximo nó(aresta) na lista de adjacência
 };

 Node* node_create(int vertex, float distance, Node* next){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->distance = distance;
    newNode->next = next;
    return newNode;
 }