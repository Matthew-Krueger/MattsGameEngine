//
// Created by matth on 10/24/20.
//

#ifndef MATTS_GAME_ENGINE_SHAREDLOGSTRUCTS_H
#define MATTS_GAME_ENGINE_SHAREDLOGSTRUCTS_H

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
 * Initializes the files that the logging functions will log to. Currently unused
 * @param mge_engineLogFile The file to log engine errors to
 * @param mge_appLogFile The file to log app errors to
 */
MGE_API void MGE_logInit(const char * mge_engineLogFile, const char * mge_appLogFile);

#endif //MATTS_GAME_ENGINE_SHAREDLOGSTRUCTS_H
