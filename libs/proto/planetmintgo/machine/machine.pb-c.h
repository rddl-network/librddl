/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/machine/machine.proto */

#ifndef PROTOBUF_C_planetmintgo_2fmachine_2fmachine_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fmachine_2fmachine_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Planetmintgo__Machine__Machine Planetmintgo__Machine__Machine;
typedef struct Planetmintgo__Machine__Metadata Planetmintgo__Machine__Metadata;
typedef struct Planetmintgo__Machine__MachineIndex Planetmintgo__Machine__MachineIndex;


/* --- enums --- */


/* --- messages --- */

struct  Planetmintgo__Machine__Machine
{
  ProtobufCMessage base;
  char *name;
  char *ticker;
  char *domain;
  protobuf_c_boolean reissue;
  uint64_t amount;
  uint64_t precision;
  char *issuerplanetmint;
  char *issuerliquid;
  char *machineid;
  Planetmintgo__Machine__Metadata *metadata;
  uint32_t type;
  char *machineidsignature;
  char *address;
};
#define PLANETMINTGO__MACHINE__MACHINE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__machine__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0, 0, 0, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, NULL, 0, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


struct  Planetmintgo__Machine__Metadata
{
  ProtobufCMessage base;
  char *gps;
  char *device;
  char *assetdefinition;
  char *additionaldatacid;
};
#define PLANETMINTGO__MACHINE__METADATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__metadata__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


struct  Planetmintgo__Machine__MachineIndex
{
  ProtobufCMessage base;
  char *machineid;
  char *issuerplanetmint;
  char *issuerliquid;
  char *address;
};
#define PLANETMINTGO__MACHINE__MACHINE_INDEX__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__machine__machine_index__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/* Planetmintgo__Machine__Machine methods */
void   planetmintgo__machine__machine__init
                     (Planetmintgo__Machine__Machine         *message);
size_t planetmintgo__machine__machine__get_packed_size
                     (const Planetmintgo__Machine__Machine   *message);
size_t planetmintgo__machine__machine__pack
                     (const Planetmintgo__Machine__Machine   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__machine__pack_to_buffer
                     (const Planetmintgo__Machine__Machine   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__Machine *
       planetmintgo__machine__machine__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__machine__free_unpacked
                     (Planetmintgo__Machine__Machine *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__Metadata methods */
void   planetmintgo__machine__metadata__init
                     (Planetmintgo__Machine__Metadata         *message);
size_t planetmintgo__machine__metadata__get_packed_size
                     (const Planetmintgo__Machine__Metadata   *message);
size_t planetmintgo__machine__metadata__pack
                     (const Planetmintgo__Machine__Metadata   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__metadata__pack_to_buffer
                     (const Planetmintgo__Machine__Metadata   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__Metadata *
       planetmintgo__machine__metadata__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__metadata__free_unpacked
                     (Planetmintgo__Machine__Metadata *message,
                      ProtobufCAllocator *allocator);
/* Planetmintgo__Machine__MachineIndex methods */
void   planetmintgo__machine__machine_index__init
                     (Planetmintgo__Machine__MachineIndex         *message);
size_t planetmintgo__machine__machine_index__get_packed_size
                     (const Planetmintgo__Machine__MachineIndex   *message);
size_t planetmintgo__machine__machine_index__pack
                     (const Planetmintgo__Machine__MachineIndex   *message,
                      uint8_t             *out);
size_t planetmintgo__machine__machine_index__pack_to_buffer
                     (const Planetmintgo__Machine__MachineIndex   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Machine__MachineIndex *
       planetmintgo__machine__machine_index__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__machine__machine_index__free_unpacked
                     (Planetmintgo__Machine__MachineIndex *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Machine__Machine_Closure)
                 (const Planetmintgo__Machine__Machine *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__Metadata_Closure)
                 (const Planetmintgo__Machine__Metadata *message,
                  void *closure_data);
typedef void (*Planetmintgo__Machine__MachineIndex_Closure)
                 (const Planetmintgo__Machine__MachineIndex *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__machine__machine__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__metadata__descriptor;
extern const ProtobufCMessageDescriptor planetmintgo__machine__machine_index__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fmachine_2fmachine_2eproto__INCLUDED */
