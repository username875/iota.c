#[[
Copyright (c) 2019 IOTA Stiftung
https://github.com/iotaledger/iota.c

Refer to the LICENSE file for licensing information
]]

cmake_minimum_required(VERSION 3.15)

project(iota_client DESCRIPTION "IOTA Client Library")

enable_language(C)
enable_testing()

option(IOTA_TESTS "Enable IOTA Client library test cases" ON)
option(IOTA_ASAN_ENABLED "Enable Address sanitizer" OFF)
option(ENABLED_JEMALLOC "Enable jemalloc memory allocator" OFF)

# fetch external libs
include(ExternalProject)

include(cmake/unity.cmake)
include(cmake/cjson.cmake)
include(cmake/uthash.cmake)
include(cmake/sodium.cmake)
include(cmake/base58.cmake)

if(ENABLED_JEMALLOC)
  include(cmake/jemalloc.cmake)
endif()

if(IOTA_ASAN_ENABLED)
  if(UNIX AND (CMAKE_BUILD_TYPE STREQUAL "Debug" OR NOT CMAKE_BUILD_TYPE))
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
      add_compile_options("-fsanitize=address,undefined,unsigned-integer-overflow"
        "-fno-omit-frame-pointer"
        "-fsanitize-address-use-after-scope"
        "-fno-sanitize-recover=undefined,unsigned-integer-overflow"
      )
      add_link_options("-fsanitize=address,undefined")
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
      add_compile_options("-fsanitize=address,undefined"
        "-fno-omit-frame-pointer"
        "-fsanitize-address-use-after-scope"
        "-fno-sanitize-recover=undefined"
      )
      add_link_options("-fsanitize=address,undefined")
    endif()
  else()
    message(WARNING "Sanitizer is not supported on Windows or Release build")
  endif()
endif()

find_package(CURL REQUIRED)

# links libraries in the sandbox
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

add_subdirectory(src)

if(IOTA_TESTS)
  add_subdirectory(tests)
endif()
