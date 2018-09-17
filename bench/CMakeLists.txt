set(BENCHMARKS ${CMAKE_CURRENT_SOURCE_DIR}/bench_lambda.cpp)

add_executable(bench_lambda ${BENCHMARKS})

target_link_libraries(bench_lambda benchmark::benchmark)
target_include_directories(bench_lambda PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../lib)

add_custom_target(perf
                  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/bench_lambda
                  COMMENT "Build & Run Benchmarks"
                  USES_TERMINAL
                  DEPENDS bench_lambda)
