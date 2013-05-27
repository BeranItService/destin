#include "destin.h"
#include "learn_strats.h"

#include "math.h"

float CLS_Fixed(Destin * d,  Node * n, uint layer, uint centroid){
    return d->fixedLearnRate;
}

float CLS_Decay(Destin * d, Node * n, uint layer, uint centroid){
    uint wincount;
    float learnRate;
    if(d->isUniform){
        wincount = d->uf_persistWinCounts[layer][centroid];
        // 2013.5.15
        // CZT
        //
        //learnRate = wincount == 0 ? 0.0 : 1.0 / (float)wincount; //TODO: test persist win counts over multiple calls to FormulateBeliefs
        learnRate = (float)(0.1 + 0.9/(1.0 + ceil(sqrt(sqrt(wincount)))));
    }else{
        learnRate = 1 / (float) n->nCounts[n->winner];
    }
    return learnRate;
}
