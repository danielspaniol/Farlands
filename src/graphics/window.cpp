#include "farlands/graphics/window.hpp"

namespace farlands {

Window::Window(GlCtx &gl) : m_gl{gl} {}

Window::~Window() {}

auto Window::is_open() const -> bool { return false; }

auto Window::update_input() -> void {}

auto Window::update_output() -> void {}

} // namespace farlands
