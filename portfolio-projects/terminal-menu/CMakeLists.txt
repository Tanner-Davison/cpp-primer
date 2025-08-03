cmake_minimum_required(VERSION 3.15)
project(terminal-menu)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for clangd/LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files found in project
set(SOURCES
    main.cpp
)

# Header files found in project
set(HEADERS
    # Add your headers here as you create them
    # e.g., TerminalMenu.hpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../headers # For Anscii.hpp
)

# Compiler-specific options
if(MSVC)
    # MSVC-specific flags
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    # GCC/Clang flags (your current setup)
    target_compile_options(${PROJECT_NAME} PRIVATE 
        -Wall 
        -Wextra 
        -g 
        -O0
    )
endif()

# Platform-specific libraries
if(WIN32)
    # Windows libraries for your console/window functions
    target_link_libraries(${PROJECT_NAME} PRIVATE 
        gdi32 
        user32
        # Add other Windows libs as needed
        # winmm      # For multimedia functions
        # kernel32   # Usually auto-linked
    )
elseif(UNIX AND NOT APPLE)
    # Linux-specific libraries if needed
    # target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
elseif(APPLE)
    # macOS-specific libraries if needed
    # target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
endif()

# Debug/Release configurations
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG=1)
    message(STATUS "Building in Debug mode")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE NDEBUG=1)
    if(NOT MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE -O3)
    endif()
    message(STATUS "Building in Release mode")
endif()

# Optional: Enable more warnings for better code quality
if(NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        # -Werror  # Treat warnings as errors (uncomment when ready)
    )
endif()

# Print some useful info
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")

# Optional: Copy resources or additional files
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.txt 
#      DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Optional: Install target (for make install)
# install(TARGETS ${PROJECT_NAME} 
#         RUNTIME DESTINATION bin)
