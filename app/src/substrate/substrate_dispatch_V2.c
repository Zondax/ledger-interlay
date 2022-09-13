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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_tokens_transfer_V2(
    parser_context_t* c, pd_tokens_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->dest))
    CHECK_ERROR(_readCurrencyId_V2(c, &m->currency_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tokens_transfer_all_V2(
    parser_context_t* c, pd_tokens_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->dest))
    CHECK_ERROR(_readCurrencyId_V2(c, &m->currency_id))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tokens_force_transfer_V2(
    parser_context_t* c, pd_tokens_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->source))
    CHECK_ERROR(_readAccountId_V2(c, &m->dest))
    CHECK_ERROR(_readCurrencyId_V2(c, &m->currency_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL

__Z_INLINE parser_error_t _readMethod_tokens_transfer_keep_alive_V2(
    parser_context_t* c, pd_tokens_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->dest))
    CHECK_ERROR(_readCurrencyId_V2(c, &m->currency_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tokens_set_balance_V2(
    parser_context_t* c, pd_tokens_set_balance_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->who))
    CHECK_ERROR(_readCurrencyId_V2(c, &m->currency_id))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_tokens_transfer_V2(c, &method->nested.tokens_transfer_V2))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_tokens_transfer_all_V2(c, &method->basic.tokens_transfer_all_V2))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_tokens_force_transfer_V2(c, &method->nested.tokens_force_transfer_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_tokens_transfer_keep_alive_V2(c, &method->nested.tokens_transfer_keep_alive_V2))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_tokens_set_balance_V2(c, &method->nested.tokens_set_balance_V2))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 21:
        return STR_MO_TOKENS;
#ifdef SUBSTRATE_PARSER_FULL
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 5376: /* module 21 call 0 */
        return STR_ME_TRANSFER;
    case 5377: /* module 21 call 1 */
        return STR_ME_TRANSFER_ALL;
    case 5379: /* module 21 call 3 */
        return STR_ME_FORCE_TRANSFER;
    default:
        return _getMethod_Name_V2_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V2_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 5378: /* module 21 call 2 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 5380: /* module 21 call 4 */
        return STR_ME_SET_BALANCE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 5376: /* module 21 call 0 */
        return 3;
    case 5377: /* module 21 call 1 */
        return 3;
    case 5379: /* module 21 call 3 */
        return 4;
#ifdef SUBSTRATE_PARSER_FULL
    case 5378: /* module 21 call 2 */
        return 3;
    case 5380: /* module 21 call 4 */
        return 4;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_currency_id;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_currency_id;
        case 2:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_currency_id;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_currency_id;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_currency_id;
        case 2:
            return STR_IT_new_free;
        case 3:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* tokens_transfer_V2 - dest */;
            return _toStringAccountId_V2(
                &m->nested.tokens_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tokens_transfer_V2 - currency_id */;
            return _toStringCurrencyId_V2(
                &m->nested.tokens_transfer_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tokens_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.tokens_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* tokens_transfer_all_V2 - dest */;
            return _toStringAccountId_V2(
                &m->basic.tokens_transfer_all_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tokens_transfer_all_V2 - currency_id */;
            return _toStringCurrencyId_V2(
                &m->basic.tokens_transfer_all_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tokens_transfer_all_V2 - keep_alive */;
            return _toStringbool(
                &m->basic.tokens_transfer_all_V2.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0: /* tokens_force_transfer_V2 - source */;
            return _toStringAccountId_V2(
                &m->nested.tokens_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tokens_force_transfer_V2 - dest */;
            return _toStringAccountId_V2(
                &m->nested.tokens_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tokens_force_transfer_V2 - currency_id */;
            return _toStringCurrencyId_V2(
                &m->nested.tokens_force_transfer_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* tokens_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.tokens_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* tokens_transfer_keep_alive_V2 - dest */;
            return _toStringAccountId_V2(
                &m->nested.tokens_transfer_keep_alive_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tokens_transfer_keep_alive_V2 - currency_id */;
            return _toStringCurrencyId_V2(
                &m->nested.tokens_transfer_keep_alive_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tokens_transfer_keep_alive_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.tokens_transfer_keep_alive_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0: /* tokens_set_balance_V2 - who */;
            return _toStringAccountId_V2(
                &m->nested.tokens_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tokens_set_balance_V2 - currency_id */;
            return _toStringCurrencyId_V2(
                &m->nested.tokens_set_balance_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tokens_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.tokens_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* tokens_set_balance_V2 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.tokens_set_balance_V2.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 5377: // Tokens:Transfer all
        return false;
    default:
        return true;
    }
}
