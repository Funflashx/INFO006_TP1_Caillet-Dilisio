
#include <cstdio>
#include "Contexte.h"
#include "ArcEnCiel.h"
#include "Cracker.h"


using namespace std;

void hex(unsigned char * p, int nb);
int p_sucess(int N,int M,int T);

int main() {
    Contexte c;
    ArcEnCiel arcEnCiel;
    string clair;

/*
    uint64 index = 14949318;
    c.i2c(index,clair);
    printf("Clair = %s \n", clair.c_str());
    Condense buff;
    printf("Hash: ");
    c.h(clair , buff);
    hex(buff, 16);
    printf("h2i(1) -> %d\n",c.h2i(1,buff));
    printf("\ni2i(1, 14949318) => %d\n", c.i2i(1,index));
*/




    //arcEnCiel.load("big_dico.txt");
    cout << "Patientez.... " << endl;
    arcEnCiel.create(c, 0, 100000, 1000);
    //arcEnCiel.displayChaine();
    arcEnCiel.sort_by_idTx();
    arcEnCiel.displayChaine();
    arcEnCiel.save("big_dico.txt");
    Cracker* cracker = new Cracker();
    int i = 0;
    unsigned char crypt1[16];

    cout << "Indiquez le MD5 à cracker : " << endl;
    while (i < 16) {
        unsigned int a;
        if (scanf("%02x", &a) == 1) {
            crypt1[i] = (unsigned char) a;
            i++;
        }
    }


    cracker->cracker(crypt1, arcEnCiel, c, clair );

    cout << "Plain text => " << clair << endl;

    delete cracker;


    //cout << p_sucess(pow(5,5), 10000, 10)  << endl;

    return 0;
}


//NON-Fonctionnel
int p_sucess(int N,int M,int T){
    int v, mm;
    mm = M;
    v = 1;
    for (int i = 0; i < T; ++i) {
        v = v * (1 - mm / N);
        mm = (int) (N * (1 - exp(-mm / N ) ));
    }
    return 1 - v;
}

void hex(unsigned char * p, int nb){
    for (int i = 0; i < nb ; ++i) {
        printf("%02x",p[i]);
    }

    printf("\n");
}


