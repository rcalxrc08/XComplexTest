project(xcomplex_tests)
include_directories(${GTEST_SOURCE_DIR} "../adept" "../xcomplex/include")
file(GLOB xcomplex_TEST_SRC "../tests/*.cpp")
add_executable(test_xcomplex ${xcomplex_TEST_SRC})
target_link_libraries(test_xcomplex LINK_PUBLIC gtest_main xcomplex)
