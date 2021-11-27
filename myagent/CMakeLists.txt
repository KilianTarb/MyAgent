add_library(
    MyAgentLib
    ./src/AgentError.c
    ./src/AgentService.c
)

target_include_directories(MyAgentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
