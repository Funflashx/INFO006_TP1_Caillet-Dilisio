//
// Created by François Caillet on 29/02/2016.
//

#include "Contexte.h"

Contexte::Contexte() {

}

// fonction de hachage
// In: Clair c ----> Out: Empreinte
void Contexte::h( std::string c, Condense & d ){
        HashMD5((unsigned char *) c.c_str(), c.size(), d);
}

uint64 Contexte::h2i( uint64 t, Condense & d ){
        uint64* ptr = (uint64*) d;
        return  ((*ptr)+t) % get_N(); //retourne l'index
}

void Contexte::i2c( uint64 idx, std::string & c ){
        for (int i = 0 ; i < getMotTailleMin() ; ++i) {
                c.push_back(getAlphabet()[idx % getNbLettres()]);
                idx = idx / getNbLettres();
        }
}