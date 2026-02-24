## Core target‑based commands

- Compile options (warning flags, dialect switches, optimizations):
    ```CMake
    target_compile_options(<tgt> [PRIVATE|PUBLIC|INTERFACE] ...options...)
    ```
- Compile definitions (preprocessor macros):
    ```CMake
    target_compile_definitions(<tgt> [PRIVATE|PUBLIC|INTERFACE] ...definitions...)
    ```
- Include directories:
    ```CMake
    target_include_directories(<tgt> [PRIVATE|PUBLIC|INTERFACE] ...dirs...)
    ```
- Link options (linker flags):
    ```CMake
    target_link_options(<tgt> [PRIVATE|PUBLIC|INTERFACE] ...options...)
    ```
- Language standard (preferred, target‑level):
    ```CMake
    target_compile_features(<tgt> PUBLIC cxx_std_20)
    ```

### Visibility scopes
 - `PRIVATE`: applies only to this target.
 - `PUBLIC`: applies to this target and propagates to dependents.
 - `INTERFACE`: does not apply to this target’s compilation, but propagates to dependents (useful for header-only or externally enforced requirements).

## Per‑compiler and per‑config flags (generator expressions)
Use generator expressions `($<...>)` to apply flags conditionally:
```CMake
target_compile_options(my_lib PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<CONFIG:Release>:$<$<CXX_COMPILER_ID:GNU,Clang>:-O3>>
    $<$<CONFIG:RelWithDebInfo>:$<$<CXX_COMPILER_ID:MSVC>:/O2>>
)
```
### Common config expressions:
 - `$<CONFIG:Debug> # or RelWithDebInfo|Release|MinSizeRel`
 - `$<CXX_COMPILER_ID:GNU> # or Clang|AppleClang|MSVC`
 - `$<BOOL:${VAR}> # for boolean cache/options`

## Linker

### Linker flags per compiler
```CMake
target_link_options(my_app PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang>:-Wl,--as-needed>
  $<$<CXX_COMPILER_ID:MSVC>:/INCREMENTAL:NO>
)
```

### Whole‑program optimization / LTO (portable property)
```CMake
set_property(TARGET my_lib PROPERTY INTERPROCEDURAL_OPTIMIZATION
  $<CONFIG:Release,RelWithDebInfo>)
```

### Sanitizers (clang/gcc)
```CMake
set(ENABLE_ASAN ON CACHE BOOL "Enable AddressSanitizer")
if (ENABLE_ASAN)
  target_compile_options(my_app PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-fsanitize=address -fno-omit-frame-pointer>)
  target_link_options(my_app    PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-  target_link_options(my_app    PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-fsanitize=address>)
```
