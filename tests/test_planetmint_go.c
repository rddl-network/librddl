#include "unity.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "tests.h"
#include "rddl.h"
#include "planetmintgo.h"
#include "rddl_types.h"

#include "bip32.h"
#include "bip39.h"
#include "curves.h"
#include "base64.h"
#include "secp256k1.h"
#include "keys.h"

const char *planetmint_service = "http://0.0.0.0:34331";


const char *mnemonic = "helmet hedgehog lab actor weekend elbow pelican valid obtain hungry rocket decade tower gallery fit practice cart cherry giggle hair snack glance bulb farm";

uint8_t reference_private_key[34] = {10, 32, 128, 112, 249, 202, 124, 175, 82, 178, 11, 149, 241, 218, 147, 44, 100, 141, 148, 52, 223, 57, 67, 112, 250, 53, 133, 185, 112, 220, 55, 149, 174, 168};
uint8_t reference_pubkey[35] = {10, 33, 2, 50, 141, 232, 120, 150, 185, 203, 181, 16, 28, 51, 95, 64, 2, 158, 75, 232, 152, 152, 139, 71, 10, 187, 246, 131, 241, 160, 179, 24, 215, 52, 112};
uint8_t reference_sha[32] = {31, 236, 15, 94, 16, 55, 101, 147, 213, 70, 37, 62, 34, 135, 62, 56, 157, 191, 178, 240, 110, 222, 141, 80, 27, 60, 48, 71, 151, 21, 141, 234};

uint8_t reference_addressbytes[20] = {46, 62, 250, 9, 104, 89, 242, 77, 48, 250, 188, 165, 41, 197, 119, 78, 195, 205, 1, 70};

const char *expected_address = "plmnt19cl05ztgt8ey6v86hjjjn3thfmpu6q2xtveehc";
uint8_t sha_hash[32] = {31, 236, 15, 94, 16, 55, 101, 147, 213, 70, 37, 62, 34, 135, 62, 56, 157, 191, 178, 240, 110, 222, 141, 80, 27, 60, 48, 71, 151, 21, 141, 234};

uint8_t expected_sig[64] = {35, 187, 131, 58, 5, 149, 242, 90, 22, 45, 245, 9, 148, 237, 110, 120, 133, 138, 248, 12, 97, 190, 2, 174, 109, 183, 114, 221, 43, 115, 189, 226, 66, 31, 36, 129, 225, 104, 149, 101, 100, 4, 158, 205, 171, 76, 54, 47, 152, 121, 186, 252, 209, 215, 98, 183, 73, 71, 222, 159, 35, 48, 233, 217};

const char *expected_tx_b64_bytes = "CvcDCvQDCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRLJAwotY29zbW9zMTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4cW1zdXl4EpcDCgdtYWNoaW5lEg5tYWNoaW5lX3RpY2tlchgBIOgHKAgyQjAyMzI4ZGU4Nzg5NmI5Y2JiNTEwMWMzMzVmNDAwMjllNGJlODk4OTg4YjQ3MGFiYmY2ODNmMWEwYjMxOGQ3MzQ3MDpveHB1YjY2MU15TXdBcVJiY0VpZ1JTR05qenFzVWJrb3hSSFREWVhEUTZvNWtxNkVRVFNZdVh4d0Q1ek5iRVhGakNHM2hEbVlacUNFNEhGdGNQQWkzVjNNVzl0VFl3cXpMRFV0OUJtSHY3ZlBjV2FCQkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBKfAozeyJMYXRpdHVkZSI6Ii00OC44NzY2NjciLCJMb25naXR1ZGUiOiItMTIzLjM5MzMzMyJ9Eix7Ik1hbnVmYWN0dXJlciI6ICJSRERMIiwiU2VyaWFsIjoiQWRuVDJ1eXQifRoSeyJWZXJzaW9uIjogIjAuMSJ9IgNDSUQSZApQCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBGAESEAoKCgVzdGFrZRIBMhDAmgwaQCO7gzoFlfJaFi31CZTtbniFivgMYb4Crm23ct0rc73iQh8kgeFolWVkBJ7Nq0w2L5h5uvzR12K3SUfenyMw6dk=";


extern uint8_t priv_key_planetmint[32+1];
extern uint8_t priv_key_liquid[32+1];
extern uint8_t pub_key_planetmint[33+1];
extern uint8_t pub_key_liquid[33+1];
extern uint8_t sdk_machineid_public_key[33*2+1];

