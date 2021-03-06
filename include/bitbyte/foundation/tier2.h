//===-- bitbyte/foundation/tier2.h ------------------------------*- C++ -*-===//
//
//  Foundation
//
//  This file is distributed under the terms described in LICENSE.
//
//  Author(s):
//
//    * Michael Williams <mike@origamicomet.com>
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Imports tier2 into Foundation's namespace.
///
//===----------------------------------------------------------------------===//

#ifndef _BITBYTE_FOUNDATION_TIER2_H_
#define _BITBYTE_FOUNDATION_TIER2_H_

//============================================================================//

#ifdef __cplusplus

//===----------------------------------------------------------------------===//

namespace bitbyte {
namespace foundation {

/// \namespace ::bitbyte::foundation::tier2
/// \brief Provides powerful debugging utilities.
///
namespace tier2 {}

using namespace ::bitbyte::foundation::tier2;

} // foundation
} // bitbyte

//===----------------------------------------------------------------------===//

#endif // __cplusplus

//============================================================================//

#include "bitbyte/foundation/tier2/linkage.h"

//===----------------------------------------------------------------------===//

#include "bitbyte/foundation/tier2/assert.h"
#include "bitbyte/foundation/tier2/debug/symbol.h"
#include "bitbyte/foundation/tier2/debug/symbols.h"
#include "bitbyte/foundation/tier2/exception.h"
#include "bitbyte/foundation/tier2/log.h"
#include "bitbyte/foundation/tier2/signal.h"

//============================================================================//

#endif // _BITBYTE_FOUNDATION_TIER2_H_

//============================================================================//
