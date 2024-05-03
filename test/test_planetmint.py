import pytest
import base64
import hashlib

from planetmintgo.machine import tx_pb2 as MachineTx
from rddl import planetmint
from rddl import signing
from bitcoinaddress import segwit_addr
from ecdsa import SigningKey, SECP256k1, NIST256p
from ecdsa.util import sigencode_string
chainID = "planetmintgo"
sequence = 0
accountID = 9

reference_private_key = bytearray([10, 32, 128, 112, 249, 202, 124, 175, 82, 178, 11, 149, 241, 218, 147, 44, 100, 141, 148, 52, 223, 57, 67, 112, 250, 53, 133, 185, 112, 220, 55, 149, 174, 168])
reference_pubkey = bytearray([10, 33, 2, 50, 141, 232, 120, 150, 185, 203, 181, 16, 28, 51, 95, 64, 2, 158, 75, 232, 152, 152, 139, 71, 10, 187, 246, 131, 241, 160, 179, 24, 215, 52, 112])
reference_sha = bytearray([31, 236, 15, 94, 16, 55, 101, 147, 213, 70, 37, 62, 34, 135, 62, 56, 157, 191, 178, 240, 110, 222, 141, 80, 27, 60, 48, 71, 151, 21, 141, 234])
expected_address = "plmnt19cl05ztgt8ey6v86hjjjn3thfmpu6q2xtveehc"


reference_addressbytes = bytearray([46,62,250,9,104,89,242,77,48,250, 188,165,41,197,119,78,195,205,1,70])
# Find the m

def test_pubKey2AddressConversion():
    ripemdHash = signing.pubkey2address(reference_pubkey[-33:])
    assert bytes(reference_addressbytes) == ripemdHash 

def test_pubKey2AddressConversion2ndWay():
    ripemdHash = signing.hash160(reference_pubkey[-33:])
    digest = ripemdHash.digest()
    assert bytes(reference_addressbytes) == digest

def test_base32encoding():
    exp_base32enc = bytes(bytearray([0x5, 0x18, 0x1f, 0xf, 0x14, 0x2, 0xb, 0x8, 0xb, 0x7, 0x19, 0x4, 0x1a, 0xc, 0x7, 0x1a, 0x17, 0x12, 0x12, 0x12, 0x13, 0x11, 0xb, 0x17, 0x9, 0x1b, 0x1, 0x1c, 0x1a, 0x0, 0xa, 0x6]))
    base23EncData = signing.base32_encode_unsafe(bytes(reference_addressbytes))
    assert len(exp_base32enc) == len(base23EncData)
    assert exp_base32enc == base23EncData
    
def test_getAddressString():
    base23EncData = signing.base32_encode_unsafe(bytes(reference_addressbytes))
    hrp = "plmnt"
    int_list = [byte for byte in base23EncData]
    bech32AddressString =segwit_addr.bech32_encode( hrp, int_list)    
    assert expected_address == bech32AddressString

def test_getAddressStringFromAddressBytes():
    bech32AddressString = signing.getAddressStringFromAddressBytes(bytes(reference_addressbytes)) 
    assert expected_address == bech32AddressString

def test_getAddressStringFromPubKey():
    bech32AddressString = signing.getAddressStringFromPubKey(reference_pubkey[-33:])
    assert expected_address == bech32AddressString
    

