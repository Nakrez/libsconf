# Unitary test : hash

enable_testing()

add_definitions(-Wall -Wextra -std=c99 -pedantic -I../../include)
add_executable(hash
               EXCLUDE_FROM_ALL
               ../../src/hash_map.c
               hash.c)

ADD_TEST(ctest_build_hash "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target hash)
ADD_TEST(ctest_run_hash hash)
