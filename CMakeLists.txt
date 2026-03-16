cmake_minimum_required(VERSION 3.15)
project("ssmi" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "" FORCE)

add_executable(ssmi WIN32 src/main.cpp)
# if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     target_link_libraries(ssmi PRIVATE "-lstdc++exp")
# endif()

target_include_directories(ssmi PRIVATE ${CMAKE_SOURCE_DIR}/ext/cppcodec)
