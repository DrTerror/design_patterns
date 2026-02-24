# #############################################################################
# CMake config file
#
# How to use:
# - include into target cmake file and
#   include(${CMAKE_SOURCE_DIR}/cmakefiles/compiler_config.cmake)
# - call the function
#   set_compiler_config
#
# #############################################################################

function(set_compiler_config target)
    # for gcc and clang
    set(config_release_gcc_clang -O3)
    set(config_release_with_debug_gcc_clang -O2 -g0 -s)
    set(config_debug_gcc_clang -O0 -g3)

    set(config_release_with_debug_msvc /O2)
    set(config_debug_msvc /O0)

    target_compile_options(${target}
        PRIVATE
            $<$<CONFIG:Release>:>
            $<$<CONFIG:Release>:$<$<CXX_COMPILER_ID:GNU,Clang>:${config_release_gcc_clang}>>
            $<$<CONFIG:RelWithDebInfo>:$<$<CXX_COMPILER_ID:GNU,Clang>:${config_release_with_debug_gcc_clang}>>
            $<$<CONFIG:Debug>:$<$<CXX_COMPILER_ID:GNU,Clang>:${config_debug_gcc_clang}>
            $<$<CONFIG:RelWithDebInfo>:$<$<CXX_COMPILER_ID:MSVC>:${config_release_with_debug_msvc}>>
            $<$<CONFIG:Debug>:$<$<CXX_COMPILER_ID:MSVC>:${config_debug_msvc}>
    )
endfunction()
