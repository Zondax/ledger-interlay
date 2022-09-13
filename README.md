# Ledger Interlay App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-interlay/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-interlay/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Interlay app (https://interlay.io) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Interlay  2.1018000.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    |   |   | `Perbill` ratio <br/> |
|Remark |    |   |   | `Vecu8` remark <br/> |
|Set heap pages |    |   |   | `u64` pages <br/> |
|Set code |    |   |   | `Vecu8` code <br/> |
|Set code without checks |    |   |   | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    |   |   | `Vecu8` remark <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    |   |   | `Compactu64` now <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch |    |   |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all |    |   |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |
|Force batch |    |   |   | `VecCall` calls <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    |   |   | `Vecu8` bytes <br/> |
|Unnote preimage |    |   |   | `Hash` hash <br/> |
|Request preimage |    |   |   | `Hash` hash <br/> |
|Unrequest preimage |    |   |   | `Hash` hash <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    |   |   | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    |   |   | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    |   |   | `AccountId` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    |   |   |  |
|Request judgement |    |   |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    |   |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    |   |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    |   |   | `Compactu32` index <br/>`AccountId` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    |   |   | `LookupasStaticLookupSource` target <br/> |
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Remove sub |    |   |   | `LookupasStaticLookupSource` sub <br/> |
|Quit sub |    |   |   |  |

## Tokens

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` dest <br/>`CurrencyId` currency_id <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` dest <br/>`CurrencyId` currency_id <br/>`bool` keep_alive <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` dest <br/>`CurrencyId` currency_id <br/>`CompactBalance` amount <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` source <br/>`AccountId` dest <br/>`CurrencyId` currency_id <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/>`CurrencyId` currency_id <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |

## Supply

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set start height and inflation |    |   |   | `BlockNumber` start_height <br/>`UnsignedFixedPoint` inflation <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    |   |   |  |
|Vested transfer |    |   |   | `LookupasStaticLookupSource` dest <br/>`VestingScheduleOf` schedule <br/> |
|Update vesting schedules |    |   |   | `LookupasStaticLookupSource` who <br/>`VecVestingScheduleOf` vesting_schedules <br/> |
|Claim for |    |   |   | `LookupasStaticLookupSource` dest <br/> |

## AssetRegistry

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register asset |    |   |   | `AssetMetadataBalanceCustomMetadata` metadata <br/>`OptionAssetId` asset_id <br/> |
|Update asset |    |   |   | `AssetId` asset_id <br/>`Optionu32` decimals <br/>`OptionVecu8` name <br/>`OptionVecu8` symbol <br/>`OptionBalance` existential_deposit <br/>`OptionOptionVersionedMultiLocation` location <br/>`OptionCustomMetadata` additional <br/> |

## Escrow

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create lock |    |   |   | `Compactu128` amount <br/>`BlockNumber` unlock_height <br/> |
|Increase amount |    |   |   | `Compactu128` amount <br/> |
|Increase unlock height |    |   |   | `BlockNumber` unlock_height <br/> |
|Withdraw |    |   |   |  |
|Set account limit |    |   |   | `AccountId` who <br/>`BlockNumber` start <br/>`BlockNumber` end <br/> |
|Set account block |    |   |   | `AccountId` who <br/> |

## EscrowAnnuity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Withdraw rewards |    |   |   |  |
|Update rewards |    |   |   |  |
|Set reward per wrapped |    |   |   | `BalanceOf` reward_per_wrapped <br/> |

## VaultAnnuity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Withdraw rewards |    |   |   |  |
|Update rewards |    |   |   |  |
|Set reward per wrapped |    |   |   | `BalanceOf` reward_per_wrapped <br/> |

## BTCRelay

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Initialize |    |   |   | `RawBlockHeader` raw_block_header <br/>`u32` block_height <br/> |
|Store block header |    |   |   | `RawBlockHeader` raw_block_header <br/> |
|Verify and validate transaction |    |   |   | `Vecu8` raw_merkle_proof <br/>`Optionu32` confirmations <br/>`Vecu8` raw_tx <br/>`Value` expected_btc <br/>`BtcAddress` recipient_btc_address <br/>`OptionH256` op_return_id <br/> |
|Verify transaction inclusion |    |   |   | `H256Le` tx_id <br/>`Vecu8` raw_merkle_proof <br/>`Optionu32` confirmations <br/> |
|Validate transaction |    |   |   | `Vecu8` raw_tx <br/>`Value` expected_btc <br/>`BtcAddress` recipient_btc_address <br/>`OptionH256` op_return_id <br/> |

