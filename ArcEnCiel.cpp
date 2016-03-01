//
// Created by François Caillet on 29/02/2016.
//

#include "ArcEnCiel.h"

void ArcEnCiel::creer( Contexte ctxt, int num, int M, int T ){
    Chaine c[this->_M];

    this->_numero = num;
    this->_M = M;
    this->_T = T;
    this->_X = c;

    uint64 indexTemp;

    for (int i = 0; i < M; ++i) {
        this->_X[i].idx1 = ctxt.randIndex();
        //printf("index = %d \n", i);
        printf("prems = %lld \n", this->_X[i].idx1);
        indexTemp = this->_X[i].idx1;
      //  printf("index = %d \n", i);
        for (int j = 1; j < T-1; ++j) {
            //printf("j= %d ----", j);
            //printf("before= %d ---",indexTemp);
            indexTemp = ctxt.i2i(j,indexTemp);
            //printf("indexTemp= %d\n",indexTemp);

        }
        this->_X[i].idxT = ctxt.i2i(T-1,indexTemp);
        printf("last= %d\n",this->_X[i].idxT );
    }
}

void ArcEnCiel::displayChaine() {
    for (int i = 0; i < this->_M ; ++i) {
        printf("%lld -i2i(1)-> ... ",this->_X[i].idx1);
        printf("-i2i(%d)-> %lld\n", this->_T-1, this->_X[i].idxT);
    }

}