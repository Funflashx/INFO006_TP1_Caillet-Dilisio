#INFO006_TP1_Caillet-Dilisio

Tables Arc-en-ciel et Attaque Compromis Temps/Mémoire
* Subject: 'http://www.lama.univ-savoie.fr/~lachaud/Cours/INFO006/Tests/doc/html/tp1.html'


##Installation

###Mac OS X "El Capitan"

Install OpenSSL:
```
$brew install openssl 
$brew link --force openssl  
$openssl version -a
```

##DONE
- [x] MD5 hash:
    ```cpp
    //@param c : plain text "hello" 
    //@return d : hash in hexadecimal (Condense => char[16]) 
    void Contexte::h( std::string c, Condense & d ){
            HashMD5((unsigned char *) c.c_str(), c.size(), d);      //put the MD5 hash result on the buffer d
    }
    
    //@param pPlain : plain text
    //@param nPlainLen : strlen
    //@return pointers to the hash value
    void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
    {
        MD5(pPlain, nPlainLen, pHash);      //use <openssl/md5.h> lib
    }
    ```
    (see [Contexte.cpp](Contexte.cpp), [Contexte.h](Contexte.h), [Hachage.cpp](Hachage.cpp), [Hachage.h](Hachage.h) for more details)
    
- [x] Display MD5 hash:
    ```cpp
    void hex(unsigned char * p, int nb){
        for (int i = 0; i < nb ; ++i) {
            printf("%02x",p[i]); //MD5 hash value is expressed as a hex number
        }
    
        printf("\n");
    }
    ```
    (see [main.cpp](main.cpp) for more details)
    