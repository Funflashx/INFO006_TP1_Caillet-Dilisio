//
// Created by François Caillet on 29/02/2016.
//
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Contexte.h"
#ifdef MACOSX
#include <sys/types.h>
#endif

#ifndef INFO006_TP1_CAILLET_DILISIO_ARCENCIEL_H
#define INFO006_TP1_CAILLET_DILISIO_ARCENCIEL_H

using namespace std;
using std::fstream;

struct Chaine {
    uint64 idx1;    // premier indice de la chaine
    uint64 idxT;    // dernier indice de la chaine
};
class ArcEnCiel {
private:
    int _numero;   // numero de la table (ici 0, mais voir "Moult tables")
    int _M;        // nombre de chaines dans la table
    int _T;        // taille de chaque chaine
    std::vector<Chaine> _X;     // la table elle-meme
public:
    // Creer les M chaînes de taille T, dans le contexte ctxt
    void creer( Contexte ctxt, int num, int M, int T );
    // Tri _X suivant idxT.
    void trier();
    // Sauvegarde la table sur disque.
    void save( std::string name );
    // Charge en mémoire la table à partir du disque.
    void load( std::string name );
    // Recherche dichotomique dans la table
    // ( p et q sont le premier/dernier trouvé )
    bool recherche( uint64 idx, int & p, int & q );

    void displayChaine();
};



#endif //INFO006_TP1_CAILLET_DILISIO_ARCENCIEL_H
