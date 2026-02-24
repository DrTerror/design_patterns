# #############################################################################
# Subdir: /src/creational
# #############################################################################

# create target (as object)
set(TARGET_NAME creational)
add_library(${TARGET_NAME} OBJECT)

option(ENABLE_FEATURE_FACTORY_METHOD    "Enable feature/target factory_method"      OFF)
option(ENABLE_FEATURE_ABSTRACT_FACTORY  "Enable feature/target abstract_factory"    OFF)
option(ENABLE_FEATURE_BUILDER           "Enable feature/target builder"             OFF)
option(ENABLE_FEATURE_PROTOTYPE         "Enable feature/target prototype"           OFF)
option(ENABLE_FEATURE_SINGLETON         "Enable feature/target singleton"           OFF)

# Add subdirectories
if(ENABLE_FEATURE_FACTORY_METHOD)
    add_subdirectory(factory_method)
endif()
if(ENABLE_FEATURE_ABSTRACT_FACTORY)
    add_subdirectory(abstract_factory)
endif()
if(ENABLE_FEATURE_BUILDER)
    add_subdirectory(builder)
endif()
if(ENABLE_FEATURE_PROTOTYPE)
    add_subdirectory(prototype)
endif()
if(ENABLE_FEATURE_SINGLETON)
    add_subdirectory(singleton)
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