def test_getAnyMachineAttestation():
    expected_tx_b64_bytes_generic_old = "CokECoYECiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRLbAwoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMSqgMKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAIOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAESYgpOCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBEhAKCgoFdG9rZW4SATIQwJoMGkBIArsZaFJp/BUiIcETm3DRiY76XFy8P6CdrmAFg0UCtC3Q0f4NcSsNU1TcaD7GwzoBlSoAMe6JXpP6TseZcmQJ"
    #expected_tx_b64_bytes_generic = "CrcECrQECiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRKJBAoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMS2AMKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAIOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAFqLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjElwKSApGCh8vY29zbW9zLmNyeXB0by5zZWNwMjU2azEuUHViS2V5EiMKIQIyjeh4lrnLtRAcM19AAp5L6JiYi0cKu/aD8aCzGNc0cBIQCgoKBXBsbW50EgEyEMCaDBpAKaK0ktRVgaUnjU1ca6Yy/4ep16IdiSy2sKkRnBZeQoy6kCBFDSfMC2k63TAwFBWpBVR0JwCpHsYCYu/u/0JlYg=="
    expected_tx_b64_bytes_generic = "CroFCrcFCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRKMBQoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMS2wQKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAJOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAFigAFiNzQ3OWVkYmY1MjNjNTVmNzcxOTkxMzkzZmNlNmI0ODFlZGZhYjRjODVhZGY2MGViMTJiZWI1ZmRjOWMxM2FhYTY3ODUyZDhjZDQyN2EzZGQ1YjkwZjBlNGY5YmRhNjk0ZTQ1M2VmNjI0ZmYwY2RlMjU0YzNiN2NjYzdjZGNkNGoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMSYgpOCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBEhAKCgoFdG9rZW4SATIQwJoMGkAJ927k1UrFEvl41jc0MmUbPOJQ+m7YHGKl0FSa6a3gZiUW1lNPv370E7FMmFPZsLnbahW8d0o67O7dCnS03+9O"
    expected_tx_b64_bytes_python_generic= 'CroFCrcFCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRKMBQoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMS2wQKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAJOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAFigAFiNzQ3OWVkYmY1MjNjNTVmNzcxOTkxMzkzZmNlNmI0ODFlZGZhYjRjODVhZGY2MGViMTJiZWI1ZmRjOWMxM2FhYTY3ODUyZDhjZDQyN2EzZGQ1YjkwZjBlNGY5YmRhNjk0ZTQ1M2VmNjI0ZmYwY2RlMjU0YzNiN2NjYzdjZGNkNGoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMSYgpOCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBEhAKCgoFdG9rZW4SATIQwJoMGkAJ927k1UrFEvl41jc0MmUbPOJQ+m7YHGKl0FSa6a3gZtrpKaywQIEL7E6zZ6wmT0TfRMcqN/5lTtD1VBgbVlHz'
    #expected_tx_b64_bytes_generic = "CroFCrcFCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRKMBQoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMS2wQKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAIOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAFigAFiNzQ3OWVkYmY1MjNjNTVmNzcxOTkxMzkzZmNlNmI0ODFlZGZhYjRjODVhZGY2MGViMTJiZWI1ZmRjOWMxM2FhYTY3ODUyZDhjZDQyN2EzZGQ1YjkwZjBlNGY5YmRhNjk0ZTQ1M2VmNjI0ZmYwY2RlMjU0YzNiN2NjYzdjZGNkNGoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMSXApICkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEhAKCgoFcGxtbnQSATIQwJoMGkCqur0NdUnNb0fndAl4H/CPD3P/6FvvrDm+DPWurjITstZ9KLdH+P9zUJ4ko+NY37CcsRecWF+XHZurdBf4OMkT"
    ref_sig_new = b'\t\xf7n\xe4\xd5J\xc5\x12\xf9x\xd6742e\x1b<\xe2P\xfan\xd8\x1cb\xa5\xd0T\x9a\xe9\xad\xe0f\xda\xe9)\xac\xb0@\x81\x0b\xecN\xb3g\xac&OD\xdfD\xc7*7\xfeeN\xd0\xf5T\x18\x1bVQ\xf3'
    attestMachine = MachineTx.MsgAttestMachine()
    attestMachine.creator = expected_address
    attestMachine.machine.name = "machine"
    attestMachine.machine.ticker = "machine_ticker"
    attestMachine.machine.domain = "lab.r3c.network"
    attestMachine.machine.reissue = True
    attestMachine.machine.amount = 1000
    attestMachine.machine.precision = 9
    attestMachine.machine.issuerPlanetmint = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470"
    attestMachine.machine.issuerLiquid = "xpub661MyMwAqRbcEigRSGNjzqsUbkoxRHTDYXDQ6o5kq6EQTSYuXxwD5zNbEXFjCG3hDmYZqCE4HFtcPAi3V3MW9tTYwqzLDUt9BmHv7fPcWaB"
    attestMachine.machine.machineId = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470"
    attestMachine.machine.metadata.additionalDataCID = "CID"
    attestMachine.machine.metadata.gps = "{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}"
    attestMachine.machine.metadata.assetDefinition = "{\"Version\": \"0.1\"}"
    attestMachine.machine.metadata.device = "{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}"
    attestMachine.machine.type = 1 #RDDL_MACHINE_POWER_SWITCH
    attestMachine.machine.machineIdSignature = "b7479edbf523c55f771991393fce6b481edfab4c85adf60eb12beb5fdc9c13aaa67852d8cd427a3dd5b90f0e4f9bda694e453ef624ff0cde254c3b7ccc7cdcd4"
    attestMachine.machine.address = expected_address
    
    anyMsg = planetmint.getAnyMachineAttestation( attestMachine )
    coin4Fee = planetmint.getCoin("token", "2")
    localSequence = 0
    rawTx = planetmint.getRawTx(anyMsg, coin4Fee, bytes(reference_pubkey[-33:]) , localSequence)
    assert bytes(ref_auth_info) == rawTx.auth_info_bytes
    assert bytes(ref_raw_tx) == rawTx.body_bytes
    signDoc = planetmint.getSignDoc( rawTx, chainID, accountID )
    signDocBytes = signDoc.SerializeToString()
    keybytes = bytes(reference_private_key[-32:])
    #shahash = signing.getHash(  signDocBytes)
    #assert bytes(ref_hash) == shahash
    signature = signing.signBytesWithKey( signDocBytes, keybytes )
    assert bytes(ref_sig_new) == signature
    rawTx.signatures.append(signature)
    rawTxBytes = rawTx.SerializeToString()
    encoded_string = base64.b64encode(rawTxBytes)
    finalString = encoded_string.decode('utf-8')
    assert expected_tx_b64_bytes_python_generic == finalString 


