cmake_minimum_required(VERSION 3.16.3...3.17.0)
project(test VERSION 1.0 DESCRIPTION "Very nice project" LANGUAGES CXX)
set(SOURCES main.cpp)
link_directories(${PROJECT_SOURCE_DIR}/third_party/SFML-2.5.1/lib)
add_executable ( ${PROJECT_NAME} ${SOURCES} )
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/third_party/SFML-2.5.1/include)
add_definitions(-DSFML_STATIC)
target_link_libraries(${PROJECT_NAME}  sfml-window-s  sfml-graphics-s  sfml-audio-s sfml-system-s opengl32 winmm gdi32 freetype)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/images"
    ${EXECUTABLE_OUTPUT_PATH}/images)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/images"
    ${CMAKE_CURRENT_BINARY_DIR}/images)