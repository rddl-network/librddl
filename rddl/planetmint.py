from google.protobuf import any_pb2
from planetmintgo.asset import tx_pb2 as AsstTx
from planetmintgo.machine import tx_pb2 as MachineTx
from planetmintgo.dao import tx_pb2 as DaoTx
from cosmos.base.v1beta1 import coin_pb2
from cosmos.tx.v1beta1 import tx_pb2 as cosmosTx
from cosmos.crypto.secp256k1 import keys_pb2


def getCoin(denom: str, amount: str) -> coin_pb2.Coin:
    coin = coin_pb2.Coin()
    coin.denom = denom
    coin.amount = amount
    return coin


def getAnyAsset(creator: str, cid: str) -> any_pb2.Any:
    testmsg = AsstTx.MsgNotarizeAsset()
    testmsg.creator = creator
    testmsg.cid = cid

    message_data = testmsg.SerializeToString()

    # Construct the Any message
    any_message = any_pb2.Any()
    any_message.type_url = "/planetmintgo.asset.MsgNotarizeAsset"
    any_message.value = message_data
    return any_message


def getAnyMachineAttestation(msg: MachineTx.MsgAttestMachine) -> any_pb2.Any:
    message_data = msg.SerializeToString()

    # Construct the Any message
    any_message = any_pb2.Any()
    any_message.type_url = "/planetmintgo.machine.MsgAttestMachine"
    any_message.value = message_data
    return any_message


def getAnyPopResult(msg: DaoTx.MsgReportPopResult) -> any_pb2.Any:
    message_data = msg.SerializeToString()

    # Construct the Any message
    any_message = any_pb2.Any()
    any_message.type_url = "/planetmintgo.dao.MsgReportPopResult"
    any_message.value = message_data
    return any_message


def getRawTx(anyMsg: any_pb2.Any, coin: coin_pb2.Coin, public_key: bytes, sequence: int) -> cosmosTx.TxRaw:

    pubKey = keys_pb2.PubKey()
    pubKey.key = public_key
    anyPubKey = any_pb2.Any()
    anyPubKey.type_url = "/cosmos.crypto.secp256k1.PubKey"
    anyPubKey.value = pubKey.SerializeToString()

    signerInfo = cosmosTx.SignerInfo()
    signerInfo.public_key.type_url = anyPubKey.type_url
    signerInfo.public_key.value = anyPubKey.value
    signerInfo.mode_info.single.mode = 1  # SIGN_MODE_DIRECT
    signerInfo.sequence = sequence

    tx = cosmosTx.Tx()
    tx.body.messages.append(anyMsg)
    tx.body.timeout_height = 0
    tx.auth_info.signer_infos.append(signerInfo)
    tx.auth_info.fee.gas_limit = 200000
    tx.auth_info.fee.amount.append(coin)

    txRaw = cosmosTx.TxRaw()

    txRaw.body_bytes = tx.body.SerializeToString()
    txRaw.auth_info_bytes = tx.auth_info.SerializeToString()
    return txRaw


def getSignDoc(rawTx: cosmosTx.TxRaw, chainID: str, accountID: int) -> cosmosTx.SignDoc:
    signDoc = cosmosTx.SignDoc()
    signDoc.body_bytes = rawTx.body_bytes
    signDoc.auth_info_bytes = rawTx.auth_info_bytes
    signDoc.chain_id = chainID
    signDoc.account_number = accountID
    return signDoc


def getAnyRedeemClaimMsg(creator: str, beneficiary: str) -> any_pb2.Any:
    msg = DaoTx.MsgCreateRedeemClaim()
    msg.creator = creator
    msg.beneficiary = beneficiary

    message_data = msg.SerializeToString()
    # Construct the Any message
    any_message = any_pb2.Any()
    any_message.type_url = "/planetmintgo.dao.MsgCreateRedeemClaim"
    any_message.value = message_data
    return any_message
