#include "memcheck.h"

#define STACK_SIZE_LIMIT 3

typedef struct DepotImplementation *Depot;

typedef struct Product
{
    int serial_no;
};

Depot create_depot();
void delete_depot(Depot depot);

void push_depot(Depot depot, Product *product);

int get_count(Depot depot);

Product *pop_depot(Depot depot);
