cmake_minimum_required(VERSION 3.2)

project(project)
# 指定 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(USE_ASAN 1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(src SOURCES)

aux_source_directory(test MAIN)
add_executable(
    project

    ${SOURCES}
    ${MAIN}
)
if(${USE_ASAN})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") 
endif()
