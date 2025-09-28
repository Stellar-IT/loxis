cmake_minimum_required(VERSION 3.26)
project(loxis LANGUAGES CXX)

# Force C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Calculate architecture suffix
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" ARCH_LOWER)

if(ARCH_LOWER MATCHES "^(x86_64|amd64)$")
    set(ARCH_SUFFIX "64")
elseif(ARCH_LOWER MATCHES "^(i[3-6]86)$")
    set(ARCH_SUFFIX "32")
elseif(ARCH_LOWER MATCHES "^(armv7|armv7l|arm)$")
    set(ARCH_SUFFIX "arm32")
elseif(ARCH_LOWER MATCHES "^(aarch64)$")
    set(ARCH_SUFFIX "arm64")
else()
    set(ARCH_SUFFIX "${ARCH_LOWER}")
endif()

# Set output directories
#set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build/${ARCH_SUFFIX}/${CMAKE_BUILD_TYPE}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${ARCH_SUFFIX}")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${ARCH_SUFFIX}")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${ARCH_SUFFIX}")

# Set build dir
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build/${ARCH_SUFFIX}/${CMAKE_BUILD_TYPE}")

# Prepare options for external libs to be used
include(FetchContent)

set(EXTERNAL_INSTALL_DIR "${CMAKE_BINARY_DIR}/external/${ARCH_SUFFIX}")
set(EXTERNAL_BUILD_DIR "${CMAKE_BINARY_DIR}/external/build/${ARCH_SUFFIX}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external")

list(PREPEND CMAKE_PREFIX_PATH "${PROJECT_BINARY_DIR}/external/${ARCH_SUFFIX}/lib/cmake")
set(ENV{PKG_CONFIG_PATH} "${PROJECT_BINARY_DIR}/external/${ARCH_SUFFIX}/lib/pkgconfig")

# Option to build documentation
option(BUILD_DOCS "Build documentation" OFF)

# Option to build tests
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_DOCS)
    # Find Doxygen
    find_package(Doxygen REQUIRED)

    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is required to build the documentation")
    else()
        message(STATUS "Found Doxygen: ${DOXYGEN_EXECUTABLE}")
    endif()

    # Check for Graphviz dot
    find_program(GRAPHVIZ_DOT_EXECUTABLE dot)

    if(NOT GRAPHVIZ_DOT_EXECUTABLE)
        message(FATAL_ERROR "Graphviz (dot) not found. It is required to build documentation.")
    else()
        message(STATUS "Found Graphviz: ${GRAPHVIZ_DOT_EXECUTABLE}")
    endif()

    # configure Doxygen
#    set(DOXYGEN_GENERATE_HTML YES)
#    set(DOXYGEN_GENERATE_LATEX NO)
#    set(DOXYGEN_DOT_EXECUTABLE "${GRAPHVIZ_DOT_EXECUTABLE}")

    set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)
    set(DOXYGEN_DOT_EXECUTABLE "${GRAPHVIZ_DOT_EXECUTABLE}")

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )

#    doxygen_add_docs(
#        docs
#        ${CMAKE_SOURCE_DIR}/loxis
#    )
endif()

if(BUILD_TESTS)
    include(external/gtest.cmake)
    find_package(GTest 1.17.0 EXACT REQUIRED)

    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory("loxis")