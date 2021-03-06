//BSD 3-Clause License
//
//Copyright (c) 2018, jadeblaquiere
//All rights reserved.
//
//Redistribution and use in source and binary forms, with or without
//modification, are permitted provided that the following conditions are met:
//
//* Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//* Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//* Neither the name of the copyright holder nor the names of its
//  contributors may be used to endorse or promote products derived from
//  this software without specific prior written permission.
//
//THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef _ECDH_DER_H_INCLUDED_
#define _ECDH_DER_H_INCLUDED_

#include <assert.h>
#include <ecc.h>
#include <gmp.h>
#include <libtasn1.h>

char *_ecdh_der_export_privkey(mpz_t privkey, mpECurve_t cv, size_t *sz);
int _ecdh_der_import_privkey(mpz_t privkey, mpECurve_t cv, char *der, size_t sz);
char *_ecdh_der_export_pubkey(mpECP_t pubkey, mpECurve_t cv, size_t *sz);
int _ecdh_der_init_import_pubkey(mpECP_t pubkey, mpECurve_t cv, char *der, size_t sz);
char *_ecdhe_der_export_message(mpECP_t pubkey, unsigned char *nonce, size_t nsz, unsigned char *msg, size_t msz, size_t *sz);
int _ecdhe_der_init_import_message(unsigned char **ptxt, int *psz, 
    unsigned char **ntxt, int *nsz, unsigned char **ctxt, int *csz,
    char *der, int sz);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif // _ECDH_DER_H_INCLUDED_
