#include <stdio.h>
#include "PQ.h"
#include "item.h"

Item make_item(int id, double value) {
    Item t;
    id(t) = id;
    value(t) = value;
    return t;
}

int main() {

    // inicializando a PQ
    PQ * pq = PQ_init(10);

    // inserindo alguns elementos na PQ
    PQ_insert(1,10.0,pq);
    PQ_insert(6, 5.0,pq);
    PQ_insert(3, 3.0,pq);
    PQ_insert(4, 4.0,pq);
    PQ_insert(7, 7.0,pq);
    PQ_insert(2, 1.0,pq);

    // alterando a prioridade de alguns elementos
    PQ_decrease_key(4, 0.5,pq); // agora o nó 4 tem valor 0.5, sua posição no heap deve mudar
    PQ_decrease_key(6, 0.1,pq); // agora o nó 6 tem valor 0.1, sua posição no heap deve mudar

    // removendo o menor elemento e imprimindo
    while (!PQ_empty(pq)) {
        Item p = PQ_delmin(pq);
        printf("Identificador %d, prioridade %lf\n", id(p), value(p));
    }
}
