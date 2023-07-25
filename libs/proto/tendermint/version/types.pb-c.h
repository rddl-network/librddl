/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: tendermint/version/types.proto */

#ifndef PROTOBUF_C_tendermint_2fversion_2ftypes_2eproto__INCLUDED
#define PROTOBUF_C_tendermint_2fversion_2ftypes_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "gogoproto/gogo.pb-c.h"

typedef struct Tendermint__Version__App Tendermint__Version__App;
typedef struct Tendermint__Version__Consensus Tendermint__Version__Consensus;


/* --- enums --- */


/* --- messages --- */

/*
 * App includes the protocol and software version for the application.
 * This information is included in ResponseInfo. The App.Protocol can be
 * updated in ResponseEndBlock.
 */
struct  Tendermint__Version__App
{
  ProtobufCMessage base;
  uint64_t protocol;
  char *software;
};
#define TENDERMINT__VERSION__APP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tendermint__version__app__descriptor) \
    , 0, (char *)protobuf_c_empty_string }


/*
 * Consensus captures the consensus rules for processing a block in the blockchain,
 * including all blockchain data structures and the rules of the application's
 * state transition machine.
 */
struct  Tendermint__Version__Consensus
{
  ProtobufCMessage base;
  uint64_t block;
  uint64_t app;
};
#define TENDERMINT__VERSION__CONSENSUS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tendermint__version__consensus__descriptor) \
    , 0, 0 }


/* Tendermint__Version__App methods */
void   tendermint__version__app__init
                     (Tendermint__Version__App         *message);
size_t tendermint__version__app__get_packed_size
                     (const Tendermint__Version__App   *message);
size_t tendermint__version__app__pack
                     (const Tendermint__Version__App   *message,
                      uint8_t             *out);
size_t tendermint__version__app__pack_to_buffer
                     (const Tendermint__Version__App   *message,
                      ProtobufCBuffer     *buffer);
Tendermint__Version__App *
       tendermint__version__app__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tendermint__version__app__free_unpacked
                     (Tendermint__Version__App *message,
                      ProtobufCAllocator *allocator);
/* Tendermint__Version__Consensus methods */
void   tendermint__version__consensus__init
                     (Tendermint__Version__Consensus         *message);
size_t tendermint__version__consensus__get_packed_size
                     (const Tendermint__Version__Consensus   *message);
size_t tendermint__version__consensus__pack
                     (const Tendermint__Version__Consensus   *message,
                      uint8_t             *out);
size_t tendermint__version__consensus__pack_to_buffer
                     (const Tendermint__Version__Consensus   *message,
                      ProtobufCBuffer     *buffer);
Tendermint__Version__Consensus *
       tendermint__version__consensus__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tendermint__version__consensus__free_unpacked
                     (Tendermint__Version__Consensus *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Tendermint__Version__App_Closure)
                 (const Tendermint__Version__App *message,
                  void *closure_data);
typedef void (*Tendermint__Version__Consensus_Closure)
                 (const Tendermint__Version__Consensus *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor tendermint__version__app__descriptor;
extern const ProtobufCMessageDescriptor tendermint__version__consensus__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_tendermint_2fversion_2ftypes_2eproto__INCLUDED */
