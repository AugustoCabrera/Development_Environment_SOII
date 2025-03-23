cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
# Establece la versión mínima de CMake requerida

# Define el proyecto con su nombre, versión y descripción
project (
    "FirstProjectInCMake"
    VERSION 1.2.0
    DESCRIPTION "CMake C Project Template for Operating Systems II"
    LANGUAGES C
)

# Habilita las pruebas unitarias con CTest (Framework para ejecutar pruebas)
include(CTest) #to enable tests
#CTest is the framework that allows you to run the tests
#not only does it allow us to execute the Utest, it also creates the pipeline for us
# CTest permite ejecutar pruebas y crear pipelines para ellas

set(CMAKE_C_STANDARD 17) # Establece que el estándar de C que se usará es C17

include_directories(include) # Incluye el directorio 'include' donde se encuentran los archivos de cabecera

include(FetchContent) #CMAKE module that allows me to download repositories


# Define la URL del repositorio para descargar la biblioteca Unity

set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git") 

set(FETCHCONTENT_QUIET OFF) # Modo "quiet" para FetchContent (sin mensajes excesivos)

# Declara el repositorio Unity para ser descargado y usado en el proyecto

FetchContent_Declare(
    Unity      
    GIT_REPOSITORY ${UNITY_GIT_URL}  #REPOSITORY WHERE TO DOWNLOAD
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity #where does git clone
    UPDATE_COMMAND ""  
)

FetchContent_MakeAvailable(Unity) #THE name of the dependency
# I stop this process until ALL of the FetchContent_Declare is finished

file(GLOB_RECURSE SOURCES "src/*.c")  #Where to look for the source code


#Now I create the executable:
#${PROJECT_NAME} to read CMake variables in the same way as
# does it in BASH therefore ${PROJECT_NAME} = GLOB_RECURSE SOURCE
# and ${SOURCES} = "src/*.c"

add_executable(${PROJECT_NAME} ${SOURCES}) #THIS IS THE TOP IN THE TREE STRUCTURE

#library compilation
add_subdirectory(lib/libdyn) #look here for the CMakeLists.txt and consider it as an isolated project
add_subdirectory(lib/libsta)

#here we only include the target
target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

#now I must link these libraries
#IN CMake EVERYTHING is a target
target_link_libraries(${PROJECT_NAME} StatiCLib DynamiCLib) 
#RUN_TESTS are variables to pass when we are doing the CMAKEs


if(RUN_TEST EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests) #this directory is added in any of these conditions
endif()

