cmake_minimum_required(VERSION 2.6)

add_subdirectory(vendors/logger)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glew/build/cmake)

add_definitions(-D_DEBUG -DIMGUI_IMPL_OPENGL_LOADER_GLEW)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(header
    vendors/glew/include
    vendors/glfw/include
    vendors/logger
    vendors/glm
    vendors/imgui
    vendors/stb_image
    test/header)

list(APPEND source_files
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/gui.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/core.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/texture.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/renderer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/application.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/vertex_array.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/index_buffer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/vertex_buffer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/shader_program.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/vertex_buffer_layout.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/stb_image/stb_image.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_menu.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_clear_color.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_texture.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_polygon.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_interpolation.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_triangle_01_01.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_triangle_01_02.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_triangle_01_03.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_polygon_01_01.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_polygon_01_02.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/test/source/test_polygon_01_03.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/imgui/imgui.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/imgui/imgui_demo.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/imgui/imgui_draw.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/imgui/imgui_impl_glfw.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/imgui/imgui_impl_opengl3.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vendors/imgui/imgui_widgets.cpp"
    )

add_executable(OpenGLTest ${source_files})
if(WIN32)
target_link_libraries(OpenGLTest logger glew glfw opengl32)
endif(WIN32)
if(UNIX)
target_link_libraries(OpenGLTest logger glew glfw GL)
endif(UNIX)


