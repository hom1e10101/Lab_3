cmake_minimum_required(VERSION 3.14)
project(Three)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

set(MAIN_SOURCE
    src/main.cpp
)

set(LIB_SOURCES
    src/Figure.cpp
    src/Hexagon.cpp
    src/Pentagon.cpp
    src/Point.cpp
    src/Rhomb.cpp
    src/Vector_figures.cpp
)

add_executable(geometry_figures ${MAIN_SOURCE} ${LIB_SOURCES} ${HEADERS})
target_include_directories(geometry_figures PRIVATE include)
target_compile_features(geometry_figures PRIVATE cxx_std_20)

set(TEST_SOURCES
    tests/test_Hexagon.cpp
    tests/test_Pentagon.cpp
    tests/test_Rhomb.cpp
    tests/main_test.cpp
    tests/test_Vector.cpp
)

add_executable(run_tests ${TEST_SOURCES} ${LIB_SOURCES})

target_include_directories(run_tests PRIVATE include)
target_compile_features(run_tests PRIVATE cxx_std_20)
target_link_libraries(run_tests PRIVATE GTest::gtest_main)

enable_testing()
add_test(NAME GeometryTests COMMAND run_tests)