def test_getAnyAsset():
    expectedBytes = "Cl0KWwokL3BsYW5ldG1pbnRnby5hc3NldC5Nc2dOb3Rhcml6ZUFzc2V0EjMKLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjEgNjaWQSZApQCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBGAESEAoKCgV0b2tlbhIBMhDAmgwaQJeTV21jy8tDU34uavG30kqSvRz0rvPMOuVxws5Z4LD4fNBywacIMOdlUTRNo1Pwa5x7LNRNXG6cqk7q4i2JUhE="
    expectedBytesNew = 'Cl0KWwokL3BsYW5ldG1pbnRnby5hc3NldC5Nc2dOb3Rhcml6ZUFzc2V0EjMKLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjEgNjaWQSXgpKCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwGAESEAoKCgVwbG1udBIBMhDAmgwaQPk5S8EqFntBJ6s1oyPhGxYAe11jW9pX5CR35QOtUE2UifYqhsMsbVpVOeu2Ofl1UFrkeRCFom/m0kURW89pO+8='
    expectedBytesPythonNew = 'Cl0KWwokL3BsYW5ldG1pbnRnby5hc3NldC5Nc2dOb3Rhcml6ZUFzc2V0EjMKLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjEgNjaWQSYgpOCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBEhAKCgoFdG9rZW4SATIQwJoMGkCfAtZzviLkt0v4Z1kjBANPOCfY0Eko3U97yUISD2pL568R7Gxm3/RXpyRXwsbZGEmGyJFPnkNL28tcc1PZpT9y'
    expSig = b'\xcap\xd4%*V\x89\x9b\xfa\x155\x85\xe4g\x80l\xa2\x10\xef\xb6\xfd\x1c\xdd\xc7\xb1e\xdf\xbf\n\x96\xf4\xf2\x9b\xb2\xbbB*\x10a\xfcV|\xc1\x06\xfd\x9e|\xd0\x8dO\xe1l\x9b\x1a&\xce;d\x08\xf2\t.\xfd\x80'
    expRawTx = b'\n\\\nZ\n#planetmintgo.asset.MsgNotarizeAsset\x123\n,plmnt19cl05ztgt8ey6v86hjjjn3thfmpu6q2xtveehc\x12\x03cid\x12^\nJ\nF\n\x1f/cosmos.crypto.secp256k1.PubKey\x12#\n!\x022\x8d\xe8x\x96\xb9\xcb\xb5\x10\x1c3_@\x02\x9eK\xe8\x98\x98\x8bG\n\xbb\xf6\x83\xf1\xa0\xb3\x18\xd74p\x18\x01\x12\x10\n\n\n\x05plmnt\x12\x012\x10\xc0\x9a\x0c'
    expDigest = b'\xd4*\xac\x04\xac\x8e\xb26t\x0b`h\xab\xc6\x03\xc2\xc5W<-M\xed\rA\xf2\x81\xc0\xb4\xaf\x07\xc6E'
    expSignDocBytes = b'\n\\\nZ\n#planetmintgo.asset.MsgNotarizeAsset\x123\n,plmnt19cl05ztgt8ey6v86hjjjn3thfmpu6q2xtveehc\x12\x03cid\x12^\nJ\nF\n\x1f/cosmos.crypto.secp256k1.PubKey\x12#\n!\x022\x8d\xe8x\x96\xb9\xcb\xb5\x10\x1c3_@\x02\x9eK\xe8\x98\x98\x8bG\n\xbb\xf6\x83\xf1\xa0\xb3\x18\xd74p\x18\x01\x12\x10\n\n\n\x05plmnt\x12\x012\x10\xc0\x9a\x0c\x1a\x0cplanetmintgo \x08'
    anyMsg = planetmint.getAnyAsset( expected_address, "cid")
    coin4Fee = planetmint.getCoin("token", "2")  #TODO change to token
    rawTx = planetmint.getRawTx(anyMsg, coin4Fee, bytes(reference_pubkey[-33:]) , sequence)
    rawtxdata = rawTx.SerializeToString()
    #assert rawtxdata == expRawTx
    signDoc = planetmint.getSignDoc( rawTx, chainID, accountID )
    signDocBytes = signDoc.SerializeToString()
    #assert signDocBytes == expSignDocBytes
    digest = signing.getHash(signDocBytes)
    #assert digest == expDigest
    keybytes = bytes(reference_private_key[-32:])
    signature = signing.signBytesWithKey( signDocBytes,keybytes )
    #assert signature == expSig 
    
    rawTx.signatures.append(signature)
    rawTxBytes = rawTx.SerializeToString()
    encoded_string = base64.b64encode(rawTxBytes)
    finalString = encoded_string.decode('utf-8')
    assert finalString == expectedBytesPythonNew


