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

#include "SharedDeclarations.h"
#include <stdio.h>
#include <stdlib.h>

static const char * decodeLogLevel(MGE_LogLevel level){
    switch(level){
        case TRACE:
            return "Trace";
        case INFO:
            return "Info";
        case FINE:
            return "Fine";
        case WARN:
            return "Warn";
        case SEVERE:
            return "Severe";
        case CRITICAL:
            return "Critical";
        default:
            exit(EXIT_FAILURE);
    }
}

void mge_core_log(const char* message, const char* reason, MGE_LogLevel level, const char* file, const char* function,
                  unsigned int line) {

    const char * levelText = decodeLogLevel(level);

    fprintf(stderr, "MGE Core Error %s ERROR in %s:%u, function %s\n Message: %s\n Reason: %s\n", levelText, file, line, function, message, reason);

}

void mge_app_log(const char* message, const char* reason, MGE_LogLevel level, const char* file, const char* function,
                 unsigned int line) {

    const char * levelText = decodeLogLevel(level);

    fprintf(stderr, "MGE App Error %s ERROR in %s:%u, function %s\nMessage: %s\n Reason: %s\n", levelText, file, line, function, message, reason);

}



void mge_core_inf(const char *message, const char *reason, const char *file, const char *function, unsigned int line) {

    fprintf(stdout, "MGE Core Info: Message %s, Reason %s", message, reason);
    fflush(stdout);

}

void mge_app_inf(const char *message, const char *reason, const char *file, const char *function, unsigned int line) {

    fprintf(stdout, "MGE Application Info: Message %s, Reason %s", message, reason);
    fflush(stdout);

}

void mge_init(const char *mge_engineLogFile, const char *mge_appLogFile) {



}

