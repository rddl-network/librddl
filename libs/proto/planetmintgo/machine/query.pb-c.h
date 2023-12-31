/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/machine/query.proto */

#ifndef PROTOBUF_C_planetmintgo_2fmachine_2fquery_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fmachine_2fquery_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "gogoproto/gogo.pb-c.h"
#include "google/api/annotations.pb-c.h"
#include "cosmos/base/query/v1beta1/pagination.pb-c.h"
#include "planetmintgo/machine/params.pb-c.h"
#include "planetmintgo/machine/machine.pb-c.h"
#include "planetmintgo/machine/liquid_asset.pb-c.h"

typedef struct Planetmintgo__Machine__QueryParamsRequest Planetmintgo__Machine__QueryParamsRequest;
typedef struct Planetmintgo__Machine__QueryParamsResponse Planetmintgo__Machine__QueryParamsResponse;
typedef struct Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest;
typedef struct Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse;
typedef struct Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest;
typedef struct Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse;
typedef struct Planetmintgo__Machine__QueryGetMachineByAddressRequest Planetmintgo__Machine__QueryGetMachineByAddressRequest;
typedef struct Planetmintgo__Machine__QueryGetMachineByAddressResponse Planetmintgo__Machine__QueryGetMachineByAddressResponse;
typedef struct Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest;
typedef struct Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse;


/* --- enums --- */


/* --- messages --- */

/*
 * QueryParamsRequest is request type for the Query/Params RPC method.
 */
struct  Planetmintgo__Machine__QueryParamsRequest
{
  ProtobufCMessage base;
};
#define PLANETMINTGO__MACHINE__QUERY_PARAMS_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_params_request__descriptor) \
     }


/*
 * QueryParamsResponse is response type for the Query/Params RPC method.
 */
struct  Planetmintgo__Machine__QueryParamsResponse
{
  ProtobufCMessage base;
  /*
   * params holds all the parameters of this module.
   */
  Planetmintgo__Machine__Params *params;
};
#define PLANETMINTGO__MACHINE__QUERY_PARAMS_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_params_response__descriptor) \
    , NULL }


struct  Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest
{
  ProtobufCMessage base;
  char *publickey;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_MACHINE_BY_PUBLIC_KEY_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_machine_by_public_key_request__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse
{
  ProtobufCMessage base;
  Planetmintgo__Machine__Machine *machine;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_MACHINE_BY_PUBLIC_KEY_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_machine_by_public_key_response__descriptor) \
    , NULL }


struct  Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest
{
  ProtobufCMessage base;
  char *machineid;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_TRUST_ANCHOR_STATUS_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_trust_anchor_status_request__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse
{
  ProtobufCMessage base;
  char *machineid;
  protobuf_c_boolean isactivated;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_TRUST_ANCHOR_STATUS_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_trust_anchor_status_response__descriptor) \
    , (char *)protobuf_c_empty_string, 0 }


struct  Planetmintgo__Machine__QueryGetMachineByAddressRequest
{
  ProtobufCMessage base;
  char *address;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_MACHINE_BY_ADDRESS_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_machine_by_address_request__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  Planetmintgo__Machine__QueryGetMachineByAddressResponse
{
  ProtobufCMessage base;
  Planetmintgo__Machine__Machine *machine;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_MACHINE_BY_ADDRESS_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_machine_by_address_response__descriptor) \
    , NULL }


struct  Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest
{
  ProtobufCMessage base;
  char *machineid;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_LIQUID_ASSETS_BY_MACHINEID_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_liquid_assets_by_machineid_request__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse
{
  ProtobufCMessage base;
  Planetmintgo__Machine__LiquidAsset *liquidassetentry;
};
#define PLANETMINTGO__MACHINE__QUERY_GET_LIQUID_ASSETS_BY_MACHINEID_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__query_get_liquid_assets_by_machineid_response__descriptor) \
    , NULL }


/* Planetmintgo__Machine__QueryParamsRequest methods */
void   planetmintgo__machine__query_params_request__init
                     (Planetmintgo__Machine__QueryParamsRequest         *message);
size_t planetmintgo__machine__query_params_request__get_packed_size
                     (const Planetmintgo__Machine__QueryParamsRequest   *message);
