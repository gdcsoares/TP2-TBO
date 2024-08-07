#include <stdio.h>
#include <stdlib.h>
#include "source/algorythm/algorythm.h"
#include "source/graph/graph.h"
#include "source/node/node.h"
#include "source/rtt/rtt.h"
#include "source/distances/distances.h"
#include "utils/utils.h"

int main(int agrc, char *argv[]){

    int V, E, S, C, M;
    int *servers, *clients, *monitors;

    // Lê os dados do arquivo
    Graph* graph = read_input_file(argv[1], &V, &E, &servers, &S, &clients, &C, &monitors, &M);

    //graph_print(graph);

    int n_rtts = S*C;

    RTT ** rtts = (RTT**)malloc(n_rtts * sizeof(RTT*));

    int important_nodes = S+C+M;

    Distances ** important_dists = (Distances**)malloc(important_nodes * sizeof(Distances*));

    distances_calculate(important_dists, important_nodes, graph, servers, clients,monitors, S, C, M);

    rtt_calculate(important_dists,rtts, servers, clients,monitors, S, C, M);

    qsort(rtts, n_rtts, sizeof(RTT*), compare_rtt);
    
    print_rtts(rtts, n_rtts, argv[2]);

    graph_destroy(graph);

    for(int i = 0;i< n_rtts; i++){
        rtt_destroy(rtts[i]);
    }

    for(int i=0; i<important_nodes;i++){
        dist_destroy(important_dists[i]);
    }

    free(servers);
    free(clients);
    free(monitors);
    free(important_dists);
    free(rtts);

    return 0;
}