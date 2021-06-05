#include "farlands/meshs/triangle_mesh.hpp"

#include <GLAD/glad.h>

namespace farlands {

TriangleMesh::TriangleMesh(GlCtx &)
    : m_vertices{
          -0.5f, -0.5f, 0.0f, //
          0.5f,  -0.5f, 0.0f, //
          0.0f,  0.5f,  0.0f  //
      } {
  glGenBuffers(1, &m_vbo);
  glGenVertexArrays(1, &m_vao);

  update();
}

auto TriangleMesh::update() -> void {
  glBindVertexArray(m_vao);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices.data(),
               GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}

auto TriangleMesh::render() -> void {
  glBindVertexArray(m_vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

} // namespace farlands