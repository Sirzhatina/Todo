set(TARGET Todo.Core)

set(SOURCES 
    IClient.hpp
    AbstractCommand.cpp
    AbstractCommand.hpp
    AddCommand.hpp
)

add_library(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} Boost::program_options)