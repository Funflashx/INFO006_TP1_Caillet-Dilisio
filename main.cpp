
#include <cstdio>
#include <iostream>
#include "Contexte.h"


using namespace std;

void hex(unsigned char * p, int nb);

int main() {
    Contexte c;
    std::string a = "hello";
    Condense buff;
    c.h(a , buff);
    hex(buff,16);

    return 0;
}

void hex(unsigned char * p, int nb){
    for (int i = 0; i < nb ; ++i) {
        printf("%02x",p[i]);
    }

    printf("\n");
}