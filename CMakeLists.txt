cmake_minimum_required(VERSION 3.15)
project(endless)
set(SFML_DIR "C:/SFML-3-install/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio)
add_executable(endless endless.cpp endless.h)

# Debug: Print paths
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "Target file dir will be: $<TARGET_FILE_DIR:endless>")

add_custom_command(TARGET endless POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:endless>/assets
    COMMENT "Copying assets to build directory"
    VERBATIM
)

target_compile_definitions(endless PRIVATE SFML_STATIC)
target_link_libraries(endless PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Window  
    SFML::System
    opengl32
    winmm
    gdi32
    user32
    kernel32
    ole32
    advapi32
    shell32
)
set_target_properties(endless PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)