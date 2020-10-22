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

#############################################
#               PROJECT SETUP               #
#############################################

cmake_minimum_required(VERSION 3.16.3)
project(Matts_Game_Engine C)

set(MGE_VERSION_MAJOR "0")
set(MGE_VERSION_MINOR "0")
set(MGE_VERSION_PATCH "0")
set(MGE_VERSION_TWEAK "1")
set(MGE_VERSION "${MGE_VERSION_MAJOR}.${MGE_VERSION_MINOR}")
set(MGE_VERSION_FULL "${MGE_VERSION}.${MGE_VERSION_PATCH}-${MGE_VERSION_TWEAK}")

set(CMAKE_C_STANDARD 99)

set(PATH_TO_ENGINE_SRC Sources/Matt-Engine)

include_directories(${PATH_TO_ENGINE_SRC}/include)

set(OpenGL_GL_PREFERENCE GLVND)

#############################################
#               Dependencies                #
#############################################

add_subdirectory(Dependencies/GL-Dependencies)
include_directories(Dependencies/GL-Dependencies/GLFW-3.3/include)
include_directories(Dependencies/GL-Dependencies/GLAD/include)

#############################################
#           Engine and Examples             #
#############################################
add_subdirectory(${PATH_TO_ENGINE_SRC})
add_subdirectory(Sources/Examples)

#############################################
#            Doxygen Generation             #
#############################################
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_CALLER_GRAPH YES)
set(DOXYGEN_CALL_GRAPH YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Docs")
set(DOXYGEN_EXCLUDE_PATTERNS ",,*/Docs/*,*/cmake-build-debug/*,*/cmake-build-release/*,*/Dependencies/*")
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
set(DOXYGEN_UML_LOOK YES)

find_package(Doxygen REQUIRED dot)
doxygen_add_docs(${PROJECT_NAME}-Doxygen "${CMAKE_SOURCE_DIR}")
