/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9-dev */

#ifndef PB_PLANETMINTGO_MACHINE_PLANETMINTGO_MACHINE_MACHINE_PB_H_INCLUDED
#define PB_PLANETMINTGO_MACHINE_PLANETMINTGO_MACHINE_MACHINE_PB_H_INCLUDED
#define PB_NO_STATIC_ASSERT 1 
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _planetmintgo_machine_Metadata {
    pb_callback_t gps;
    pb_callback_t device;
    pb_callback_t assetDefinition;
    pb_callback_t additionalDataCID;
} planetmintgo_machine_Metadata;

typedef struct _planetmintgo_machine_Machine {
    pb_callback_t name;
    pb_callback_t ticker;
    pb_callback_t domain;
    bool reissue;
    uint64_t amount;
    uint64_t precision;
    pb_callback_t issuerPlanetmint;
    pb_callback_t issuerLiquid;
    pb_callback_t machineId;
    bool has_metadata;
    planetmintgo_machine_Metadata metadata;
    uint32_t type;
    pb_callback_t machineIdSignature;
    pb_callback_t address;
} planetmintgo_machine_Machine;

typedef struct _planetmintgo_machine_MachineIndex {
    pb_callback_t machineId;
    pb_callback_t issuerPlanetmint;
    pb_callback_t issuerLiquid;
    pb_callback_t address;
} planetmintgo_machine_MachineIndex;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define planetmintgo_machine_Machine_init_default {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, planetmintgo_machine_Metadata_init_default, 0, {{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_machine_Metadata_init_default {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_machine_MachineIndex_init_default {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_machine_Machine_init_zero   {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, planetmintgo_machine_Metadata_init_zero, 0, {{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_machine_Metadata_init_zero  {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define planetmintgo_machine_MachineIndex_init_zero {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define planetmintgo_machine_Metadata_gps_tag    1
#define planetmintgo_machine_Metadata_device_tag 2
#define planetmintgo_machine_Metadata_assetDefinition_tag 3
#define planetmintgo_machine_Metadata_additionalDataCID_tag 4
#define planetmintgo_machine_Machine_name_tag    1
#define planetmintgo_machine_Machine_ticker_tag  2
#define planetmintgo_machine_Machine_domain_tag  3
#define planetmintgo_machine_Machine_reissue_tag 4
#define planetmintgo_machine_Machine_amount_tag  5
#define planetmintgo_machine_Machine_precision_tag 6
#define planetmintgo_machine_Machine_issuerPlanetmint_tag 7
#define planetmintgo_machine_Machine_issuerLiquid_tag 8
#define planetmintgo_machine_Machine_machineId_tag 9
#define planetmintgo_machine_Machine_metadata_tag 10
#define planetmintgo_machine_Machine_type_tag    11
#define planetmintgo_machine_Machine_machineIdSignature_tag 12
#define planetmintgo_machine_Machine_address_tag 13
#define planetmintgo_machine_MachineIndex_machineId_tag 1
#define planetmintgo_machine_MachineIndex_issuerPlanetmint_tag 2
#define planetmintgo_machine_MachineIndex_issuerLiquid_tag 3
#define planetmintgo_machine_MachineIndex_address_tag 4

/* Struct field encoding specification for nanopb */
#define planetmintgo_machine_Machine_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   name,              1) \
X(a, CALLBACK, SINGULAR, STRING,   ticker,            2) \
X(a, CALLBACK, SINGULAR, STRING,   domain,            3) \
X(a, STATIC,   SINGULAR, BOOL,     reissue,           4) \
X(a, STATIC,   SINGULAR, UINT64,   amount,            5) \
X(a, STATIC,   SINGULAR, UINT64,   precision,         6) \
X(a, CALLBACK, SINGULAR, STRING,   issuerPlanetmint,   7) \
X(a, CALLBACK, SINGULAR, STRING,   issuerLiquid,      8) \
X(a, CALLBACK, SINGULAR, STRING,   machineId,         9) \
X(a, STATIC,   OPTIONAL, MESSAGE,  metadata,         10) \
X(a, STATIC,   SINGULAR, UINT32,   type,             11) \
X(a, CALLBACK, SINGULAR, STRING,   machineIdSignature,  12) \
X(a, CALLBACK, SINGULAR, STRING,   address,          13)
#define planetmintgo_machine_Machine_CALLBACK pb_default_field_callback
#define planetmintgo_machine_Machine_DEFAULT NULL
#define planetmintgo_machine_Machine_metadata_MSGTYPE planetmintgo_machine_Metadata

#define planetmintgo_machine_Metadata_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   gps,               1) \
X(a, CALLBACK, SINGULAR, STRING,   device,            2) \
X(a, CALLBACK, SINGULAR, STRING,   assetDefinition,   3) \
X(a, CALLBACK, SINGULAR, STRING,   additionalDataCID,   4)
#define planetmintgo_machine_Metadata_CALLBACK pb_default_field_callback
#define planetmintgo_machine_Metadata_DEFAULT NULL

#define planetmintgo_machine_MachineIndex_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   machineId,         1) \
X(a, CALLBACK, SINGULAR, STRING,   issuerPlanetmint,   2) \
X(a, CALLBACK, SINGULAR, STRING,   issuerLiquid,      3) \
X(a, CALLBACK, SINGULAR, STRING,   address,           4)
#define planetmintgo_machine_MachineIndex_CALLBACK pb_default_field_callback
#define planetmintgo_machine_MachineIndex_DEFAULT NULL

extern const pb_msgdesc_t planetmintgo_machine_Machine_msg;
extern const pb_msgdesc_t planetmintgo_machine_Metadata_msg;
extern const pb_msgdesc_t planetmintgo_machine_MachineIndex_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define planetmintgo_machine_Machine_fields &planetmintgo_machine_Machine_msg
#define planetmintgo_machine_Metadata_fields &planetmintgo_machine_Metadata_msg
#define planetmintgo_machine_MachineIndex_fields &planetmintgo_machine_MachineIndex_msg

/* Maximum encoded size of messages (where known) */
/* planetmintgo_machine_Machine_size depends on runtime parameters */
/* planetmintgo_machine_Metadata_size depends on runtime parameters */
/* planetmintgo_machine_MachineIndex_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
