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

#include "include/Matts-Engine/RequiredGlobals.h"

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
                  unsigned int line, int exitCode) {

    const char * levelText = decodeLogLevel(level);

    fprintf(stderr, "\nMGE Core Error %s ERROR in %s:%u\n Function: %s\n Message: %s\n Reason: %s\n", levelText, file, line, function, message, reason);
    fprintf(MGE_CORE_LOG, "\nMGE App Error %s ERROR in %s:%u\n Function: %s\n Message: %s\n Reason: %s\n", levelText, file, line, function, message, reason);


    if(level == CRITICAL){
        fprintf(stderr, "\nError was critical, code: %u. Exiting...", exitCode);
        exit(exitCode);
    }

}

void mge_app_log(const char* message, const char* reason, MGE_LogLevel level, const char* file, const char* function,
                 unsigned int line, int exitCode) {

    const char * levelText = decodeLogLevel(level);

    fprintf(stderr, "\nMGE App Error %s ERROR in %s:%u\n Function: %s\n Message: %s\n Reason: %s\n", levelText, file, line, function, message, reason);
    fprintf(MGE_APP_LOG, "\nMGE App Error %s ERROR in %s:%u\n Function: %s\n Message: %s\n Reason: %s\n", levelText, file, line, function, message, reason);

    if(level == CRITICAL){
        fprintf(stderr, "\nError was critical, code: %u. Exiting...", exitCode);
        exit(exitCode);
    }

}



void mge_core_inf(const char *message, const char *reason, const char *file, const char *function, unsigned int line) {

    char * reasonFinal = (char *)calloc(300,sizeof(char));
    if(reason[0] != '\0'){
        sprintf(reasonFinal, ", Reason %s", reason);
    }

    fprintf(stdout, "\nMGE Core Info: Message %s%s\n", message, reasonFinal);
    fprintf(MGE_CORE_LOG, "\nMGE Core Info: Message %s%s\n", message, reasonFinal);


    free(reasonFinal);

}

void mge_app_inf(const char *message, const char *reason, const char *file, const char *function, unsigned int line) {

    char * reasonFinal = calloc(300,sizeof(char));
    if(reason[0] != '\0'){
        sprintf(reasonFinal, ", Reason %s", reason);
    }

    fprintf(stdout, "\nMGE Application Info: Message %s%s\n", message, reasonFinal);
    fprintf(MGE_APP_LOG, "\nMGE Core Info: Message %s%s\n", message, reasonFinal);

    free(reasonFinal);

}

void MGE_logInit(const char *mge_engineLogFile, const char *mge_appLogFile) {

    MGE_CORE_LOG = fopen(mge_engineLogFile, "w+");
    MGE_APP_LOG = fopen(mge_appLogFile, "w+");

}

