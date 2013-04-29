# Unitary test : list

enable_testing()

add_definitions(-Wall -Wextra -std=c99 -pedantic -I../../include)
add_executable(list
               EXCLUDE_FROM_ALL
               ../../src/list.c
               list.c)

ADD_TEST(ctest_build_list "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target list)
ADD_TEST(ctest_run_list list)
