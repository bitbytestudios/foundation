// The author(s) disclaim copyright to this source-code.
// Can be licensed under MIT (in case the public domain is not recognized).
// More information can be found in the LICENSE file.

#ifndef _FOUNDATION_CONTAINERS_ARRAY_H_
#define _FOUNDATION_CONTAINERS_ARRAY_H_

// Provides a generic flexibly sized array.

#include <foundation/detect.h>
#include <foundation/compat.h>
#include <foundation/config.h>
#include <foundation/assert.h>
#include <foundation/allocator.h>
#include <foundation/algorithms/limit.h>
#include <foundation/algorithms/optimized_copy.h>

namespace foundation {
  template <typename T>
  class FOUNDATION_EXPORT Array final {
    public:
      class Iterator final {
        private:
          friend class Array<T>;

        private:
          FOUNDATION_INLINE Iterator(
            Array<T>& array,
            size_t idx
          ) : _array(array)
            , _idx(idx)
          {}

        public:
          FOUNDATION_INLINE Iterator(
            const Iterator& iter
          ) : _array(iter._array)
            , _idx(iter._idx)
          {}

          FOUNDATION_INLINE Iterator& operator= ( const Iterator& iter )
          { _array = iter._array; _idx = iter._idx; return *this; }

        public:
          FOUNDATION_INLINE bool operator== ( const Iterator& iter )
          { return ((&_array == &iter._array) && (_idx == iter._idx)); }

          FOUNDATION_INLINE bool operator!= ( const Iterator& iter )
          { return ((&_array != &iter._array) || (_idx != iter._idx)); }

          FOUNDATION_INLINE Iterator operator++ ()
          { _idx = min(_idx + 1, _array.size()); return *this; }

          FOUNDATION_INLINE Iterator operator++ ( int )
          { Iterator iter(*this); ++(*this); return iter; }

          FOUNDATION_INLINE Iterator operator-- ()
          { _idx = max(1, _idx) - 1; return *this; }

          FOUNDATION_INLINE Iterator operator-- ( int )
          { Iterator iter(*this); --(*this); return iter; }

        public:
          FOUNDATION_INLINE T& to_ref()
          { return _array.to_ptr()[_idx]; }

          FOUNDATION_INLINE T& operator* ()
          { return to_ref(); }

          FOUNDATION_INLINE const T& to_ref() const
          { return _array.to_ptr()[_idx]; }

          FOUNDATION_INLINE const T& operator* () const
          { return to_ref(); }

        private:
          Array<T>& _array;
          size_t _idx;
      };

    private:
      friend class Iterator;

    public:
      explicit Array(
        Allocator& allocator,
        size_t reserve = 0
      ) : _allocator(allocator)
        , _size(0), _reserved(reserve)
        , _array((T*)allocator.alloc(reserve * sizeof(T), alignment_of<T>::value))
      {
      }

      Array(
        const Array<T>& array
      ) : _allocator(array._allocator)
        , _size(array._size), _reserved(array._reserved)
        , _array((T*)array._allocator.alloc(array._reserved * sizeof(T), alignment_of<T>::value))
      {
        optimized_copy<T>(_array, array._array, array._size);
      }

      Array(
        Allocator& allocator,
        const Array<T>& array
      ) : _allocator(allocator)
        , _size(array._size), _reserved(array._reserved)
        , _array((T*)allocator.alloc(array._reserved * sizeof(T), alignment_of<T>::value))
      {
        optimized_copy<T>(_array, array._array, array._size);
      }

      Array(
        const Iterator& min,
        const Iterator& max
      ) : _allocator(min._array._allocator)
        , _size(0), _reserved(0)
        , _array(nullptr)
      {
        _size = _reserved = max(min._idx, max._idx) - min(min._idx, max._idx);
        _array = (T*)_allocator.alloc(_reserved * sizeof(T), alignment_of<T>::value);
        optimized_copy<T>(_array, &min._array._array[min(min._idx, max._idx)], _size);
      }

