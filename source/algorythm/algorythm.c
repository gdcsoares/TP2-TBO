#include <stdio.h>
#include <stdlib.h>
#include "algorythm.h"
#include "../../priority_queue/PQ.h"
#include "../rtt//rtt.h"
#include <limits.h>

#define INFINITY INT_MAX
#define UNDEFINED -1

void djikstra_solve(Graph *G, int source, int *dist, int *prev){
    // Inicializa a fila de prioridade
    PQ *pq = PQ_init(return_vertices(G));
    
    // Inicialização da distância e pai do vértice "source"
    dist[source] = 0;
    prev[source] = UNDEFINED;
    PQ_insert(source, 0, pq);

    // Inicialização das distâncias e pais dos demais vértices
    for(int v = 0; v < return_vertices(G); v++){
        if(v != source){
            dist[v] = INFINITY;
            prev[v] = UNDEFINED;
            PQ_insert(v, INFINITY, pq);
        }
    }

    while(!PQ_empty(pq)){
        // Remove o vértice com a menor distância
        int u = PQ_delmin(pq);

        Node ** adj_list = return_adjLists(G);
        // Para cada vizinho v de u
        for(Node *a = adj_list[u]; a != NULL; a = return_next(a)){
            int v = return_vertex(a);
            int alt = dist[u] + return_distance(a); // Calcula a nova distância
            if(alt < dist[v]){
                prev[v] = u;
                dist[v] = alt;
                PQ_decrease_key(v, alt, pq);
            }
        }
    }

    PQ_finish(pq);
}

void real_rtt_calculate(RTT * rtts,Graph * G, int * servers, int * clients, int n){
    
    for(int i=0; i< n; i++){
        
    }

}