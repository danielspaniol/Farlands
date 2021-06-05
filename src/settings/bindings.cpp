#include "farlands/settings/bindings.hpp"

namespace farlands {

auto Bindings::operator[](KeyCode code) const -> Action {
  assert(code < NUM_KEYS);
  return m_binding[code];
}

auto Bindings::operator[](KeyCode code) -> Action & {
  assert(code < NUM_KEYS);
  return m_binding[code];
}

} // namespace farlands