#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct graph Graph;

Graph *graph_create(int V, int E);

void node_insert(Graph * g, int a, int b, float distance);

void graph_print(Graph* graph);

void graph_destroy(Graph * graph);




#endif
