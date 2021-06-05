#include "farlands/graphics/gl_ctx.hpp"

#include "farlands/prelude.hpp"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glog/logging.h>

namespace farlands {

bool GlCtx::sm_initialized = false;

GlCtx::GlCtx() {
  if (sm_initialized) {
    LOG(WARNING) << "Tried to create multiple OpenGL contexts";
    return;
  }

  init_glfw();
  sm_initialized = true;
}

GlCtx::~GlCtx() {
  terminate_glfw();
  terminate_glad();
}

auto GlCtx::init_glfw() -> void {
  LOG(INFO) << "Initialize global GLFW contex";

  glfwSetErrorCallback([](i32 code, cstrref msg) {
    LOG(ERROR) << "GLFW failure (" << code << "): " << msg;
  });

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

auto GlCtx::init_glad() -> void {
  LOG(INFO) << "Initialize global GLAD contex";

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    LOG(ERROR) << "Failed to initialize GLAD";
    exit(ExitCode::ERR_GFX);
  }
}

auto GlCtx::terminate_glfw() -> void {
  LOG(INFO) << "Terminate global GLFW contex";
}

auto GlCtx::terminate_glad() -> void {
  LOG(INFO) << "Terminate global GLAD contex";
}

} // namespace farlands