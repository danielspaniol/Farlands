#pragma once

#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/meshs/vertex.hpp"
#include "farlands/prelude.hpp"

#include <array>

namespace farlands {

class TriangleMesh {
public:
  static constexpr usize NUM_VERTICES = 9;

  explicit TriangleMesh(GlCtx &);

  auto render() -> void;
  auto update() -> void;

private:
  std::array<f32, NUM_VERTICES> m_vertices;
  VBO m_vbo;
  VAO m_vao;
};

} // namespace farlands