#include <stdio.h>
#include <stdlib.h>
#include "algorythm.h"
#include "../../priority_queue/PQ.h"
#include "../rtt/rtt.h"
#include <limits.h>

#define INFINITY (1.0 / 0.0) 

void dijkstra_solve(Graph *G, int source, double* dist){
    // Inicializa a fila de prioridade
    PQ *pq = PQ_init(return_vertices(G));
    
    // Inicialização da distância e pai do vértice "source"
    dist[source] = 0;
    PQ_insert(source, 0, pq);

    // Inicialização das distâncias e pais dos demais vértices
    for(int v = 0; v < return_vertices(G); v++){
        if(v != source){
            dist[v] = INFINITY;
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
            double alt = dist[u] + return_distance(a); // Calcula a nova distância
            if(alt < dist[v]){
                dist[v] = alt;
                PQ_decrease_key(v, alt, pq);
            }
        }
    }

    PQ_finish(pq);
}

void distances_calculate(Distances ** important_dists,int important_nodes,Graph * G, int * servers, int * clients,int * monitors, int S, int C, int M){
    int num_vertices = return_vertices(G);

    for(int i=0; i < important_nodes ; i++){
        important_dists[i]= dist_create(num_vertices);
    }

    for(int i=0; i < S; i++){
        dist_add_origin(important_dists[i],servers[i]);
        dijkstra_solve(G,servers[i],return_distances(important_dists[i]));
    }

    for(int i=0; i < C; i++){
        dist_add_origin(important_dists[i+S],clients[i]);
        dijkstra_solve(G,clients[i],return_distances(important_dists[i+S]));
    }

    for(int i=0; i < M; i++){
        dist_add_origin(important_dists[i+S+C],monitors[i]);
        dijkstra_solve(G,monitors[i],return_distances(important_dists[i+S+C]));
    }

    /*for(int i=0; i < important_nodes; i++){
        print_distances(important_dists[i],num_vertices);
        printf("\n");
    }*/
}

void rtt_calculate(Distances ** dists,RTT ** rtts,int * servers, int * clients,int * monitors, int S, int C, int M){


    int n_dists = S+C+M;
    double rtt_real, rtt_aprox, rtt_aprox_temp;
    int n=0;


    for(int i=0; i < S; i++){  

        Distances * distS = find_distance(dists,servers[i],n_dists);

        double * distS_double = return_distances(distS);

        for(int j = 0; j < C; j++){

            Distances * distC = find_distance(dists,clients[j],S+C+M);

            double * distC_double = return_distances(distC);

            rtt_real = add_distances(servers[i],clients[j],distS_double,distC_double);
            //printf("RTT: %f - ",rtt_real);

            rtt_aprox = INFINITY;
            for(int k = 0; k < M; k++){

                Distances * distM = find_distance(dists,monitors[k],S+C+M);

                double * distM_double = return_distances(distM);

                rtt_aprox_temp = add_distances(servers[i],monitors[k],distS_double,distM_double)+add_distances(monitors[k],clients[j],distM_double,distC_double);
                if(rtt_aprox_temp < rtt_aprox){
                    rtt_aprox = rtt_aprox_temp;
                }
            }
            //printf("RTT*: %f - RAZAO: %f\n", rtt_aprox, (rtt_aprox/rtt_real));

            RTT * rtt = rtt_create(servers[i],clients[j], rtt_aprox/rtt_real);
            rtts[n]=rtt;
            n++;
        }
    }
}

Distances * find_distance(Distances ** dists, int idx, int n){
    Distances * dist;
    for(int i=0; i < n; i++){

        if(return_origin(dists[i])==idx){
            dist = dists[i];
        }
    }

    return dist;
}


double add_distances(int a,int b, double * distA, double * distB){
    double distIda= distA[b];
    double distVolta = distB[a];

    return distIda+distVolta;
}