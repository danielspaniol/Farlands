FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(glfw)

add_library(glad ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/external/glad/include)