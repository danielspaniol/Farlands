#include "farlands/graphics/gl_ctx.hpp"

namespace farlands {

bool GlCtx::sm_initialized = false;

GlCtx::GlCtx() {}

GlCtx::~GlCtx() {}

auto GlCtx::init_glfw() -> void {}

auto GlCtx::init_glad() -> void {}

auto GlCtx::terminate_glfw() -> void {}

auto GlCtx::terminate_glad() -> void {}

} // namespace farlands