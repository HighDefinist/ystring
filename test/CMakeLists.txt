# Test list
set (TESTS_C11 
  simple
)

# Enable coverage testing
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
if(CMAKE_COMPILER_IS_GNUCXX)
  include(CodeCoverage)
  setup_target_for_coverage(setup_coverage ystring_test coverage)
endif()  
if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
endif()

# Enable testing
include(CTest)
enable_testing()

# Include tests
foreach (test ${TESTS_C11})
  add_executable(${test} ${test}/${test}.cpp)
  target_compile_features(${test} INTERFACE cxx_std_11)
  add_test(test_${test} ${test})
endforeach()