extern char plmnt_address[64];
extern char ext_pub_key_planetmint[EXT_PUB_KEY_SIZE+1];
extern char ext_pub_key_liquid[EXT_PUB_KEY_SIZE+1];
extern char machineid_public_key_hex[33*2+1];

void test_getPlntmntKeys()
{
  char localMnemonic[] = "penalty police pool orphan snack faith educate syrup skill picnic prepare mystery dune control near nation report evolve ethics genius elite tool rigid crane";
  const char* returnedMnemonic  = setSeed( localMnemonic );
  TEST_ASSERT_EQUAL_STRING( localMnemonic, returnedMnemonic);

  getPlntmntKeys();
  TEST_ASSERT_EQUAL_STRING("plmnt199zf0vkmehhr2hhdt3e425r5dx4749dmenm35w", plmnt_address);
  TEST_ASSERT_EQUAL_STRING("pmpb7uVnQPmrApcxz8p1fKsbq1GugjP8ys6fT7RRiMG57hXRCZRo4zhDxD5WoS5EwaFnGdJCBKinZaqYzETY89yLDyVzKsMF8mZj8Wx1QEYam3Y", ext_pub_key_planetmint);
  TEST_ASSERT_EQUAL_STRING("xpub6FidezPD3CR4ED2wVoDX4RJy95F9Bep11muvgmrGwZHdfhpcLzWdxm1ui5jLAAiekrKiAXng2LScATvTD2xfbaBdoBAFmf2kM2eWYWCTNxS", ext_pub_key_liquid);
  TEST_ASSERT_EQUAL_STRING("03E58EC4AE9B60564EDF51A1C9BCF9759C63B276D236CD55F15B02FD226AC2CE3F", machineid_public_key_hex);
}

