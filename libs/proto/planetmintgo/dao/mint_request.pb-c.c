/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/dao/mint_request.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "planetmintgo/dao/mint_request.pb-c.h"
void   planetmintgo__dao__mint_request__init
                     (Planetmintgo__Dao__MintRequest         *message)
{
  static const Planetmintgo__Dao__MintRequest init_value = PLANETMINTGO__DAO__MINT_REQUEST__INIT;
  *message = init_value;
}
size_t planetmintgo__dao__mint_request__get_packed_size
                     (const Planetmintgo__Dao__MintRequest *message)
{
  assert(message->base.descriptor == &planetmintgo__dao__mint_request__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t planetmintgo__dao__mint_request__pack
                     (const Planetmintgo__Dao__MintRequest *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &planetmintgo__dao__mint_request__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t planetmintgo__dao__mint_request__pack_to_buffer
                     (const Planetmintgo__Dao__MintRequest *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &planetmintgo__dao__mint_request__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Planetmintgo__Dao__MintRequest *
       planetmintgo__dao__mint_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Planetmintgo__Dao__MintRequest *)
     protobuf_c_message_unpack (&planetmintgo__dao__mint_request__descriptor,
                                allocator, len, data);
}
void   planetmintgo__dao__mint_request__free_unpacked
                     (Planetmintgo__Dao__MintRequest *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &planetmintgo__dao__mint_request__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor planetmintgo__dao__mint_request__field_descriptors[3] =
{
  {
    "beneficiary",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Planetmintgo__Dao__MintRequest, beneficiary),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "amount",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Planetmintgo__Dao__MintRequest, amount),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "liquidTxHash",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Planetmintgo__Dao__MintRequest, liquidtxhash),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned planetmintgo__dao__mint_request__field_indices_by_name[] = {
  1,   /* field[1] = amount */
  0,   /* field[0] = beneficiary */
  2,   /* field[2] = liquidTxHash */
};
static const ProtobufCIntRange planetmintgo__dao__mint_request__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor planetmintgo__dao__mint_request__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "planetmintgo.dao.MintRequest",
  "MintRequest",
  "Planetmintgo__Dao__MintRequest",
  "planetmintgo.dao",
  sizeof(Planetmintgo__Dao__MintRequest),
  3,
  planetmintgo__dao__mint_request__field_descriptors,
  planetmintgo__dao__mint_request__field_indices_by_name,
  1,  planetmintgo__dao__mint_request__number_ranges,
  (ProtobufCMessageInit) planetmintgo__dao__mint_request__init,
  NULL,NULL,NULL    /* reserved[123] */
};
