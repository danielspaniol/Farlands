#include "farlands/graphics/shader_loader.hpp"

#include "farlands/prelude.hpp"

#include <GLAD/glad.h>
#include <glog/logging.h>

#include <fstream>
#include <sstream>

namespace farlands {

Shader ShaderLoader::load_from_file(ShaderName name) {
  std::stringstream base_path;
  base_path << "res/shaders/" << name;

  auto vertex_path = base_path.str() + ".vs";
  auto fragment_path = base_path.str() + ".fs";

  LOG(INFO) << "Loading shaders '" << vertex_path << "' and '" << fragment_path
            << "'";

  auto vertex_src = load_text(vertex_path);
  auto fragment_src = load_text(fragment_path);

  return load_from_string(name, vertex_src.c_str(), fragment_src.c_str());
}

std::string ShaderLoader::load_text(std::string file) {
  std::ifstream stream{file};
  std::stringstream text;
  if (stream.bad()) {
    LOG(ERROR) << "Unable to laod '" << file << "'";
    exit(ExitCode::ERR_RES);
  }
  stream >> text.rdbuf();
  return text.str();
}

Shader ShaderLoader::load_from_string(ShaderName name, ShaderSrc vertex,
                                      ShaderSrc fragment) {
  Shader shader{name};
  shader.compile(vertex, fragment);
  return shader;
}

} // namespace farlands