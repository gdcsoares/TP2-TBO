#include "distances.h"
#include <stdio.h>
#include <stdlib.h>


struct dist{
    int origin;
    double * distances;
};


Distances * dist_create(int n){
    Distances * d = (Distances*)malloc(sizeof(Distances));
    d->distances = (double*)malloc(n*sizeof(double));

    return d;
}

void dist_add_origin(Distances * d,int origin){
    d->origin = origin;
}

int return_origin(Distances * d){
    return d->origin;
}

double * return_distances(Distances * d){
    return d->distances;
}

void print_distances(Distances * d, int n){
    for(int i=0; i < n; i++){
        printf("%d->%d: %f / ",d->origin, i ,d->distances[i]);
    }
}

void dist_destroy(Distances * d){
    free(d->distances);
    free(d);
}