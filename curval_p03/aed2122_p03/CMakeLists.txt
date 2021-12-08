cmake_minimum_required(VERSION 3.10)
project(aed2122_p03)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aed2122_p03 main.cpp Tests/tests.cpp Tests/funSearchProblem.cpp)

target_link_libraries(aed2122_p03 gtest gtest_main)

# Doxygen Build
set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
if(NOT EXISTS "${BUILD_DOC_DIR}")
    file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
endif()
set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
message("Doxygen build started")
add_custom_target(Doxygen ALL
        COMMAND "C:/Portable/doxygen/doxygen.exe" "${DOXYGEN_OUT}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