def test_secp256k1_machineID():
    exp_signature = 'b7479edbf523c55f771991393fce6b481edfab4c85adf60eb12beb5fdc9c13aaa67852d8cd427a3dd5b90f0e4f9bda694e453ef624ff0cde254c3b7ccc7cdcd4'
    exp_compressedKey = '02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470'
    private_key = bytes(reference_private_key[-32:])
    signing_key = SigningKey.from_string(private_key, curve=SECP256k1, hashfunc=hashlib.sha256)
    vk = signing_key.get_verifying_key()
    compressedKey_hex = vk.to_string(encoding="compressed").hex()

    #hash256 = signing.getHash( )
    signature = signing_key.sign_deterministic(compressedKey_hex.encode('utf-8'), hashfunc=hashlib.sha256,sigencode=sigencode_string)
    assert exp_compressedKey == compressedKey_hex 
    assert exp_signature == signature.hex()
 


def test_secp256r1_machineID():
    exp_signature = '84f43efa663981302aada8776ac658ee12997d4a187a27dd753411afd766ef27a3f2edfdff3a08240fee6c3c864c73f220dedf5e0fd93bb0806b094f666c492d'
    exp_compressedKey = '03d4c632e834e3e58058b6cc72f4dc6be1e80a8ebd397de09dbb8ac63acb7aff63'
    private_key = bytes(reference_private_key[-32:])
    signing_key = SigningKey.from_string(private_key, curve=NIST256p, hashfunc=hashlib.sha256)
    vk = signing_key.get_verifying_key()
    compressedKey_hex = vk.to_string(encoding="compressed").hex()
    signature = signing_key.sign_deterministic(compressedKey_hex.encode('utf-8'), hashfunc=hashlib.sha256,sigencode=sigencode_string)
    assert exp_compressedKey == compressedKey_hex 
    assert exp_signature == signature.hex()
    
    return


