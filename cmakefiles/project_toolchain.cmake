# #############################################################################
# CMake toolchain file
# #############################################################################

# Detect OS, ...
#if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(OS_FOUND "Linux")
    message( STATUS "OS check: Linux found" )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(OS_FOUND "MacOS")
    message( SEND_ERROR "unsupportet OS (yet)!" )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(OS_FOUND "Windows")
    message( STATUS "OS check: Windows found" )
else()
    # TODO
    execute_process(COMMAND uname OUTPUT_VARIABLE uname)
    if (uname MATCHES "^MSYS" OR uname MATCHES "^MINGW")
        message("This is MSYS")
    else()
        message("This is not MSYS")
        endif()

    message("CMAKE_SYSTEM_NAME-name=${CMAKE_SYSTEM_NAME}, CMAKE_HOST_SYSTEM_NAME=${CMAKE_HOST_SYSTEM_NAME}")
    set(OS_FOUND "unknown")
endif()


# create compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# #############################################################################
# Verbose messages
if (ENABLE_VERBOSE)
    message("###############################################################################")
    message("CMAKE_SOURCE_DIR:      " ${CMAKE_SOURCE_DIR})
    message("CMAKE_BINARY_DIR:      " ${CMAKE_BINARY_DIR})
    message("COMPILER SETTING:")
    message("    BUILD TYPE:        " ${CMAKE_BUILD_TYPE})
    message("CMAKE_C_COMPILER:      " ${CMAKE_C_COMPILER})
    message("        C FLAGS:       " ${CMAKE_C_FLAGS})
    message("CMAKE_CXX_COMPILER:    " ${CMAKE_CXX_COMPILER})
    message("        CXX FLAGS:     " ${CMAKE_CXX_FLAGS})
    message("-------------------------------------")
    message("CMAKE_AR:              " ${CMAKE_AR})
    message("CMAKE_ASM_COMPILER:    " ${CMAKE_ASM_COMPILER})
    message("CMAKE_LINKER:          " ${CMAKE_LINKER})
    message("CMAKE_OBJCOPY:         " ${CMAKE_OBJCOPY})
    message("CMAKE_RANLIB:          " ${CMAKE_RANLIB})
    message("    DEFINES:")
    foreach(def ${COMP_DEFS_STR})
        message("               " ${def})
    endforeach()
    message("    LINKED LIBRARIES:")
    foreach(lib ${LINKED_LIBS_STR})
        message("               " ${lib})
    endforeach()
    message("###############################################################################")
    message("")
endif()
