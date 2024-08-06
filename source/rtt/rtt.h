#ifndef _RTT_H_
#define _RTT_H_

typedef struct rtt RTT;

RTT* rtt_create(int server, int client, double rtt);

void rtt_aprox_add(RTT * rtt, double rtt_aprox);

void rtt_destroy(RTT * rtt);


#endif