## Security

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set parachain status |    |   |   | `StatusCode` status_code <br/> |
|Insert parachain error |    |   |   | `ErrorCode` error_code <br/> |
|Remove parachain error |    |   |   | `ErrorCode` error_code <br/> |

## VaultRegistry

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register vault |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`Compactu128` collateral <br/> |
|Deposit collateral |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`Compactu128` amount <br/> |
|Withdraw collateral |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`Compactu128` amount <br/> |
|Register public key |    |   |   | `BtcPublicKey` public_key <br/> |
|Accept new issues |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`bool` accept_new_issues <br/> |
|Set custom secure threshold |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`OptionUnsignedFixedPointT` custom_threshold <br/> |
|Report undercollateralized vault |    |   |   | `DefaultVaultIdT` vault_id <br/> |
|Set minimum collateral |    |   |   | `CurrencyIdT` currency_id <br/>`Balance` minimum <br/> |
|Set system collateral ceiling |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`Balance` ceiling <br/> |
|Set secure collateral threshold |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`UnsignedFixedPointT` threshold <br/> |
|Set premium redeem threshold |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`UnsignedFixedPointT` threshold <br/> |
|Set liquidation collateral threshold |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`UnsignedFixedPointT` threshold <br/> |
|Set current client release |    |   |   | `Vecu8` uri <br/>`Hash` code_hash <br/> |
|Set pending client release |    |   |   | `Vecu8` uri <br/>`Hash` code_hash <br/> |
|Recover vault id |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/> |

## Oracle

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Feed values |    |   |   | `VecTupleOracleKeyUnsignedFixedPoint` values <br/> |
|Insert authorized oracle |    |   |   | `AccountId` account_id <br/>`Vecu8` name <br/> |
|Remove authorized oracle |    |   |   | `AccountId` account_id <br/> |

## Issue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Request issue |    |   |   | `Compactu128` amount <br/>`DefaultVaultIdT` vault_id <br/> |
|Execute issue |    |   |   | `H256` issue_id <br/>`Vecu8` merkle_proof <br/>`Vecu8` raw_tx <br/> |
|Cancel issue |    |   |   | `H256` issue_id <br/> |
|Set issue period |    |   |   | `BlockNumber` period <br/> |

## Redeem

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Request redeem |    |   |   | `Compactu128` amount_wrapped <br/>`BtcAddress` btc_address <br/>`DefaultVaultIdT` vault_id <br/> |
|Liquidation redeem |    |   |   | `DefaultVaultCurrencyPairT` currencies <br/>`Compactu128` amount_wrapped <br/> |
|Execute redeem |    |   |   | `H256` redeem_id <br/>`Vecu8` merkle_proof <br/>`Vecu8` raw_tx <br/> |
|Cancel redeem |    |   |   | `H256` redeem_id <br/>`bool` reimburse <br/> |
|Set redeem period |    |   |   | `BlockNumber` period <br/> |
|Mint tokens for reimbursed redeem |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`H256` redeem_id <br/> |

## Replace

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Request replace |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`Compactu128` amount <br/> |
|Withdraw replace |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`Compactu128` amount <br/> |
|Accept replace |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/>`DefaultVaultIdT` old_vault <br/>`Compactu128` amount_btc <br/>`Compactu128` collateral <br/>`BtcAddress` btc_address <br/> |
|Execute replace |    |   |   | `H256` replace_id <br/>`Vecu8` merkle_proof <br/>`Vecu8` raw_tx <br/> |
|Cancel replace |    |   |   | `H256` replace_id <br/> |
|Set replace period |    |   |   | `BlockNumber` period <br/> |

## Fee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Withdraw rewards |    |   |   | `DefaultVaultIdT` vault_id <br/>`OptionIndex` index <br/> |
|Set issue fee |    |   |   | `UnsignedFixedPointT` fee <br/> |
|Set issue griefing collateral |    |   |   | `UnsignedFixedPointT` griefing_collateral <br/> |
|Set redeem fee |    |   |   | `UnsignedFixedPointT` fee <br/> |
|Set refund fee |    |   |   | `UnsignedFixedPointT` fee <br/> |
|Set premium redeem fee |    |   |   | `UnsignedFixedPointT` fee <br/> |
|Set punishment fee |    |   |   | `UnsignedFixedPointT` fee <br/> |
|Set replace griefing collateral |    |   |   | `UnsignedFixedPointT` griefing_collateral <br/> |

