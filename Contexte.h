//
// Created by François Caillet on 29/02/2016.
//
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include "Hachage.h"
#ifdef MACOSX
#include <sys/types.h>
#endif

#ifndef INFO006_TP1_CAILLET_DILISIO_CONTEXTE_H
#define INFO006_TP1_CAILLET_DILISIO_CONTEXTE_H

typedef unsigned char Condense [16];
typedef unsigned long long uint64;


class Contexte {
private:
    uint64 _N = pow(_nb_lettres,_mot_taille_min);            // nombre de mots
    int _mot_taille_min=5;  // nombre de lettres min d'un mot
    int _mot_taille_max=5;  // nombre de lettres max d'un mot
    uint64 _N_taille[5];   // tableau, nombre de mots d'une taille donnée
    const static int _nb_lettres = 26;      // nombre de lettres possibles pour un caractère
    char _lettres[_nb_lettres] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};;      // tableau des lettres de taille _nb_lettres


    // fonction de hachage
    // In: Clair c ----> Out: Empreinte
public:
    Contexte();
    void h( std::string c, Condense & d );

    // In: position t, empreinte d ---> Retourne index
    uint64 h2i( uint64 t, Condense & d );

    // In: index idx ----> Out: Clair c
    void i2c( uint64 idx, std::string & c );

    // In: index idx ----> retourne index (la composée des précédentes)
    uint64 i2i( uint64 idx );

    // Retourne un indice aléatoire valide.
    uint64 randIndex();
};


#endif //INFO006_TP1_CAILLET_DILISIO_CONTEXTE_H
