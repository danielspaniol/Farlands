#pragma once

#include "farlands/control/action.hpp"
#include "farlands/prelude.hpp"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <array>

namespace farlands {

using KeyCode = u32;

class Bindings {
public:
  auto operator[](KeyCode code) const -> Action;
  auto operator[](KeyCode code) -> Action &;

private:
  static constexpr usize NUM_KEYS = GLFW_KEY_LAST + 1;

  std::array<Action, NUM_KEYS> m_binding;
};

} // namespace farlands