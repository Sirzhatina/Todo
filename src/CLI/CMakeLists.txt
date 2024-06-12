set(TARGET Todo.CLI)

set(SOURCES
    main.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)