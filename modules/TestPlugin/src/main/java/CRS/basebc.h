#ifndef BASEBC_H
#define BASEBC_H
#include "bc-seq-brandes.h"

int base_bc(int nVtx, int *xadj, int *adj, Betweenness *bc, int maxvertex,
            int nTry, util::timestamp &totaltime, util::timestamp &phase1time,
            util::timestamp &phase2time
#ifdef PARTIAL_BC
            ,
            double partial_bc_factor
#endif

);

#endif