size_t planetmintgo__machine__query_params_request__pack
                     (const Planetmintgo__Machine__QueryParamsRequest   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_params_request__pack_to_buffer
                     (const Planetmintgo__Machine__QueryParamsRequest   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryParamsRequest *
       planetmintgo__machine__query_params_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_params_request__free_unpacked
                     (Planetmintgo__Machine__QueryParamsRequest *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryParamsResponse methods */
void   planetmintgo__machine__query_params_response__init
                     (Planetmintgo__Machine__QueryParamsResponse         *message);
size_t planetmintgo__machine__query_params_response__get_packed_size
                     (const Planetmintgo__Machine__QueryParamsResponse   *message);
size_t planetmintgo__machine__query_params_response__pack
                     (const Planetmintgo__Machine__QueryParamsResponse   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_params_response__pack_to_buffer
                     (const Planetmintgo__Machine__QueryParamsResponse   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryParamsResponse *
       planetmintgo__machine__query_params_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_params_response__free_unpacked
                     (Planetmintgo__Machine__QueryParamsResponse *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest methods */
void   planetmintgo__machine__query_get_machine_by_public_key_request__init
                     (Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest         *message);
size_t planetmintgo__machine__query_get_machine_by_public_key_request__get_packed_size
                     (const Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest   *message);
size_t planetmintgo__machine__query_get_machine_by_public_key_request__pack
                     (const Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_machine_by_public_key_request__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest *
       planetmintgo__machine__query_get_machine_by_public_key_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_machine_by_public_key_request__free_unpacked
                     (Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse methods */
void   planetmintgo__machine__query_get_machine_by_public_key_response__init
                     (Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse         *message);
size_t planetmintgo__machine__query_get_machine_by_public_key_response__get_packed_size
                     (const Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse   *message);
size_t planetmintgo__machine__query_get_machine_by_public_key_response__pack
                     (const Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_machine_by_public_key_response__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse *
       planetmintgo__machine__query_get_machine_by_public_key_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_machine_by_public_key_response__free_unpacked
                     (Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest methods */
void   planetmintgo__machine__query_get_trust_anchor_status_request__init
                     (Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest         *message);
size_t planetmintgo__machine__query_get_trust_anchor_status_request__get_packed_size
                     (const Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest   *message);
size_t planetmintgo__machine__query_get_trust_anchor_status_request__pack
                     (const Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_trust_anchor_status_request__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest *
       planetmintgo__machine__query_get_trust_anchor_status_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_trust_anchor_status_request__free_unpacked
                     (Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse methods */
void   planetmintgo__machine__query_get_trust_anchor_status_response__init
                     (Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse         *message);
size_t planetmintgo__machine__query_get_trust_anchor_status_response__get_packed_size
                     (const Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse   *message);
size_t planetmintgo__machine__query_get_trust_anchor_status_response__pack
                     (const Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_trust_anchor_status_response__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse *
       planetmintgo__machine__query_get_trust_anchor_status_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_trust_anchor_status_response__free_unpacked
                     (Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetMachineByAddressRequest methods */
void   planetmintgo__machine__query_get_machine_by_address_request__init
                     (Planetmintgo__Machine__QueryGetMachineByAddressRequest         *message);
size_t planetmintgo__machine__query_get_machine_by_address_request__get_packed_size
                     (const Planetmintgo__Machine__QueryGetMachineByAddressRequest   *message);
size_t planetmintgo__machine__query_get_machine_by_address_request__pack
                     (const Planetmintgo__Machine__QueryGetMachineByAddressRequest   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_machine_by_address_request__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetMachineByAddressRequest   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetMachineByAddressRequest *
       planetmintgo__machine__query_get_machine_by_address_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_machine_by_address_request__free_unpacked
                     (Planetmintgo__Machine__QueryGetMachineByAddressRequest *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetMachineByAddressResponse methods */
void   planetmintgo__machine__query_get_machine_by_address_response__init
                     (Planetmintgo__Machine__QueryGetMachineByAddressResponse         *message);
size_t planetmintgo__machine__query_get_machine_by_address_response__get_packed_size
                     (const Planetmintgo__Machine__QueryGetMachineByAddressResponse   *message);
size_t planetmintgo__machine__query_get_machine_by_address_response__pack
                     (const Planetmintgo__Machine__QueryGetMachineByAddressResponse   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_machine_by_address_response__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetMachineByAddressResponse   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetMachineByAddressResponse *
       planetmintgo__machine__query_get_machine_by_address_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_machine_by_address_response__free_unpacked
                     (Planetmintgo__Machine__QueryGetMachineByAddressResponse *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest methods */
void   planetmintgo__machine__query_get_liquid_assets_by_machineid_request__init
                     (Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest         *message);
size_t planetmintgo__machine__query_get_liquid_assets_by_machineid_request__get_packed_size
                     (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest   *message);
size_t planetmintgo__machine__query_get_liquid_assets_by_machineid_request__pack
                     (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_liquid_assets_by_machineid_request__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest *
       planetmintgo__machine__query_get_liquid_assets_by_machineid_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_liquid_assets_by_machineid_request__free_unpacked
                     (Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse methods */
void   planetmintgo__machine__query_get_liquid_assets_by_machineid_response__init
                     (Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse         *message);
size_t planetmintgo__machine__query_get_liquid_assets_by_machineid_response__get_packed_size
                     (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse   *message);
size_t planetmintgo__machine__query_get_liquid_assets_by_machineid_response__pack
                     (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__query_get_liquid_assets_by_machineid_response__pack_to_buffer
                     (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse *
       planetmintgo__machine__query_get_liquid_assets_by_machineid_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__query_get_liquid_assets_by_machineid_response__free_unpacked
                     (Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Machine__QueryParamsRequest_Closure)
                 (const Planetmintgo__Machine__QueryParamsRequest *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryParamsResponse_Closure)
                 (const Planetmintgo__Machine__QueryParamsResponse *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest_Closure)
                 (const Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse_Closure)
                 (const Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest_Closure)
                 (const Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse_Closure)
                 (const Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetMachineByAddressRequest_Closure)
                 (const Planetmintgo__Machine__QueryGetMachineByAddressRequest *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetMachineByAddressResponse_Closure)
                 (const Planetmintgo__Machine__QueryGetMachineByAddressResponse *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest_Closure)
                 (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse_Closure)
                 (const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse *message,
                  void *closure_data);

/* --- services --- */

typedef struct Planetmintgo__Machine__Query_Service Planetmintgo__Machine__Query_Service;
struct Planetmintgo__Machine__Query_Service
{
  ProtobufCService base;
  void (*params)(Planetmintgo__Machine__Query_Service *service,
                 const Planetmintgo__Machine__QueryParamsRequest *input,
                 Planetmintgo__Machine__QueryParamsResponse_Closure closure,
                 void *closure_data);
  void (*get_machine_by_public_key)(Planetmintgo__Machine__Query_Service *service,
                                    const Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest *input,
                                    Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse_Closure closure,
                                    void *closure_data);
  void (*get_trust_anchor_status)(Planetmintgo__Machine__Query_Service *service,
                                  const Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest *input,
                                  Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse_Closure closure,
                                  void *closure_data);
  void (*get_machine_by_address)(Planetmintgo__Machine__Query_Service *service,
                                 const Planetmintgo__Machine__QueryGetMachineByAddressRequest *input,
                                 Planetmintgo__Machine__QueryGetMachineByAddressResponse_Closure closure,
                                 void *closure_data);
  void (*get_liquid_assets_by_machineid)(Planetmintgo__Machine__Query_Service *service,
                                         const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest *input,
                                         Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse_Closure closure,
                                         void *closure_data);
};
typedef void (*Planetmintgo__Machine__Query_ServiceDestroy)(Planetmintgo__Machine__Query_Service *);
void planetmintgo__machine__query__init (Planetmintgo__Machine__Query_Service *service,
                                         Planetmintgo__Machine__Query_ServiceDestroy destroy);
#define PLANETMINTGO__MACHINE__QUERY__BASE_INIT \
    { &planetmintgo__machine__query__descriptor, protobuf_c_service_invoke_internal, NULL }
#define PLANETMINTGO__MACHINE__QUERY__INIT(function_prefix__) \
    { PLANETMINTGO__MACHINE__QUERY__BASE_INIT,\
      function_prefix__ ## params,\
      function_prefix__ ## get_machine_by_public_key,\
      function_prefix__ ## get_trust_anchor_status,\
      function_prefix__ ## get_machine_by_address,\
      function_prefix__ ## get_liquid_assets_by_machineid  }
void planetmintgo__machine__query__params(ProtobufCService *service,
                                          const Planetmintgo__Machine__QueryParamsRequest *input,
                                          Planetmintgo__Machine__QueryParamsResponse_Closure closure,
                                          void *closure_data);
void planetmintgo__machine__query__get_machine_by_public_key(ProtobufCService *service,
                                                             const Planetmintgo__Machine__QueryGetMachineByPublicKeyRequest *input,
                                                             Planetmintgo__Machine__QueryGetMachineByPublicKeyResponse_Closure closure,
                                                             void *closure_data);
void planetmintgo__machine__query__get_trust_anchor_status(ProtobufCService *service,
                                                           const Planetmintgo__Machine__QueryGetTrustAnchorStatusRequest *input,
                                                           Planetmintgo__Machine__QueryGetTrustAnchorStatusResponse_Closure closure,
                                                           void *closure_data);
void planetmintgo__machine__query__get_machine_by_address(ProtobufCService *service,
                                                          const Planetmintgo__Machine__QueryGetMachineByAddressRequest *input,
                                                          Planetmintgo__Machine__QueryGetMachineByAddressResponse_Closure closure,
                                                          void *closure_data);
void planetmintgo__machine__query__get_liquid_assets_by_machineid(ProtobufCService *service,
                                                                  const Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidRequest *input,
                                                                  Planetmintgo__Machine__QueryGetLiquidAssetsByMachineidResponse_Closure closure,
                                                                  void *closure_data);

/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__machine__query_params_request__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_params_response__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_machine_by_public_key_request__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_machine_by_public_key_response__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_trust_anchor_status_request__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_trust_anchor_status_response__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_machine_by_address_request__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_machine_by_address_response__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_liquid_assets_by_machineid_request__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__query_get_liquid_assets_by_machineid_response__descriptor;
extern const ProtobufCServiceDescriptor planetmintgo__machine__query__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fmachine_2fquery_2eproto__INCLUDED */
