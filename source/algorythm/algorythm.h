#ifndef _ALGORYTHM_H_
#define _ALGORYTHM_H_

#include "../graph/graph.h"
#include "../rtt/rtt.h"
#include "../distances/distances.h"


void dijkstra_solve(Graph *G, int source, double* dist);

void distances_calculate(Distances ** dists, int important_nodes, Graph * G, int * servers, int * clients,int * monitors, int S, int C, int M);

void rtt_calculate(Distances ** dists,RTT ** rtts,int * servers, int * clients,int * monitors, int S, int C, int M);

Distances * find_distance(Distances ** dists, int idx, int n);

double add_distances(int a,int b, double * distA, double * distB);

int compare_rtt(const void *a, const void *b);

#endif