def test_auth_info_creation():
    from google.protobuf import any_pb2
    from cosmos.base.v1beta1 import coin_pb2
    from cosmos.tx.v1beta1 import tx_pb2 as cosmosTx
    from cosmos.crypto.secp256k1 import keys_pb2


    public_key = bytes(reference_pubkey[-33:])
    pubKey = keys_pb2.PubKey()
    pubKey.key = public_key
    anyPubKey = any_pb2.Any()
    anyPubKey.type_url = "/cosmos.crypto.secp256k1.PubKey"
    anyPubKey.value = pubKey.SerializeToString()

    # modeInfo = cosmosTx.ModeInfo()
    # modeInfo.Single.mode = 1 #SIGN_MODE_DIRECT

    signerInfo = cosmosTx.SignerInfo()
    signerInfo.public_key.type_url = anyPubKey.type_url
    signerInfo.public_key.value = anyPubKey.value
    #signerInfo.mode_info.sum = 1 #SIGN_MODE_DIRECT
    signerInfo.mode_info.single.mode = 1 #SIGN_MODE_DIRECT
    signerInfo.sequence = sequence
    
    #fees = cosmosTx.Fee()
    #fees.amount.append( coin )
    #fees.gas_limit = 200000
    
    coin2 = coin_pb2.Coin()
    coin2.denom= "token"
    coin2.amount = "2"
    
    auth_info =cosmosTx.AuthInfo()
    auth_info.signer_infos.append( signerInfo )
    auth_info.fee.gas_limit = 200000
    auth_info.fee.amount.append( coin2 )
    auth_info.fee.payer=""
    auth_info.fee.granter=""
    
    
    serialized = auth_info.SerializeToString()
    assert len(ref_auth_info) == len(serialized)
    assert bytes(ref_auth_info) == serialized


ref_auth_info = bytearray([0x0a, 0x4e, 0x0a, 0x46, 0x0a, 0x1f, 0x2f, 0x63,\
0x6f, 0x73, 0x6d, 0x6f, 0x73, 0x2e, 0x63, 0x72,\
0x79, 0x70, 0x74, 0x6f, 0x2e, 0x73, 0x65, 0x63,\
0x70, 0x32, 0x35, 0x36, 0x6b, 0x31, 0x2e, 0x50,\
0x75, 0x62, 0x4b, 0x65, 0x79, 0x12, 0x23, 0x0a,\
0x21, 0x02, 0x32, 0x8d, 0xe8, 0x78, 0x96, 0xb9,\
0xcb, 0xb5, 0x10, 0x1c, 0x33, 0x5f, 0x40, 0x02,\
0x9e, 0x4b, 0xe8, 0x98, 0x98, 0x8b, 0x47, 0x0a,\
0xbb, 0xf6, 0x83, 0xf1, 0xa0, 0xb3, 0x18, 0xd7,\
0x34, 0x70, 0x12, 0x04, 0x0a, 0x02, 0x08, 0x01,\
0x12, 0x10, 0x0a, 0x0a, 0x0a, 0x05, 0x74, 0x6f,\
0x6b, 0x65, 0x6e, 0x12, 0x01, 0x32, 0x10, 0xc0,\
0x9a, 0x0c ] )