void test_attest_machine_generic_signed_by_mnemonic()
{
  char localMnemonic[] = "penalty police pool orphan snack faith educate syrup skill picnic prepare mystery dune control near nation report evolve ethics genius elite tool rigid crane";
  const char* returnedMnemonic  = setSeed( localMnemonic );
  TEST_ASSERT_EQUAL_STRING( localMnemonic, returnedMnemonic);


  getPlntmntKeys();
  clearStack();
  //char *expected_tx_b64_bytes_generic_old = "CokECoYECiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRLbAwoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMSqgMKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAIOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAESYgpOCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBEhAKCgoFdG9rZW4SATIQwJoMGkBIArsZaFJp/BUiIcETm3DRiY76XFy8P6CdrmAFg0UCtC3Q0f4NcSsNU1TcaD7GwzoBlSoAMe6JXpP6TseZcmQJ";
  char *expected_tx_b64_bytes_generic = "CowGCokGCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRLeBQoscGxtbnQxOTl6ZjB2a21laGhyMmhoZHQzZTQyNXI1ZHg0NzQ5ZG1lbm0zNXcSrQUKCk15TWFjaGluZTA6b3hwdWI2R2hKdG1zWjVUNnpGUEI5NjFZVlNwTUVrb0dRMk1jWUU1M0hRRGlxWXg1Yll3aUNtZ0FoZXdWSlNDVmtoMzhvVmVIdGFBVjlRSkoxYVNFSlpzemoxNGU4RzgzWkwzQ1ZTNWJkRHF1M25XbkJvcG1wYjd2VVRlQkdDRDVKdHo5enJyY3FXb01CWGRRVkVyMXFlYkpzWWdFVFhOZWJ1S21uek1pNFMyYk1xcEVzd0xVbUVhMnM2SGVYejhjZ1ZyZHNZVG5RVnRjeGJkNVZyN1pacHFtTUdYNlpUOHRRSoABNjAwM2QwYWI5YWY0ZWMxMTI2MjkxOTVhNzI2NmEyNDRhZWNmMWFjNzY5MWRhMDA4NGJlM2U3Y2VlYTJlZTcxNTcxYjA5NjNmZmZkOWM4MGE2NDAzMTc1MDlhNjgxYWM2NmMyZWQ3MGVjYzlmMzE3YTBkMmIxYTliZmY5NGZmNzRSdwozeyJMYXRpdHVkZSI6Ii00OC44NzY2NjciLCJMb25naXR1ZGUiOiItMTIzLjM5MzMzMyJ9Eix7Ik1hbnVmYWN0dXJlciI6ICJSRERMIiwiU2VyaWFsIjoiQWRuVDJ1eXQifRoSeyJWZXJzaW9uIjogIjAuMSJ9WAFikAEzMDQ2MDIyMTAwZTUxY2YwMmEwYjkwMGEzNmY3OGU4YzFmZjA1NjI4Nzk0NjkwOTRlNDJhYjQ0ZGIxMzcyOTdjNjg2YTFkOTI4ZTAyMjEwMGI4NDU4M2NlZGExNDVkMTBkMDE5YjMxYjg0YTRmNGQwZTYyNzAwYWUwOTQyMDRjOWRhYmVlMTcyNDRiNjI5MjZqLHBsbW50MTk5emYwdmttZWhocjJoaGR0M2U0MjVyNWR4NDc0OWRtZW5tMzV3EmIKTgpGCh8vY29zbW9zLmNyeXB0by5zZWNwMjU2azEuUHViS2V5EiMKIQLrk8HpZN1Y2GEZO/AVsHQ4HUQyKCGnnFSiC0VbTFfBxhIECgIIARIQCgoKBXBsbW50EgExEMCaDBpARkw+0nSaage+6g7wSsY4wdUanxG8pfjs51x5yLzulDRuBKJkUo8+zRFEvijctPBsXVx0wYzxZEsJgw9TMVUdUQ==";

  Planetmintgo__Machine__Metadata metadata = PLANETMINTGO__MACHINE__METADATA__INIT;
  metadata.additionaldatacid = "";
  metadata.gps = "{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}";
  metadata.assetdefinition = "{\"Version\": \"0.1\"}";
  metadata.device = "{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}";


  Planetmintgo__Machine__Machine machine = PLANETMINTGO__MACHINE__MACHINE__INIT;
  machine.name = "MyMachine0";
  machine.ticker = "";
  machine.domain = "";
  machine.reissue = false;
  machine.amount = 0;
  machine.precision = 0;
  machine.issuerplanetmint = "xpub6GhJtmsZ5T6zFPB961YVSpMEkoGQ2McYE53HQDiqYx5bYwiCmgAhewVJSCVkh38oVeHtaAV9QJJ1aSEJZszj14e8G83ZL3CVS5bdDqu3nWn";
  machine.issuerliquid = "pmpb7vUTeBGCD5Jtz9zrrcqWoMBXdQVEr1qebJsYgETXNebuKmnzMi4S2bMqpEswLUmEa2s6HeXz8cgVrdsYTnQVtcxbd5Vr7ZZpqmMGX6ZT8tQ";
  machine.machineid = "6003d0ab9af4ec112629195a7266a244aecf1ac7691da0084be3e7ceea2ee71571b0963fffd9c80a640317509a681ac66c2ed70ecc9f317a0d2b1a9bff94ff74";
  machine.metadata = &metadata;
  machine.type = RDDL_MACHINE_POWER_SWITCH;
  machine.address = plmnt_address;
  machine.machineidsignature = "3046022100e51cf02a0b900a36f78e8c1ff0562879469094e42ab44db137297c686a1d928e022100b84583ceda145d10d019b31b84a4f4d0e62700ae094204c9dabee17244b62926";

  Planetmintgo__Machine__MsgAttestMachine machineMsg = PLANETMINTGO__MACHINE__MSG_ATTEST_MACHINE__INIT;
  machineMsg.creator = plmnt_address;
  machineMsg.machine = &machine;

  Google__Protobuf__Any anyMsg = GOOGLE__PROTOBUF__ANY__INIT;
  int ret = generateAnyAttestMachineMsg(&anyMsg, &machineMsg);
  TEST_ASSERT_EQUAL_INT(0, ret);

  Cosmos__Base__V1beta1__Coin coin = COSMOS__BASE__V1BETA1__COIN__INIT;
  coin.denom = "plmnt";
  coin.amount = "1";

  uint8_t *txbytes = NULL;
  size_t tx_size = 0;
  uint64_t sequence = 0;
  ret = prepareTx(&anyMsg, &coin, priv_key_planetmint, pub_key_planetmint,
                  sequence, "planetmintgo", 15, &txbytes, &tx_size);
  TEST_ASSERT_EQUAL_INT(0, ret);
  // free(anyMsg.value.data);
  char tx_bytes_b64[2000] = {0};
  char *p = bintob64(tx_bytes_b64, txbytes, tx_size);
  size_t length = p - tx_bytes_b64;

  // free( txbytes );
  TEST_ASSERT_EQUAL_MEMORY(expected_tx_b64_bytes_generic, tx_bytes_b64, length);
}


