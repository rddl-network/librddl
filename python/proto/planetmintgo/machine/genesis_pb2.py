# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: planetmintgo/machine/genesis.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from gogoproto import gogo_pb2 as gogoproto_dot_gogo__pb2
from planetmintgo.machine import params_pb2 as planetmintgo_dot_machine_dot_params__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\"planetmintgo/machine/genesis.proto\x12\x14planetmintgo.machine\x1a\x14gogoproto/gogo.proto\x1a!planetmintgo/machine/params.proto\"B\n\x0cGenesisState\x12\x32\n\x06params\x18\x01 \x01(\x0b\x32\x1c.planetmintgo.machine.ParamsB\x04\xc8\xde\x1f\x00\x42\x35Z3github.com/planetmint/planetmint-go/x/machine/typesb\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'planetmintgo.machine.genesis_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  DESCRIPTOR._serialized_options = b'Z3github.com/planetmint/planetmint-go/x/machine/types'
  _GENESISSTATE.fields_by_name['params']._options = None
  _GENESISSTATE.fields_by_name['params']._serialized_options = b'\310\336\037\000'
  _GENESISSTATE._serialized_start=117
  _GENESISSTATE._serialized_end=183
# @@protoc_insertion_point(module_scope)
