/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9-dev */

#ifndef PB_PLANETMINTGO_DAO_PLANETMINTGO_DAO_PARAMS_PB_H_INCLUDED
#define PB_PLANETMINTGO_DAO_PLANETMINTGO_DAO_PARAMS_PB_H_INCLUDED
#include <pb.h>
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Params defines the parameters for the module. */
typedef struct _planetmintgo_dao_Params {
    pb_callback_t mint_address;
} planetmintgo_dao_Params;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define planetmintgo_dao_Params_init_default     {{{NULL}, NULL}}
#define planetmintgo_dao_Params_init_zero        {{{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define planetmintgo_dao_Params_mint_address_tag 1

/* Struct field encoding specification for nanopb */
#define planetmintgo_dao_Params_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   mint_address,      1)
#define planetmintgo_dao_Params_CALLBACK pb_default_field_callback
#define planetmintgo_dao_Params_DEFAULT NULL

extern const pb_msgdesc_t planetmintgo_dao_Params_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define planetmintgo_dao_Params_fields &planetmintgo_dao_Params_msg

/* Maximum encoded size of messages (where known) */
/* planetmintgo_dao_Params_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
