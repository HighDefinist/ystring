cmake_minimum_required (VERSION 3.1)
project("mz_ystring")
add_library(${PROJECT_NAME} INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)
get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
  include_directories(${PROJECT_SOURCE_DIR}/include)
  include_directories(${PROJECT_SOURCE_DIR}/include_extra)
  add_executable(ystring example/simple/ystr.cpp)
  add_executable(ystring_test test/basic/ystr_test.cpp)
  enable_testing()
  add_test(NAME ystring_test COMMAND ystring_test)
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
 
 