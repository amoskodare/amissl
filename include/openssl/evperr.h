#if !defined(PROTO_AMISSL_H) && !defined(AMISSL_COMPILE)
#include <proto/amissl.h>
#endif
/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_EVPERR_H
# define HEADER_EVPERR_H

# ifndef HEADER_SYMHACKS_H
#  include <openssl/symhacks.h>
# endif

# ifdef  __cplusplus
extern "C"
# endif
int ERR_load_EVP_strings(void);

/*
 * EVP function codes.
 */
# define EVP_F_AESNI_INIT_KEY                             165
# define EVP_F_AESNI_XTS_INIT_KEY                         207
# define EVP_F_AES_GCM_CTRL                               196
# define EVP_F_AES_INIT_KEY                               133
# define EVP_F_AES_OCB_CIPHER                             169
# define EVP_F_AES_T4_INIT_KEY                            178
# define EVP_F_AES_T4_XTS_INIT_KEY                        208
# define EVP_F_AES_WRAP_CIPHER                            170
# define EVP_F_AES_XTS_INIT_KEY                           209
# define EVP_F_ALG_MODULE_INIT                            177
# define EVP_F_ARIA_CCM_INIT_KEY                          175
# define EVP_F_ARIA_GCM_CTRL                              197
# define EVP_F_ARIA_GCM_INIT_KEY                          176
# define EVP_F_ARIA_INIT_KEY                              185
# define EVP_F_B64_NEW                                    198
# define EVP_F_CAMELLIA_INIT_KEY                          159
# define EVP_F_CHACHA20_POLY1305_CTRL                     182
# define EVP_F_CMLL_T4_INIT_KEY                           179
# define EVP_F_DES_EDE3_WRAP_CIPHER                       171
# define EVP_F_DO_SIGVER_INIT                             161
# define EVP_F_ENC_NEW                                    199
# define EVP_F_EVP_CIPHERINIT_EX                          123
# define EVP_F_EVP_CIPHER_ASN1_TO_PARAM                   204
# define EVP_F_EVP_CIPHER_CTX_COPY                        163
# define EVP_F_EVP_CIPHER_CTX_CTRL                        124
# define EVP_F_EVP_CIPHER_CTX_SET_KEY_LENGTH              122
# define EVP_F_EVP_CIPHER_PARAM_TO_ASN1                   205
# define EVP_F_EVP_DECRYPTFINAL_EX                        101
# define EVP_F_EVP_DECRYPTUPDATE                          166
# define EVP_F_EVP_DIGESTFINALXOF                         174
# define EVP_F_EVP_DIGESTINIT_EX                          128
# define EVP_F_EVP_ENCRYPTDECRYPTUPDATE                   219
# define EVP_F_EVP_ENCRYPTFINAL_EX                        127
# define EVP_F_EVP_ENCRYPTUPDATE                          167
# define EVP_F_EVP_MD_CTX_COPY_EX                         110
# define EVP_F_EVP_MD_SIZE                                162
# define EVP_F_EVP_OPENINIT                               102
# define EVP_F_EVP_PBE_ALG_ADD                            115
# define EVP_F_EVP_PBE_ALG_ADD_TYPE                       160
# define EVP_F_EVP_PBE_CIPHERINIT                         116
# define EVP_F_EVP_PBE_SCRYPT                             181
# define EVP_F_EVP_PKCS82PKEY                             111
# define EVP_F_EVP_PKEY2PKCS8                             113
# define EVP_F_EVP_PKEY_ASN1_ADD0                         188
# define EVP_F_EVP_PKEY_CHECK                             186
# define EVP_F_EVP_PKEY_COPY_PARAMETERS                   103
# define EVP_F_EVP_PKEY_CTX_CTRL                          137
# define EVP_F_EVP_PKEY_CTX_CTRL_STR                      150
# define EVP_F_EVP_PKEY_CTX_DUP                           156
# define EVP_F_EVP_PKEY_CTX_MD                            168
# define EVP_F_EVP_PKEY_DECRYPT                           104
# define EVP_F_EVP_PKEY_DECRYPT_INIT                      138
# define EVP_F_EVP_PKEY_DECRYPT_OLD                       151
# define EVP_F_EVP_PKEY_DERIVE                            153
# define EVP_F_EVP_PKEY_DERIVE_INIT                       154
# define EVP_F_EVP_PKEY_DERIVE_SET_PEER                   155
# define EVP_F_EVP_PKEY_ENCRYPT                           105
# define EVP_F_EVP_PKEY_ENCRYPT_INIT                      139
# define EVP_F_EVP_PKEY_ENCRYPT_OLD                       152
# define EVP_F_EVP_PKEY_GET0_DH                           119
# define EVP_F_EVP_PKEY_GET0_DSA                          120
# define EVP_F_EVP_PKEY_GET0_EC_KEY                       131
# define EVP_F_EVP_PKEY_GET0_HMAC                         183
# define EVP_F_EVP_PKEY_GET0_POLY1305                     184
# define EVP_F_EVP_PKEY_GET0_RSA                          121
# define EVP_F_EVP_PKEY_GET0_SIPHASH                      172
# define EVP_F_EVP_PKEY_GET_RAW_PRIVATE_KEY               202
# define EVP_F_EVP_PKEY_GET_RAW_PUBLIC_KEY                203
# define EVP_F_EVP_PKEY_KEYGEN                            146
# define EVP_F_EVP_PKEY_KEYGEN_INIT                       147
# define EVP_F_EVP_PKEY_METH_ADD0                         194
# define EVP_F_EVP_PKEY_METH_NEW                          195
# define EVP_F_EVP_PKEY_NEW                               106
# define EVP_F_EVP_PKEY_NEW_CMAC_KEY                      193
# define EVP_F_EVP_PKEY_NEW_RAW_PRIVATE_KEY               191
# define EVP_F_EVP_PKEY_NEW_RAW_PUBLIC_KEY                192
# define EVP_F_EVP_PKEY_PARAMGEN                          148
# define EVP_F_EVP_PKEY_PARAMGEN_INIT                     149
# define EVP_F_EVP_PKEY_PARAM_CHECK                       189
# define EVP_F_EVP_PKEY_PUBLIC_CHECK                      190
# define EVP_F_EVP_PKEY_SET1_ENGINE                       187
# define EVP_F_EVP_PKEY_SET_ALIAS_TYPE                    206
# define EVP_F_EVP_PKEY_SIGN                              140
# define EVP_F_EVP_PKEY_SIGN_INIT                         141
# define EVP_F_EVP_PKEY_VERIFY                            142
# define EVP_F_EVP_PKEY_VERIFY_INIT                       143
# define EVP_F_EVP_PKEY_VERIFY_RECOVER                    144
# define EVP_F_EVP_PKEY_VERIFY_RECOVER_INIT               145
# define EVP_F_EVP_SIGNFINAL                              107
# define EVP_F_EVP_VERIFYFINAL                            108
# define EVP_F_INT_CTX_NEW                                157
# define EVP_F_OK_NEW                                     200
# define EVP_F_PKCS5_PBE_KEYIVGEN                         117
# define EVP_F_PKCS5_V2_PBE_KEYIVGEN                      118
# define EVP_F_PKCS5_V2_PBKDF2_KEYIVGEN                   164
# define EVP_F_PKCS5_V2_SCRYPT_KEYIVGEN                   180
# define EVP_F_PKEY_SET_TYPE                              158
# define EVP_F_RC2_MAGIC_TO_METH                          109
# define EVP_F_RC5_CTRL                                   125
# define EVP_F_R_32_12_16_INIT_KEY                        242
# define EVP_F_S390X_AES_GCM_CTRL                         201
# define EVP_F_UPDATE                                     173

