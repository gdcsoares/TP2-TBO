#include "rtt.h"
#include <stdlib.h>
#include <stdio.h>

struct rtt {
   int server;  
   int client;  
   double razao;
};

RTT* rtt_create(int server, int client, double razao){
    RTT* rtt = (RTT*)malloc(sizeof(RTT));
    rtt->server = server;
    rtt->client = client;
    rtt->razao = razao;
    return rtt;
}


void rtt_destroy(RTT * rtt){
    free(rtt);
}

int compare_rtt(const void *a, const void *b){
    RTT *rttA = *(RTT **)a;
    RTT *rttB = *(RTT **)b;

    if(rttA->razao < rttB->razao) return -1;
    if(rttA->razao > rttB->razao) return 1;
    return 0;
}

void print_rtts(RTT ** rtts, int n_rtts, char *filename){
    FILE *saida = fopen(filename, "w");
    for(int i = 0; i < n_rtts; i++){
        fprintf(saida, "%d %d %.16lf\n", rtts[i]->server, rtts[i]->client, rtts[i]->razao);
    }
    fclose(saida);
}