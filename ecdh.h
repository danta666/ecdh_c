
#ifndef ECDH_H // ECDH
#define ECDH_H

#include <string.h>
#include "openssl/aes.h"
#include "openssl/rsa.h"
#include "openssl/ec.h"
#include "openssl/ecdh.h"
#include "openssl/md5.h"

#ifdef __cpluspluls
extern "C" {
#endif // __cpluspluls

#ifndef bool
#define bool int
#endif

#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

bool GenEcdh(int nid, unsigned char *szPriKey, int *pLenPri, 
            unsigned char *szPubKey, int *pLenPub);

bool DoEcdh(int nid, unsigned char * szServerPubKey, int nLenServerPub, 
            unsigned char * szLocalPriKey, int nLenLocalPri, 
            unsigned char * szShareKey, int *pLenShareKey);

#ifdef __cpluspluls
}
#endif // __cpluspluls

#endif // ECDH
