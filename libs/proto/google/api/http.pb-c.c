/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: google/api/http.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "google/api/http.pb-c.h"
void   google__api__http__init
                     (Google__Api__Http         *message)
{
  static const Google__Api__Http init_value = GOOGLE__API__HTTP__INIT;
  *message = init_value;
}
size_t google__api__http__get_packed_size
                     (const Google__Api__Http *message)
{
  assert(message->base.descriptor == &google__api__http__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t google__api__http__pack
                     (const Google__Api__Http *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &google__api__http__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t google__api__http__pack_to_buffer
                     (const Google__Api__Http *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &google__api__http__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Google__Api__Http *
       google__api__http__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Google__Api__Http *)
     protobuf_c_message_unpack (&google__api__http__descriptor,
                                allocator, len, data);
}
void   google__api__http__free_unpacked
                     (Google__Api__Http *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &google__api__http__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   google__api__http_rule__init
                     (Google__Api__HttpRule         *message)
{
  static const Google__Api__HttpRule init_value = GOOGLE__API__HTTP_RULE__INIT;
  *message = init_value;
}
size_t google__api__http_rule__get_packed_size
                     (const Google__Api__HttpRule *message)
{
  assert(message->base.descriptor == &google__api__http_rule__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t google__api__http_rule__pack
                     (const Google__Api__HttpRule *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &google__api__http_rule__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t google__api__http_rule__pack_to_buffer
                     (const Google__Api__HttpRule *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &google__api__http_rule__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Google__Api__HttpRule *
       google__api__http_rule__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Google__Api__HttpRule *)
     protobuf_c_message_unpack (&google__api__http_rule__descriptor,
                                allocator, len, data);
}
void   google__api__http_rule__free_unpacked
                     (Google__Api__HttpRule *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &google__api__http_rule__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   google__api__custom_http_pattern__init
                     (Google__Api__CustomHttpPattern         *message)
{
  static const Google__Api__CustomHttpPattern init_value = GOOGLE__API__CUSTOM_HTTP_PATTERN__INIT;
  *message = init_value;
}
size_t google__api__custom_http_pattern__get_packed_size
                     (const Google__Api__CustomHttpPattern *message)
{
  assert(message->base.descriptor == &google__api__custom_http_pattern__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t google__api__custom_http_pattern__pack
                     (const Google__Api__CustomHttpPattern *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &google__api__custom_http_pattern__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t google__api__custom_http_pattern__pack_to_buffer
                     (const Google__Api__CustomHttpPattern *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &google__api__custom_http_pattern__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Google__Api__CustomHttpPattern *
       google__api__custom_http_pattern__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Google__Api__CustomHttpPattern *)
     protobuf_c_message_unpack (&google__api__custom_http_pattern__descriptor,
                                allocator, len, data);
}
void   google__api__custom_http_pattern__free_unpacked
                     (Google__Api__CustomHttpPattern *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &google__api__custom_http_pattern__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor google__api__http__field_descriptors[2] =
{
  {
    "rules",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Google__Api__Http, n_rules),
    offsetof(Google__Api__Http, rules),
    &google__api__http_rule__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "fully_decode_reserved_expansion",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Google__Api__Http, fully_decode_reserved_expansion),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned google__api__http__field_indices_by_name[] = {
  1,   /* field[1] = fully_decode_reserved_expansion */
  0,   /* field[0] = rules */
};
static const ProtobufCIntRange google__api__http__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor google__api__http__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "google.api.Http",
  "Http",
  "Google__Api__Http",
  "google.api",
  sizeof(Google__Api__Http),
  2,
  google__api__http__field_descriptors,
  google__api__http__field_indices_by_name,
  1,  google__api__http__number_ranges,
  (ProtobufCMessageInit) google__api__http__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor google__api__http_rule__field_descriptors[10] =
{
  {
    "selector",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Google__Api__HttpRule, selector),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "get",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Google__Api__HttpRule, pattern_case),
    offsetof(Google__Api__HttpRule, get),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "put",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Google__Api__HttpRule, pattern_case),
    offsetof(Google__Api__HttpRule, put),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "post",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Google__Api__HttpRule, pattern_case),
    offsetof(Google__Api__HttpRule, post),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "delete",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Google__Api__HttpRule, pattern_case),
    offsetof(Google__Api__HttpRule, delete_),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "patch",
    6,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Google__Api__HttpRule, pattern_case),
    offsetof(Google__Api__HttpRule, patch),
    NULL,
    &protobuf_c_empty_string,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "body",
    7,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Google__Api__HttpRule, body),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "custom",
    8,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Google__Api__HttpRule, pattern_case),
    offsetof(Google__Api__HttpRule, custom),
    &google__api__custom_http_pattern__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "additional_bindings",
    11,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Google__Api__HttpRule, n_additional_bindings),
    offsetof(Google__Api__HttpRule, additional_bindings),
    &google__api__http_rule__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "response_body",
    12,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Google__Api__HttpRule, response_body),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned google__api__http_rule__field_indices_by_name[] = {
  8,   /* field[8] = additional_bindings */
  6,   /* field[6] = body */
  7,   /* field[7] = custom */
  4,   /* field[4] = delete */
  1,   /* field[1] = get */
  5,   /* field[5] = patch */
  3,   /* field[3] = post */
  2,   /* field[2] = put */
  9,   /* field[9] = response_body */
  0,   /* field[0] = selector */
};
static const ProtobufCIntRange google__api__http_rule__number_ranges[2 + 1] =
{
  { 1, 0 },
  { 11, 8 },
  { 0, 10 }
};
const ProtobufCMessageDescriptor google__api__http_rule__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "google.api.HttpRule",
  "HttpRule",
  "Google__Api__HttpRule",
  "google.api",
  sizeof(Google__Api__HttpRule),
  10,
  google__api__http_rule__field_descriptors,
  google__api__http_rule__field_indices_by_name,
  2,  google__api__http_rule__number_ranges,
  (ProtobufCMessageInit) google__api__http_rule__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor google__api__custom_http_pattern__field_descriptors[2] =
{
  {
    "kind",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Google__Api__CustomHttpPattern, kind),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "path",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Google__Api__CustomHttpPattern, path),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned google__api__custom_http_pattern__field_indices_by_name[] = {
  0,   /* field[0] = kind */
  1,   /* field[1] = path */
};
static const ProtobufCIntRange google__api__custom_http_pattern__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor google__api__custom_http_pattern__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "google.api.CustomHttpPattern",
  "CustomHttpPattern",
  "Google__Api__CustomHttpPattern",
  "google.api",
  sizeof(Google__Api__CustomHttpPattern),
  2,
  google__api__custom_http_pattern__field_descriptors,
  google__api__custom_http_pattern__field_indices_by_name,
  1,  google__api__custom_http_pattern__number_ranges,
  (ProtobufCMessageInit) google__api__custom_http_pattern__init,
  NULL,NULL,NULL    /* reserved[123] */
};
