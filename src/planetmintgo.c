#include "sha2.h"
#include "ripemd160.h"
#include "base32.h"
#include "rddl.h"
#include "ecdsa.h"
#include "secp256k1.h"
#include "planetmintgo.h"
#include "planetmintgo/machine/machine.pb-c.h"
#include "planetmintgo/machine/tx.pb-c.h"
#include "cosmos/tx/v1beta1/tx.pb-c.h"
#include "cosmos/crypto/secp256k1/keys.pb-c.h"

#define COMPACT_SIG_MAGIC_OFFSET (27)

void pubkey2address(const uint8_t *pubkey, size_t key_length, uint8_t *address)
{
    SHA256_CTX ctx;
    uint8_t ripemd160_hash[RIPEMD160_DIGEST_LENGTH] = {0};

    uint8_t hash[SHA256_DIGEST_LENGTH] = {0};
    sha256_Init(&ctx);
    // Hash the string
    sha256_Update(&ctx, pubkey, key_length);
    sha256_Final(&ctx, hash);

    ripemd160((const uint8_t *)hash, SHA256_DIGEST_LENGTH, ripemd160_hash);
    memcpy(address, ripemd160_hash, 20);
}

int getAddressString(const uint8_t *address, char *stringbuffer)
{
    const char *hrp = "cosmos";
    size_t data_len = 32;
    uint8_t paddingbuffer[32] = {0};
    uint8_t base32_enc[100] = {0};
    base32_encode_unsafe(address, 20, base32_enc);

    size_t len = strlen(base32_enc);
    return bech32_encode(stringbuffer, hrp, base32_enc, data_len);
}

void tx_to_tw_raw(Cosmos__Tx__V1beta1__Tx *tx, Cosmos__Tx__V1beta1__TxRaw *txRaw)
{
    txRaw->body_bytes.len = cosmos__tx__v1beta1__tx_body__get_packed_size(tx->body);
    txRaw->body_bytes.data = malloc(txRaw->body_bytes.len);
    cosmos__tx__v1beta1__tx_body__pack(tx->body, txRaw->body_bytes.data);

    txRaw->auth_info_bytes.len = cosmos__tx__v1beta1__auth_info__get_packed_size(tx->auth_info);
    txRaw->auth_info_bytes.data = malloc(txRaw->auth_info_bytes.len);
    cosmos__tx__v1beta1__auth_info__pack(tx->auth_info, txRaw->auth_info_bytes.data);
}



