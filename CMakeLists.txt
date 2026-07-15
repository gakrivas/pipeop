cmake_minimum_required(VERSION 4.2)
project(pipeop CXX)

set(CMAKE_CXX_STANDARD 23)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 14)
    message(FATAL_ERROR
        "This project uses std::ranges::to, views::zip, views::chunk_by, views::join_with "
        "and <print>, which need GCC 14+ (found GCC ${CMAKE_CXX_COMPILER_VERSION}). "
        "Reconfigure with -DCMAKE_CXX_COMPILER=g++-14.")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 17)
    message(FATAL_ERROR
        "This project uses std::ranges::to, views::zip, views::chunk_by, views::join_with "
        "and <print>, which need Clang 17+ with libc++ (found Clang ${CMAKE_CXX_COMPILER_VERSION}). "
        "Reconfigure with -DCMAKE_CXX_COMPILER=clang++-17 (or newer).")
endif()

# 1. Fetch GoogleTest from GitHub
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows/MSVC compatibility, prevent overriding the parent project's compiler settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



#find_package(GTest REQUIRED)

add_executable(pipeop main.cpp src/pipeop.cpp)
target_include_directories(pipeop PRIVATE include)

add_executable(run_unit_tests test_main.cpp tests/pipeop_tests.cpp src/pipeop.cpp)
target_link_libraries(run_unit_tests PRIVATE
        gmock           # The core Google Mock library
        gtest           # The core Google Test library
        gtest_main      # The library that provides the main() function for tests
)

target_include_directories(run_unit_tests PRIVATE include ${GTEST_INCLUDE_DIRS})
enable_testing()
add_test(NAME AllTests COMMAND run_unit_tests)

