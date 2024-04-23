/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: planetmintgo/dao/distribution_order.proto */

#ifndef PROTOBUF_C_planetmintgo_2fdao_2fdistribution_5forder_2eproto__INCLUDED
#define PROTOBUF_C_planetmintgo_2fdao_2fdistribution_5forder_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Planetmintgo__Dao__DistributionOrder Planetmintgo__Dao__DistributionOrder;


/* --- enums --- */


/* --- messages --- */

struct  Planetmintgo__Dao__DistributionOrder
{
  ProtobufCMessage base;
  char *daoaddr;
  char *daoamount;
  char *daotxid;
  char *investoraddr;
  char *investoramount;
  char *investortxid;
  char *popaddr;
  char *popamount;
  char *poptxid;
  int64_t firstpop;
  int64_t lastpop;
  char *proposer;
  char *earlyinvaddr;
  char *earlyinvamount;
  char *earlyinvtxid;
  char *strategicaddr;
  char *strategicamount;
  char *strategictxid;
};
#define PLANETMINTGO__DAO__DISTRIBUTION_ORDER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&planetmintgo__dao__distribution_order__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0, 0, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/* Planetmintgo__Dao__DistributionOrder methods */
void   planetmintgo__dao__distribution_order__init
                     (Planetmintgo__Dao__DistributionOrder         *message);
size_t planetmintgo__dao__distribution_order__get_packed_size
                     (const Planetmintgo__Dao__DistributionOrder   *message);
size_t planetmintgo__dao__distribution_order__pack
                     (const Planetmintgo__Dao__DistributionOrder   *message,
                      uint8_t             *out);
size_t planetmintgo__dao__distribution_order__pack_to_buffer
                     (const Planetmintgo__Dao__DistributionOrder   *message,
                      ProtobufCBuffer     *buffer);
Planetmintgo__Dao__DistributionOrder *
       planetmintgo__dao__distribution_order__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   planetmintgo__dao__distribution_order__free_unpacked
                     (Planetmintgo__Dao__DistributionOrder *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Planetmintgo__Dao__DistributionOrder_Closure)
                 (const Planetmintgo__Dao__DistributionOrder *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor planetmintgo__dao__distribution_order__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_planetmintgo_2fdao_2fdistribution_5forder_2eproto__INCLUDED */
