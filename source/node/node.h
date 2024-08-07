#ifndef _NODE_H_
#define _NODE_H_

typedef struct node Node;

Node* node_create(int vertex, double distance, Node* next);

int return_vertex(Node * node);

double return_distance(Node * node);

Node* return_next(Node * node);

void node_destroy(Node * node);


#endif