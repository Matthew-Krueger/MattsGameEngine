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
#       define MGE_API __attribute__ ((visibility ("default")))
#       define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
#   else
#       define MGE_API
#       define MGE_API_HIDDEN
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

MGE_API MGE_LogLevel MGE_levelTrace     = TRACE;
MGE_API MGE_LogLevel MGE_levelInfo      = INFO;
MGE_API MGE_LogLevel MGE_levelFine      = FINE;
MGE_API MGE_LogLevel MGE_levelWarn      = WARN;
MGE_API MGE_LogLevel MGE_levelSevere    = SEVERE;
MGE_API MGE_LogLevel MGE_levelCritical  = CRITICAL;


MGE_API void mge_core_log(const char * message, const char * reason, MGE_LogLevel level, const char * file, const char * function, unsigned int line);
MGE_API void mge_app_log(const char * message, const char * reason, MGE_LogLevel level, const char * file, const char * function, unsigned int line);

#ifdef NDEBUG
#   ifdef INCLUDE_FINE
    // Release FINE Core
#       define MGE_CORE_LOG_TRACE(message, reason)    mge_core_log(message, reason, MGE_levelTrace,     __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_INFO(message, reason)     mge_core_log(message, reason, MGE_levelInfo,      __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_FINE(message, reason)     mge_core_log(message, reason, MGE_levelFine,      __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_WARN(message, reason)     mge_core_log(message, reason, MGE_levelWarning,   __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_SEVERE(message, reason)   mge_core_log(message, reason, MGE_levelSevere,    __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_CRITICAL(message, reason) mge_core_log(message, reason, MGE_levelCritical,  __FILE__, __func__, __LINE__);
    // Release FINE App
#       define MGE_APP_LOG_TRACE(message, reason)     mge_app_log(message, reason, MGE_levelTrace,      __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_INFO(message, reason)      mge_app_log(message, reason, MGE_levelInfo,       __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_FINE(message, reason)      mge_app_log(message, reason, MGE_levelFine,       __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_WARN(message, reason)      mge_app_log(message, reason, MGE_levelWarn,       __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_SEVERE(message, reason)    mge_app_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_CRITICAL(message, reason)  mge_app_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__);
#   else
    // Release Core
#       define MGE_CORE_LOG_TRACE(message, reason)
#       define MGE_CORE_LOG_INFO(message, reason)
#       define MGE_CORE_LOG_FINE(message, reason)
#       define MGE_CORE_LOG_WARN(message, reason)
#       define MGE_CORE_LOG_SEVERE(message, reason)   mge_core_log(message, reason, MGE_levelSevere,    __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_CRITICAL(message, reason) mge_core_log(message, reason, MGE_levelCritical,  __FILE__, __func__, __LINE__);
    // Release App
#       define MGE_APP_LOG_TRACE(message, reason)
#       define MGE_APP_LOG_INFO(message, reason)
#       define MGE_APP_LOG_FINE(message, reason)
#       define MGE_APP_LOG_WARN(message, reason)
#       define MGE_APP_LOG_SEVERE(message, reason)   mge_app_log(message, reason, MGE_levelSevere,      __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_CRITICAL(message, reason) mge_app_log(message, reason, MGE_levelCritical,    __FILE__, __func__, __LINE__);
#   endif
#else
    // Debug Core
#       define MGE_CORE_LOG_TRACE(message, reason)    mge_core_log(message, reason, MGE_levelTrace,     __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_INFO(message, reason)     mge_core_log(message, reason, MGE_levelInfo,      __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_FINE(message, reason)     mge_core_log(message, reason, MGE_levelFine,      __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_WARN(message, reason)     mge_core_log(message, reason, MGE_levelWarn,      __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_SEVERE(message, reason)   mge_core_log(message, reason, MGE_levelSevere,    __FILE__, __func__, __LINE__);
#       define MGE_CORE_LOG_CRITICAL(message, reason) mge_core_log(message, reason, MGE_levelCritical,  __FILE__, __func__, __LINE__);
    // Debug App
#       define MGE_APP_LOG_TRACE(message, reason)    mge_app_log(message, reason, MGE_levelTrace,       __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_INFO(message, reason)     mge_app_log(message, reason, MGE_levelInfo,        __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_FINE(message, reason)     mge_app_log(message, reason, MGE_levelFine,        __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_WARN(message, reason)     mge_app_log(message, reason, MGE_levelWarn,        __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_SEVERE(message, reason)   mge_app_log(message, reason, MGE_levelSevere,      __FILE__, __func__, __LINE__);
#       define MGE_APP_LOG_CRITICAL(message, reason) mge_app_log(message, reason, MGE_levelCritical,    __FILE__, __func__, __LINE__);
#endif

#endif //MATTS_GAME_ENGINE_SHAREDDECLARATIONS_H
