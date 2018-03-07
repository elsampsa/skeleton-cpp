## A skeleton CMake, (C) 2018 Sampsa Riikonen
# #
# cmake .
# make
## (or make VERBOSE=1)
##
##
##
## *** Here we are creating a shared library ***
## - The shared library comes with a test suite = small test executables
## - The shared library encapsulates statically compiled libraries (in this example, at the demo_dep/ directory)
## - The shared library depends on another shared library (in this example, it is the "sqlite3" library)

cmake_minimum_required(VERSION 3.1)
find_package(PkgConfig REQUIRED)

project(skeleton)

## **** INPUT VARIABLES ****

## verbosity, etc. switches with this formula:
option(verbose "verbose" OFF)
if    (verbose)
  add_definitions("-DVERBOSE")
  message("VERBOSE ENABLED")
endif (verbose)

## string (directories, etc) with this formula:
option(demo_root "demo_root" "")
SET(DEMO_ROOT ${demo_root})

# ***************************************************************************
## WARNING: the following three lines are modified by the "setver.bash" script
SET(MAJOR_VERSION "0") 
SET(MINOR_VERSION "1") 
SET(PATCH_VERSION "0") 
## ***************************************************************************
set(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

## [some directory definitions]
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

## compiler flags
add_compile_options("-std=c++14" "-pthread")

## [define library source files]
file(GLOB SOURCES src/*.cpp)

## [we're compiling a library here..]
add_library(${PROJECT_NAME} SHARED ${SOURCES})

## [define library header files]
target_include_directories(${PROJECT_NAME} PUBLIC include)

## [set our version]
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${VERSION_STRING} SOVERSION ${MAJOR_VERSION})

## ****** Static libraries (archive files ".a") encapsulated in the current shared library ******
## 
## So, the shared library we're currently building here, depends on some other libraries.  We have compiled those other libraries ourselves and want to include them
## as static code (without external dependencies) into our shared library.  
##
message("USING STATICALLY COMPILED DEMO LIBRARY")
message("DEMO LIBRARY ROOT: ${DEMO_ROOT}")

## The statically compiled library we're encapsulating here into our library, might have some dependencies on some elemental libraries
## In the case the static library would depend on, say, x11, glew and alsa, you would use:
# pkg_search_module(X11 REQUIRED x11)
# pkg_search_module(GLEW REQUIRED glew)
# pkg_search_module(ALSA REQUIRED alsa)
## header file location
# target_include_directories(${PROJECT_NAME} PUBLIC ${X11_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
## link time dependencies
# target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES} ${GLEW_LIBRARIES} ${ALSA_LIBRARIES})
## *******************************************************************************

## define header file location (you have installed this by yourself)
target_include_directories(${PROJECT_NAME} PUBLIC "${DEMO_ROOT}")
## define where the .a files are to be found (you have compiled this by yourself)
target_link_libraries(${PROJECT_NAME} "-L${DEMO_ROOT}")
## link time dependencies
target_link_libraries(${PROJECT_NAME} "rt")
target_link_libraries(${PROJECT_NAME} "-Wl,--allow-multiple-definition" "-Wl,-Bsymbolic" "-Wl,--start-group" "-Wl,--whole-archive")
target_link_libraries(${PROJECT_NAME} ":demo.a") # you could have a whole list of .a files here
target_link_libraries(${PROJECT_NAME} "-Wl,--no-whole-archive" "-Wl,--end-group")
##
## **************************************************************************************************
  

## ****** System provided shared libraries.  Our library will depend on them dynamically ************
message("USING SYSTEM PROVIDED SHARED LIBRARY FOR SQLITE3")
## In this demo, our library will depend dynamically on the sqlite3 library.  Install that into your system with: sudo apt-get install libsqlite3-dev
pkg_search_module(SQLITE REQUIRED sqlite3)
## define header file location
target_include_directories(${PROJECT_NAME} PUBLIC ${SQLITE_INCLUDE_DIRS})
## link time dependencies
target_link_libraries(${PROJECT_NAME} ${SQLITE_LIBRARIES})
# **************************************************************************************************
  

## *** test programs ***
## use the script "test/list.bash" to update this list
set(TESTNAMES "test1" "test2")

add_custom_target(tests)
foreach( testname ${TESTNAMES} )
  add_executable(${testname} "test/${testname}.cpp") 
  
  ## we're using our libraries header files, of course:
  target_include_directories(${testname} PUBLIC "include")
  
  target_link_libraries(${testname} ${SQLITE_LIBRARIES})
  
  ## we're linking the tests against our library
  target_link_libraries(${testname} "${PROJECT_NAME}")
  
  add_dependencies(tests ${testname}) # tests dependencies on the executable
  add_dependencies(${testname} ${PROJECT_NAME}) # test depends on libValkka
endforeach( testname ${TESTNAMES} )

## *** packaging ***
exec_program(dpkg ARGS --print-architecture OUTPUT_VARIABLE MY_ARCH)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_PACKAGE_NAME ${PROJECT_NAME})

SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
SET(CPACK_PACKAGE_VERSION "${VERSION_STRING}")

SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${MY_ARCH})
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libgcc1(>= 1:6.0.1), libc6(>= 2.23), libsqlite3(>= 3.11.0)") # ubuntu 16

##
## objdump -p libXXXXX.so
## dpkg -S libc.so.6
## => libc6:amd64: /lib/x86_64-linux-gnu/libc.so.6
## apt-cache show libc6 | grep "Version"
## => Version: 2.23-0ubuntu9
## a typical dependency seems to be: libc6 (>= 2.17)

SET(CPACK_PACKAGE_CONTACT "your.email@your.domain")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Your description")
SET(CPACK_DEBIAN_PACKAGE_RECOMMENDS "")
SET(CPACK_DEBIAN_PACKAGE_SUGGESTS "")

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib) # install the shared library

## install header files for the developers:

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include" DESTINATION "${PROJECT_NAME}" FILES_MATCHING PATTERN "*.h") # install header files
## The install command: https://cmake.org/cmake/help/v3.0/command/install.html

## include header files from the statically built library
install(DIRECTORY "${DEMO_ROOT}" DESTINATION "${PROJECT_NAME}" FILES_MATCHING PATTERN "*.h*")

## check your package with:
## dpkg --contents package_name.deb

## This must always be last!
INCLUDE(CPack)
