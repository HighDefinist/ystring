cmake_minimum_required (VERSION 3.1)
project("mz_ystring")
# Setup as header-only library for parent cmake project
add_library(${PROJECT_NAME} INTERFACE)
set (CMAKE_CXX_STANDARD 11)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)

# Only include tests and example, if there is no parent cmake project
get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
  # Include example
  include_directories(${PROJECT_SOURCE_DIR}/include)
  include_directories(${PROJECT_SOURCE_DIR}/include_extra)
  add_executable(ystring example/simple/ystr.cpp)
  target_compile_features(ystring INTERFACE cxx_std_11)

  # Enable coverage testing
  add_executable(ystring_test test/basic/ystr_test.cpp)
  set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
  if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(setup_coverage ystring_test coverage)
  endif()  
  if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
  endif()

  # Include test
  include(CTest)
  enable_testing()
  target_compile_features(ystring_test INTERFACE cxx_std_11)
  add_test(Test_basic ystring_test)
endif()
 
 
