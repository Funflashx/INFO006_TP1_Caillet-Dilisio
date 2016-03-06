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

public:
    int _numero;                // numero de la table (ici 0, mais voir "Moult tables")
    int _M;                     // nombre de chaines dans la table
    int _T;                     // taille de chaque chaine
    std::vector<Chaine> _X;     // la table elle-meme

    /**
     *  Creer les M chaînes de taille T, dans le contexte ctxt
     */
    void create(Contexte ctxt, int num, int M, int T);

    /**
     *  Tri _X suivant les idxT.
     */
    void sort_by_idTx();

    /**
     *  Sauvegarde la table sur disque.
     *  @param name : nom du fichier où stocker la table.
     */
    void save( std::string name );

    /**
     *  Charge la table du disque.
     *  @param name : nom du fichier à charger.
     */
    void load( std::string name );

    /**
     *  Recherche dichotomique dans la table
     *  SOURCE: Dichotomie — Wikipédia (https://fr.wikipedia.org/wiki/Dichotomie)
     *  @param p : premier trouvé
     *  @param q : dernier trouvé
     *  @return trouvé ou !trouvé
     */
    bool find(uint64 idx, Chaine *&p, Chaine *&q);

    /**
     *  Affiche la table
     */
    void displayChaine();

};



#endif //INFO006_TP1_CAILLET_DILISIO_ARCENCIEL_H
