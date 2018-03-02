cmake_minimum_required (VERSION 3.1)
project("mz_ystring")
add_library(${PROJECT_NAME} INTERFACE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)
get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
  include_directories(${PROJECT_SOURCE_DIR}/include)
  include_directories(${PROJECT_SOURCE_DIR}/include_extra)
  add_executable(ystring example/simple/ystr.cpp)
  add_executable(ystring_test test/basic/ystr_test.cpp)
  target_compile_features(ystring INTERFACE cxx_std_11)
  


  # Setting default folders
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  # In CMakeModules I include code coverage for c++
  set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

  if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(Example_coverage ystring_test coverage)
  endif()  

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")

  include(CTest)
  enable_testing()
  target_compile_features(ystring_test INTERFACE cxx_std_11)
  add_test(Test_basic ystring_test)


  #add_custom_target(check 
        #${CMAKE_COMMAND} -E echo CWD=${CMAKE_BINARY_DIR}
        #COMMAND ${CMAKE_COMMAND} -E echo CMD=${CMAKE_CTEST_COMMAND} -C $<CONFIG>
        #COMMAND ${CMAKE_COMMAND} -E echo ----------------------------------
        #COMMAND ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1
            #${CMAKE_CTEST_COMMAND} -C $<CONFIG>
    #WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    #DEPENDS ALL_BUILD
    #)  
endif()
 
 