['0xa', '0x48', '0xa', '0x46', '0xa', '0x1f', '0x2f', '0x63',
 '0x6f', '0x73', '0x6d', '0x6f', '0x73', '0x2e', '0x63', '0x72',
 '0x79', '0x70', '0x74', '0x6f', '0x2e', '0x73', '0x65', '0x63',
 '0x70', '0x32', '0x35', '0x36', '0x6b', '0x31', '0x2e', '0x50',
 '0x75', '0x62', '0x4b', '0x65', '0x79', '0x12', '0x23', '0x0a',
 '0x21', '0x02', '0x32', '0x8d', '0xe8', '0x78', '0x96', '0xb9', 
 '0xcb', '0xb5', '0x10', '0x1c', '0x33', '0x5f', '0x40', '0x02', 
 '0x9e', '0x4b', '0xe8', '0x98', '0x98', '0x8b', '0x47', '0x0a', 
 '0xbb', '0xf6', '0x83', '0xf1', '0xa0', '0xb3', '0x18', '0xd7',
 
 '0x34', '0x70', '0x12', '0x10', '0x0a', '0x0a', '0x0a', '0x05', 
 '0x74', '0x6f', '0x6b', '0x65', '0x6e', '0x12', '0x01', '0x32',
 '0x10', '0xc0', '0x9a', '0xc']



