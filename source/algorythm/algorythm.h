#ifndef _ALGORYTHM_H_
#define _ALGORYTHM_H_

#include "../graph/graph.h"

void djikstra_solve(Graph *G, int source, int *dist, int *prev);

void real_rtt_calculate(RTT * rtts, Graph * G, int * servers, int * clients);

#endif