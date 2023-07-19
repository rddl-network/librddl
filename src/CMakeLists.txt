
file(GLOB SOURCES "*.c")
file(GLOB CID_SOURCES "rddl_cid/*.cpp")
file(GLOB JSON_SOURCES "../libs/json-maker/json-maker.c")
file(GLOB JSON_PARSER_SOURCES "../libs/tiny-json/tiny-json.c")
file(GLOB TREZOR_CRYPTO_ED255 "../libs/trezor-crypto/ed25519-donna/*.c")
file(GLOB TREZOR_CRYPTO "../libs/trezor-crypto/*.c")
file(GLOB BASE64 "../libs/base64/base64.c")

add_library(RDDLC STATIC
    ${SOURCES}
    ${TREZOR_CRYPTO}
    ${TREZOR_CRYPTO_ED255}
    ${JSON_SOURCES}
    ${JSON_PARSER_SOURCES}
    ${BASE64}
    ${CID_SOURCES}
        )

    set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${TREZOR_CRYPTO} PROPERTIES LANGUAGE C)
    set_source_files_properties(${TREZOR_CRYPTO_ED255} PROPERTIES LANGUAGE C)
    set_source_files_properties(${JSON_SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${JSON_PARSER_SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${BASE64} PROPERTIES LANGUAGE C)
    set_source_files_properties(${CID_SOURCES} PROPERTIES LANGUAGE C)

target_include_directories(RDDLC PUBLIC
    ../inc
    ../libs/trezor-crypto/
    ../libs/trezor-crypto/ed25519-donna/
    ../
    ../libs/json-maker
    ../libs/tiny-json
    ../libs/base64
)