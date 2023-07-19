#include "unity.h"
#include <stdio.h>
#include <string.h>

#include "planetmintgo.h"


const char* planetmint_service="http://0.0.0.0:34331";


// legacy: https://docs.cosmos.network/v0.45/architecture/adr-028-public-key-addresses.html

//pub key secp256k1
//[]uint8 len: 35, cap: 48, [10,33,2,50,141,232,120,150,185,203,181,16,28,51,95,64,2,158,75,232,152,152,139,71,10,187,246,131,241,160,179,24,215,52,112]

//*github.com/cosmos/cosmos-sdk/crypto/keyring.Record {Name: "machine", PubKey: *github.com/cosmos/cosmos-sdk/codec/types.Any {TypeUrl: "/cosmos.crypto.secp256k1.PubKey", Value: []uint8 len: 35, cap: 35, [10,33,2,50,141,232,120,150,185,203,181,16,28,51,95,64,2,158,75,232,152,152,139,71,10,187,246,131,241,160,179,24,215,52,112], XXX_NoUnkeyedLiteral: struct {} {}, XXX_unrecognized: []uint8 len: 0, cap: 0, nil, XXX_sizecache: 0, cachedValue: interface {}(*github.com/cosmos/cosmos-sdk/crypto/keys/secp256k1.PubKey) ..., compat: *github.com/cosmos/cosmos-sdk/codec/types.anyCompat nil}, Item: github.com/cosmos/cosmos-sdk/crypto/keyring.isRecord_Item(*github.com/cosmos/cosmos-sdk/crypto/keyring.Record_Local_) *{Local: *(*"github.com/cosmos/cosmos-sdk/crypto/keyring.Record_Local")(0xc0006211a8)}}
//[]uint8 len: 35, cap: 35, [10,33,2,50,141,232,120,150,185,203,181,16,28,51,95,64,2,158,75,232,152,152,139,71,10,187,246,131,241,160,179,24,215,52,112]
//private key
//[]uint8 len: 34, cap: 34, [10,32,128,112,249,202,124,175,82,178,11,149,241,218,147,44,100,141,148,52,223,57,67,112,250,53,133,185,112,220,55,149,174,168]

//address
//string: ".>\xfa\thY\xf2M0\xfa\xbc\xa5)\xc5wN\xc3\xcd\x01F"
//github.com/cosmos/cosmos-sdk/types.AccAddress len: 20, cap: 24, [46,62,250,9,104,89,242,77,48,250,188,165,41,197,119,78,195,205,1,70]
//address string: "cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx"

//address object:
//github.com/cosmos/cosmos-sdk/types.AccAddress len: 20, cap: 24, [46,62,250,9,104,89,242,77,48,250,188,165,41,197,119,78,195,205,1,70]

#define PUBKEY_SIZE 35
#define ADDRESS_TAIL 20
uint8_t reference_pubkey[35] = {10,33,2,50,141,232,120,150,185,203, 181,16,28,51,95,64,2,158,75,232, 152,152,139,71,10,187,246,131,241,160, 179,24,215,52,112};
uint8_t reference_addressbytes[20] = {46,62,250,9,104,89,242,77,48,250, 188,165,41,197,119,78,195,205,1,70};

const char* expected_address = "cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx";


void test_pubkey2address_convertion()
{
    uint8_t address_bytes[ADDRESS_TAIL] = {0};
    pubkey2address( reference_pubkey+2, address_bytes );
    int result = memcmp( reference_addressbytes, address_bytes, ADDRESS_TAIL);
    printf("result %u", result);

}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_pubkey2address_convertion);

  return UNITY_END();
}
