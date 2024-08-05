#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"


struct pq{
    Item *queue;
    int *map;
    int N;
};

static void swap(int i, int j,PQ * pq) {
    exch(pq->queue[i], pq->queue[j]);
    pq->map[id(pq->queue[i])] = i;
    pq->map[id(pq->queue[j])] = j;
}

void fix_up(PQ * pq, int k) {
    while (k > 1 && more(pq->queue[k/2], pq->queue[k])) {
        swap(k, k/2,pq);
        k = k/2;
    }
}

void fix_down(PQ * pq, int k){
  while (2*k <= pq->N) {
    int j = 2*k;
    if (j < pq->N && more(pq->queue[j], pq->queue[j+1])){
      j++;
    }
    if (!more(pq->queue[k], pq->queue[j])) {
      break;
    }
    swap(k, j,pq);
    k = j;
  }
}

PQ * PQ_init(int maxN) {
    PQ * pq = (PQ*)calloc(1,sizeof(pq));

    pq->queue = (Item *) malloc((maxN+1) * sizeof (Item));
    pq->map = (int *) malloc((maxN+1) * sizeof (int));
    pq->N = 0;

    return pq;
}

void PQ_insert(Item v, PQ * pq) {
    pq->N++;
    pq->queue[pq->N] = v;
    pq->map[id(v)] = pq->N;
    fix_up(pq, pq->N);
}

Item PQ_delmin(PQ * pq) {
    Item min = pq->queue[1];
    swap(1, pq->N,pq);
    pq->N--;
    fix_down(pq, 1);
    return min;
}

Item PQ_min(PQ * pq) {
    return pq->queue[1];
}

void PQ_decrease_key(int id, double value,PQ * pq) {
    int i = pq->map[id];
    value(pq->queue[i]) = value;
    fix_up(pq, i);
}

bool PQ_empty(PQ * pq) {
    return pq->N == 0;
}

int  PQ_size(PQ * pq) {
    return pq->N;
}

void PQ_finish(PQ * pq) {
    free(pq->queue);
    free(pq->map);
}


