#####################################################################################
#  Matt's Game Engine is licensed under a BSD 3-Clause License                      #
#                                                                                   #
#  BSD 3-Clause License                                                             #
#                                                                                   #
#  Copyright (c) 2020, Matthew Krueger                                              #
#  All rights reserved.                                                             #
#                                                                                   #
#  Redistribution and use in source and binary forms, with or without               #
#  modification, are permitted provided that the following conditions are met:      #
#                                                                                   #
#  1. Redistributions of source code must retain the above copyright notice, this   #
#  list of conditions and the following disclaimer.                                 #
#                                                                                   #
#  2. Redistributions in binary form must reproduce the above copyright notice,     #
#  this list of conditions and the following disclaimer in the documentation        #
#  and/or other materials provided with the distribution.                           #
#                                                                                   #
#  3. Neither the name of the copyright holder nor the names of its                 #
#  contributors may be used to endorse or promote products derived from             #
#  this software without specific prior written permission.                         #
#                                                                                   #
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"      #
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE        #
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE   #
#  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE     #
#  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL       #
#  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR       #
#  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER       #
#  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,    #
#  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    #
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             #
#####################################################################################

set (MODULE_NAME "Example_Texturing-${PROJECT_NAME}")
set (FOLDER_NAME Texturing)

set (OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin/Examples/${MODULE_NAME})
set (RESOURCE_SRC_DIR ${CMAKE_SOURCE_DIR}/Sources/Examples/${FOLDER_NAME}/Resource/)
set (RESOURCE_DST_DIR ${OUTPUT_DIR}/Resource/)

add_executable("${MODULE_NAME}" Texturing.c)
target_link_libraries("${MODULE_NAME}" Matts_Game_Engine)

set_target_properties(${MODULE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}
        )

add_custom_command(TARGET ${MODULE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCE_SRC_DIR} ${RESOURCE_DST_DIR}
        )

if(WIN32)
add_custom_command(TARGET ${MODULE_NAME} POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_BINARY_DIR}/bin/Matts_Game_Engine.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:${MODULE_NAME}>/Matts_Game_Engine.dll)                 # <--this is out-file path
endif(WIN32)