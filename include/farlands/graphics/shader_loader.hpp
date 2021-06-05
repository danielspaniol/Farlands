#pragma once

#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/graphics/shader.hpp"

#include <string>

namespace farlands {

class ShaderLoader {
public:
  explicit ShaderLoader(GlCtx &) {}

  Shader load_from_file(ShaderName name);
  Shader load_from_string(ShaderName name, ShaderSrc vertex,
                          ShaderSrc fragment);

private:
  std::string load_text(std::string file);
};

} // namespace farlands