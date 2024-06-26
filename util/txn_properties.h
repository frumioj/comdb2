/*
   Copyright 2015, 2021 Bloomberg Finance L.P.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#ifndef INCLUDED_TXN_PROPERTIES_H
#define INCLUDED_TXN_PROPERTIES_H
#include <stdint.h>

struct txn_properties {
    uint32_t priority;
    uint32_t retries;
    uint32_t flags;
    uint32_t prepared_txnid;
    uint64_t prepared_utxnid;
    DB_LSN begin_lsn;
};
#endif
