#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "../source/graph/graph.h" 


Graph* read_input_file(const char *filename, int *V, int *E, int **servers, int *S, int **clients, int *C, int **monitors, int *M);

#endif