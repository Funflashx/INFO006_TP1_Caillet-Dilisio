//
// Created by François Caillet on 29/02/2016.
//

#include <openssl/md5.h>
#include <openssl/sha.h>

#include <openssl/des.h>
#ifdef _WIN32
#pragma comment(lib, "libeay32.lib")
#endif

#ifndef INFO006_TP1_CAILLET_DILISIO_HACHAGE_H
#define INFO006_TP1_CAILLET_DILISIO_HACHAGE_H

void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void setup_des_key(unsigned char key_56[], des_key_schedule &ks);
void HashLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);

#endif //INFO006_TP1_CAILLET_DILISIO_HACHAGE_H



