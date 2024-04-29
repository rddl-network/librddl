/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/dao/genesis.proto */

#ifndef PROTOBUF_C_planetmintgo_2fdao_2fgenesis_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fdao_2fgenesis_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "gogoproto/gogo.pb-c.h"
#include "planetmintgo/dao/params.pb-c.h"
#include "planetmintgo/dao/redeem_claim.pb-c.h"

typedef struct Planetmintgo__Dao__GenesisState Planetmintgo__Dao__GenesisState;


/* --- enums --- */


/* --- messages --- */

/*
 * GenesisState defines the dao module's genesis state.
 */
struct  Planetmintgo__Dao__GenesisState
{
  ProtobufCMessage base;
  Planetmintgo__Dao__Params *params;
};
#define PLANETMINTGO__DAO__GENESIS_STATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__dao__genesis_state__descriptor) \
    , NULL }


/* Planetmintgo__Dao__GenesisState methods */
void   planetmintgo__dao__genesis_state__init
                     (Planetmintgo__Dao__GenesisState         *message);
size_t planetmintgo__dao__genesis_state__get_packed_size
                     (const Planetmintgo__Dao__GenesisState   *message);
size_t planetmintgo__dao__genesis_state__pack
                     (const Planetmintgo__Dao__GenesisState   *message,
                      uint8_t             *out);
size_t planetmintgo__dao__genesis_state__pack_to_buffer
                     (const Planetmintgo__Dao__GenesisState   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Dao__GenesisState *
       planetmintgo__dao__genesis_state__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__dao__genesis_state__free_unpacked
                     (Planetmintgo__Dao__GenesisState *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Dao__GenesisState_Closure)
                 (const Planetmintgo__Dao__GenesisState *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__dao__genesis_state__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fdao_2fgenesis_2eproto__INCLUDED */
