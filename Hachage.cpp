//
// Created by François Caillet on 29/02/2016.
//

#include "Hachage.h"

/* Fonction de Hachage MD5 */
void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    MD5(pPlain, nPlainLen, pHash);
}

/* Fonction de Hachage SHA1 */
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    SHA1(pPlain, nPlainLen, pHash);
}

/* HashLM */
void setup_des_key(unsigned char key_56[], des_key_schedule &ks)
{
    des_cblock key;
    key[0] = key_56[0];
    key[1] = (key_56[0] << 7) | (key_56[1] >> 1);
    key[2] = (key_56[1] << 6) | (key_56[2] >> 2);
    key[3] = (key_56[2] << 5) | (key_56[3] >> 3);
    key[4] = (key_56[3] << 4) | (key_56[4] >> 4);
    key[5] = (key_56[4] << 3) | (key_56[5] >> 5);
    key[6] = (key_56[5] << 2) | (key_56[6] >> 6);
    key[7] = (key_56[6] << 1);
    des_set_key(&key, ks);
}
static unsigned char magic[]={0x4B, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25};

/* Fonction de Hachage HashLM */
void HashLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    int i;
    for (i = nPlainLen; i < 7; i++) pPlain[i] = 0;
    des_key_schedule ks;
    setup_des_key(pPlain, ks);
    des_ecb_encrypt((des_cblock*)magic, (des_cblock*)pHash, ks, DES_ENCRYPT);
}