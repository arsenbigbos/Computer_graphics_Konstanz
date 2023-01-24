cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

set(PROJECT_NAME "introduction")
project(${PROJECT_NAME} LANGUAGES CXX)

# Source files
list(APPEND HEADERS "src/container.h")
list(APPEND HEADERS "src/container.h")
list(APPEND HEADERS "src/memory.h")
list(APPEND HEADERS "src/passing.h")
list(APPEND HEADERS "src/polygon.h")
list(APPEND HEADERS "src/compile_and_link.h")

list(APPEND SOURCES "src/container.cpp")
list(APPEND SOURCES "src/container.cpp")
list(APPEND SOURCES "src/main.cpp")
list(APPEND SOURCES "src/memory.cpp")
list(APPEND SOURCES "src/passing.cpp")
list(APPEND SOURCES "src/polygon.cpp")
list(APPEND SOURCES "src/compile_and_link.cpp")

source_group(${PROJECT_NAME}\\headers FILES ${HEADERS})
source_group(${PROJECT_NAME}\\sources FILES ${SOURCES})

# Executable
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