      Array(
        Allocator& allocator,
        const Iterator& min,
        const Iterator& max
      ) : _allocator(allocator)
        , _size(0), _reserved(0)
        , _array(nullptr)
      {
        _size = _reserved = max(min._idx, max._idx) - min(min._idx, max._idx);
        _array = (T*)_allocator.alloc(_reserved * sizeof(T), alignment_of<T>::value);
        optimized_copy<T>(_array, &min._array._array[min(min._idx, max._idx)], _size);
      }

      Array(
        Allocator& allocator,
        const T array[]
      ) : _allocator(allocator)
        , _size(0), _reserved(0)
        , _array(nullptr)
      {
        _size = _reserved = sizeof(array) / sizeof(T);
        _array = (T*)_allocator.alloc(_reserved * sizeof(T), alignment_of<T>::value);
        optimized_copy<T>(_array, &array[0], _size);
      }

      Array(
        Allocator& allocator,
        const T* array,
        size_t array_len
      ) : _allocator(allocator)
        , _size(array_len), _reserved(array_len)
        , _array((T*)allocator.alloc(array_len * sizeof(T), alignment_of<T>::value))
      {
        optimized_copy<T>(_array, &array[0], array_len);
      }

      Array& operator= ( const Array<T>& array )
      {
        if (&array == this)
          return *this;
        _size = array._size;
        _reserved = array._reserved;
        _array = (T*)_allocator.realloc((void*)_array, _reserved * sizeof(T), alignment_of<T>::value);
        optimized_copy<T>(_array, array._array, _size);
        return *this;
      }

      Array& operator= ( const T array[] )
      {
        optimized_destruct<T>(_array, _size);
        _size = _reserved = sizeof(array) / sizeof(T);
        _array = (T*)_allocator.realloc((void*)_array, _reserved * sizeof(T), alignment_of<T>::value);
        optimized_copy<T>(_array, &array[0], _size);
        return *this;
      }

      ~Array()
      {
        _allocator.free((void*)_array);
      }

    public:
      FOUNDATION_INLINE Iterator begin() const
      { return Iterator((Array<T>&)*this, (size_t)0); }

      FOUNDATION_INLINE Iterator end() const
      { return Iterator((Array<T>&)*this, _size); }

      FOUNDATION_INLINE Iterator front() const
      { return Iterator((Array<T>&)*this, 0); }

      FOUNDATION_INLINE Iterator back() const
      { return Iterator((Array<T>&)*this, max(_size, (size_t)1) - 1); }

    public:
      void operator+= ( const T& obj )
      {
        if (_size == _reserved)
          reserve(_reserved ? _reserved : 1);
        optimized_copy<T>(&_array[_size++], &obj, 1);
      }

      T& operator[] ( const size_t idx )
      {
        assert(idx < _reserved);
        if (idx > _size)
          _size = idx;
        return _array[idx];
      }

      const T& operator[] ( const size_t idx ) const
      {
        assert(idx < _reserved);
        if (idx > _size)
          _size = idx;
        return _array[idx];
      }

    public:
      FOUNDATION_INLINE Allocator& allocator() const
      { return _allocator; }
    
    public:
      FOUNDATION_INLINE size_t size() const
      { return _size; }

      void resize( size_t size )
      {
        if (size == _reserved) {
          _size = size; return; }
        _size = _reserved = size;
        _array = (T*)_allocator.realloc(
          (void*)_array, size * sizeof(T), alignment_of<T>::value);
      }

    public:
      FOUNDATION_INLINE size_t reserved() const
      { return _reserved; }

      void reserve( size_t more )
      {
        _reserved += more;
        _array = (T*)_allocator.realloc(
          (void*)_array, _reserved * sizeof(T), alignment_of<T>::value);
      }

    public:
      FOUNDATION_EXPORT T* to_ptr()
      { return _array; }

      FOUNDATION_INLINE const T* to_ptr() const
      { return _array; }

    protected:
      Allocator& _allocator;
      mutable size_t _size, _reserved;
      T* _array;
  };
} // foundation

#endif // _FOUNDATION_CONTAINERS_ARRAY_H_