void test_attest_machine_generic()
{
  clearStack();
  char *expected_tx_b64_bytes_generic = "CroFCrcFCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRKMBQoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMS2wQKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAJOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAFigAFiNzQ3OWVkYmY1MjNjNTVmNzcxOTkxMzkzZmNlNmI0ODFlZGZhYjRjODVhZGY2MGViMTJiZWI1ZmRjOWMxM2FhYTY3ODUyZDhjZDQyN2EzZGQ1YjkwZjBlNGY5YmRhNjk0ZTQ1M2VmNjI0ZmYwY2RlMjU0YzNiN2NjYzdjZGNkNGoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMSYgpOCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBEhAKCgoFdG9rZW4SATIQwJoMGkAJ927k1UrFEvl41jc0MmUbPOJQ+m7YHGKl0FSa6a3gZiUW1lNPv370E7FMmFPZsLnbahW8d0o67O7dCnS03+9O";

  Planetmintgo__Machine__Metadata metadata = PLANETMINTGO__MACHINE__METADATA__INIT;
  metadata.additionaldatacid = "CID";
  metadata.gps = "{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}";
  metadata.assetdefinition = "{\"Version\": \"0.1\"}";
  metadata.device = "{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}";

  const char *address = "plmnt19cl05ztgt8ey6v86hjjjn3thfmpu6q2xtveehc";

  Planetmintgo__Machine__Machine machine = PLANETMINTGO__MACHINE__MACHINE__INIT;
  machine.name = "machine";
  machine.ticker = "machine_ticker";
  machine.domain = "lab.r3c.network";
  machine.reissue = true;
  machine.amount = 1000;
  machine.precision = 9;
  machine.issuerplanetmint = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470";
  machine.issuerliquid = "xpub661MyMwAqRbcEigRSGNjzqsUbkoxRHTDYXDQ6o5kq6EQTSYuXxwD5zNbEXFjCG3hDmYZqCE4HFtcPAi3V3MW9tTYwqzLDUt9BmHv7fPcWaB";
  machine.machineid = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470";
  machine.metadata = &metadata;
  machine.type = RDDL_MACHINE_POWER_SWITCH;
  machine.address = (char *)address;
  machine.machineidsignature = "b7479edbf523c55f771991393fce6b481edfab4c85adf60eb12beb5fdc9c13aaa67852d8cd427a3dd5b90f0e4f9bda694e453ef624ff0cde254c3b7ccc7cdcd4";

  Planetmintgo__Machine__MsgAttestMachine machineMsg = PLANETMINTGO__MACHINE__MSG_ATTEST_MACHINE__INIT;
  machineMsg.creator = (char *)address;
  machineMsg.machine = &machine;

  Google__Protobuf__Any anyMsg = GOOGLE__PROTOBUF__ANY__INIT;
  int ret = generateAnyAttestMachineMsg(&anyMsg, &machineMsg);
  TEST_ASSERT_EQUAL_INT(0, ret);

  Cosmos__Base__V1beta1__Coin coin = COSMOS__BASE__V1BETA1__COIN__INIT;
  coin.denom = "token";
  coin.amount = "2";

  uint8_t *txbytes = NULL;
  size_t tx_size = 0;
  uint64_t sequence = 0;
  ret = prepareTx(&anyMsg, &coin, reference_private_key + 2, reference_pubkey + 2,
                  sequence, "planetmintgo", 9, &txbytes, &tx_size);
  TEST_ASSERT_EQUAL_INT(0, ret);
  // free(anyMsg.value.data);
  char tx_bytes_b64[2000] = {0};
  char *p = bintob64(tx_bytes_b64, txbytes, tx_size);
  size_t length = p - tx_bytes_b64;

  // free( txbytes );
  TEST_ASSERT_EQUAL_MEMORY(expected_tx_b64_bytes_generic, tx_bytes_b64, length);
}