## Refund

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Execute refund |    |   |   | `H256` refund_id <br/>`Vecu8` merkle_proof <br/>`Vecu8` raw_tx <br/> |
|Set refund transaction size |    |   |   | `u32` size <br/> |

## Nomination

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set nomination enabled |    |   |   | `bool` enabled <br/> |
|Opt in to nomination |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/> |
|Opt out of nomination |    |   |   | `DefaultVaultCurrencyPairT` currency_pair <br/> |
|Deposit collateral |    |   |   | `DefaultVaultIdT` vault_id <br/>`Balance` amount <br/> |
|Withdraw collateral |    |   |   | `DefaultVaultIdT` vault_id <br/>`Balance` amount <br/>`OptionIndex` index <br/> |

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    |   |   | `Hash` proposal_hash <br/>`CompactBalance` amount <br/> |
|Second |    |   |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> |
|Vote |    |   |   | `Compactu32` ref_index <br/>`VoteBalanceOfT` vote <br/> |
|Fast track |    |   |   | `Compactu32` prop_index <br/>`BlockNumber` delay <br/> |
|Fast track default |    |   |   | `Compactu32` prop_index <br/>`BlockNumber` delay <br/> |
|Fast track referendum |    |   |   | `Compactu32` ref_index <br/> |
|Cancel referendum |    |   |   | `Compactu32` ref_index <br/> |
|Cancel queued |    |   |   | `ReferendumIndex` which <br/> |
|Clear public proposals |    |   |   |  |
|Cancel proposal |    |   |   | `Compactu32` prop_index <br/> |
|Note preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Reap preimage |    |   |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> |
|Remove vote |    |   |   | `ReferendumIndex` index <br/> |
|Enact proposal |    |   |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    |   |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    |   |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> |

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    |   |   | `AccountId` who <br/> |
|Remove member |    |   |   | `AccountId` who <br/> |
|Swap member |    |   |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    |   |   | `VecAccountId` members <br/> |
|Change key |    |   |   | `AccountId` new_ <br/> |
|Set prime |    |   |   | `AccountId` who <br/> |
|Clear prime |    |   |   |  |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    |   |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Remove approval |    |   |   | `Compactu32` proposal_id <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## CollatorSelection

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set invulnerables |    |   |   | `VecAccountId` new_ <br/> |
|Set desired candidates |    |   |   | `u32` max <br/> |
|Set candidacy bond |    |   |   | `Balance` bond <br/> |
|Register as candidate |    |   |   |  |
|Leave intent |    |   |   |  |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys |    |   |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys |    |   |   |  |

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation data |    |   |   | `ParachainInherentData` data <br/> |
|Sudo send upward message |    |   |   | `UpwardMessage` message <br/> |
|Authorize upgrade |    |   |   | `Hash` code_hash <br/> |
|Enact authorized upgrade |    |   |   | `Vecu8` code <br/> |

## XcmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |
|Suspend xcm execution |    |   |   |  |
|Resume xcm execution |    |   |   |  |
|Update suspend threshold |    |   |   | `u32` new_ <br/> |
|Update drop threshold |    |   |   | `u32` new_ <br/> |
|Update resume threshold |    |   |   | `u32` new_ <br/> |
|Update threshold weight |    |   |   | `Weight` new_ <br/> |
|Update weight restrict decay |    |   |   | `Weight` new_ <br/> |
|Update xcmp max individual weight |    |   |   | `Weight` new_ <br/> |

## PolkadotXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> |
|Teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Execute |    |   |   | `BoxVersionedXcmTasSysConfigCall` message <br/>`Weight` max_weight <br/> |
|Force xcm version |    |   |   | `BoxMultiLocation` location <br/>`XcmVersion` xcm_version <br/> |
|Force default xcm version |    |   |   | `OptionXcmVersion` maybe_xcm_version <br/> |
|Force subscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Force unsubscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Limited reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |
|Limited teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |

## CumulusXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## DmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |

## XTokens

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer |    |   |   | `CurrencyId` currency_id <br/>`Balance` amount <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multiasset |    |   |   | `BoxVersionedMultiAsset` asset <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer with fee |    |   |   | `CurrencyId` currency_id <br/>`Balance` amount <br/>`Balance` fee <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multiasset with fee |    |   |   | `BoxVersionedMultiAsset` asset <br/>`BoxVersionedMultiAsset` fee <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multicurrencies |    |   |   | `VecTupleCurrencyIdBalance` currencies <br/>`u32` fee_item <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multiassets |    |   |   | `BoxVersionedMultiAssets` assets <br/>`u32` fee_item <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |

