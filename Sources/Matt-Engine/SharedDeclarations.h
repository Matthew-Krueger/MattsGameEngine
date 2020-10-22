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

#ifndef MATTS_GAME_ENGINE_SHAREDDECLARATIONS_H
#define MATTS_GAME_ENGINE_SHAREDDECLARATIONS_H


// DLL Export
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

// Logging

/**
 * The Log Levels of the logger. Calling MGE_*_LOG_CRITICAL will cause a crash.
 */
typedef enum{
    TRACE,
    INFO,
    FINE,
    WARN,
    SEVERE,
    CRITICAL
} MGE_LogLevel;

/**
 * Logs a message from the CORE, i.e. the engine. Please use MGE_CORE_LOG_LEVEL
 * @param message The message to log
 * @param reason The reason for the log
 * @param level The \link MGE_LogLevel MGE_LogLevel \endlink of the log
 * @param file The file in which it occurred
 * @param function The function in which it occurred
 * @param line The line on which it occurred
 * @param exitCode The exit code if it is \link MGE_LogLevel::CRITICAL MGE_LogLevel::CRITICAL \endlink
 */
MGE_API void mge_core_log(const char * message, const char * reason, MGE_LogLevel level, const char * file, const char * function, unsigned int line, int exitCode);

/**
 * Logs a message from the CORE, i.e. the engine. Please use MGE_APP_LOG_LEVEL
 * @param message The message to log
 * @param reason The reason for the log
 * @param level The \link MGE_LogLevel MGE_LogLevel \endlink of the log
 * @param file The file in which it occurred
 * @param function The function in which it occurred
 * @param line The line on which it occurred
 * @param exitCode The exit code if it is \link MGE_LogLevel::CRITICAL MGE_LogLevel::CRITICAL \endlink
 */
MGE_API void mge_app_log(const char * message, const char * reason, MGE_LogLevel level, const char * file, const char * function, unsigned int line, int exitCode);

/**
 * Logs a message from core. No level required. Always runs with MGE_CORE_INFO
 * @param message The message to log
 * @param reason The reason for the log
 * @param file The file in which it occurred
 * @param function The function in which it occurred
 * @param line The line on which it occurred
 */
MGE_API void mge_core_inf(const char * message, const char * reason, const char * file, const char * function, unsigned int line);

/**
 * Logs a message from core. No level required. Always runs with MGE_APP_INFO
 * @param message The message to log
 * @param reason The reason for the log
 * @param file The file in which it occurred
 * @param function The function in which it occurred
 * @param line The line on which it occurred
 */
MGE_API void mge_app_inf(const char * message, const char * reason, const char * file, const char * function, unsigned int line);


#ifdef NDEBUG
#   ifdef INCLUDE_FINE
    // Release FINE Core
#       define MGE_CORE_LOG_TRACE(message, reason)              { MGE_LogLevel MGE_levelTrace    = TRACE;     mge_core_log(message, reason, MGE_levelTrace,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_INFO(message, reason)               { MGE_LogLevel MGE_levelInfo     = INFO;      mge_core_log(message, reason, MGE_levelInfo,      __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_FINE(message, reason)               { MGE_LogLevel MGE_levelFine     = FINE;      mge_core_log(message, reason, MGE_levelFine,      __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_WARN(message, reason)               { MGE_LogLevel MGE_levelWarning  = WARNING;   mge_core_log(message, reason, MGE_levelWarning,   __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_SEVERE(message, reason)             { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_core_log(message, reason, MGE_levelSevere,    __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_CRITICAL(message, reason, exitCode) { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_core_log(message, reason, MGE_levelCritical,  __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_CORE_INFO(message, reason)                   {                                             mge_core_inf(message, reason,                     __FILE__, __func__, __LINE__); }

    // Release FINE App
#       define MGE_APP_LOG_TRACE(message, reason)               { MGE_LogLevel MGE_levelTrace    = TRACE;     mge_app_log(message, reason, MGE_levelTrace,      __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_INFO(message, reason)                { MGE_LogLevel MGE_levelInfo     = INFO;      mge_app_log(message, reason, MGE_levelInfo,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_FINE(message, reason)                { MGE_LogLevel MGE_levelFine     = FINE;      mge_app_log(message, reason, MGE_levelFine,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_WARN(message, reason)                { MGE_LogLevel MGE_levelWarning  = WARNING;   mge_app_log(message, reason, MGE_levelWarn,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_SEVERE(message, reason)              { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_app_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_CRITICAL(message, reason, exitCode)  { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_app_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_APP_INFO(message, reason)                    {                                             mge_app_inf(message, reason,                      __FILE__, __func__, __LINE__); }
#   else
    // Release Core
#       define MGE_CORE_LOG_TRACE(message, reason)
#       define MGE_CORE_LOG_INFO(message, reason)
#       define MGE_CORE_LOG_FINE(message, reason)
#       define MGE_CORE_LOG_WARN(message, reason)
#       define MGE_CORE_LOG_SEVERE(message, reason)             { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_core_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_CRITICAL(message, reason, exitCode) { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_core_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_CORE_INFO(message, reason)                   {                                             mge_core_inf(message, reason,                      __FILE__, __func__, __LINE__); }
    // Release App
#       define MGE_APP_LOG_TRACE(message, reason)
#       define MGE_APP_LOG_INFO(message, reason)
#       define MGE_APP_LOG_FINE(message, reason)
#       define MGE_APP_LOG_WARN(message, reason)
#       define MGE_APP_LOG_SEVERE(message, reason)              { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_core_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_CRITICAL(message, reason, exitCode)  { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_core_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_APP_INFO(message, reason)                    {                                             mge_core_inf(message, reason,                      __FILE__, __func__, __LINE__); }
#   endif
#else
    // Debug Core
#       define MGE_CORE_LOG_TRACE(message, reason)              { MGE_LogLevel MGE_levelTrace    = TRACE;     mge_core_log(message, reason, MGE_levelTrace,      __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_INFO(message, reason)               { MGE_LogLevel MGE_levelInfo     = INFO;      mge_core_log(message, reason, MGE_levelInfo,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_FINE(message, reason)               { MGE_LogLevel MGE_levelFine     = FINE;      mge_core_log(message, reason, MGE_levelFine,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_WARN(message, reason)               { MGE_LogLevel MGE_levelWarning  = WARNING;   mge_core_log(message, reason, MGE_levelWarn,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_SEVERE(message, reason)             { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_core_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_CRITICAL(message, reason, exitCode) { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_core_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_CORE_INFO(message, reason)                   {                                             mge_core_inf(message, reason,                      __FILE__, __func__, __LINE__); }
    // Debug App
#       define MGE_APP_LOG_TRACE(message, reason)               { MGE_LogLevel MGE_levelTrace    = TRACE;     mge_app_log(message, reason, MGE_levelTrace,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_INFO(message, reason)                { MGE_LogLevel MGE_levelInfo     = INFO;      mge_app_log(message, reason, MGE_levelInfo,        __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_FINE(message, reason)                { MGE_LogLevel MGE_levelFine     = FINE;      mge_app_log(message, reason, MGE_levelFine,        __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_WARN(message, reason)                { MGE_LogLevel MGE_levelWarning  = WARNING;   mge_app_log(message, reason, MGE_levelWarn,        __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_SEVERE(message, reason)              { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_app_log(message, reason, MGE_levelSevere,      __FILE__, __func__, __LINE__, 0); }
#       define MGE_APP_LOG_CRITICAL(message, reason, exitCode)  { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_app_log(message, reason, MGE_levelCritical,    __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_APP_INFO(message, reason)                    {                                             mge_app_inf(message, reason,                       __FILE__, __func__, __LINE__); }
#endif

/**
 * Initializes the files that the logging functions will log to. Currently unused
 * @param mge_engineLogFile The file to log engine errors to
 * @param mge_appLogFile The file to log app errors to
 */
MGE_API void MGE_logInit(const char * mge_engineLogFile, const char * mge_appLogFile);

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

#endif //MATTS_GAME_ENGINE_SHAREDDECLARATIONS_H
