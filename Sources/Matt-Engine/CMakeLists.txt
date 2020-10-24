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
#  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRAC`T, STRICT LIABILITY,    #
#  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    #
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIILITY OF SUCH DAMAGE.             #
#####################################################################################

set (MODULE_NAME "Matts_Game_Engine")

find_library(OpenGL REQUIRED)

add_library("${MODULE_NAME}" SHARED Graphics/Displays.c Graphics/Displays.h SharedDeclarations.h include/Matts-Engine/Core.h SharedDeclarations.c include/Matts-Engine/RequiredGlobals.h Utils/linmath.h Utils/pch.h Utils/pch.c Utils/Callbacks.c Utils/Callbacks.h Utils/Input.c Utils/Input.h Graphics/Vertices.c Graphics/Vertices.h Utils/Loader.c Utils/Loader.h Graphics/Rendering.c Graphics/Rendering.h Graphics/ShaderManagement.c Graphics/ShaderManagement.h)
add_dependencies("${MODULE_NAME}" glfw GLAD)

target_compile_definitions("${MODULE_NAME}" PRIVATE MGE_BUILD_LIBRARY)
target_precompile_headers("${MODULE_NAME}" PRIVATE Utils/pch.h)

target_link_libraries("${MODULE_NAME}" GL glfw GLAD)

set_target_properties(${MODULE_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/
        )
