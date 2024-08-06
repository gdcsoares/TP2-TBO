#include "rtt.h"
#include <stdlib.h>
#include <stdio.h>

struct rtt {
   int server;  
   int client;  
   double rtt_real;  
   double rtt_aprox;
};

RTT* rtt_create(int server, int client, double rtt_real){
    RTT* rtt = (RTT*)malloc(sizeof(rtt));
    rtt->server = server;
    rtt->client = client;
    rtt->rtt_real = rtt;
    rtt->rtt_aprox = 0;
    return rtt;
}

void rtt_aprox_add(RTT * rtt, double rtt_aprox){
    rtt->rtt_aprox = rtt_aprox;
}

void node_destroy(RTT * rtt){
    free(rtt);
}