ref_raw_tx = bytearray([ 0x0a, 0xb7, 0x05, 0x0a, 0x26, 0x2f, 0x70, 0x6c,\
0x61, 0x6e, 0x65, 0x74, 0x6d, 0x69, 0x6e, 0x74,\
0x67, 0x6f, 0x2e, 0x6d, 0x61, 0x63, 0x68, 0x69,\
0x6e, 0x65, 0x2e, 0x4d, 0x73, 0x67, 0x41, 0x74,\
0x74, 0x65, 0x73, 0x74, 0x4d, 0x61, 0x63, 0x68,\
0x69, 0x6e, 0x65, 0x12, 0x8c, 0x05, 0x0a, 0x2c,\
0x70, 0x6c, 0x6d, 0x6e, 0x74, 0x31, 0x39, 0x63,\
0x6c, 0x30, 0x35, 0x7a, 0x74, 0x67, 0x74, 0x38,\
0x65, 0x79, 0x36, 0x76, 0x38, 0x36, 0x68, 0x6a,\
0x6a, 0x6a, 0x6e, 0x33, 0x74, 0x68, 0x66, 0x6d,\
0x70, 0x75, 0x36, 0x71, 0x32, 0x78, 0x74, 0x76,\
0x65, 0x65, 0x68, 0x63, 0x12, 0xdb, 0x04, 0x0a,\
0x07, 0x6d, 0x61, 0x63, 0x68, 0x69, 0x6e, 0x65,\
0x12, 0x0e, 0x6d, 0x61, 0x63, 0x68, 0x69, 0x6e,\
0x65, 0x5f, 0x74, 0x69, 0x63, 0x6b, 0x65, 0x72,\
0x1a, 0x0f, 0x6c, 0x61, 0x62, 0x2e, 0x72, 0x33,\
0x63, 0x2e, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72,\
0x6b, 0x20, 0x01, 0x28, 0xe8, 0x07, 0x30, 0x09,\
0x3a, 0x42, 0x30, 0x32, 0x33, 0x32, 0x38, 0x64,\
0x65, 0x38, 0x37, 0x38, 0x39, 0x36, 0x62, 0x39,\
0x63, 0x62, 0x62, 0x35, 0x31, 0x30, 0x31, 0x63,\
0x33, 0x33, 0x35, 0x66, 0x34, 0x30, 0x30, 0x32,\
0x39, 0x65, 0x34, 0x62, 0x65, 0x38, 0x39, 0x38,\
0x39, 0x38, 0x38, 0x62, 0x34, 0x37, 0x30, 0x61,\
0x62, 0x62, 0x66, 0x36, 0x38, 0x33, 0x66, 0x31,\
0x61, 0x30, 0x62, 0x33, 0x31, 0x38, 0x64, 0x37,\
0x33, 0x34, 0x37, 0x30, 0x42, 0x6f, 0x78, 0x70,\
0x75, 0x62, 0x36, 0x36, 0x31, 0x4d, 0x79, 0x4d,\
0x77, 0x41, 0x71, 0x52, 0x62, 0x63, 0x45, 0x69,\
0x67, 0x52, 0x53, 0x47, 0x4e, 0x6a, 0x7a, 0x71,\
0x73, 0x55, 0x62, 0x6b, 0x6f, 0x78, 0x52, 0x48,\
0x54, 0x44, 0x59, 0x58, 0x44, 0x51, 0x36, 0x6f,\
0x35, 0x6b, 0x71, 0x36, 0x45, 0x51, 0x54, 0x53,\
0x59, 0x75, 0x58, 0x78, 0x77, 0x44, 0x35, 0x7a,\
0x4e, 0x62, 0x45, 0x58, 0x46, 0x6a, 0x43, 0x47,\
0x33, 0x68, 0x44, 0x6d, 0x59, 0x5a, 0x71, 0x43,\
0x45, 0x34, 0x48, 0x46, 0x74, 0x63, 0x50, 0x41,\
0x69, 0x33, 0x56, 0x33, 0x4d, 0x57, 0x39, 0x74,\
0x54, 0x59, 0x77, 0x71, 0x7a, 0x4c, 0x44, 0x55,\
0x74, 0x39, 0x42, 0x6d, 0x48, 0x76, 0x37, 0x66,\
0x50, 0x63, 0x57, 0x61, 0x42, 0x4a, 0x42, 0x30,\
0x32, 0x33, 0x32, 0x38, 0x64, 0x65, 0x38, 0x37,\
0x38, 0x39, 0x36, 0x62, 0x39, 0x63, 0x62, 0x62,\
0x35, 0x31, 0x30, 0x31, 0x63, 0x33, 0x33, 0x35,\
0x66, 0x34, 0x30, 0x30, 0x32, 0x39, 0x65, 0x34,\
0x62, 0x65, 0x38, 0x39, 0x38, 0x39, 0x38, 0x38,\
0x62, 0x34, 0x37, 0x30, 0x61, 0x62, 0x62, 0x66,\
0x36, 0x38, 0x33, 0x66, 0x31, 0x61, 0x30, 0x62,\
0x33, 0x31, 0x38, 0x64, 0x37, 0x33, 0x34, 0x37,\
0x30, 0x52, 0x7c, 0x0a, 0x33, 0x7b, 0x22, 0x4c,\
0x61, 0x74, 0x69, 0x74, 0x75, 0x64, 0x65, 0x22,\
0x3a, 0x22, 0x2d, 0x34, 0x38, 0x2e, 0x38, 0x37,\
0x36, 0x36, 0x36, 0x37, 0x22, 0x2c, 0x22, 0x4c,\
0x6f, 0x6e, 0x67, 0x69, 0x74, 0x75, 0x64, 0x65,\
0x22, 0x3a, 0x22, 0x2d, 0x31, 0x32, 0x33, 0x2e,\
0x33, 0x39, 0x33, 0x33, 0x33, 0x33, 0x22, 0x7d,\
0x12, 0x2c, 0x7b, 0x22, 0x4d, 0x61, 0x6e, 0x75,\
0x66, 0x61, 0x63, 0x74, 0x75, 0x72, 0x65, 0x72,\
0x22, 0x3a, 0x20, 0x22, 0x52, 0x44, 0x44, 0x4c,\
0x22, 0x2c, 0x22, 0x53, 0x65, 0x72, 0x69, 0x61,\
0x6c, 0x22, 0x3a, 0x22, 0x41, 0x64, 0x6e, 0x54,\
0x32, 0x75, 0x79, 0x74, 0x22, 0x7d, 0x1a, 0x12,\
0x7b, 0x22, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6f,\
0x6e, 0x22, 0x3a, 0x20, 0x22, 0x30, 0x2e, 0x31,\
0x22, 0x7d, 0x22, 0x03, 0x43, 0x49, 0x44, 0x58,\
0x01, 0x62, 0x80, 0x01, 0x62, 0x37, 0x34, 0x37,\
0x39, 0x65, 0x64, 0x62, 0x66, 0x35, 0x32, 0x33,\
0x63, 0x35, 0x35, 0x66, 0x37, 0x37, 0x31, 0x39,\
0x39, 0x31, 0x33, 0x39, 0x33, 0x66, 0x63, 0x65,\
0x36, 0x62, 0x34, 0x38, 0x31, 0x65, 0x64, 0x66,\
0x61, 0x62, 0x34, 0x63, 0x38, 0x35, 0x61, 0x64,\
0x66, 0x36, 0x30, 0x65, 0x62, 0x31, 0x32, 0x62,\
0x65, 0x62, 0x35, 0x66, 0x64, 0x63, 0x39, 0x63,\
0x31, 0x33, 0x61, 0x61, 0x61, 0x36, 0x37, 0x38,\
0x35, 0x32, 0x64, 0x38, 0x63, 0x64, 0x34, 0x32,\
0x37, 0x61, 0x33, 0x64, 0x64, 0x35, 0x62, 0x39,\
0x30, 0x66, 0x30, 0x65, 0x34, 0x66, 0x39, 0x62,\
0x64, 0x61, 0x36, 0x39, 0x34, 0x65, 0x34, 0x35,\
0x33, 0x65, 0x66, 0x36, 0x32, 0x34, 0x66, 0x66,\
0x30, 0x63, 0x64, 0x65, 0x32, 0x35, 0x34, 0x63,\
0x33, 0x62, 0x37, 0x63, 0x63, 0x63, 0x37, 0x63,\
0x64, 0x63, 0x64, 0x34, 0x6a, 0x2c, 0x70, 0x6c,\
0x6d, 0x6e, 0x74, 0x31, 0x39, 0x63, 0x6c, 0x30,\
0x35, 0x7a, 0x74, 0x67, 0x74, 0x38, 0x65, 0x79,\
0x36, 0x76, 0x38, 0x36, 0x68, 0x6a, 0x6a, 0x6a,\
0x6e, 0x33, 0x74, 0x68, 0x66, 0x6d, 0x70, 0x75,\
0x36, 0x71, 0x32, 0x78, 0x74, 0x76, 0x65, 0x65,\
0x68, 0x63] )

