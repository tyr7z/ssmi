cmake_minimum_required(VERSION 3.12)
project("ssmi" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(ssmi WIN32 src/main.cpp)
# if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     target_link_libraries(ssmi PRIVATE "-lstdc++exp")
# endif()
set_target_properties(ssmi PROPERTIES PREFIX "")
