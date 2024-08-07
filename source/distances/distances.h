#ifndef _DISTANCES_H_
#define _DISTANCES_H_

typedef struct dist Distances;

Distances * dist_create(int n);

void dist_add_origin(Distances * d,int origin);

int return_origin(Distances * d);

double * return_distances(Distances * d);

void print_distances(Distances * d, int n);

void dist_destroy(Distances * d);




#endif