set(TARGET Todo.CLI)

set(SOURCES
    main.cpp
)

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)

target_link_libraries(${TARGET} Boost::program_options)
# target_link_libraries(${TARGET} Todo.Core)