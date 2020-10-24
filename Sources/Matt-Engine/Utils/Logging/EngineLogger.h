//
// Created by matth on 10/24/20.
//

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
