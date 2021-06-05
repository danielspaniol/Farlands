#pragma once

#include "farlands/prelude.hpp"

namespace farlands {

using ShaderName = cstrref;
using ShaderId = u32;
using ShaderSrc = cstrref;
enum class ShaderType { VERTEX, FRAGMENT };

/// \brief OpenGL shader program
class Shader {
public:
  /// \brief Creates a shader with the given name to be filled.
  explicit Shader(ShaderName name);
  /// \brief Deletes the OpenGL resources
  ~Shader();

  /// \brief Creates the OpenGL shader program with the given shaders.
  auto compile(ShaderSrc vertex, ShaderSrc fragment) -> void;

  /// \brief Use this shader for draw operations.
  auto use() -> void;

private:
  auto compile_shader(ShaderSrc src, ShaderType type) -> ShaderId;
  auto link_program(ShaderId vertex, ShaderId fragment) -> void;

  auto validate_shader(ShaderId id, ShaderName type) -> void;
  auto validate_program(ShaderId id) -> void;

  ShaderName m_name;
  ShaderId m_id;
};

} // namespace farlands