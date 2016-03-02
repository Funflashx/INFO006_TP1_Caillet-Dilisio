//
// Created by François Caillet on 29/02/2016.
//

#include "ArcEnCiel.h"

void ArcEnCiel::creer( Contexte ctxt, int num, int M, int T ){
    _X.resize( M );

    this->_numero = num;
    this->_M = M;
    this->_T = T;

    uint64 indexTemp;

    for (int i = 0; i < M; ++i) {
        this->_X[i].idx1 = ctxt.randIndex();
        indexTemp = this->_X[i].idx1;
        for (int j = 1; j < T-1; ++j) {
            indexTemp = ctxt.i2i(j,indexTemp);
        }
        this->_X[i].idxT = ctxt.i2i(T-1,indexTemp);
    }
}

void ArcEnCiel::displayChaine() {
    for (int i = 0; i < this->_M ; ++i) {
        printf("%lld -i2i(1)-> ... ",this->_X[i].idx1);
        printf("-i2i(%d)-> %lld\n", this->_T-1, this->_X[i].idxT);
    }

}

bool sort_chaine(Chaine const& c1,Chaine const& c2){
    return c1.idxT < c2.idxT;
}

void ArcEnCiel::trier(){
    std::sort(this->_X.begin(), this->_X.end(), &sort_chaine);
}

