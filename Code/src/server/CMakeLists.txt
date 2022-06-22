add_executable(server main.cpp)
target_include_directories(server PUBLIC ${PROJECT_SOURCE_DIR}/external/asio/asio/include)