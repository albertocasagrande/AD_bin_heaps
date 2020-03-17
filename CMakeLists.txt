cmake_minimum_required(VERSION 2.56)
project(libbinheap)

set( DESCRIPTION "libbinheap - A simple array-based implementation of binary heaps" )

set( CMAKE_BUILD_TYPE "Release" )

# project version
set( PROJECT_MAJOR_VERSION 0  )
set( PROJECT_MINOR_VERSION 0  ) 
set( PROJECT_PATCH_LEVEL 1  )

set( PROJECT_LIB_NAME libbinheap )

IF(NOT DEFINED ${CMAKE_INSTALL_PREFIX})
set(CMAKE_INSTALL_PREFIX "/usr")
ENDIF(NOT DEFINED ${CMAKE_INSTALL_PREFIX})

set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)

set( TESTS_SRC_DIR "${PROJECT_SOURCE_DIR}/tests" )
SET( LIB_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
SET( LIB_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

include_directories ("${LIB_INCLUDE_DIR}")

FILE (GLOB PROJ_INCLUDES "${LIB_INCLUDE_DIR}/*.h")
FILE (GLOB SOURCES "${LIB_SRC_DIR}/*.c")

message("BOH" ${LIB_SRC_DIR})

add_library(${PROJECT_LIB_NAME} SHARED 
	    ${SOURCES} 
            ${PROJ_INCLUDES})

target_link_libraries (${PROJECT_LIB_NAME} )

install (TARGETS ${PROJECT_LIB_NAME} 
	LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR})

link_directories(${LINK_DIRS})
include_directories(${INCLUDE_DIRS} ) 

include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include" )

set( EXECUTABLE "test_bin_heap")
FILE (GLOB TEST_SOURCES "${TESTS_SRC_DIR}/*.c"
	                "${TESTS_SRC_DIR}/*.h")
add_executable(${EXECUTABLE} ${TEST_SOURCES})

target_link_libraries(${EXECUTABLE} ${PROJECT_LIB_NAME})

install( TARGETS ${EXECUTABLE} 
            RUNTIME DESTINATION ${BINARY_INSTALL_DIR} 
            LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR} )

include( InstallRequiredSystemLibraries )


