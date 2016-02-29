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