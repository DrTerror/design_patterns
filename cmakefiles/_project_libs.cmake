# #############################################################################
# CMake library file
# #############################################################################

### add os specific libs
if(${OS_FOUND} STREQUAL "Linux")
    # add everything to the target
    target_link_libraries(${CMAKE_PROJECT_NAME}
        pthread # for threads
        #rt # for real time
    )
elseif(${OS_FOUND} STREQUAL "Windows")
    # add everything to the target
    target_link_libraries(${CMAKE_PROJECT_NAME}
        #pthread # for threads
        #rt # for real time
    )
else()
    # unknown or unsupportet OS
     message( FATAL_ERROR "unknown or unsupportet OS!" )
endif()


### add general libs
target_link_libraries(${CMAKE_PROJECT_NAME}
    PUBLIC
        #pthread
        # pq

    PRIVATE
)

# Get all libraries used by this build
get_target_property(LINKED_LIBS ${CMAKE_PROJECT_NAME} LINK_LIBRARIES)


# #############################################################################
# Verbose messages
if (ENABLE_VERBOSE)
    message("###############################################################################")
    message("    LINKED LIBRARIES:")
    foreach(lib ${LINKED_LIBS})
        message("               " ${lib})
    endforeach()
    message("###############################################################################")
    message("")
endif()