ref_hash = bytearray([0xa9, 0x61, 0xbf, 0x96, 0x46, 0x44, 0x42, 0x1d,\
0xc2, 0xe0, 0x7a, 0x2d, 0xee, 0xb5, 0x41, 0xf1,\
0x9a, 0x18, 0x79, 0xff, 0x4f, 0x78, 0x14, 0xad,\
0xdc, 0xa2, 0xea, 0xe2, 0x6c, 0xf2, 0x75, 0x27 ])

ref_sig = bytearray([0x09, 0xf7, 0x6e, 0xe4, 0xd5, 0x4a, 0xc5, 0x12,\
0xf9, 0x78, 0xd6, 0x37, 0x34, 0x32, 0x65, 0x1b,\
0x3c, 0xe2, 0x50, 0xfa, 0x6e, 0xd8, 0x1c, 0x62,\
0xa5, 0xd0, 0x54, 0x9a, 0xe9, 0xad, 0xe0, 0x66,\
0x25, 0x16, 0xd6, 0x53, 0x4f, 0xbf, 0x7e, 0xf4,\
0x13, 0xb1, 0x4c, 0x98, 0x53, 0xd9, 0xb0, 0xb9,\
0xdb, 0x6a, 0x15, 0xbc, 0x77, 0x4a, 0x3a, 0xec,\
0xee, 0xdd, 0x0a, 0x74, 0xb4, 0xdf, 0xef, 0x4e])