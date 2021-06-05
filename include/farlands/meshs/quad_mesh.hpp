#pragma once

#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/meshs/vertex.hpp"
#include "farlands/prelude.hpp"

#include <array>

namespace farlands {

class QuadMesh {
public:
  static constexpr usize NUM_VERTICES = 12;
  static constexpr usize NUM_INDICES = 6;

  explicit QuadMesh(GlCtx &);

  auto render() -> void;
  auto update() -> void;

private:
  std::array<f32, NUM_VERTICES> m_vertices;
  std::array<u32, NUM_INDICES> m_indices;
  VBO m_vbo;
  VAO m_vao;
  EBO m_ebo;
};

} // namespace farlands
