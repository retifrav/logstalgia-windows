cmake_minimum_required(VERSION 3.10)

project("logstalgia" VERSION 1.1.2)
message("Project name: " ${CMAKE_PROJECT_NAME})

set("tools-path" "d:/programs")
set(CMAKE_INSTALL_PREFIX "${tools-path}/${CMAKE_PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

find_library(SDL2 SDL2 PATHS "${tools-path}/sdl/lib/x64" NO_DEFAULT_PATH)
find_library(SDL2main SDL2main PATHS "${tools-path}/sdl/lib/x64" NO_DEFAULT_PATH)
find_library(SDL2_image SDL2_image PATHS "${tools-path}/sdl/sdl-image/lib/x64" NO_DEFAULT_PATH)
find_library(freetype freetype PATHS "${tools-path}/freetype/win64" NO_DEFAULT_PATH)
find_library(libpng libpng16 PATHS "${tools-path}/libpng/lib" NO_DEFAULT_PATH)
find_library(GLEW glew32 PATHS "${tools-path}/glew/lib/Release/x64" NO_DEFAULT_PATH)
find_library(PCRE pcre PATHS "${tools-path}/pcre/lib" NO_DEFAULT_PATH)

include_directories(
    "${tools-path}/boost"
    "${tools-path}/glm/include"
    "${tools-path}/glew/include"
    "${tools-path}/sdl/include"
    "${tools-path}/sdl/sdl-image/include"
    "${tools-path}/freetype/include"
    "${tools-path}/libpng/include"
    "${tools-path}/pcre/include"
    )

set(sources
    src/custom.cpp
    src/logentry.cpp
    src/logstalgia.cpp
    src/main.cpp
    src/ncsa.cpp
    src/paddle.cpp
    src/requestball.cpp
    src/settings.cpp
    src/slider.cpp
    src/summarizer.cpp
    src/textarea.cpp
    src/tests.cpp
    src/configwatcher.cpp
    src/core/conffile.cpp
    src/core/display.cpp
    src/core/frustum.cpp
    src/core/fxfont.cpp
    src/core/logger.cpp
    src/core/plane.cpp
    src/core/png_writer.cpp
    src/core/ppm.cpp
    src/core/quadtree.cpp
    src/core/regex.cpp
    src/core/resource.cpp
    src/core/sdlapp.cpp
    src/core/seeklog.cpp
    src/core/settings.cpp
    src/core/shader.cpp
    src/core/shader_common.cpp
    src/core/stringhash.cpp
    src/core/texture.cpp
    src/core/timezone.cpp
    src/core/vbo.cpp
    src/core/vectors.cpp
    )

add_executable(${CMAKE_PROJECT_NAME} ${sources})
target_link_libraries(${CMAKE_PROJECT_NAME}
    ${OPENGL_gl_LIBRARY}
    ${GLEW}
    ${SDL2}
    ${SDL2main}
    ${SDL2_image}
    ${freetype}
    ${libpng}
    ${PCRE}
    -lglu32
    -static-libgcc
    -static-libstdc++
    -lcomdlg32
    )

install(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}"
    )
install(DIRECTORY "data" DESTINATION "${CMAKE_INSTALL_PREFIX}")
