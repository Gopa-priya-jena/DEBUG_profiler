cmake_minimum_required(VERSION 4.0.0)
project(
    "DEBUG_Profile"
    VERSION 1
    DESCRIPTION
        "It is printf style debug+profile for fast devlopment session without opening debugger multiple times"
    LANGUAGES CXX C
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

function(file_list NAME)
    message("\n THE LIST OF ${NAME} FILES ARE \n")
    message(
        "----------------------------------------------------------------------------------------------------------------------------------------------"
    )
    foreach(item ${ARGN})
        message(${item})
    endforeach()
endfunction()

set(Source_files)

file(
    GLOB_RECURSE Source_files
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
file(
    GLOB_RECURSE Header_files
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.hpp
)
# compile tracy only needed
if(TRACY_ENABLE)
    add_subdirectory(External/TRACY)
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/External/TRACY/public/tracy/
    )
    list(
        APPEND
        Source_files
        ${CMAKE_CURRENT_SOURCE_DIR}/External/TRACY/public/TracyClient.cpp
    )
endif()
file_list("DEBUG_Profiler_src files"   ${Source_files})
file_list("DEBUG_Profiler_hdr files"   ${Header_files})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_library(DEBUG_Profiler ${Source_files} ${Header_files})
target_include_directories(
    DEBUG_Profiler
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/
        ${CMAKE_CURRENT_SOURCE_DIR}/External/TRACY/public/tracy/
)

add_macro













if(TRACY_ENABLE)
    target_link_libraries(DEBUG_Profiler PUBLIC Tracy::TracyClient)
endif()
if(UNIX)
    target_link_libraries(DEBUG_Profiler PUBLIC stdc++exp)
    set(CMAKE_CXX_FLAGS "-std=c++23")
endif()
#remove this its a testing part

add_executable(DEBUG_Profiler_test ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(DEBUG_Profiler_test PUBLIC DEBUG_Profiler)
target_include_directories(
    DEBUG_Profiler_test
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc/
)
