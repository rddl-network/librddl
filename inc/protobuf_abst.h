void* Create_AnyMsg();
void* fullfill_planetmintgo_machine_metadata(char* cid, char* gps, char* assetdef, char* device);
void* fullfill_planetmintgo_machine_machine(void* metadata_ptr, char* signature_hex, char* name, char* issuePlanetmint, 
                                            char* issuerLiquid, char* machineID, uint32_t type);
void* fullfill_planetmintgo_machine_msgAttestMachine(void* machine_ptr, char* creator);
int bind_msgAttestMachine_to_anyMsg(void* anyMsg, void* machineMsg);
void* fullfill_cosmos_base_v1beta1_coin(char* denom, char* tokenAmount);
void* fullfill_cosmos_tx_v1beta1_txBody(void** msg, int msg_len, int timeout);
int bind_cosmos_sec256k1_pk_to_anyMsg(void* anyMsg, unsigned char* pubkey, int pubkey_len, char* url);
void* fullfill_cosmos_tx_v1beta1_signerInfo(void* anyMsg, uint64_t sequence);
void* fullfill_cosmos_tx_v1beta1_fee(void** coins, int gas_limit);
void* fullfill_cosmos_tx_v1beta1_authInfo(void* fee, void** signer_infos);
void* fullfill_cosmos_tx_v1beta1_tx(void* body, void* auth);
void* fullfill_cosmos_tx_v1beta1_txRaw(void* tx);
void* fullfill_binMessage(void* txRaw, const char *chain_id, uint64_t account_id, int* data_len);
void* prepare_txRaw_data(uint8_t** tx_bytes, size_t* tx_size, void* txRaw, unsigned char* signature, int signLen);
void* fullfill_planetmintgo_asset_msgnotarizeasset(const char* cid, char* public_address);
int bind_planetmintgo_asset_notarizeMsg_to_anyMsg(void* anyMsg, void* msg);

