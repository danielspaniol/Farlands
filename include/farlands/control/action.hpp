#pragma once

#include "farlands/prelude.hpp"

namespace farlands {

struct Action {
  enum T {
    NONE,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT,
  };

  static constexpr usize CNT = static_cast<usize>(MOVE_RIGHT) + 1;

  constexpr Action() : m_data{NONE} {}
  constexpr Action(T t) : m_data{t} {}
  constexpr operator T() const { return m_data; }

private:
  T m_data;
};

} // namespace farlands