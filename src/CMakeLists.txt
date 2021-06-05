set(PROJECT_LIB_SRC
    graphics/gl_ctx.cpp
    graphics/shader.cpp
    graphics/shader_loader.cpp
    graphics/window.cpp
    meshs/triangle_mesh.cpp
    prelude.cpp
)

add_library(${PROJECT_LIB_NAME} ${PROJECT_LIB_SRC})
target_include_directories(${PROJECT_LIB_NAME} PUBLIC ../include)
target_link_libraries(${PROJECT_LIB_NAME} glog::glog glfw glad)
target_set_warnings(${PROJECT_LIB_NAME} ENABLE ALL)