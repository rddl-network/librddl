/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/asset/genesis.proto */

#ifndef PROTOBUF_C_planetmintgo_2fasset_2fgenesis_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fasset_2fgenesis_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "gogoproto/gogo.pb-c.h"
#include "planetmintgo/asset/params.pb-c.h"

typedef struct Planetmintgo__Asset__GenesisState Planetmintgo__Asset__GenesisState;


/* --- enums --- */


/* --- messages --- */

/*
 * GenesisState defines the asset module's genesis state.
 */
struct  Planetmintgo__Asset__GenesisState
{
  ProtobufCMessage base;
  Planetmintgo__Asset__Params *params;
};
#define PLANETMINTGO__ASSET__GENESIS_STATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__asset__genesis_state__descriptor) \
    , NULL }


/* Planetmintgo__Asset__GenesisState methods */
void   planetmintgo__asset__genesis_state__init
                     (Planetmintgo__Asset__GenesisState         *message);
size_t planetmintgo__asset__genesis_state__get_packed_size
                     (const Planetmintgo__Asset__GenesisState   *message);
size_t planetmintgo__asset__genesis_state__pack
                     (const Planetmintgo__Asset__GenesisState   *message,
                      uint8_t             *out);
size_t planetmintgo__asset__genesis_state__pack_to_buffer
                     (const Planetmintgo__Asset__GenesisState   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Asset__GenesisState *
       planetmintgo__asset__genesis_state__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__asset__genesis_state__free_unpacked
                     (Planetmintgo__Asset__GenesisState *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Asset__GenesisState_Closure)
                 (const Planetmintgo__Asset__GenesisState *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__asset__genesis_state__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fasset_2fgenesis_2eproto__INCLUDED */
