# #############################################################################
# Main CMake file
#
# TODO make .c files PRIVATE, some .h PRIVATE too and the remaining .h files PUBLIC
#   - PRIVATE: src would be added to target.
#   - PUBLIC: src would be added to target and all targets that link to target.
#   - INTERFACE: src would not be added to target but all targets that link to target.
#
# #############################################################################

cmake_minimum_required(VERSION 3.13.0)

# variables
set(PROJECT_CMAKE_SCRIPT_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/cmakefiles/")

# Toolchain settings
include(${PROJECT_CMAKE_SCRIPT_FOLDER}project_toolchain.cmake)

# Project settings
include(${PROJECT_CMAKE_SCRIPT_FOLDER}project_info.cmake)
if(NOT PROJECT_VERSION_TWEAK)
    set(PROJECT_TEMP_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
else()
    set(PROJECT_TEMP_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK})
endif()

project(${TARGET_NAME}
    VERSION ${PROJECT_TEMP_VERSION}
    DESCRIPTION ${TARGET_DESCRIPTION}
    #HOMEPAGE_URL "https://example.com"
    LANGUAGES CXX
)


# #############################################################################
message("")
message("###############################################################################")
message("Building: " ${CMAKE_PROJECT_NAME} " v" ${PROJECT_TEMP_VERSION} " (" ${OS_FOUND} ")")
message("")


# #############################################################################

# include cmake files
include(${PROJECT_CMAKE_SCRIPT_FOLDER}project_source_folders.cmake)

include(${PROJECT_CMAKE_SCRIPT_FOLDER}project_options.cmake)

# Add the defines to the target
if (NOT DEFINED ${DEFS})
    target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC ${DEFS})
endif()

# Add the defines to the target
#include(${PROJECT_CMAKE_SCRIPT_FOLDER}project_defines.cmake)

# Link the used libraries to the target
#include(${PROJECT_CMAKE_SCRIPT_FOLDER}project_libs.cmake)

# #############################################################################
# linked include paths
if (ENABLE_VERBOSE)
    message("###############################################################################")
    message("    INCLUDES:")
    get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
    foreach(dir ${dirs})
        message("               " ${dir})
    endforeach()
    message("###############################################################################")
    message("")
endif()

# #############################################################################
# links (???)
if (ENABLE_VERBOSE)
    message("###############################################################################")
    message("    LINKS:")
    get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY LINK_DIRECTORIES)
    foreach(dir ${dirs})
        message("               " ${dir})
    endforeach()
    message("###############################################################################")
    message("")
endif()
