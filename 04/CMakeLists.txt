cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

set(PROJECT_NAME "exercise_04")
project(${PROJECT_NAME} LANGUAGES CXX)

include(CgConfigFile)

list(APPEND LIBRARIES cg)

# Source files
list(APPEND SOURCES "src/main.cpp")

source_group(${PROJECT_NAME}\\headers FILES ${HEADERS})
source_group(${PROJECT_NAME}\\sources FILES ${SOURCES})

# Executable
cg_add_config_file()
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})


target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