const char *get_ext_pub_key()
{
  uint8_t priv_key[32] = {0};
  uint8_t pub_key[33] = {0};
  HDNode node;
  hdnode_from_seed(secret_seed, SEED_SIZE, SECP256K1_NAME, &node);
  hdnode_private_ckd_prime(&node, 44);
  hdnode_private_ckd_prime(&node, 8680);
  hdnode_private_ckd_prime(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_fill_public_key(&node);
  memcpy(priv_key, node.private_key, 32);
  memcpy(pub_key, node.public_key, 33);

  static char str[112 + 1] = {0};
  size_t strsize = 112;
  uint32_t fingerprint = hdnode_fingerprint(&node);
  int ret = hdnode_serialize_public(&node, fingerprint, 0x03E14247, str, strsize);
  if( ret != 0 )
    return NULL;
  return (const char *)str;
}

void test_attest_asset_generic()
{
  clearStack();
  char *expected_tx_b64_bytes_generic = "Cl0KWwokL3BsYW5ldG1pbnRnby5hc3NldC5Nc2dOb3Rhcml6ZUFzc2V0EjMKLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjEgNjaWQSZApQCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBGAESEAoKCgV0b2tlbhIBMhDAmgwaQJeTV21jy8tDU34uavG30kqSvRz0rvPMOuVxws5Z4LD4fNBywacIMOdlUTRNo1Pwa5x7LNRNXG6cqk7q4i2JUhE=";
  Google__Protobuf__Any anyMsg = GOOGLE__PROTOBUF__ANY__INIT;

  int ret = generateAnyCIDAttestMsg(&anyMsg, "cid", expected_address);
  TEST_ASSERT_EQUAL_INT(0, ret);

  Cosmos__Base__V1beta1__Coin coin = COSMOS__BASE__V1BETA1__COIN__INIT;
  coin.denom = "token";
  coin.amount = "2";

  uint8_t *txbytes = NULL;
  size_t tx_size = 0;
  uint64_t sequence = 1;
  char *chain_id = "planetmintgo";
  uint64_t account_id = 8;
  ret = prepareTx(&anyMsg, &coin, reference_private_key + 2, reference_pubkey + 2,
                  sequence, chain_id, account_id, &txbytes, &tx_size);
  TEST_ASSERT_EQUAL_INT(0, ret);
  char tx_bytes_b64[1000] = {0};
  char *p = bintob64(tx_bytes_b64, txbytes, tx_size);
  size_t length = p - tx_bytes_b64;

  TEST_ASSERT_EQUAL_MEMORY(expected_tx_b64_bytes_generic, tx_bytes_b64, length);
}

extern uint8_t secret_seed[SEED_SIZE];
void private2public_key()
{

  uint8_t reference_private_key_8680[34] = {10, 32, 203, 100, 215, 232, 29, 78, 103, 123, 94, 137, 110, 235, 33, 88, 220, 0, 201, 95, 59, 32, 98, 73, 204, 29, 144, 234, 24, 67, 129, 108, 170, 160};
  uint8_t reference_pubkey_8680[35] = {10, 33, 2, 28, 210, 165, 156, 111, 148, 2, 206, 9, 239, 251, 168, 155, 61, 235, 107, 181, 134, 55, 51, 230, 37, 242, 44, 6, 32, 73, 24, 6, 29, 180, 240};

  uint8_t priv_key[32] = {0};
  uint8_t pub_key[33] = {0};
  if (!mnemonic_check(mnemonic))
    return;

  mnemonic_to_seed(mnemonic, "", secret_seed, 0);

  HDNode node;
  hdnode_from_seed(secret_seed, SEED_SIZE, SECP256K1_NAME, &node);
  hdnode_private_ckd_prime(&node, 44);
  hdnode_private_ckd_prime(&node, 8680);
  hdnode_private_ckd_prime(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_fill_public_key(&node);
  memcpy(priv_key, node.private_key, 32);
  memcpy(pub_key, node.public_key, 33);

  TEST_ASSERT_EQUAL_MEMORY(reference_private_key_8680 + 2, priv_key, 32);
  TEST_ASSERT_EQUAL_MEMORY(reference_pubkey_8680 + 2, pub_key, 33);

  char str[112];
  size_t strsize = 112;
  uint32_t fingerprint = hdnode_fingerprint(&node);
  int ret = hdnode_serialize_public(&node, fingerprint, 0x03E14247, str, strsize);

  TEST_ASSERT_EQUAL_INT32(112, ret);

  HDNode node_decoded;
  uint32_t fingerprint_decoded = 0;
  ret = hdnode_deserialize(str, 0x03E14247, 0, SECP256K1_NAME, &node_decoded, &fingerprint_decoded);
  TEST_ASSERT_EQUAL_INT32(0, ret);
  TEST_ASSERT_EQUAL_MEMORY(node.public_key, node_decoded.public_key, 33);
}

void test_pubkey2address_convertion()
{
  int offset = 2;
  uint8_t address_bytes[ADDRESS_TAIL] = {0};
  pubkey2address(reference_pubkey + offset, 35 - offset, address_bytes);
  TEST_ASSERT_EQUAL_MEMORY(reference_addressbytes, address_bytes, 20);
}

void test_from_address_to_address_string()
{
  char address_string[64] = {0};
  int res = getAddressString(reference_addressbytes, address_string);
  TEST_ASSERT_EQUAL_INT( 1, res);
  TEST_ASSERT_EQUAL_MEMORY(expected_address, address_string, strlen(expected_address));
}

void parse_account_info()
{
  char expected_result[] = "{\"info\":{\"address\":\"cosmos18pmruqqx370lvdnufcjs55ntt74y38844pkjqn\",\"pub_key\":{\"@type\":\"/cosmos.crypto.secp256k1.PubKey\",\"key\":\"Ai6QqpR/xwvwoKd19AYrz/t9v5jEQbwwkaWSya08W1sY\"},\"account_number\":\"21\",\"sequence\":\"11\"}}";
  int account_id;
  int sequence;
  bool f = get_account_info(expected_result, &account_id, &sequence);
  TEST_ASSERT_TRUE(f);
  TEST_ASSERT_EQUAL_INT32(11, sequence);
  TEST_ASSERT_EQUAL_INT32(21, account_id);
}

void parse_account_info_invalid()
{
  char expected_result[] = "{ \
    \"code\": 13, \
    \"message\": \"Expecting non nil value to create a new Any: failed packing protobuf message to Any\", \
    \"details\": [] }";
  int account_id = 0;
  int sequence = 0;
  bool f = get_account_info(expected_result, &account_id, &sequence);
  TEST_ASSERT_FALSE(f);
  TEST_ASSERT_EQUAL_INT32(0, sequence);
  TEST_ASSERT_EQUAL_INT32(0, account_id);
}

void test_persistence_lookup()
{
  char expected_value[] = "31323334";
  char value[] = "1234";
  size_t length = strlen(value);
  length = length * 2;
  char *hexstring = (char *)malloc(length + 1);
  hexstring[length] = 0;
  toHexString((char *)hexstring, (uint8_t *)value, length);
  TEST_ASSERT_EQUAL_MEMORY(expected_value, hexstring, 8);
  free(hexstring);
}

void test_gps_string_parsing_adjustments()
{
  //{"Country":"AT","Region":"9","City":"vienna","CityLatLong":"48.208174,16.373819","User-IP":"84.112.103.218"}
  char *gps_json_string = "{\"Country\":\"AT\",\"Region\":\"9\",\"City\":\"vienna\",\"CityLatLong\":\"48.208174,16.373819\",\"User-IP\":\"84.112.103.218\"}";
  char *exp_gps_string = "{\"Country\":\"AT\",\"Region\":\"9\",\"City\":\"vienna\",\"CityLatLong\":\"48.208174,16.373819\"}";
  char *gps_data = malloc(strlen(gps_json_string) + 1);
  strcpy(gps_data, gps_json_string);
  bool ret = removeIPAddr(gps_data);
  TEST_ASSERT_EQUAL_MEMORY(exp_gps_string, gps_data, strlen(exp_gps_string));
  TEST_ASSERT_TRUE(ret);
  free(gps_data);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_persistence_lookup);

  RUN_TEST(parse_account_info);
  RUN_TEST(parse_account_info_invalid);
  
  RUN_TEST(test_attest_asset_generic);
  RUN_TEST(test_attest_machine_generic);
  RUN_TEST(private2public_key);
  RUN_TEST(test_pubkey2address_convertion);
  RUN_TEST(test_from_address_to_address_string);
  RUN_TEST(test_gps_string_parsing_adjustments);
  RUN_TEST( test_attest_machine_generic_signed_by_mnemonic);
  RUN_TEST(test_getPlntmntKeys);
  return UNITY_END();
}
