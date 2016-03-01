
#include <cstdio>
#include <iostream>
#include "Contexte.h"


using namespace std;

void hex(unsigned char * p, int nb);

int main() {
    Contexte c;



    std::string clair;
    c.i2c(14949318,clair);
    printf("Clair = %s \n", clair.c_str());
    Condense buff;
    c.h(clair , buff);
    hex(buff, 16);


    return 0;
}

void hex(unsigned char * p, int nb){
    for (int i = 0; i < nb ; ++i) {
        printf("%02x",p[i]);
    }

    printf("\n");
}