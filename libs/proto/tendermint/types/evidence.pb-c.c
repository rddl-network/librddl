/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: tendermint/types/evidence.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "tendermint/types/evidence.pb-c.h"
void   tendermint__types__evidence__init
                     (Tendermint__Types__Evidence         *message)
{
  static const Tendermint__Types__Evidence init_value = TENDERMINT__TYPES__EVIDENCE__INIT;
  *message = init_value;
}
size_t tendermint__types__evidence__get_packed_size
                     (const Tendermint__Types__Evidence *message)
{
  assert(message->base.descriptor == &tendermint__types__evidence__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t tendermint__types__evidence__pack
                     (const Tendermint__Types__Evidence *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &tendermint__types__evidence__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t tendermint__types__evidence__pack_to_buffer
                     (const Tendermint__Types__Evidence *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &tendermint__types__evidence__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Tendermint__Types__Evidence *
       tendermint__types__evidence__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Tendermint__Types__Evidence *)
     protobuf_c_message_unpack (&tendermint__types__evidence__descriptor,
                                allocator, len, data);
}
void   tendermint__types__evidence__free_unpacked
                     (Tendermint__Types__Evidence *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &tendermint__types__evidence__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   tendermint__types__duplicate_vote_evidence__init
                     (Tendermint__Types__DuplicateVoteEvidence         *message)
{
  static const Tendermint__Types__DuplicateVoteEvidence init_value = TENDERMINT__TYPES__DUPLICATE_VOTE_EVIDENCE__INIT;
  *message = init_value;
}
size_t tendermint__types__duplicate_vote_evidence__get_packed_size
                     (const Tendermint__Types__DuplicateVoteEvidence *message)
{
  assert(message->base.descriptor == &tendermint__types__duplicate_vote_evidence__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t tendermint__types__duplicate_vote_evidence__pack
                     (const Tendermint__Types__DuplicateVoteEvidence *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &tendermint__types__duplicate_vote_evidence__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t tendermint__types__duplicate_vote_evidence__pack_to_buffer
                     (const Tendermint__Types__DuplicateVoteEvidence *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &tendermint__types__duplicate_vote_evidence__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Tendermint__Types__DuplicateVoteEvidence *
       tendermint__types__duplicate_vote_evidence__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Tendermint__Types__DuplicateVoteEvidence *)
     protobuf_c_message_unpack (&tendermint__types__duplicate_vote_evidence__descriptor,
                                allocator, len, data);
}
void   tendermint__types__duplicate_vote_evidence__free_unpacked
                     (Tendermint__Types__DuplicateVoteEvidence *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &tendermint__types__duplicate_vote_evidence__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   tendermint__types__light_client_attack_evidence__init
                     (Tendermint__Types__LightClientAttackEvidence         *message)
{
  static const Tendermint__Types__LightClientAttackEvidence init_value = TENDERMINT__TYPES__LIGHT_CLIENT_ATTACK_EVIDENCE__INIT;
  *message = init_value;
}
size_t tendermint__types__light_client_attack_evidence__get_packed_size
                     (const Tendermint__Types__LightClientAttackEvidence *message)
{
  assert(message->base.descriptor == &tendermint__types__light_client_attack_evidence__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t tendermint__types__light_client_attack_evidence__pack
                     (const Tendermint__Types__LightClientAttackEvidence *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &tendermint__types__light_client_attack_evidence__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t tendermint__types__light_client_attack_evidence__pack_to_buffer
                     (const Tendermint__Types__LightClientAttackEvidence *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &tendermint__types__light_client_attack_evidence__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Tendermint__Types__LightClientAttackEvidence *
       tendermint__types__light_client_attack_evidence__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Tendermint__Types__LightClientAttackEvidence *)
     protobuf_c_message_unpack (&tendermint__types__light_client_attack_evidence__descriptor,
                                allocator, len, data);
}
void   tendermint__types__light_client_attack_evidence__free_unpacked
                     (Tendermint__Types__LightClientAttackEvidence *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &tendermint__types__light_client_attack_evidence__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   tendermint__types__evidence_list__init
                     (Tendermint__Types__EvidenceList         *message)
{
  static const Tendermint__Types__EvidenceList init_value = TENDERMINT__TYPES__EVIDENCE_LIST__INIT;
  *message = init_value;
}
size_t tendermint__types__evidence_list__get_packed_size
                     (const Tendermint__Types__EvidenceList *message)
{
  assert(message->base.descriptor == &tendermint__types__evidence_list__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t tendermint__types__evidence_list__pack
                     (const Tendermint__Types__EvidenceList *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &tendermint__types__evidence_list__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t tendermint__types__evidence_list__pack_to_buffer
                     (const Tendermint__Types__EvidenceList *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &tendermint__types__evidence_list__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Tendermint__Types__EvidenceList *
       tendermint__types__evidence_list__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Tendermint__Types__EvidenceList *)
     protobuf_c_message_unpack (&tendermint__types__evidence_list__descriptor,
                                allocator, len, data);
}
void   tendermint__types__evidence_list__free_unpacked
                     (Tendermint__Types__EvidenceList *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &tendermint__types__evidence_list__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor tendermint__types__evidence__field_descriptors[2] =
{
  {
    "duplicate_vote_evidence",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Tendermint__Types__Evidence, sum_case),
    offsetof(Tendermint__Types__Evidence, duplicate_vote_evidence),
    &tendermint__types__duplicate_vote_evidence__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "light_client_attack_evidence",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Tendermint__Types__Evidence, sum_case),
    offsetof(Tendermint__Types__Evidence, light_client_attack_evidence),
    &tendermint__types__light_client_attack_evidence__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned tendermint__types__evidence__field_indices_by_name[] = {
  0,   /* field[0] = duplicate_vote_evidence */
  1,   /* field[1] = light_client_attack_evidence */
};
static const ProtobufCIntRange tendermint__types__evidence__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor tendermint__types__evidence__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "tendermint.types.Evidence",
  "Evidence",
  "Tendermint__Types__Evidence",
  "tendermint.types",
  sizeof(Tendermint__Types__Evidence),
  2,
  tendermint__types__evidence__field_descriptors,
  tendermint__types__evidence__field_indices_by_name,
  1,  tendermint__types__evidence__number_ranges,
  (ProtobufCMessageInit) tendermint__types__evidence__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor tendermint__types__duplicate_vote_evidence__field_descriptors[5] =
{
  {
    "vote_a",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__DuplicateVoteEvidence, vote_a),
    &tendermint__types__vote__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vote_b",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__DuplicateVoteEvidence, vote_b),
    &tendermint__types__vote__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "total_voting_power",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__DuplicateVoteEvidence, total_voting_power),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "validator_power",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__DuplicateVoteEvidence, validator_power),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "timestamp",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__DuplicateVoteEvidence, timestamp),
    &google__protobuf__timestamp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned tendermint__types__duplicate_vote_evidence__field_indices_by_name[] = {
  4,   /* field[4] = timestamp */
  2,   /* field[2] = total_voting_power */
  3,   /* field[3] = validator_power */
  0,   /* field[0] = vote_a */
  1,   /* field[1] = vote_b */
};
static const ProtobufCIntRange tendermint__types__duplicate_vote_evidence__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 5 }
};
const ProtobufCMessageDescriptor tendermint__types__duplicate_vote_evidence__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "tendermint.types.DuplicateVoteEvidence",
  "DuplicateVoteEvidence",
  "Tendermint__Types__DuplicateVoteEvidence",
  "tendermint.types",
  sizeof(Tendermint__Types__DuplicateVoteEvidence),
  5,
  tendermint__types__duplicate_vote_evidence__field_descriptors,
  tendermint__types__duplicate_vote_evidence__field_indices_by_name,
  1,  tendermint__types__duplicate_vote_evidence__number_ranges,
  (ProtobufCMessageInit) tendermint__types__duplicate_vote_evidence__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor tendermint__types__light_client_attack_evidence__field_descriptors[5] =
{
  {
    "conflicting_block",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__LightClientAttackEvidence, conflicting_block),
    &tendermint__types__light_block__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "common_height",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__LightClientAttackEvidence, common_height),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "byzantine_validators",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Tendermint__Types__LightClientAttackEvidence, n_byzantine_validators),
    offsetof(Tendermint__Types__LightClientAttackEvidence, byzantine_validators),
    &tendermint__types__validator__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "total_voting_power",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__LightClientAttackEvidence, total_voting_power),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "timestamp",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Tendermint__Types__LightClientAttackEvidence, timestamp),
    &google__protobuf__timestamp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned tendermint__types__light_client_attack_evidence__field_indices_by_name[] = {
  2,   /* field[2] = byzantine_validators */
  1,   /* field[1] = common_height */
  0,   /* field[0] = conflicting_block */
  4,   /* field[4] = timestamp */
  3,   /* field[3] = total_voting_power */
};
static const ProtobufCIntRange tendermint__types__light_client_attack_evidence__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 5 }
};
const ProtobufCMessageDescriptor tendermint__types__light_client_attack_evidence__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "tendermint.types.LightClientAttackEvidence",
  "LightClientAttackEvidence",
  "Tendermint__Types__LightClientAttackEvidence",
  "tendermint.types",
  sizeof(Tendermint__Types__LightClientAttackEvidence),
  5,
  tendermint__types__light_client_attack_evidence__field_descriptors,
  tendermint__types__light_client_attack_evidence__field_indices_by_name,
  1,  tendermint__types__light_client_attack_evidence__number_ranges,
  (ProtobufCMessageInit) tendermint__types__light_client_attack_evidence__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor tendermint__types__evidence_list__field_descriptors[1] =
{
  {
    "evidence",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Tendermint__Types__EvidenceList, n_evidence),
    offsetof(Tendermint__Types__EvidenceList, evidence),
    &tendermint__types__evidence__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned tendermint__types__evidence_list__field_indices_by_name[] = {
  0,   /* field[0] = evidence */
};
static const ProtobufCIntRange tendermint__types__evidence_list__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor tendermint__types__evidence_list__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "tendermint.types.EvidenceList",
  "EvidenceList",
  "Tendermint__Types__EvidenceList",
  "tendermint.types",
  sizeof(Tendermint__Types__EvidenceList),
  1,
  tendermint__types__evidence_list__field_descriptors,
  tendermint__types__evidence_list__field_indices_by_name,
  1,  tendermint__types__evidence_list__number_ranges,
  (ProtobufCMessageInit) tendermint__types__evidence_list__init,
  NULL,NULL,NULL    /* reserved[123] */
};
