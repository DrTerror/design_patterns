# #############################################################################
# Submodule: common_header_collection
# #############################################################################

set(TARGET_NAME common_headers)
add_library(${TARGET_NAME} INTERFACE)

### Target options

#target_compile_features(${TARGET_NAME}
#    PUBLIC
#        cxx_std_20
#)

#target_compile_definitions(${TARGET_NAME} PRIVATE define)

target_include_directories(${TARGET_NAME}
    INTERFACE
        #${CMAKE_CURRENT_SOURCE_DIR}
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        #$<INSTALL_INTERFACE:includes>
)
