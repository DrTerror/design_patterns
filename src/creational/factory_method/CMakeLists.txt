# #############################################################################
# Subdir: /src/creational/factory_method/
# #############################################################################

target_sources(${TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/factory_method.cpp
)

### Target options
target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../includes>
        #$<INSTALL_INTERFACE:includes>
)
