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

#ifndef MATTS_GAME_ENGINE_ENGINELOGGER_H
#define MATTS_GAME_ENGINE_ENGINELOGGER_H

#include "SharedLogStructs.h"

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
MGE_API_HIDDEN void mge_core_log(const char * message, const char * reason, MGE_LogLevel level, const char * file, const char * function, unsigned int line, int exitCode);


/**
 * Logs a message from core. No level required. Always runs with MGE_CORE_INFO
 * @param message The message to log
 * @param reason The reason for the log
 * @param file The file in which it occurred
 * @param function The function in which it occurred
 * @param line The line on which it occurred
 */
MGE_API void mge_core_inf(const char * message, const char * reason, const char * file, const char * function, unsigned int line);

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
#    else
    // Release Core
#       define MGE_CORE_LOG_TRACE(message, reason)
#       define MGE_CORE_LOG_INFO(message, reason)
#       define MGE_CORE_LOG_FINE(message, reason)
#       define MGE_CORE_LOG_WARN(message, reason)
#       define MGE_CORE_LOG_SEVERE(message, reason)             { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_core_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_CRITICAL(message, reason, exitCode) { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_core_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_CORE_INFO(message, reason)                   {                                             mge_core_inf(message, reason,                      __FILE__, __func__, __LINE__); }
#    endif
#else
// Debug Core
#       define MGE_CORE_LOG_TRACE(message, reason)              { MGE_LogLevel MGE_levelTrace    = TRACE;     mge_core_log(message, reason, MGE_levelTrace,      __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_INFO(message, reason)               { MGE_LogLevel MGE_levelInfo     = INFO;      mge_core_log(message, reason, MGE_levelInfo,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_FINE(message, reason)               { MGE_LogLevel MGE_levelFine     = FINE;      mge_core_log(message, reason, MGE_levelFine,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_WARN(message, reason)               { MGE_LogLevel MGE_levelWarning  = WARNING;   mge_core_log(message, reason, MGE_levelWarn,       __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_SEVERE(message, reason)             { MGE_LogLevel MGE_levelSevere   = SEVERE;    mge_core_log(message, reason, MGE_levelSevere,     __FILE__, __func__, __LINE__, 0); }
#       define MGE_CORE_LOG_CRITICAL(message, reason, exitCode) { MGE_LogLevel MGE_levelCritical = CRITICAL;  mge_core_log(message, reason, MGE_levelCritical,   __FILE__, __func__, __LINE__, exitCode); }
#       define MGE_CORE_INFO(message, reason)                   {                                             mge_core_inf(message, reason,                      __FILE__, __func__, __LINE__); }
#endif

#endif //MATTS_GAME_ENGINE_ENGINELOGGER_H
