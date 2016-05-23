
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
#include "ostype.h"
#include "UtilPdu.h"

//解密
//cipherFile为要加密的源文件名 keyStr 为8位字符密钥  plainFile为加密后的目标文件名

#ifdef __cplusplus
extern "C" {
#endif


int DecryptionFile(const char *strOutFile, const char *keyStr0, const char *strName);
//加密
int EncryptionFile(char *strName, char *keyStr0, char *strOutFile);

int Decryption(CSimpleBuffer *inbuffer, char *key, CSimpleBuffer *outbuffer);
int Encryption(CSimpleBuffer *inbuffer, char *key, CSimpleBuffer *outbuffer);

#ifdef __cplusplus
}
#endif
