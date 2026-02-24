# #############################################################################
# Subdir: /src/behavioral
# #############################################################################

# create target (as object)
set(TARGET_NAME behavioral)
add_library(${TARGET_NAME} OBJECT)

option(ENABLE_FEATURE_CHAIN_OF_RESPONSIBILITY   "Enable feature/target chain_of_responsibility" OFF)
option(ENABLE_FEATURE_COMMAND                   "Enable feature/target command"                 OFF)
option(ENABLE_FEATURE_INTERPRETER               "Enable feature/target interpreter"             OFF)
option(ENABLE_FEATURE_ITERATOR                  "Enable feature/target iterator"                OFF)
option(ENABLE_FEATURE_MEDIATOR                  "Enable feature/target mediator"                ON)
option(ENABLE_FEATURE_MEMENTO                   "Enable feature/target memento"                 OFF)
option(ENABLE_FEATURE_OBSERVER                  "Enable feature/target observer"                OFF)
option(ENABLE_FEATURE_STATE                     "Enable feature/target state"                   OFF)
option(ENABLE_FEATURE_STRATEGY                  "Enable feature/target strategy"                OFF)
option(ENABLE_FEATURE_TEMPLATE_METHOD           "Enable feature/target template_method"         OFF)
option(ENABLE_FEATURE_VISITOR                   "Enable feature/target visitor"                 OFF)

# Add subdirectories
if(ENABLE_FEATURE_CHAIN_OF_RESPONSIBILITY)
    add_subdirectory(chain_of_responsibility)
endif()
if(ENABLE_FEATURE_COMMAND)
    add_subdirectory(command)
endif()
if(ENABLE_FEATURE_INTERPRETER)
    add_subdirectory(interpreter)
endif()
if(ENABLE_FEATURE_ITERATOR)
    add_subdirectory(iterator)
endif()
if(ENABLE_FEATURE_MEDIATOR)
    add_subdirectory(mediator)
endif()
if(ENABLE_FEATURE_MEMENTO)
    add_subdirectory(memento)
endif()
if(ENABLE_FEATURE_OBSERVER)
    add_subdirectory(observer)
endif()
if(ENABLE_FEATURE_STATE)
    add_subdirectory(state)
endif()
if(ENABLE_FEATURE_STRATEGY)
    add_subdirectory(strategy)
endif()
if(ENABLE_FEATURE_TEMPLATE_METHOD)
    add_subdirectory(template_method)
endif()
if(ENABLE_FEATURE_VISITOR)
    add_subdirectory(visitor)
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
