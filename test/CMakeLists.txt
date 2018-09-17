
set(TESTS ${CMAKE_CURRENT_SOURCE_DIR}/test_bind.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/test_dollar.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/test_curry.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/test_maybe.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/test_show.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/test_stream.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/test_lambda.cpp)

add_executable(test_lambda ${TESTS})

target_link_libraries(test_lambda GTest::GTest GTest::Main ${GMOCK_BOTH_LIBRARIES})
target_include_directories(test_lambda PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../lib)

add_custom_target(verify
                  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_lambda
                  COMMENT "Build & Run Tests"
                  USES_TERMINAL
                  DEPENDS test_lambda)
