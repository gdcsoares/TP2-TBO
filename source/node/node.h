#ifndef _NODE_H_
#define _NODE_H_

typedef struct node Node;

Node* node_create(int vertex, float distance, Node* next);

#endif