cmake_minimum_required(VERSION 3.22)

project(Study)

# 设置 C++ 标准为 C++20（如果需要）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(USE_ASAN 1)
# 收集源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE MAIN "test/*.cpp")

# 添加可执行文件
add_executable(study_exec ${SOURCES} ${MAIN})

# 包含头文件路径
target_include_directories(study_exec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# AddressSanitizer 配置
if(USE_ASAN)
    target_compile_options(study_exec PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    target_link_options(study_exec PRIVATE -fsanitize=address)
endif()

# 如果有其他依赖库或配置，可以在这里添加