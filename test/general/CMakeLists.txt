# Unitary test : hash

enable_testing()

add_definitions(-Wall -Wextra -std=c99 -pedantic -I../../include)
add_executable(main
               EXCLUDE_FROM_ALL
               main.c)

target_link_libraries(main libsconf)

ADD_TEST(ctest_build_main "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target main)
ADD_TEST(ctest_run_main main)
