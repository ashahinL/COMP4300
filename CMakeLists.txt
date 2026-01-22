cmake_minimum_required(VERSION 3.22)

project(comp4300 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(APP "lecture01" CACHE STRING "App to build/run")
set_property(CACHE APP PROPERTY STRINGS lecture01 lecture02_imgui assignment01)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SFML_STATIC_LIBRARIES OFF)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

if(APP STREQUAL "lecture03")
    set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
    if(NOT EXISTS ${IMGUI_DIR}/imgui.h)
        message(FATAL_ERROR "ImGui not found at ${IMGUI_DIR}. Clone it into external/imgui.")
    endif()

    set(BUILD_SHARED_LIBS ON)

    add_subdirectory(${CMAKE_SOURCE_DIR}/external/imgui-sfml external/imgui-sfml-build)

    add_executable(lecture03 apps/lecture03/main.cpp)
    target_link_libraries(lecture03 PRIVATE ImGui-SFML::ImGui-SFML SFML::Graphics SFML::Window SFML::System)
    target_compile_definitions(lecture03 PRIVATE SFML_STATIC=0)
    add_custom_target(run
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lecture03
        DEPENDS lecture03
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
elseif(APP STREQUAL "assignment01")
    set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
    if(NOT EXISTS ${IMGUI_DIR}/imgui.h)
        message(FATAL_ERROR "ImGui not found at ${IMGUI_DIR}. Clone it into external/imgui.")
    endif()

    set(BUILD_SHARED_LIBS ON)

    add_subdirectory(${CMAKE_SOURCE_DIR}/external/imgui-sfml external/imgui-sfml-build)

    add_executable(assignment01 
        apps/assignment01/main.cpp
        apps/assignment01/SegmentedShape.cpp
        apps/assignment01/Rect.cpp
    )
    target_include_directories(assignment01 PRIVATE apps/assignment01)
    target_link_libraries(assignment01 PRIVATE ImGui-SFML::ImGui-SFML SFML::Graphics SFML::Window SFML::System)
    target_compile_definitions(assignment01 PRIVATE SFML_STATIC=0)
    add_custom_target(run
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assignment01
        DEPENDS assignment01
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
elseif(APP STREQUAL "lecture04")
    set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
    if(NOT EXISTS ${IMGUI_DIR}/imgui.h)
        message(FATAL_ERROR "ImGui not found at ${IMGUI_DIR}. Clone it into external/imgui.")
    endif()

    set(BUILD_SHARED_LIBS ON)

    add_subdirectory(${CMAKE_SOURCE_DIR}/external/imgui-sfml external/imgui-sfml-build)

    add_executable(lecture04 
        apps/lecture04/main.cpp
        apps/lecture04/Entity.cpp
        apps/lecture04/Component.cpp
    )
    target_include_directories(lecture04 PRIVATE apps/lecture04)
    target_link_libraries(lecture04 PRIVATE ImGui-SFML::ImGui-SFML SFML::Graphics SFML::Window SFML::System)
    target_compile_definitions(lecture04 PRIVATE SFML_STATIC=0)
    add_custom_target(run
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lecture04
        DEPENDS lecture04
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
else()
    message(FATAL_ERROR "Unknown APP: ${APP}. Use one of: lecture03, assignment01, lecture04")
endif()