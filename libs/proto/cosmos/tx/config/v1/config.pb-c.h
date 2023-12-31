/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: cosmos/tx/config/v1/config.proto */

#ifndef PROTOBUF_C_cosmos_2ftx_2fconfig_2fv1_2fconfig_2eproto__INCLUDED
#define PROTOBUF_C_cosmos_2ftx_2fconfig_2fv1_2fconfig_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "cosmos/app/v1alpha1/module.pb-c.h"

typedef struct Cosmos__Tx__Config__V1__Config Cosmos__Tx__Config__V1__Config;


/* --- enums --- */


/* --- messages --- */

/*
 * Config is the config object of the x/auth/tx package.
 */
struct  Cosmos__Tx__Config__V1__Config
{
  ProtobufCMessage base;
  /*
   * skip_ante_handler defines whether the ante handler registration should be skipped in case an app wants to override
   * this functionality.
   */
  protobuf_c_boolean skip_ante_handler;
  /*
   * skip_post_handler defines whether the post handler registration should be skipped in case an app wants to override
   * this functionality.
   */
  protobuf_c_boolean skip_post_handler;
};
#define COSMOS__TX__CONFIG__V1__CONFIG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&cosmos__tx__config__v1__config__descriptor) \
    , 0, 0 }


/* Cosmos__Tx__Config__V1__Config methods */
void   cosmos__tx__config__v1__config__init
                     (Cosmos__Tx__Config__V1__Config         *message);
size_t cosmos__tx__config__v1__config__get_packed_size
                     (const Cosmos__Tx__Config__V1__Config   *message);
size_t cosmos__tx__config__v1__config__pack
                     (const Cosmos__Tx__Config__V1__Config   *message,
                      uint8_t             *out);
size_t cosmos__tx__config__v1__config__pack_to_buffer
                     (const Cosmos__Tx__Config__V1__Config   *message,
                      ProtobufCBuffer     *buffer);
Cosmos__Tx__Config__V1__Config *
       cosmos__tx__config__v1__config__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   cosmos__tx__config__v1__config__free_unpacked
                     (Cosmos__Tx__Config__V1__Config *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Cosmos__Tx__Config__V1__Config_Closure)
                 (const Cosmos__Tx__Config__V1__Config *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor cosmos__tx__config__v1__config__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_cosmos_2ftx_2fconfig_2fv1_2fconfig_2eproto__INCLUDED */
