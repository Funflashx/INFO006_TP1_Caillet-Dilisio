//
// Created by François Caillet on 29/02/2016.
//
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "Hachage.h"
#ifdef MACOSX
#include <sys/types.h>
#endif

#ifndef INFO006_TP1_CAILLET_DILISIO_CONTEXTE_H
#define INFO006_TP1_CAILLET_DILISIO_CONTEXTE_H

typedef unsigned char Condense [16];
typedef unsigned long long uint64;

using namespace std;

class Contexte {
private:
    const static int _nb_lettres = 26;                      // nombre de lettres possibles pour un caractère
    int _mot_taille_min=5;                                  // nombre de lettres min d'un mot
    int _mot_taille_max=5;                                  // nombre de lettres max d'un mot
    uint64 _N = pow(_nb_lettres,_mot_taille_max);           // nombre de mots
    uint64 _N_taille[5];                                    // tableau, nombre de mots d'une taille donnée
    char alphabet[_nb_lettres] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                   'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
            /*, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'*/};      // tableau des lettres de taille _nb_lettres
    //char alphabet[_nb_lettres] =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

public:
    Contexte();

    /**
     *  fonction de hachage (MD5)
     *  @param c : plain text "hello"
     *  @return d : hash in hexadecimal (Condense => char[16])
     */
    void h( std::string c, Condense & d );

    /**
     *  Hash vers index
     *  @param t : position
     *  @param d : empreinte
     *  @return l'index
     */
    uint64 h2i( uint64 t, Condense & d );

    /**
     *  index vers clair
     *  @param idx : index
     *  @return c : le clair correspondant
     */
    void i2c( uint64 idx, std::string & c );

    /**
     *  index vers index
     *  @param idx : index
     *  @param t : position
     *  @return index (la composée des précédentes)
     */
    uint64 i2i( uint64 t, uint64 idx );

    /**
     *  @return retourne un indice aléatoire valide
     */
    uint64 randIndex();

    ////GETTERS////
    uint64 get_N(){
        return this->_N;
    }

    int getMotTailleMin() {
        return this->_mot_taille_min;
    }

    char* getAlphabet() {
        return this->alphabet;
    }

    int getNbLettres() {
        return this->_nb_lettres;
    }


};


#endif //INFO006_TP1_CAILLET_DILISIO_CONTEXTE_H
