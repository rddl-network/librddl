/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/dao/challenge.proto */

#ifndef PROTOBUF_C_planetmintgo_2fdao_2fchallenge_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fdao_2fchallenge_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Planetmintgo__Dao__Challenge Planetmintgo__Dao__Challenge;


/* --- enums --- */


/* --- messages --- */

struct  Planetmintgo__Dao__Challenge
{
  ProtobufCMessage base;
  char *initiator;
  char *challenger;
  char *challengee;
  int64_t height;
  protobuf_c_boolean success;
  protobuf_c_boolean finished;
};
#define PLANETMINTGO__DAO__CHALLENGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__dao__challenge__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0, 0, 0 }


/* Planetmintgo__Dao__Challenge methods */
void   planetmintgo__dao__challenge__init
                     (Planetmintgo__Dao__Challenge         *message);
size_t planetmintgo__dao__challenge__get_packed_size
                     (const Planetmintgo__Dao__Challenge   *message);
size_t planetmintgo__dao__challenge__pack
                     (const Planetmintgo__Dao__Challenge   *message,
                      uint8_t             *out);
size_t planetmintgo__dao__challenge__pack_to_buffer
                     (const Planetmintgo__Dao__Challenge   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Dao__Challenge *
       planetmintgo__dao__challenge__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__dao__challenge__free_unpacked
                     (Planetmintgo__Dao__Challenge *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Dao__Challenge_Closure)
                 (const Planetmintgo__Dao__Challenge *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__dao__challenge__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fdao_2fchallenge_2eproto__INCLUDED */
