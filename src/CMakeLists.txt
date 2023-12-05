
file(GLOB SOURCES "*.c")
file(GLOB CID_SOURCES "rddl_cid/*.cpp")
file(GLOB TREZOR_CRYPTO_ED255 "../libs/trezor-crypto/ed25519-donna/*.c")
file(GLOB TREZOR_CRYPTO "../libs/trezor-crypto/*.c")
file(GLOB BASE64 "../libs/base64/base64.c")
file(GLOB_RECURSE PROTO_COSMOS "../libs/proto/cosmos/*.c")
file(GLOB PROTO_COSMOS_PROTO "../libs/proto/cosmos-proto/*.c")
file(GLOB PROTO_AMINO "../libs/proto/amino/*.c")
file(GLOB PROTO_GOGO "../libs/proto/gogoproto/*.c")
file(GLOB_RECURSE PROTO_GOOGLE "../libs/proto/google/*.c")
file(GLOB PROTO_PLANETMINT_MACHINE "../libs/proto/planetmintgo/machine/*.c")
file(GLOB PROTO_PLANETMINT_ASSET "../libs/proto/planetmintgo/asset/*.c")
file(GLOB_RECURSE PROTO_TENDERMINT "../libs/proto/tendermint/*.c")

add_library(RDDLC STATIC
    ${SOURCES}
    ${TREZOR_CRYPTO}
    ${TREZOR_CRYPTO_ED255}
    ${JSON_SOURCES}
    ${JSON_PARSER_SOURCES}
    ${BASE64}
    ${CID_SOURCES}
    ${PROTO_COSMOS}
    ${PROTO_COSMOS_PROTO}
    ${PROTO_AMINO}
    ${PROTO_GOGO}
    ${PROTO_GOOGLE}
    ${PROTO_PLANETMINT_MACHINE}
    ${PROTO_PLANETMINT_ASSET}
    ${PROTO_TENDERMINT}
        )

    set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${TREZOR_CRYPTO} PROPERTIES LANGUAGE C)
    set_source_files_properties(${TREZOR_CRYPTO_ED255} PROPERTIES LANGUAGE C)
    set_source_files_properties(${JSON_SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${JSON_PARSER_SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${BASE64} PROPERTIES LANGUAGE C)
    set_source_files_properties(${CID_SOURCES} PROPERTIES LANGUAGE C)
    set_source_files_properties(${PROTO_COSMOS} PROPERTIES LANGUAGE C)
    set_source_files_properties(${PROTO_GOGO} PROPERTIES LANGUAGE C)
    set_source_files_properties(${PROTO_GOOGLE} PROPERTIES LANGUAGE C)
    set_source_files_properties(${PROTO_PLANETMINT_MACHINE} PROPERTIES LANGUAGE C)
    set_source_files_properties(${PROTO_PLANETMINT_ASSET} PROPERTIES LANGUAGE C)

target_include_directories(RDDLC PUBLIC
    ../inc
    ../libs/trezor-crypto/
    ../libs/trezor-crypto/ed25519-donna/
    ../
    ../libs/base64
    ../libs/proto
    /usr/include
)
set(CMAKE_CXX_FLAGS "-fpermissive")
target_link_libraries(RDDLC PRIVATE ${ProtobufC_LIBRARIES})