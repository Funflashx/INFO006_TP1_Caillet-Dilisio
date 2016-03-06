//
// Created by François Caillet on 03/03/2016.
//
#include "ArcEnCiel.h"

#ifndef INFO006_TP1_CAILLET_DILISIO_CRACKER_H
#define INFO006_TP1_CAILLET_DILISIO_CRACKER_H


class Cracker {

public:
    /**
     *  "Crack" un chiffré (MD5)
     *  @param y : le chiffré
     *  @param aec : une table arc-en-ciel adaptée
     *  @param ctxt : le contexte de cette table
     *  @return pText (plain text) : le clair
     */
    bool cracker( Condense& y, ArcEnCiel& aec, Contexte & ctxt, string & pText );

    /**
     *  Vérifie si "une ligne" trouvée contient l'empreinte "en colonne"
     *  @param y : le chiffré
     *  @param t : position
     *  @param m : première à la dernière chaine trouvé (cf. find [ArcEnCiel])
     *  @param ctxt : le contexte
     *  @return pText (plain text) : le clair || le nombre de fausses alertes
     */
    bool checkAlarm(Condense &y, Contexte &ctxt, int t, Chaine *m, std::string &pText);
};


#endif //INFO006_TP1_CAILLET_DILISIO_CRACKER_H
