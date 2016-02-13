cmake_minimum_required (VERSION 2.6)

# Project meta informations
project (OODuck)
set (OODUCK_AUTHOR "David Delassus <david.jose.delassus@gmail.com>")
set (OODUCK_PACKAGE_NAME "OODuck")
set (OODUCK_VERSION_MAJOR 0)
set (OODUCK_VERSION_MINOR 4)
set (OODUCK_VERSION_PATCH 1)
set (OODUCK_LICENSE "MIT")

# Build configuration
set (CMAKE_C_FLAGS "--std=c99 -Wall -O2")

if (WITH_PTHREAD)
    set (CMAKE_C_FLAGS "-DHAVE_PTHREAD -DE4C_THREADSAFE -lpthread")
endif (WITH_PTHREAD)

if (WITH_DEBUG)
    set (CMAKE_BUILD_TYPE DEBUG)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
else (WITH_DEBUG)
    set (CMAKE_BUILD_TYPE RELEASE)
endif (WITH_DEBUG)

message ("!! Build type: ${CMAKE_BUILD_TYPE}")
message ("!! CFLAGS: ${CMAKE_C_FLAGS}")

configure_file (
    "${PROJECT_SOURCE_DIR}/src/config.h.in"
    "${PROJECT_BINARY_DIR}/generated/ooduck/config.h"
)

include_directories (
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/generated"
)

add_library (ooduck SHARED
    "${PROJECT_SOURCE_DIR}/src/asprintf.c"
    "${PROJECT_SOURCE_DIR}/src/e4c.c"
    "${PROJECT_SOURCE_DIR}/src/exceptions.c"
    "${PROJECT_SOURCE_DIR}/src/object.c"
    "${PROJECT_SOURCE_DIR}/src/singleton.c"
    "${PROJECT_SOURCE_DIR}/src/value.c"
    "${PROJECT_SOURCE_DIR}/src/string.c"
    "${PROJECT_SOURCE_DIR}/src/iterable.c"
    "${PROJECT_SOURCE_DIR}/src/collection.c"
    "${PROJECT_SOURCE_DIR}/src/hashmap.c"
)

if (WITH_DEBUG)
    add_executable (ooduck-example "${PROJECT_SOURCE_DIR}/test/main.c")
    target_link_libraries (ooduck-example ooduck)

    enable_testing()
    add_test (ooduck-test ooduck-example)
endif (WITH_DEBUG)

# Deployment configuration

install (TARGETS ooduck DESTINATION lib)

set (HEADERS
    "${PROJECT_BINARY_DIR}/generated/ooduck/config.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/asprintf.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/e4c.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/exceptions.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/define.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/object.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/object.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/object.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/singleton.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/singleton.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/singleton.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/value.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/value.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/value.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/string.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/string.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/string.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/iterable.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/iterable.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/iterable.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/collection.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/collection.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/collection.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/hashmap.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_defs/hashmap.h"
    "${PROJECT_SOURCE_DIR}/include/ooduck/_priv/hashmap.h"
)

install (FILES ${HEADERS} DESTINATION include/ooduck)