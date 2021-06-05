#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/graphics/shader.hpp"
#include "farlands/graphics/shader_loader.hpp"
#include "farlands/graphics/window.hpp"

#include <glog/logging.h>

using namespace farlands;

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  LOG(INFO) << "Starting application";

  GlCtx gl;
  Window window{gl};
  ShaderLoader shader_loader{gl};

  auto default_shader = shader_loader.load_from_file("default");

  while (window.is_open()) {
    default_shader.use();

    window.update_input();
    window.update_output();
  }

  LOG(INFO) << "Stopping application";
}
