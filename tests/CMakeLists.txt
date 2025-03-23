cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

#CMAKE_CURRENT_SOURCE_DIR refers to the directory where THIS file is located
# ...TP0/setup-environment-AugustoCabrera/test/unit/CMakeLists.txt
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

file(GLOB TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/unit/*.c) 
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../src/logic.c) 

#here we only include the target
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity/src)

#coverage (optional)

if(RUN_COVERAGE)
        message("Coverage enabled")
        find_program(LCOV_PATH lcov)
            if(NOT LCOV_PATH)
                message(FATAL_ERROR "lcov not found! Aborting...")
        endif()
        find_program(GCOV_PATH gcov)
            if(NOT GCOV_PATH)
                message(FATAL_ERROR "gcov not found! Aborting...")
        endif()
        find_program(GENHTML_PATH genhtml)
            if(NOT GENHTML_PATH)
                message(FATAL_ERROR "genhtml not found! Aborting...")
        endif()

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fprofile-arcs -ftest-coverage --coverage")     
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov --coverage")   
endif()


#test_${PROJECT_NAME} how should I test
#${SRC_fILES} to know what I'm testing
add_executable(test_${PROJECT_NAME} ${TESTS_FILES} ${SRC_FILES})

target_link_libraries(test_${PROJECT_NAME} unity)

add_test(NAME test_${PROJECT_NAME} COMMAND test_${PROJECT_NAME})

