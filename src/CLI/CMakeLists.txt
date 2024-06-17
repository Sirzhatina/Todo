set(TARGET Todo.CLI)

set(SOURCES
    main.cpp
    Client.hpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)