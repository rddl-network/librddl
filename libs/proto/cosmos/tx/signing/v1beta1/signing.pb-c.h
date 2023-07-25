/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: cosmos/tx/signing/v1beta1/signing.proto */

#ifndef PROTOBUF_C_cosmos_2ftx_2fsigning_2fv1beta1_2fsigning_2eproto__INCLUDED
#define PROTOBUF_C_cosmos_2ftx_2fsigning_2fv1beta1_2fsigning_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "cosmos/crypto/multisig/v1beta1/multisig.pb-c.h"
#include "google/protobuf/any.pb-c.h"

typedef struct Cosmos__Tx__Signing__V1beta1__SignatureDescriptors Cosmos__Tx__Signing__V1beta1__SignatureDescriptors;
typedef struct Cosmos__Tx__Signing__V1beta1__SignatureDescriptor Cosmos__Tx__Signing__V1beta1__SignatureDescriptor;
typedef struct Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data;
typedef struct Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single;
typedef struct Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi;


/* --- enums --- */

/*
 * SignMode represents a signing mode with its own security guarantees.
 * This enum should be considered a registry of all known sign modes
 * in the Cosmos ecosystem. Apps are not expected to support all known
 * sign modes. Apps that would like to support custom  sign modes are
 * encouraged to open a small PR against this file to add a new case
 * to this SignMode enum describing their sign mode so that different
 * apps have a consistent version of this enum.
 */
typedef enum _Cosmos__Tx__Signing__V1beta1__SignMode {
  /*
   * SIGN_MODE_UNSPECIFIED specifies an unknown signing mode and will be
   * rejected.
   */
  COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_UNSPECIFIED = 0,
  /*
   * SIGN_MODE_DIRECT specifies a signing mode which uses SignDoc and is
   * verified with raw bytes from Tx.
   */
  COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_DIRECT = 1,
  /*
   * SIGN_MODE_TEXTUAL is a future signing mode that will verify some
   * human-readable textual representation on top of the binary representation
   * from SIGN_MODE_DIRECT. It is currently experimental, and should be used
   * for testing purposes only, until Textual is fully released. Please follow
   * the tracking issue https://github.com/cosmos/cosmos-sdk/issues/11970.
   */
  COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_TEXTUAL = 2,
  /*
   * SIGN_MODE_DIRECT_AUX specifies a signing mode which uses
   * SignDocDirectAux. As opposed to SIGN_MODE_DIRECT, this sign mode does not
   * require signers signing over other signers' `signer_info`. It also allows
   * for adding Tips in transactions.
   * Since: cosmos-sdk 0.46
   */
  COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_DIRECT_AUX = 3,
  /*
   * SIGN_MODE_LEGACY_AMINO_JSON is a backwards compatibility mode which uses
   * Amino JSON and will be removed in the future.
   */
  COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_LEGACY_AMINO_JSON = 127,
  /*
   * SIGN_MODE_EIP_191 specifies the sign mode for EIP 191 signing on the Cosmos
   * SDK. Ref: https://eips.ethereum.org/EIPS/eip-191
   * Currently, SIGN_MODE_EIP_191 is registered as a SignMode enum variant,
   * but is not implemented on the SDK by default. To enable EIP-191, you need
   * to pass a custom `TxConfig` that has an implementation of
   * `SignModeHandler` for EIP-191. The SDK may decide to fully support
   * EIP-191 in the future.
   * Since: cosmos-sdk 0.45.2
   */
  COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_EIP_191 = 191
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE)
} Cosmos__Tx__Signing__V1beta1__SignMode;

/* --- messages --- */

/*
 * SignatureDescriptors wraps multiple SignatureDescriptor's.
 */
struct  Cosmos__Tx__Signing__V1beta1__SignatureDescriptors
{
  ProtobufCMessage base;
  /*
   * signatures are the signature descriptors
   */
  size_t n_signatures;
  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor **signatures;
};
#define COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTORS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&cosmos__tx__signing__v1beta1__signature_descriptors__descriptor) \
    , 0,NULL }


/*
 * Single is the signature data for a single signer
 */
struct  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single
{
  ProtobufCMessage base;
  /*
   * mode is the signing mode of the single signer
   */
  Cosmos__Tx__Signing__V1beta1__SignMode mode;
  /*
   * signature is the raw signature bytes
   */
  ProtobufCBinaryData signature;
};
#define COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__SINGLE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&cosmos__tx__signing__v1beta1__signature_descriptor__data__single__descriptor) \
    , COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_UNSPECIFIED, {0,NULL} }


/*
 * Multi is the signature data for a multisig public key
 */
struct  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi
{
  ProtobufCMessage base;
  /*
   * bitarray specifies which keys within the multisig are signing
   */
  Cosmos__Crypto__Multisig__V1beta1__CompactBitArray *bitarray;
  /*
   * signatures is the signatures of the multi-signature
   */
  size_t n_signatures;
  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data **signatures;
};
#define COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__MULTI__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&cosmos__tx__signing__v1beta1__signature_descriptor__data__multi__descriptor) \
    , NULL, 0,NULL }


