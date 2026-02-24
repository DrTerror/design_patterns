# #############################################################################
# CMake option file
# #############################################################################

# verbosity
option(ENABLE_VERBOSE                       "Enable detailed cmake informations"    ON)

# features/targets
option(ENABLE_TARGET_BEHAVIORAL             "Enable creating the behavioral target" ON)
option(ENABLE_TARGET_CREATIONAL             "Enable creating the creational target" OFF)
option(ENABLE_TARGET_STRUCTURAL             "Enable creating the structural target" OFF)

option(ENABLE_PROJECT_WARNINGS_AS_ERRORS    "Elevate some warnings to errors"       OFF)



# Propagate the option to this target as a preprocessor define
#target_compile_definitions(MyProj_alpha
#  PUBLIC          # Or PRIVATE; PUBLIC propagates to dependents
#    $<$<BOOL:${ENABLE_FEATURE}>:ENABLE_FEATURE>
#)

# Alternatively, if you want a specific value (0/1)
#target_compile_definitions(MyProj_alpha
#  PUBLIC ENABLE_FEATURE=$<IF:$<BOOL:${ENABLE_FEATURE}>,1,0>
#)
