set(PARSER_SOURCES parser.cc parser.h)

add_library(parser STATIC ${PARSER_SOURCES})
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ipc main.cc)
target_link_libraries(ipc PRIVATE parser)