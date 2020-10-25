/************************************************************************************
* Matt's Game Engine is licensed under a BSD 3-Clause License                       *
*                                                                                   *
* BSD 3-Clause License                                                              *
*                                                                                   *
* Copyright (c) 2020, Matthew Krueger                                               *
* All rights reserved.                                                              *
*                                                                                   *
* Redistribution and use in source and binary forms, with or without                *
* modification, are permitted provided that the following conditions are met:       *
*                                                                                   *
* 1. Redistributions of source code must retain the above copyright notice, this    *
*    list of conditions and the following disclaimer.                               *
*                                                                                   *
* 2. Redistributions in binary form must reproduce the above copyright notice,      *
*    this list of conditions and the following disclaimer in the documentation      *
*    and/or other materials provided with the distribution.                         *
*                                                                                   *
* 3. Neither the name of the copyright holder nor the names of its                  *
*    contributors may be used to endorse or promote products derived from           *
*    this software without specific prior written permission.                       *
*                                                                                   *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"       *
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE         *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE    *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE      *
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL        *
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR        *
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER        *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,     *
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
************************************************************************************/

#ifndef MATTS_GAME_ENGINE_USEFULMACROS_H
#define MATTS_GAME_ENGINE_USEFULMACROS_H

#if defined _WIN32 || defined __CYGWIN__
#   ifdef MGE_BUILD_LIBRARY
        // Exporting...
#       ifdef __GNUC__
#           define MGE_API __attribute__ ((dllexport))
#       else
#           define MGE_API __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#       endif
#   else
#       ifdef __GNUC__
#           define MGE_API __attribute__ ((dllimport))
#       else
#           define MGE_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#       endif
#   endif
#   define MGE_API_HIDDEN
#else
#   if __GNUC__ >= 4
#       define MGE_API __attribute__ ((visibility ("default"))) extern
#       define MGE_API_HIDDEN  __attribute__ ((visibility ("hidden")))
#   else
#       define MGE_API
#       define MGE_API_HIDDEN
#       error Problem configuring
#   endif
#endif

/* Debugging assertions and traps
 * Portable Snippets - https://github.com/nemequ/portable-snippets
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 *   To the extent possible under law, the authors have waived all
 *   copyright and related or neighboring rights to this code.  For
 *   details, see the Creative Commons Zero 1.0 Universal license at
 *   https://creativecommons.org/publicdomain/zero/1.0/
 */

#if !defined(PSNIP_NDEBUG) && defined(NDEBUG) && !defined(PSNIP_DEBUG)
#  define PSNIP_NDEBUG 1
#endif

#if defined(__has_builtin) && !defined(__ibmxl__)
#  if __has_builtin(__builtin_debugtrap)
#    define MGE_DEBUG_BREAK() __builtin_debugtrap()
#  elif __has_builtin(__debugbreak)
#    define MGE_DEBUG_BREAK() __debugbreak()
#  endif
#endif
#if !defined(MGE_DEBUG_BREAK)
#  if defined(_MSC_VER) || defined(__INTEL_COMPILER)
#    define MGE_DEBUG_BREAK() __debugbreak()
#  elif defined(__ARMCC_VERSION)
#    define MGE_DEBUG_BREAK() __breakpoint(42)
#  elif defined(__ibmxl__) || defined(__xlC__)
#    include <builtins.h>
#    define MGE_DEBUG_BREAK() __trap(42)
#  elif defined(__DMC__) && defined(_M_IX86)
static inline void MGE_DEBUG_BREAK(void) { __asm int 3h; }
#  elif defined(__i386__) || defined(__x86_64__)
static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__("int3"); }
#  elif defined(__thumb__)
static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__(".inst 0xde01"); }
#  elif defined(__aarch64__)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__(".inst 0xd4200000"); }
#  elif defined(__arm__)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__(".inst 0xe7f001f0"); }
#  elif defined (__alpha__) && !defined(__osf__)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__("bpt"); }
#  elif defined(_54_)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__("ESTOP"); }
#  elif defined(_55_)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__(";\n .if (.MNEMONIC)\n ESTOP_1\n .else\n ESTOP_1()\n .endif\n NOP"); }
#  elif defined(_64P_)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__("SWBP 0"); }
#  elif defined(_6x_)
     static inline void MGE_DEBUG_BREAK(void) { __asm__ __volatile__("NOP\n .word 0x10000000"); }
#  elif defined(__STDC_HOSTED__) && (__STDC_HOSTED__ == 0) && defined(__GNUC__)
#    define MGE_DEBUG_BREAK() __builtin_trap()
#  else
#    include <signal.h>
#    if defined(SIGTRAP)
#      define MGE_DEBUG_BREAK() raise(SIGTRAP)
#    else
#      define MGE_DEBUG_BREAK() raise(SIGABRT)
#    endif
#  endif
#endif

#endif //MATTS_GAME_ENGINE_USEFULMACROS_H
