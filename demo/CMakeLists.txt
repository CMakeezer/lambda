set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/euler.cpp)

add_executable(demo_lambda ${SRC})

target_link_libraries(demo_lambda)
target_include_directories(demo_lambda PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../lib)

add_custom_target(demo
                  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/demo_lambda
                  COMMENT "Run demo!"
                  USES_TERMINAL
                  DEPENDS demo_lambda)
