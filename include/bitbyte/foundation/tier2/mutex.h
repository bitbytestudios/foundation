//=== bitbyte/foundation/tier2/mutex.h =======================================//
//                                                                            //
//  Foundation                                                                //
//                                                                            //
//  This file is distributed under the terms described in LICENSE.            //
//                                                                            //
//  Author(s):                                                                //
//   Michael Williams <mwilliams@bitbyte.ca>                                  //
//                                                                            //
//===----------------------------------------------------------------------===//

/// @file bitbyte/foundation/tier2/mutex.h
/// @brief Provides a recursive mutex.
///

#ifndef _BITBYTE_FOUNDATION_TIER2_MUTEX_H_
#define _BITBYTE_FOUNDATION_TIER2_MUTEX_H_

#include <bitbyte/foundation/config.h>
#include <bitbyte/foundation/tier0/tier0.h>
#include <bitbyte/foundation/tier1/tier1.h>
#include <bitbyte/foundation/tier2/export.h>

namespace bitbyte {
namespace foundation {
namespace tier2 {

class BITBYTE_FOUNDATION_TIER2_EXPORT Mutex {
  private: // constructor:
    Mutex();

  private: // copy-constructor:
    Mutex(const Mutex &mutex);

  private: // assignment operator:
    Mutex &operator=(const Mutex &mutex);

  private: // destructor:
    ~Mutex();

  public: // static methods:
    /// ...
    static Mutex &create();

  public: // methods:
    /// ...
    void lock();

    /// ...
    bool try_lock();

    /// ...
    void unlock();

    /// ...
    void destroy();
};

} // tier2
} // foundation
} // bitbyte

#endif // _BITBYTE_FOUNDATION_TIER2_MUTEX_H_
