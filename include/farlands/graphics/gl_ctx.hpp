#pragma once

namespace farlands {

/// \brief The global OpenGL context
/// \note Exactly one object should be created in main.
/// If any of the initializations fail, the program exits.
class GlCtx {
public:
  /// \brief Initializes all OpenGL libraries
  /// \note GLAD cannot be initialized here and the window needs to initalize it
  GlCtx();

  /// \brief Terminates all OpenGL libraries
  ~GlCtx();

  friend class Window;

private:
  auto init_glfw() -> void;
  auto init_glad() -> void;

  auto terminate_glfw() -> void;
  auto terminate_glad() -> void;

  static bool sm_initialized; ///< Exaclty one instance is allowed.
};

} // namespace farlands