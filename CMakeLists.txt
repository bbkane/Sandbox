# Author: Ben Kane

cmake_minimum_required(VERSION 3.0)

# Name the Project that holds all other projects
# Prefix with underscore for easy finding :)
project(_Sandbox)

# add warnings to all projects
if(MSVC)
    add_compile_options(/W4 /wd4100)
else(MSVC)
    add_compile_options(-std=c++1y -Wall -Wextra -pedantic -Wno-unused-parameter)
    # add_compile_options(-save-temps)
    # broken...
    # add_compile_options(-S -emit-llvm)
endif(MSVC)

# set output for all projects
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin)

# # Boost :)
# set(Boost_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/boost_1_59_0)
# set(Boost_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/lib/boost_1_59_0/stage/lib)
# find_package(Boost REQUIRED)
# include_directories(${Boost_INCLUDE_DIR})

# Usage: create_unmade <file1>...
# creates files if they don't exist. Starts looking in the directory of the CMakeLists.txt file it's called in
function(create_unmade)
    foreach(word ${ARGV}) # ${ARGV} expands to all arguments
        if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${word})
            message("---- creating: ${word} ----")
            file(WRITE ${word} "")
        endif()
    endforeach()
endfunction()

# Usage: add_proj <name> <file1>...
# creates a simple project from files. Files are placed in a folder called name
function(add_proj name)
    foreach(word ${ARGN})  # ${ARGN} expands to all unexpected arguments
        set(word src/${name}/${word}) # prefix every filename with the project name
        set(Files_To_Make ${Files_To_Make} ${word})
    endforeach()
    create_unmade(${Files_To_Make})
    source_group(${name}_Files FILES ${Files_To_Make})
    add_executable(${name} ${Files_To_Make})
    # Add a data directory for each project
    target_compile_definitions(${name} PUBLIC DATA_DIR=${CMAKE_SOURCE_DIR}/data/${name})
    file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/data/${name})
    # target_link_libraries(${name} ${Boost_Libraries})
endfunction()

if(WIN32)
    add_proj(ScreenShotDimensions ScreenShotDimensions.cpp)
    add_proj(ScreenShot ScreenShot.cpp)
    add_proj(KeyLogger main.cpp)
elseif(APPLE)
    add_proj(MacScreenshot MacScreenshot.cpp)
endif()

add_proj(Algorithms main.cpp)

add_proj(Timer Timer.cpp Timer.h main.cpp)

add_proj(Date main.cpp)

add_proj(Primes main.cpp)

add_proj(Files main.cpp)

add_proj(PerfectForwarding PerfectForwarding.cpp)

add_proj(HigherFunctions HigherFunctions.cpp)

add_proj(AnonNamespace AnonNamespace.cpp Header.h Header.cpp)

add_proj(Random Random.cpp)

add_proj(System System.cpp)

add_proj(BinaryCalc BinaryCalc.cpp StringFunctions.h)

add_proj(SeeWhitespace SeeWhitespace.cpp Function.h)

add_proj(UniquePtr UniquePtr.cpp)

add_proj(LogMacro LogMacro.cpp)

add_proj(Restrict Restrict.cpp)

add_proj(FunctionDef ezmukszik.h ezmukszik.cpp main.cpp)

add_proj(AStar main.cpp)

add_proj(Vectors main.cpp)

add_proj(TypeChecking main.cpp)

add_proj(CurDir main.cpp)

add_proj(ass4check main.cpp)

add_proj(variadic main.cpp)

add_proj(Unsigned_Interp main.cpp)

add_proj(Accumulate main.cpp)

# add_proj(Boost_Hello main.cpp)

add_proj(ClassMemberInit main.cpp)

add_proj(DoublyLinkedList main.cpp)

add_proj(Array_Time main.cpp)

add_proj(AStarEasy main.cpp)

add_proj(DATA_DIR_test main.cpp)
