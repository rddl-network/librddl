/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9-dev */

#ifndef PB_PLANETMINTGO_ASSET_PLANETMINTGO_ASSET_TX_PB_H_INCLUDED
#define PB_PLANETMINTGO_ASSET_PLANETMINTGO_ASSET_TX_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _planetmintgo_asset_MsgNotarizeAsset {
    pb_callback_t creator;
    pb_callback_t cid;
} planetmintgo_asset_MsgNotarizeAsset;

typedef struct _planetmintgo_asset_MsgNotarizeAssetResponse {
    char dummy_field;
} planetmintgo_asset_MsgNotarizeAssetResponse;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define planetmintgo_asset_MsgNotarizeAsset_init_default {{{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_asset_MsgNotarizeAssetResponse_init_default {0}
#define planetmintgo_asset_MsgNotarizeAsset_init_zero {{{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_asset_MsgNotarizeAssetResponse_init_zero {0}

/* Field tags (for use in manual encoding/decoding) */
#define planetmintgo_asset_MsgNotarizeAsset_creator_tag 1
#define planetmintgo_asset_MsgNotarizeAsset_cid_tag 2

/* Struct field encoding specification for nanopb */
#define planetmintgo_asset_MsgNotarizeAsset_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   creator,           1) \
X(a, CALLBACK, SINGULAR, STRING,   cid,               2)
#define planetmintgo_asset_MsgNotarizeAsset_CALLBACK pb_default_field_callback
#define planetmintgo_asset_MsgNotarizeAsset_DEFAULT NULL

#define planetmintgo_asset_MsgNotarizeAssetResponse_FIELDLIST(X, a) \

#define planetmintgo_asset_MsgNotarizeAssetResponse_CALLBACK NULL
#define planetmintgo_asset_MsgNotarizeAssetResponse_DEFAULT NULL

extern const pb_msgdesc_t planetmintgo_asset_MsgNotarizeAsset_msg;
extern const pb_msgdesc_t planetmintgo_asset_MsgNotarizeAssetResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define planetmintgo_asset_MsgNotarizeAsset_fields &planetmintgo_asset_MsgNotarizeAsset_msg
#define planetmintgo_asset_MsgNotarizeAssetResponse_fields &planetmintgo_asset_MsgNotarizeAssetResponse_msg

/* Maximum encoded size of messages (where known) */
/* planetmintgo_asset_MsgNotarizeAsset_size depends on runtime parameters */
#define planetmintgo_asset_MsgNotarizeAssetResponse_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
