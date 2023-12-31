/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: tendermint/types/block.proto */

#ifndef PROTOBUF_C_tendermint_2ftypes_2fblock_2eproto__INCLUDED
#define PROTOBUF_C_tendermint_2ftypes_2fblock_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "gogoproto/gogo.pb-c.h"
#include "tendermint/types/types.pb-c.h"
#include "tendermint/types/evidence.pb-c.h"

typedef struct Tendermint__Types__Block Tendermint__Types__Block;


/* --- enums --- */


/* --- messages --- */

struct  Tendermint__Types__Block
{
  ProtobufCMessage base;
  Tendermint__Types__Header *header;
  Tendermint__Types__Data *data;
  Tendermint__Types__EvidenceList *evidence;
  Tendermint__Types__Commit *last_commit;
};
#define TENDERMINT__TYPES__BLOCK__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tendermint__types__block__descriptor) \
    , NULL, NULL, NULL, NULL }


/* Tendermint__Types__Block methods */
void   tendermint__types__block__init
                     (Tendermint__Types__Block         *message);
size_t tendermint__types__block__get_packed_size
                     (const Tendermint__Types__Block   *message);
size_t tendermint__types__block__pack
                     (const Tendermint__Types__Block   *message,
                      uint8_t             *out);
size_t tendermint__types__block__pack_to_buffer
                     (const Tendermint__Types__Block   *message,
                      ProtobufCBuffer     *buffer);
Tendermint__Types__Block *
       tendermint__types__block__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tendermint__types__block__free_unpacked
                     (Tendermint__Types__Block *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Tendermint__Types__Block_Closure)
                 (const Tendermint__Types__Block *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor tendermint__types__block__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_tendermint_2ftypes_2fblock_2eproto__INCLUDED */
