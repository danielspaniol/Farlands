#include "farlands/meshs/quad_mesh.hpp"

#include <GLAD/glad.h>

namespace farlands {

QuadMesh::QuadMesh(GlCtx &)
    : m_vertices{0.5f,  0.5f,  0.0f,  // top right
                 0.5f,  -0.5f, 0.0f,  // bottom right
                 -0.5f, -0.5f, 0.0f,  // bottom left
                 -0.5f, 0.5f,  0.0f}, // top left
      m_indices{0, 1, 3,              // first triangle
                1, 2, 3}              // seconds triangle
{
  glGenBuffers(1, &m_vbo);
  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_ebo);

  update();
}

auto QuadMesh::update() -> void {
  glBindVertexArray(m_vao);

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices.data(),
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices.data(),
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}

auto QuadMesh::render() -> void {
  glBindVertexArray(m_vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

} // namespace farlands