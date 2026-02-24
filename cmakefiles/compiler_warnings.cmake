# #############################################################################
# CMake warnings file
#
# How to use:
# - include into target cmake file and
#   include(${CMAKE_SOURCE_DIR}/cmakefiles/compiler_warnings.cmake)
# - call the function
#   set_project_warnings
#
# #############################################################################

function(set_project_warnings target)
    # for gcc and clang
    set(warnings_gcc_clang
        -Wall
        -Wextra
        #-Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wshadow
        -Wdouble-promotion
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wstack-usage=2048
    )
    if (ENABLE_PROJECT_WARNINGS_AS_ERRORS)
        set(warnings_gcc_clang "${warnings_gcc_clang} -Werror")
    endif()
    # for clang only
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(warnings_gcc_clang "${warnings_gcc_clang} -Wnewline-eof")
    endif()

    # elevate some warnings to errors
    set(warnings_gcc_clang_warn2err
        -Werror=maybe-uninitialized
        -Werror=uninitialized
        -Werror=sign-compare
        -Werror=tautological-compare
        -Werror=type-limits
        -Werror=return-type
        -Werror=unused-value
        -Werror=unused-function
        -Werror=format-truncation
        -Werror=address
        -Werror=sizeof-pointer-div
    )
    set(warnings_gcc_clang "${warnings_gcc_clang} ${warnings_gcc_clang_warn2err}")

    # for msvc
    set(warnings_msvc
        /W4
        /permissive-
        /EHsc
        /w14242
        /w14254
        /w14263
        /w14265
        /w14287
        /we4289
        /w14296
        /w14311
        /w14545
        /w14546
        /w14547
        /w14549
        /w14555
        /w14619
        /w14640
        /w14826
        /w14905
        /w14906
        /w14928
    )
    if (ENABLE_PROJECT_WARNINGS_AS_ERRORS)
        set(warnings_msvc "${warnings_msvc} /WX")
    endif()

    target_compile_options(${target}
        PRIVATE
            $<$<CXX_COMPILER_ID:GNU,Clang>:${warnings_gcc_clang}>
            $<$<CXX_COMPILER_ID:AppleClang>:${warnings_gcc_clang}>
            $<$<CXX_COMPILER_ID:MSVC>:${warnings_msvc}>
    )
endfunction()
