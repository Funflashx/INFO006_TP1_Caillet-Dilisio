
#include <cstdio>
#include <iostream>
#include "Contexte.h"
#include "ArcEnCiel.h"


using namespace std;

void hex(unsigned char * p, int nb);

int main() {
    Contexte c;
    //std::string clair;
    //uint64 index = 14949318;

    ArcEnCiel arcEnCiel;

/*    c.i2c(index,clair);
    printf("Clair = %s \n", clair.c_str());
    Condense buff;
    printf("Hash: ");
    c.h(clair , buff);
    hex(buff, 16);
    printf("h2i(1) -> %d\n",c.h2i(1,buff));

    printf("\ni2i(1, 14949318) => %d\n", c.i2i(1,index));
    printf("nombre de mot = %d\nIndex Random = %d\n ", c.get_N(), c.randIndex());*/

    arcEnCiel.creer(c,0,10, 50);
    arcEnCiel.displayChaine();


    return 0;
}

void hex(unsigned char * p, int nb){
    for (int i = 0; i < nb ; ++i) {
        printf("%02x",p[i]);
    }

    printf("\n");
}