typedef enum {
  COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__SUM__NOT_SET = 0,
  COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__SUM_SINGLE = 1,
  COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__SUM_MULTI = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__SUM__CASE)
} Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__SumCase;

/*
 * Data represents signature data
 */
struct  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data
{
  ProtobufCMessage base;
  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__SumCase sum_case;
  union {
    /*
     * single represents a single signer
     */
    Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single *single;
    /*
     * multi represents a multisig signer
     */
    Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi *multi;
  };
};
#define COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&cosmos__tx__signing__v1beta1__signature_descriptor__data__descriptor) \
    , COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__DATA__SUM__NOT_SET, {0} }


/*
 * SignatureDescriptor is a convenience type which represents the full data for
 * a signature including the public key of the signer, signing modes and the
 * signature itself. It is primarily used for coordinating signatures between
 * clients.
 */
struct  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor
{
  ProtobufCMessage base;
  /*
   * public_key is the public key of the signer
   */
  Google__Protobuf__Any *public_key;
  Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data *data;
  /*
   * sequence is the sequence of the account, which describes the
   * number of committed transactions signed by a given address. It is used to prevent
   * replay attacks.
   */
  uint64_t sequence;
};
#define COSMOS__TX__SIGNING__V1BETA1__SIGNATURE_DESCRIPTOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&cosmos__tx__signing__v1beta1__signature_descriptor__descriptor) \
    , NULL, NULL, 0 }


/* Cosmos__Tx__Signing__V1beta1__SignatureDescriptors methods */
void   cosmos__tx__signing__v1beta1__signature_descriptors__init
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptors         *message);
size_t cosmos__tx__signing__v1beta1__signature_descriptors__get_packed_size
                     (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptors   *message);
size_t cosmos__tx__signing__v1beta1__signature_descriptors__pack
                     (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptors   *message,
                      uint8_t             *out);
size_t cosmos__tx__signing__v1beta1__signature_descriptors__pack_to_buffer
                     (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptors   *message,
                      ProtobufCBuffer     *buffer);
Cosmos__Tx__Signing__V1beta1__SignatureDescriptors *
       cosmos__tx__signing__v1beta1__signature_descriptors__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   cosmos__tx__signing__v1beta1__signature_descriptors__free_unpacked
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptors *message,
                      ProtobufCAllocator *allocator);
/* Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single methods */
void   cosmos__tx__signing__v1beta1__signature_descriptor__data__single__init
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single         *message);
/* Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi methods */
void   cosmos__tx__signing__v1beta1__signature_descriptor__data__multi__init
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi         *message);
/* Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data methods */
void   cosmos__tx__signing__v1beta1__signature_descriptor__data__init
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data         *message);
/* Cosmos__Tx__Signing__V1beta1__SignatureDescriptor methods */
void   cosmos__tx__signing__v1beta1__signature_descriptor__init
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptor         *message);
size_t cosmos__tx__signing__v1beta1__signature_descriptor__get_packed_size
                     (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor   *message);
size_t cosmos__tx__signing__v1beta1__signature_descriptor__pack
                     (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor   *message,
                      uint8_t             *out);
size_t cosmos__tx__signing__v1beta1__signature_descriptor__pack_to_buffer
                     (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor   *message,
                      ProtobufCBuffer     *buffer);
Cosmos__Tx__Signing__V1beta1__SignatureDescriptor *
       cosmos__tx__signing__v1beta1__signature_descriptor__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   cosmos__tx__signing__v1beta1__signature_descriptor__free_unpacked
                     (Cosmos__Tx__Signing__V1beta1__SignatureDescriptor *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Cosmos__Tx__Signing__V1beta1__SignatureDescriptors_Closure)
                 (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptors *message,
                  void *closure_data);
typedef void (*Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single_Closure)
                 (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Single *message,
                  void *closure_data);
typedef void (*Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi_Closure)
                 (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data__Multi *message,
                  void *closure_data);
typedef void (*Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data_Closure)
                 (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor__Data *message,
                  void *closure_data);
typedef void (*Cosmos__Tx__Signing__V1beta1__SignatureDescriptor_Closure)
                 (const Cosmos__Tx__Signing__V1beta1__SignatureDescriptor *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    cosmos__tx__signing__v1beta1__sign_mode__descriptor;
extern const ProtobufCMessageDescriptor cosmos__tx__signing__v1beta1__signature_descriptors__descriptor;
extern const ProtobufCMessageDescriptor cosmos__tx__signing__v1beta1__signature_descriptor__descriptor;
extern const ProtobufCMessageDescriptor cosmos__tx__signing__v1beta1__signature_descriptor__data__descriptor;
extern const ProtobufCMessageDescriptor cosmos__tx__signing__v1beta1__signature_descriptor__data__single__descriptor;
extern const ProtobufCMessageDescriptor cosmos__tx__signing__v1beta1__signature_descriptor__data__multi__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_cosmos_2ftx_2fsigning_2fv1beta1_2fsigning_2eproto__INCLUDED */
