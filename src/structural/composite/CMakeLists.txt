# #############################################################################
# Subdir: /src/structural/composite/
# #############################################################################

target_sources(${TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/composite.cpp
)

### Target options
target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../includes>
        #$<INSTALL_INTERFACE:includes>
)
