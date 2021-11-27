cmake_minimum_required(VERSION 3.21.1)
project(MyAgent VERSION 0.1.0)

include(CPack)

# Main application component
add_subdirectory(myagent)

# Entry executable
add_executable(
    MyAgentMain
    main.c
)

target_include_directories(MyAgentMain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/myagent/include)
target_link_libraries(MyAgentMain PUBLIC MyAgentLib)
