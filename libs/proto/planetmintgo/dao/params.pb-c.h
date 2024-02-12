/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/dao/params.proto */

#ifndef PROTOBUF_C_planetmintgo_2fdao_2fparams_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fdao_2fparams_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "gogoproto/gogo.pb-c.h"

typedef struct Planetmintgo__Dao__Params Planetmintgo__Dao__Params;


/* --- enums --- */


/* --- messages --- */

/*
 * Params defines the parameters for the module.
 */
struct  Planetmintgo__Dao__Params
{
  ProtobufCMessage base;
  char *mint_address;
};
#define PLANETMINTGO__DAO__PARAMS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__dao__params__descriptor) \
    , (char *)protobuf_c_empty_string }


/* Planetmintgo__Dao__Params methods */
void   planetmintgo__dao__params__init
                     (Planetmintgo__Dao__Params         *message);
size_t planetmintgo__dao__params__get_packed_size
                     (const Planetmintgo__Dao__Params   *message);
size_t planetmintgo__dao__params__pack
                     (const Planetmintgo__Dao__Params   *message,
                      uint8_t             *out);
size_t planetmintgo__dao__params__pack_to_buffer
                     (const Planetmintgo__Dao__Params   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Dao__Params *
       planetmintgo__dao__params__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__dao__params__free_unpacked
                     (Planetmintgo__Dao__Params *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Dao__Params_Closure)
                 (const Planetmintgo__Dao__Params *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__dao__params__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fdao_2fparams_2eproto__INCLUDED */