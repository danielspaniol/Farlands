#include "farlands/graphics/window.hpp"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glog/logging.h>

namespace farlands {

Window::Window(GlCtx &gl) : m_gl{gl} {
  LOG(INFO) << "Create GLFW window";

  m_handle = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);
  if (!m_handle) {
    LOG(ERROR) << "Failed to create GLFW window";
    exit(ExitCode::ERR_GFX);
  }

  glfwMakeContextCurrent(m_handle);
  m_gl.init_glad();

  glViewport(0, 0, WIDTH, HEIGHT);
  glfwSetFramebufferSizeCallback(
      m_handle, [](auto, auto w, auto h) { glViewport(0, 0, w, h); });
}

Window::~Window() {}

auto Window::is_open() const -> bool {
  return !glfwWindowShouldClose(m_handle);
}

auto Window::update_input() -> void { glfwPollEvents(); }

auto Window::update_output() -> void {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glfwSwapBuffers(m_handle);
}

} // namespace farlands
