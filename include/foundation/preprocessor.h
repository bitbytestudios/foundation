/* ========================================================================== */
/*                                                                            */
/* This file is part of Foundation.                                           */
/*                                                                            */
/* Author(s):                                                                 */
/*                                                                            */
/*   Michael Williams <devbug@bitbyte.ca>                                     */
/*                                                                            */
/* This is free and unencumbered software released into the public domain.    */
/*                                                                            */
/* Anyone is free to copy, modify, publish, use, compile, sell, or distribute */
/* this software, either in source code form or as a compiled binary, for any */
/* purpose, commercial or non-commercial, and by any means.                   */
/*                                                                            */
/* In jurisdictions that recognize copyright laws, the author or authors of   */
/* this software dedicate any and all copyright interest in the software to   */
/* the public domain. We make this dedication for the benefit of the public   */
/* large and to the detriment of our heirs and successors. We intend this     */
/* dedication to be an overt act of relinquishment in perpetuity of all       */
/* present and future rights to this software under copyright law.            */
/*                                                                            */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    */
/* THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER   */
/* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      */
/* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR      */
/* OTHER DEALINGS IN THE SOFTWARE.                                            */
/*                                                                            */
/* For more information, please refer to <http://unlicense.org/>              */
/*                                                                            */
/* ========================================================================== */
/*! @file include/foundation/preprocessor.h
     Abuses the pre-processor to provide useful functionality.                */
/* ========================================================================== */

#ifndef _FOUNDATION_PREPROCESSOR_H_
#define _FOUNDATION_PREPROCESSOR_H_

/* ========================================================================== */
/*  Pre-processor:                                                            */
/*   * Fully expanding token stringification and joining;                     */
/* ========================================================================== */

/* ========================================================================== */
/*  Fully expanding token stringification and joining:                        */
/* ========================================================================== */

/*! @def fnd_stringificate
  Forces the expansion of the token `_` prior to stringification. */
#define __fnd_stringificate__(_) #_
#define __fnd_stringificate_(_) __fnd_stringificate__(_)
#define fnd_stringificate(_) __fnd_stringificate_(_)

/*! @def fnd_join
  Forces the expansion of `_Lhs` and `_Rhs` tokens prior to joining. */
#define __fnd_join__(_Lhs, _Rhs) _Lhs ## _Rhs
#define __fnd_join_(_Lhs, _Rhs) __fnd_join__(_Lhs, _Rhs)
#define fnd_join(_Lhs, _Rhs) __fnd_join_(_Lhs, _Rhs)

#endif /* _FOUNDATION_PREPROCESSOR_H_ */
