/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V2(parser_context_t* c, pd_AccountId_V2_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readCurrencyId_V2(parser_context_t* c, pd_CurrencyId_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_readTokenSymbol_V2(c, &v->token))
        break;
    case 1: // ForeignAssetId
        CHECK_ERROR(_readUInt32(c, &v->foreignAsset))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readTokenSymbol_V2(parser_context_t* c, pd_TokenSymbol_V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V2(
    const pd_AccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurrencyId_V2(
    const pd_CurrencyId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // TokenSymbol
        CHECK_ERROR(_toStringTokenSymbol_V2(&v->token, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // ForeignAssetId
        CHECK_ERROR(_toStringu32(&v->foreignAsset, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringTokenSymbol_V2(
    const pd_TokenSymbol_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "DOT");
        break;
    case 1:
        snprintf(outValue, outValueLen, "IBTC");
        break;
    case 2:
        snprintf(outValue, outValueLen, "INTR");
        break;
    case 10:
        snprintf(outValue, outValueLen, "KSM");
        break;
    case 11:
        snprintf(outValue, outValueLen, "KBTC");
        break;
    case 12:
        snprintf(outValue, outValueLen, "KINT");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}
