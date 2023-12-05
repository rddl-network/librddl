#ifndef _RDDL_NETWORK_TESTS_H_
#define _RDDL_NETWORK_TESTS_H_

#include "unity.h"
#include <stdio.h>
#include <string.h>

#include "sha3.h"
#include "base58.h"
#include "hmac.h"
#include "tiny-json.h"
#include "sha3.h"
#include "bip32.h"
#include "curves.h"

#ifdef TASMOTA
#include "base64_plntmnt.h"
#include "ed25519.h"
#else
#include "base64.h"
#include "ed25519-donna/ed25519.h"
#endif

#include "ed25519-donna/ed25519.h"


#endif //_UECC_TESTS_H_
