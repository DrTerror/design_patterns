# #############################################################################
# Subdir: /src/
# #############################################################################

# source files in main folder
set(TARGET_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Define the execuable
add_executable(${CMAKE_PROJECT_NAME} ${TARGET_SOURCES})

# Target options
#target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE define)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
#target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
#target_compile_options()

### libraries/objects/interfaces to link
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE common_headers)

# Optionally link feature libs when enabled
if(ENABLE_TARGET_BEHAVIORAL)
    add_subdirectory(behavioral)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE behavioral)
endif()
if(ENABLE_TARGET_CREATIONAL)
    add_subdirectory(creational)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE creational)
endif()
if(ENABLE_TARGET_STRUCTURAL)
    add_subdirectory(structural)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE structural)
endif()

# Generate the config header into the build tree
configure_file(
    ${PROJECT_CMAKE_SCRIPT_FOLDER}/ins/config_defines.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/includes/generated/config_defines.hpp
    @ONLY
)
