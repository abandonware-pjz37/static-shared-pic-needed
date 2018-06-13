cmake_minimum_required(VERSION 3.2)
project(foo)

add_library(foo foo.cpp foo.hpp)
add_library(boo STATIC boo.cpp boo.hpp)

# This one needed for BUILD_SHARED_LIBS=ON
# set_target_properties(boo PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

set(generated_headers "${CMAKE_CURRENT_BINARY_DIR}/generated_headers")
set(foo_export "${generated_headers}/FOO_EXPORT.h")
include(GenerateExportHeader)
generate_export_header(foo EXPORT_FILE_NAME ${foo_export})

target_include_directories(
    boo
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<BUILD_INTERFACE:${generated_headers}>
)

target_link_libraries(foo PUBLIC boo)