bool attestMachine(uint8_t *priv_key, uint8_t *pub_key, char *public_address, uint8_t* signature)
{
    //
    // create body
    //
    Planetmintgo__Machine__Metadata metadata = PLANETMINTGO__MACHINE__METADATA__INIT;
    metadata.additionaldatacid = "CID";
    metadata.gps = "{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}";
    metadata.assetdefinition = "{\"Version\": \"0.1\"}";
    metadata.device = "{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}";
    const char *address = "cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx";
    const char *pubKey = "AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRw";

    
    Planetmintgo__Machine__Machine machine = PLANETMINTGO__MACHINE__MACHINE__INIT;
    machine.name = "machine";
    machine.ticker = "machine_ticker";
    machine.reissue = true;
    machine.amount = 1000;
    machine.precision = 8;
    machine.issuerplanetmint = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470";
    machine.issuerliquid = "xpub661MyMwAqRbcEigRSGNjzqsUbkoxRHTDYXDQ6o5kq6EQTSYuXxwD5zNbEXFjCG3hDmYZqCE4HFtcPAi3V3MW9tTYwqzLDUt9BmHv7fPcWaB";
    machine.machineid = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470";
    machine.metadata = &metadata;

    Planetmintgo__Machine__MsgAttestMachine machineMsg = PLANETMINTGO__MACHINE__MSG_ATTEST_MACHINE__INIT;
    machineMsg.creator = address;
    machineMsg.machine = &machine;

    Google__Protobuf__Any anyMsg = GOOGLE__PROTOBUF__ANY__INIT;
    anyMsg.type_url = "/planetmintgo.machine.MsgAttestMachine";
    anyMsg.value.len = planetmintgo__machine__msg_attest_machine__get_packed_size(&machineMsg);
    anyMsg.value.data = malloc(anyMsg.value.len);
    planetmintgo__machine__msg_attest_machine__pack(&machineMsg, anyMsg.value.data);

    Cosmos__Tx__V1beta1__TxBody body;
    cosmos__tx__v1beta1__tx_body__init(&body);
    Google__Protobuf__Any messages[1] = {&anyMsg};
    body.n_messages = 1;
    body.messages = messages;
    body.timeout_height = 0;
    // body.memo = NULL;
    // body.n_extension_options=0;
    // body.extension_options=0;
    // body.n_non_critical_extension_options=0;
    // body.non_critical_extension_options=NULL;
    


    Cosmos__Tx__V1beta1__ModeInfo__Single mode_single= COSMOS__TX__V1BETA1__MODE_INFO__SINGLE__INIT;
    mode_single.mode = COSMOS__TX__SIGNING__V1BETA1__SIGN_MODE__SIGN_MODE_DIRECT;
    
    Cosmos__Tx__V1beta1__ModeInfo mode_info = COSMOS__TX__V1BETA1__MODE_INFO__INIT;
    mode_info.sum_case = COSMOS__TX__V1BETA1__MODE_INFO__SUM_SINGLE;
    mode_info.single = &mode_single;



    Cosmos__Crypto__Secp256k1__PubKey pubkey = COSMOS__CRYPTO__SECP256K1__PUB_KEY__INIT;
    pubkey.key.len = 33;
    pubkey.key.data = malloc(33);
    memcpy(pubkey.key.data, pub_key, 33);
    Google__Protobuf__Any any_pub_key = GOOGLE__PROTOBUF__ANY__INIT;
    any_pub_key.type_url = "/cosmos.crypto.secp256k1.PubKey";
    any_pub_key.value.len = cosmos__crypto__secp256k1__pub_key__get_packed_size(&pubkey);
    any_pub_key.value.data = malloc(any_pub_key.value.len);
    cosmos__crypto__secp256k1__pub_key__pack(&pubkey, any_pub_key.value.data);

    Cosmos__Tx__V1beta1__SignerInfo signInfo = COSMOS__TX__V1BETA1__SIGNER_INFO__INIT;
    cosmos__tx__v1beta1__signer_info__init(&signInfo);
    signInfo.mode_info = &mode_info;
    signInfo.sequence = 1;
    signInfo.public_key = &any_pub_key;


    Cosmos__Base__V1beta1__Coin coin = COSMOS__BASE__V1BETA1__COIN__INIT;
    Cosmos__Base__V1beta1__Coin coins[1] = {&coin};
    coin.denom = "stake";
    coin.amount = "2";

    Cosmos__Tx__V1beta1__Fee fee = COSMOS__TX__V1BETA1__FEE__INIT;
    cosmos__tx__v1beta1__fee__init(&fee);
    fee.amount = &coins;
    fee.gas_limit = 200000;
    fee.n_amount = 1;

    Cosmos__Base__V1beta1__Coin tip_coin = COSMOS__BASE__V1BETA1__COIN__INIT;
    Cosmos__Base__V1beta1__Coin tip_coins[1] = {tip_coin};
    tip_coin.denom="stake";
    tip_coin.amount="6";
    Cosmos__Tx__V1beta1__Tip tip = COSMOS__TX__V1BETA1__TIP__INIT;
    tip.n_amount=1;
    tip.amount= tip_coins;
    tip.tipper=address;

    Cosmos__Tx__V1beta1__SignerInfo signer_infos[1] = {&signInfo};
    Cosmos__Tx__V1beta1__AuthInfo auth;
    cosmos__tx__v1beta1__auth_info__init(&auth);
    auth.n_signer_infos = 1;
    auth.signer_infos = signer_infos;
    auth.fee = &fee;
    //&auth.tip = &tip;

    size_t singer_info_len = cosmos__tx__v1beta1__signer_info__get_packed_size( &signInfo );
    size_t fee_len = cosmos__tx__v1beta1__fee__get_packed_size( &fee );
    //size_t tip_len = cosmos__tx__v1beta1__tip__get_packed_size( &tip );




    //
    //transaction composition
    //
    Cosmos__Tx__V1beta1__Tx tx;
    cosmos__tx__v1beta1__tx__init(&tx);
    tx.body = &body;
    tx.auth_info = &auth;
    // tx.n_signatures=0;
    // tx.signatures = NULL;

    Cosmos__Tx__V1beta1__TxRaw txRaw;
    cosmos__tx__v1beta1__tx_raw__init(&txRaw);
    tx_to_tw_raw(&tx, &txRaw);
    txRaw.n_signatures = tx.n_signatures;

    // create Cosmos__Tx__V1beta1__SignDoc
    // to create a signature
    Cosmos__Tx__V1beta1__SignDoc signDoc;
    cosmos__tx__v1beta1__sign_doc__init(&signDoc);
    signDoc.body_bytes = txRaw.body_bytes;
    signDoc.auth_info_bytes = txRaw.auth_info_bytes;
    signDoc.chain_id = "chain-foobarbaz";
    signDoc.account_number = 7;

    ProtobufCBinaryData binMessage;
    binMessage.len = cosmos__tx__v1beta1__sign_doc__get_packed_size(&signDoc);
    binMessage.data = malloc(binMessage.len);
    cosmos__tx__v1beta1__sign_doc__pack(&signDoc, binMessage.data);

    uint8_t digest[SHA256_DIGEST_LENGTH] = {0};
    sha256(binMessage.data, binMessage.len, digest);

    //unsigned char signature[64] = {0};
    const ecdsa_curve *curve = &secp256k1;
    //ed25519_sign((const unsigned char *)digest, SHA256_DIGEST_LENGTH, (const unsigned char *)priv_key, (const unsigned char *)pub_key + 1, signature);
    
    int res = ecdsa_sign_digest(curve, (const unsigned char *)priv_key, (const unsigned char *)digest, signature, NULL, NULL);

    // 513 bytesSign
    //"\n\x88\x03\n\x85\x03\n&/planetmintgo.machine.MsgAttestMachine\x12\xda\x02\n-cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx\x12\xa8\x02\n\amachine\x12\x0emachine_ticker\x18\x01 \xe8\a(\b2,AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRw:,AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwB,AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwJ|\n3{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}\x12,{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}\x1a\x12{\"Version\": \"0.1\"}\"\x03CID\x12d\nP\nF\n\x1f/cosmos.crypto.secp256k1.PubKey\x12#\n!\x022\x8d\xe8x\x96\xb9˵\x10\x1c3_@\x02\x9eK蘘\x8bG\n\xbb\xf6\x83\xf1\xa0\xb3\x18\xd74p\x12\x04\n\x02\b\x01\x18\x01\x12\x10\n\n\n\x05stake\x12\x012\x10\xc0\x9a\f\x1a\fchain-mP3enC "

    //"http://0.0.0.0:42807/cosmos/auth/v1beta1/account_info/cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx"
    //"{\"info\":{\"address\":\"cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx\",\"pub_key\":{\"@type\":\"/cosmos.crypto.secp256k1.PubKey\",\"key\":\"AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRw\"},\"account_number\":\"7\",\"sequence\":\"1\"}}"

    free(binMessage.data);
    free(txRaw.body_bytes.data);
    free(txRaw.auth_info_bytes.data);
    free(anyMsg.value.data);
    free(pubkey.key.data);
    free(any_pub_key.value.data);
}
