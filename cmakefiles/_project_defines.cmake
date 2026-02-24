# #############################################################################
# CMake defines file
# #############################################################################

target_compile_definitions(${CMAKE_PROJECT_NAME}
    PUBLIC
)

# Get all defines used by this build
get_target_property(COMP_DEFS ${CMAKE_PROJECT_NAME} COMPILE_DEFINITIONS)


# #############################################################################
# Verbose messages
if (ENABLE_VERBOSE)
    message("###############################################################################")
    message("    DEFINES:")
    foreach(def ${COMP_DEFS})
        message("               " ${def})
    endforeach()
    message("###############################################################################")
    message("")
endif()
