#include "farlands/graphics/shader.hpp"

#include <GLAD/glad.h>
#include <glog/logging.h>

#include <GLM/gtc/type_ptr.hpp>

namespace farlands {

static const GLenum SHADER_TYPE[] = {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER};
static const ShaderName SHADER_NAME[] = {"vertex", "fragment"};
static constexpr usize LOG_SIZE = 512;

Shader::Shader(ShaderName name) : m_name{name}, m_id{glCreateProgram()} {}

Shader::~Shader() {
  LOG(INFO) << "Deleting shader '" << m_name << "'";
  glDeleteProgram(m_id);
}

auto Shader::compile(ShaderSrc vertex, ShaderSrc fragment) -> void {
  auto vertex_id = compile_shader(vertex, ShaderType::VERTEX);
  auto fragment_id = compile_shader(fragment, ShaderType::FRAGMENT);

  link_program(vertex_id, fragment_id);

  glDeleteShader(vertex_id);
  glDeleteShader(fragment_id);
}

auto Shader::compile_shader(ShaderSrc src, ShaderType type) -> ShaderId {
  const auto idx = static_cast<usize>(type);
  const auto gl_type = SHADER_TYPE[idx];
  const auto gl_name = SHADER_NAME[idx];

  LOG(INFO) << "Compiling " << gl_name << " shader for '" << m_name << "'";

  auto id = glCreateShader(gl_type);
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  validate_shader(id, gl_name);

  return id;
}

auto Shader::link_program(ShaderId vertex, ShaderId fragment) -> void {
  glAttachShader(m_id, vertex);
  glAttachShader(m_id, fragment);
  glLinkProgram(m_id);

  validate_program(m_id);
}

auto Shader::validate_shader(ShaderId id, ShaderName type) -> void {
  i32 success;
  char log[LOG_SIZE];

  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(id, LOG_SIZE, nullptr, log);
    LOG(ERROR) << "Failed to compile " << type << " shader for '" << m_name
               << "': " << log;
    exit(ExitCode::ERR_GFX);
  }
}

auto Shader::validate_program(ShaderId id) -> void {
  i32 success;
  char log[LOG_SIZE];

  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id, LOG_SIZE, nullptr, log);
    LOG(ERROR) << "Failed to link '" << m_name << "': " << log;
    exit(ExitCode::ERR_GFX);
  }
}

auto Shader::use() -> void { glUseProgram(m_id); }

auto Shader::set(ShaderProp prop, glm::mat4 mat) -> void {
  unsigned int transformLoc = glGetUniformLocation(m_id, prop);
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

} // namespace farlands