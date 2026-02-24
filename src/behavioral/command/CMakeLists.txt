# #############################################################################
# Subdir: /src/behavioral/command/
# #############################################################################

# add sources
target_sources(${TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/command.cpp
)

### Target options
target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../includes>
        #$<INSTALL_INTERFACE:includes>
)
