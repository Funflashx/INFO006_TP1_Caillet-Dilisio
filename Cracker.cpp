//
// Created by François Caillet on 03/03/2016.
//

#include "Cracker.h"

bool Cracker::cracker( Condense & y, ArcEnCiel& aec, Contexte & ctxt, string & clair )
{
    Chaine* p=0;
    Chaine* q=0;
    int nb_false_alarm = 0;

    for ( int t = aec._T - 1; t > 0; --t ) {
        uint64 idx = ctxt.h2i((uint64) t, y );
        for ( int k = t+1; k <= aec._T-1 ; ++k ) {
            idx = ctxt.i2i((uint64) k, idx);
        }
        if (aec.find(idx, p, q) ) {
            for ( Chaine* m = p; m <= q; m++ ) {
                if (checkAlarm(y, ctxt, t, m, clair))
                {
                    return true;
                }
                nb_false_alarm++;
            }
        }
    }
    cout << "Plain text not found, false alarms = " << nb_false_alarm << endl;

    return false;
}

bool Cracker::checkAlarm(Condense &y, Contexte &ctxt, int t, Chaine *c, std::string &pText)
{
    Condense hash;
    uint64_t idx = c->idx1;

    for(int i=0; i<t; i++)
    {
        ctxt.i2c(idx, pText);
        ctxt.h(pText, hash);

        idx = ctxt.h2i((uint64) i, hash);

        int j = 0;

        while (hash[j] == y[j])
        {
            j++;
            if(y[j] == '\0') return true;
        }
    }
    pText ="No match is found";
    return false;
}