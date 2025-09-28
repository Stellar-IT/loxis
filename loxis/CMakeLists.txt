set(SERIALIZATION_SOURCES
    serialization/message_header.cpp
)

set(SERIALIZATION_HEADERS
    serialization/serialization_types.h
    serialization/message_header.h
)

# Static library
add_library(loxis_serialization_static STATIC
    ${SERIALIZATION_SOURCES} ${SERIALIZATION_HEADERS}
)
target_include_directories(loxis_serialization_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/serialization)

# Shared library
add_library(loxis_serialization_shared SHARED
    ${SERIALIZATION_SOURCES} ${SERIALIZATION_HEADERS}
)
target_include_directories(loxis_serialization_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/serialization)

# Give them the same alias "loxis::serialization"
add_library(loxis::serialization_static ALIAS loxis_serialization_static)
add_library(loxis::serialization_shared ALIAS loxis_serialization_shared)
