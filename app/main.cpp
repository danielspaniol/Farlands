#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/graphics/window.hpp"

#include <glog/logging.h>

using namespace farlands;

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  LOG(INFO) << "Starting application";

  GlCtx gl;
  Window window{gl};

  while (window.is_open()) {
    window.update_input();
    window.update_output();
  }

  LOG(INFO) << "Stopping application";
}
