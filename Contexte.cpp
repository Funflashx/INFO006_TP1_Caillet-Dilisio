//
// Created by François Caillet on 29/02/2016.
//

#include "Contexte.h"
#include <ctime>

Contexte::Contexte() {

}

void Contexte::i2c( uint64 idx, string & c ){
        c = "";
        for (int i = 0 ; i < getMotTailleMin() ; ++i) {
                c.push_back(getAlphabet()[idx % getNbLettres()]);
                idx /= getNbLettres();
        }
}

void Contexte::h( string c, Condense & d ){
        HashMD5((unsigned char *) c.c_str(), (int) c.size(), d);
}

uint64 Contexte::h2i( uint64 t, Condense & d ){
        uint64* ptr = (uint64*) d;
        return  ((*ptr)+t) % get_N(); //retourne l'index
}

uint64 Contexte::i2i( uint64 t, uint64 idx ){
        string c;
        Condense buff;

        i2c(idx,c);
        h(c,buff);
        return h2i(t,buff); //index
}

uint64 Contexte::randIndex(){
        unsigned long n1 = (unsigned long) random();
        unsigned long n2 = (unsigned long) random();
        return  ( (uint64) n2 )
                + ( ( (uint64) n1 ) << 32 ) % get_N();
}

