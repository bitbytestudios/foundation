// The author(s) disclaim copyright to this source-code.
// Can be licensed under MIT (in case the public domain is not recognized).
// More information can be found in the LICENSE file.

#ifndef _FOUNDATION_PAIR_H_
#define _FOUNDATION_PAIR_H_

// A structure that consists of a comparable key, and an associated value.

#include <foundation/detect.h>
#include <foundation/compat.h>
#include <foundation/config.h>

namespace foundation {
  template <typename _Key, typename _Value>
  class FOUNDATION_EXPORT Pair {
    public:
      Pair( const _Key& key, const _Value& value )
        : key(key), value(value)
      {}

      Pair( const Pair<_Key, _Value>& pair )
        : key(pair.key), value(pair.value)
      {}

      Pair& operator= ( const Pair<_Key, _Value>& pair )
      {
        if (&pair == this)
          return *this;

        key = pair.key;
        value = pair.value;
        return *this;
      }

    public:
      FOUNDATION_INLINE bool operator< ( const Pair<_Key, _Value>& pair )
      { return (key < pair.key); }

      FOUNDATION_INLINE bool operator> ( const Pair<_Key, _Value>& pair )
      { return (key > pair.key); }

    public:
      _Key key;
      _Value value;
  };
} // foundation

#endif // _FOUNDATION_PAIR_H_