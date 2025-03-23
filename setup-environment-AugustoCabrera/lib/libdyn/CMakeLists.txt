cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project (
"DynamiCLib"
VERSION 1.0.0
DESCRIPTION "CMake C Project Template for Operating Systems II"
LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")  #Where to look for the source code


#Now I create the executable:
#${PROJECT_NAME} to read CMake variables in the same way as
# does it in BASH therefore ${PROJECT_NAME} = GLOB_RECURSE SOURCE
# and ${SOURCES} = "src/*.c"

add_library(${PROJECT_NAME} SHARED ${SOURCES})