/*
 * EVP reason codes.
 */
# define EVP_R_AES_KEY_SETUP_FAILED                       143
# define EVP_R_ARIA_KEY_SETUP_FAILED                      176
# define EVP_R_BAD_DECRYPT                                100
# define EVP_R_BAD_KEY_LENGTH                             195
# define EVP_R_BUFFER_TOO_SMALL                           155
# define EVP_R_CAMELLIA_KEY_SETUP_FAILED                  157
# define EVP_R_CIPHER_PARAMETER_ERROR                     122
# define EVP_R_COMMAND_NOT_SUPPORTED                      147
# define EVP_R_COPY_ERROR                                 173
# define EVP_R_CTRL_NOT_IMPLEMENTED                       132
# define EVP_R_CTRL_OPERATION_NOT_IMPLEMENTED             133
# define EVP_R_DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH          138
# define EVP_R_DECODE_ERROR                               114
# define EVP_R_DIFFERENT_KEY_TYPES                        101
# define EVP_R_DIFFERENT_PARAMETERS                       153
# define EVP_R_ERROR_LOADING_SECTION                      165
# define EVP_R_ERROR_SETTING_FIPS_MODE                    166
# define EVP_R_EXPECTING_AN_HMAC_KEY                      174
# define EVP_R_EXPECTING_AN_RSA_KEY                       127
# define EVP_R_EXPECTING_A_DH_KEY                         128
# define EVP_R_EXPECTING_A_DSA_KEY                        129
# define EVP_R_EXPECTING_A_EC_KEY                         142
# define EVP_R_EXPECTING_A_POLY1305_KEY                   164
# define EVP_R_EXPECTING_A_SIPHASH_KEY                    175
# define EVP_R_FIPS_MODE_NOT_SUPPORTED                    167
# define EVP_R_GET_RAW_KEY_FAILED                         182
# define EVP_R_ILLEGAL_SCRYPT_PARAMETERS                  171
# define EVP_R_INITIALIZATION_ERROR                       134
# define EVP_R_INPUT_NOT_INITIALIZED                      111
# define EVP_R_INVALID_DIGEST                             152
# define EVP_R_INVALID_FIPS_MODE                          168
# define EVP_R_INVALID_KEY                                163
# define EVP_R_INVALID_KEY_LENGTH                         130
# define EVP_R_INVALID_OPERATION                          148
# define EVP_R_KEYGEN_FAILURE                             120
# define EVP_R_KEY_SETUP_FAILED                           180
# define EVP_R_MEMORY_LIMIT_EXCEEDED                      172
# define EVP_R_MESSAGE_DIGEST_IS_NULL                     159
# define EVP_R_METHOD_NOT_SUPPORTED                       144
# define EVP_R_MISSING_PARAMETERS                         103
# define EVP_R_NOT_XOF_OR_INVALID_LENGTH                  178
# define EVP_R_NO_CIPHER_SET                              131
# define EVP_R_NO_DEFAULT_DIGEST                          158
# define EVP_R_NO_DIGEST_SET                              139
# define EVP_R_NO_KEY_SET                                 154
# define EVP_R_NO_OPERATION_SET                           149
# define EVP_R_ONLY_ONESHOT_SUPPORTED                     177
# define EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE   150
# define EVP_R_OPERATON_NOT_INITIALIZED                   151
# define EVP_R_PARTIALLY_OVERLAPPING                      162
# define EVP_R_PBKDF2_ERROR                               181
# define EVP_R_PKEY_APPLICATION_ASN1_METHOD_ALREADY_REGISTERED 179
# define EVP_R_PRIVATE_KEY_DECODE_ERROR                   145
# define EVP_R_PRIVATE_KEY_ENCODE_ERROR                   146
# define EVP_R_PUBLIC_KEY_NOT_RSA                         106
# define EVP_R_UNKNOWN_CIPHER                             160
# define EVP_R_UNKNOWN_DIGEST                             161
# define EVP_R_UNKNOWN_OPTION                             169
# define EVP_R_UNKNOWN_PBE_ALGORITHM                      121
# define EVP_R_UNSUPPORTED_ALGORITHM                      156
# define EVP_R_UNSUPPORTED_CIPHER                         107
# define EVP_R_UNSUPPORTED_KEYLENGTH                      123
# define EVP_R_UNSUPPORTED_KEY_DERIVATION_FUNCTION        124
# define EVP_R_UNSUPPORTED_KEY_SIZE                       108
# define EVP_R_UNSUPPORTED_NUMBER_OF_ROUNDS               135
# define EVP_R_UNSUPPORTED_PRF                            125
# define EVP_R_UNSUPPORTED_PRIVATE_KEY_ALGORITHM          118
# define EVP_R_UNSUPPORTED_SALT_TYPE                      126
# define EVP_R_WRAP_MODE_NOT_ALLOWED                      170
# define EVP_R_WRONG_FINAL_BLOCK_LENGTH                   109
# define EVP_R_XTS_DUPLICATED_KEYS                        183

#endif
