# #############################################################################
# Subdir: /src/structural
# #############################################################################

# create target (as object)
set(TARGET_NAME structural)
add_library(${TARGET_NAME} OBJECT)

option(ENABLE_FEATURE_ADAPTER       "Enable feature/target adapter"     OFF)
option(ENABLE_FEATURE_BRIDGE        "Enable feature/target bridge"      OFF)
option(ENABLE_FEATURE_COMPOSITE     "Enable feature/target composite"   OFF)
option(ENABLE_FEATURE_DECORATOR     "Enable feature/target decorator"   OFF)
option(ENABLE_FEATURE_FACADE        "Enable feature/target facade"      OFF)
option(ENABLE_FEATURE_FLYWEIGHT     "Enable feature/target flyweight"   OFF)
option(ENABLE_FEATURE_PROXY         "Enable feature/target proxy"       OFF)

# Add subdirectories
if(ENABLE_FEATURE_ADAPTER)
    add_subdirectory(adapter)
endif()
if(ENABLE_FEATURE_BRIDGE)
    add_subdirectory(bridge)
endif()
if(ENABLE_FEATURE_COMPOSITE)
    add_subdirectory(composite)
endif()
if(ENABLE_FEATURE_DECORATOR)
    add_subdirectory(decorator)
endif()
if(ENABLE_FEATURE_FACADE)
    add_subdirectory(facade)
endif()
if(ENABLE_FEATURE_FLYWEIGHT)
    add_subdirectory(flyweight)
endif()
if(ENABLE_FEATURE_PROXY)
    add_subdirectory(proxy)
endif()

#target_compile_features(feature_a PUBLIC cxx_std_20)
#target_compile_definitions(${TARGET_NAME} PRIVATE <define=0>)

target_link_libraries(${TARGET_NAME}
    PRIVATE
        common_headers
)

target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
