import pytest
import base64

from planetmintgo.machine import tx_pb2 as MachineTx
from rddl import planetmint
from rddl import signing
from bitcoinaddress import segwit_addr
chainID = "planetmintgo"
sequence = 1
accountID = 8

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
    expected_tx_b64_bytes_generic = "CrcECrQECiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRKJBAoscGxtbnQxOWNsMDV6dGd0OGV5NnY4NmhqampuM3RoZm1wdTZxMnh0dmVlaGMS2AMKB21hY2hpbmUSDm1hY2hpbmVfdGlja2VyGg9sYWIucjNjLm5ldHdvcmsgASjoBzAIOkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBCb3hwdWI2NjFNeU13QXFSYmNFaWdSU0dOanpxc1Via294UkhURFlYRFE2bzVrcTZFUVRTWXVYeHdENXpOYkVYRmpDRzNoRG1ZWnFDRTRIRnRjUEFpM1YzTVc5dFRZd3F6TERVdDlCbUh2N2ZQY1dhQkpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwUnwKM3siTGF0aXR1ZGUiOiItNDguODc2NjY3IiwiTG9uZ2l0dWRlIjoiLTEyMy4zOTMzMzMifRIseyJNYW51ZmFjdHVyZXIiOiAiUkRETCIsIlNlcmlhbCI6IkFkblQydXl0In0aEnsiVmVyc2lvbiI6ICIwLjEifSIDQ0lEWAFqLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjElwKSApGCh8vY29zbW9zLmNyeXB0by5zZWNwMjU2azEuUHViS2V5EiMKIQIyjeh4lrnLtRAcM19AAp5L6JiYi0cKu/aD8aCzGNc0cBIQCgoKBXBsbW50EgEyEMCaDBpAKaK0ktRVgaUnjU1ca6Yy/4ep16IdiSy2sKkRnBZeQoy6kCBFDSfMC2k63TAwFBWpBVR0JwCpHsYCYu/u/0JlYg=="
    
    attestMachine = MachineTx.MsgAttestMachine()
    attestMachine.creator = expected_address
    attestMachine.machine.name = "machine"
    attestMachine.machine.ticker = "machine_ticker"
    attestMachine.machine.domain = "lab.r3c.network"
    attestMachine.machine.reissue = True
    attestMachine.machine.amount = 1000
    attestMachine.machine.precision = 8
    attestMachine.machine.issuerPlanetmint = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470"
    attestMachine.machine.issuerLiquid = "xpub661MyMwAqRbcEigRSGNjzqsUbkoxRHTDYXDQ6o5kq6EQTSYuXxwD5zNbEXFjCG3hDmYZqCE4HFtcPAi3V3MW9tTYwqzLDUt9BmHv7fPcWaB"
    attestMachine.machine.machineId = "02328de87896b9cbb5101c335f40029e4be898988b470abbf683f1a0b318d73470"
    attestMachine.machine.metadata.additionalDataCID = "CID"
    attestMachine.machine.metadata.gps = "{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}"
    attestMachine.machine.metadata.assetDefinition = "{\"Version\": \"0.1\"}"
    attestMachine.machine.metadata.device = "{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}"
    attestMachine.machine.type = 1 #RDDL_MACHINE_POWER_SWITCH
    attestMachine.machine.machineIdSignature = ""
    attestMachine.machine.address = expected_address
    
    anyMsg = planetmint.getAnyMachineAttestation( attestMachine )
    coin4Fee = planetmint.getCoin("token", "2")
    localSequence = 0
    rawTx = planetmint.getRawTx(anyMsg, coin4Fee, bytes(reference_pubkey[-33:]) , localSequence)
    signDoc = planetmint.getSignDoc( rawTx, chainID, accountID )
    signDocBytes = signDoc.SerializeToString()
    keybytes = bytes(reference_private_key[-32:])
    signature = signing.signBytesWithKey( signDocBytes,keybytes )
    
    rawTx.signatures.append(signature)
    rawTxBytes = rawTx.SerializeToString()
    encoded_string = base64.b64encode(rawTxBytes).decode('utf-8')
    assert expected_tx_b64_bytes_generic == encoded_string 


def test_getAnyAsset():
    expectedBytes = "Cl0KWwokL3BsYW5ldG1pbnRnby5hc3NldC5Nc2dOb3Rhcml6ZUFzc2V0EjMKLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjEgNjaWQSZApQCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBGAESEAoKCgV0b2tlbhIBMhDAmgwaQJeTV21jy8tDU34uavG30kqSvRz0rvPMOuVxws5Z4LD4fNBywacIMOdlUTRNo1Pwa5x7LNRNXG6cqk7q4i2JUhE="
    expectedBytesNew = 'Cl0KWwokL3BsYW5ldG1pbnRnby5hc3NldC5Nc2dOb3Rhcml6ZUFzc2V0EjMKLHBsbW50MTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4dHZlZWhjEgNjaWQSXgpKCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwGAESEAoKCgVwbG1udBIBMhDAmgwaQPk5S8EqFntBJ6s1oyPhGxYAe11jW9pX5CR35QOtUE2UifYqhsMsbVpVOeu2Ofl1UFrkeRCFom/m0kURW89pO+8='
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
    encoded_string = base64.b64encode(rawTxBytes).decode('utf-8')
    assert encoded_string == expectedBytesNew


    