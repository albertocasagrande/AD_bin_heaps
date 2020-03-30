cmake_minimum_required(VERSION 2.56)
project(binheap)

set( DESCRIPTION "libbinheap - A simple array-based implementation of binary heaps" )

set( CMAKE_BUILD_TYPE "Release" )

# project version
set( PROJECT_MAJOR_VERSION 0  )
set( PROJECT_MINOR_VERSION 0  ) 
set( PROJECT_PATCH_LEVEL 1  )

set( PROJECT_LIB_NAME binheap )

set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)

set( TESTS_SRC_DIR "${PROJECT_SOURCE_DIR}/tests" )
set( TESTS_COMMON_SRC_DIR "${TESTS_SRC_DIR}/common" )
SET( LIB_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
SET( LIB_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

include_directories ("${LIB_INCLUDE_DIR}")

FILE (GLOB PROJ_INCLUDES "${LIB_INCLUDE_DIR}/*.h")
FILE (GLOB SOURCES "${LIB_SRC_DIR}/*.c")

add_library(${PROJECT_LIB_NAME} SHARED 
            ${SOURCES} 
            ${PROJ_INCLUDES})

SET(${LIB_REQUIRED_LIBRARIES} "")

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  # If your system is a Linux system, then try to detect if librt is 
  # required, i.e.,  glibc < 2.17 || glibc = 2.29
  
  include(CheckCXXSourceCompiles)
  set(CLOCK_GETTIME_TEST
    "
    #include <time.h>
    int main() {
      clock_gettime(CLOCK_REALTIME, NULL);
      return 0;
    }
    "
  )
  check_cxx_source_compiles( "${CLOCK_GETTIME_TEST}" 
                             LIBRT_IS_NOT_REQUIRED )
  if (NOT LIBRT_IS_NOT_REQUIRED)
    # ch
    message(STATUS "libc doesn't contain clock_gettime()")
    set(CMAKE_REQUIRED_LIBS_OLD "${CMAKE_REQUIRED_LIBRARIES}")
    set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBRARIES} rt")
	check_cxx_source_compiles( "${CLOCK_GETTIME_TEST}" 
                               LIBRT_CONTAINS_CLOCK_GETTIME)
    set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBS_OLD}")
    if (LIBRT_CONTAINS_CLOCK_GETTIME)
      list(APPEND LIB_REQUIRED_LIBRARIES "rt")
    else()
      message(FATAL_ERROR "librt (required to get clock_gettime()) cannot be linked")
    endif()
  endif()
endif()

target_link_libraries (${PROJECT_LIB_NAME} ${LIB_REQUIRED_LIBRARIES})
set_property(TARGET ${PROJECT_LIB_NAME} PROPERTY C_STANDARD 99)
set_target_properties(${PROJECT_LIB_NAME} PROPERTIES 
	                   PUBLIC_HEADER "${PROJ_INCLUDES}")

install (TARGETS ${PROJECT_LIB_NAME} 
	LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR}
	PUBLIC_HEADER DESTINATION ${INCLUDE_INSTALL_DIR})

link_directories(${LINK_DIRS})
include_directories(${INCLUDE_DIRS} ) 

include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include" )

FILE (GLOB TESTS_COMMON_SOURCES "${TESTS_COMMON_SRC_DIR}/*.c"
	                            "${TESTS_COMMON_SRC_DIR}/*.h")
add_library("common" ${TESTS_COMMON_SOURCES})
target_link_libraries("common" ${PROJECT_LIB_NAME})
set_property(TARGET "common" PROPERTY C_STANDARD 99)

set( EXECUTABLES "test_delete_min" "test_insert")
foreach( EXECUTABLE ${EXECUTABLES} )
   add_executable(${EXECUTABLE} "${TESTS_SRC_DIR}/${EXECUTABLE}.c")
   target_link_libraries(${EXECUTABLE} ${PROJECT_LIB_NAME} "common")
   set_property(TARGET ${EXECUTABLE} PROPERTY C_STANDARD 99)
endforeach( EXECUTABLE ${EXECUTABLES} )

include( InstallRequiredSystemLibraries )


