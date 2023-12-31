/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: cosmos/tx/config/v1/config.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "cosmos/tx/config/v1/config.pb-c.h"
void   cosmos__tx__config__v1__config__init
                     (Cosmos__Tx__Config__V1__Config         *message)
{
  static const Cosmos__Tx__Config__V1__Config init_value = COSMOS__TX__CONFIG__V1__CONFIG__INIT;
  *message = init_value;
}
size_t cosmos__tx__config__v1__config__get_packed_size
                     (const Cosmos__Tx__Config__V1__Config *message)
{
  assert(message->base.descriptor == &cosmos__tx__config__v1__config__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cosmos__tx__config__v1__config__pack
                     (const Cosmos__Tx__Config__V1__Config *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cosmos__tx__config__v1__config__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cosmos__tx__config__v1__config__pack_to_buffer
                     (const Cosmos__Tx__Config__V1__Config *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cosmos__tx__config__v1__config__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Cosmos__Tx__Config__V1__Config *
       cosmos__tx__config__v1__config__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Cosmos__Tx__Config__V1__Config *)
     protobuf_c_message_unpack (&cosmos__tx__config__v1__config__descriptor,
                                allocator, len, data);
}
void   cosmos__tx__config__v1__config__free_unpacked
                     (Cosmos__Tx__Config__V1__Config *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cosmos__tx__config__v1__config__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor cosmos__tx__config__v1__config__field_descriptors[2] =
{
  {
    "skip_ante_handler",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Cosmos__Tx__Config__V1__Config, skip_ante_handler),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "skip_post_handler",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Cosmos__Tx__Config__V1__Config, skip_post_handler),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cosmos__tx__config__v1__config__field_indices_by_name[] = {
  0,   /* field[0] = skip_ante_handler */
  1,   /* field[1] = skip_post_handler */
};
static const ProtobufCIntRange cosmos__tx__config__v1__config__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor cosmos__tx__config__v1__config__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "cosmos.tx.config.v1.Config",
  "Config",
  "Cosmos__Tx__Config__V1__Config",
  "cosmos.tx.config.v1",
  sizeof(Cosmos__Tx__Config__V1__Config),
  2,
  cosmos__tx__config__v1__config__field_descriptors,
  cosmos__tx__config__v1__config__field_indices_by_name,
  1,  cosmos__tx__config__v1__config__number_ranges,
  (ProtobufCMessageInit) cosmos__tx__config__v1__config__init,
  NULL,NULL,NULL    /* reserved[123] */
};
