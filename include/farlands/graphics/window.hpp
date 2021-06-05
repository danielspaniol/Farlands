#pragma once

#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/prelude.hpp"

struct GLFWwindow;

namespace farlands {

/// \brief GLFW based window
/// \note If creation fails, the program terminates.
class Window {
public:
  explicit Window(GlCtx &gl);
  ~Window();

  /// \returns false if the window should be closed.
  auto is_open() const -> bool;

  /// \brief Polls the inputs and updates the internal state.
  auto update_input() -> void;
  /// \brief Draws and displays the graphics.
  auto update_output() -> void;

private:
  static constexpr u32 WIDTH = 1280;
  static constexpr u32 HEIGHT = 720;
  static constexpr cstrref TITLE = "farlands";

  GlCtx &m_gl;
  GLFWwindow *m_handle;
};

} // namespace farlands