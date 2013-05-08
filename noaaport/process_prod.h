/*
 * This file declares the public interface of the process_prod module.
 */
#ifndef PROCESS_PROD_H
#define PROCESS_PROD_H

#include "nport.h"

#ifdef __cplusplus
extern "C" {
#endif

void ds_init(int nfrags);

datastore *ds_alloc();

void ds_free ();

int prod_isascii (char *pname, char *prod, size_t psize);

void process_prod(
    prodstore                   nprod,
    char*                       PROD_NAME,
    char*                       memheap,
    size_t                      heapsize,
    MD5_CTX*                    md5try,
    LdmProductQueue* const      lpq,            /**< Pointer to LDM
                                                 *   product-queue object */
    psh_struct*                 psh,
    sbn_struct*                 sbn);

size_t prodalloc (long int nfrags, long int dbsize, char **heap);

#ifdef __cplusplus
}
#endif

#endif
