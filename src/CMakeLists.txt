
file(GLOB SOURCES "*.c")
file(GLOB JSON_SOURCES "../libs/json-maker/json-maker.c")
file(GLOB JSON_PARSER_SOURCES "../libs/tiny-json/tiny-json.c")
file(GLOB TREZOR_CRYPTO_ED255 "../libs/trezor-crypto/ed25519-donna/*.c")
file(GLOB TREZOR_CRYPTO "../libs/trezor-crypto/*.c")
file(GLOB BASE64 "../libs/base64/base64.c")
file(GLOB MULTIBASE "../libs/multibase/multibase/*.cpp")
file(GLOB MULTIHASH "../libs/multihash/multihash/*.cpp")

add_library(CPPBIG STATIC
    ${SOURCES}
    ${TREZOR_CRYPTO}
    ${TREZOR_CRYPTO_ED255}
    ${JSON_SOURCES}
    ${JSON_PARSER_SOURCES}
    ${BASE64}
    ${MULTIBASE}
    ${MULTIHASH}
        rddl_cid/rddl_cid.cpp)
 
target_include_directories(CPPBIG PUBLIC
    ../inc
    ../libs/trezor-crypto/
    ../
    ../libs/json-maker
    ../libs/tiny-json
    ../libs/base64
    ../libs/multibase
    ../libs/multihash
)