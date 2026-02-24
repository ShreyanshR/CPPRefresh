cmake_minimum_required(VERSION 3.15)

find_package(GTest CONFIG QUIET)

if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/*_test.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp"
)

add_executable(
  lru_cache_tests
  ${TEST_SOURCES}
  ${CMAKE_SOURCE_DIR}/src/LRUCacheSimple.cpp
)

target_include_directories(lru_cache_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(lru_cache_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lru_cache_tests)
