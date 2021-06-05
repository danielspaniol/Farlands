/// \file prelude.hpp
/// \brief Most basic utilities that should be included in every file.

#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>

/// \brief Remove warnings for unused variables
#define FARLANDS_UNUSED(var) ((void)var)
/// \brief Used when the compiler can't see some code cannot be reached
#define FARLANDS_UNREACHABLE farlands::_unreachable(__FILE__, __LINE__)

namespace farlands {

using usize = std::size_t; ///< Integer for indices and sizes

using i8 = std::int8_t;    ///< 8-bit signed integer
using i16 = std::int16_t;  ///< 16-bit signed integer
using i32 = std::int32_t;  ///< 32-bit signed integer
using i64 = std::int64_t;  ///< 64-bit signed integer
using u8 = std::uint8_t;   ///< 8-bit unsigned integer
using u16 = std::uint16_t; ///< 16-bit unsigned integer
using u32 = std::uint32_t; ///< 32-bit unsigned integer
using u64 = std::uint64_t; ///< 64-bit unsigned integer

using f32 = float;  ///< 32-bit float
using f64 = double; ///< 64-bit float
static_assert(sizeof(f32) == 4, "f32 must be 4 bytes big");
static_assert(sizeof(f64) == 8, "f64 must be 8 bytes big");

using cstr = char *;          ///< C string
using cstrref = const char *; ///< constant "reference" to a C string

/// \brief Type-safer exit codes
enum class ExitCode { OK, ERR_SYS };

/// \brief Terminates the program if unreachable code manages to be reached
[[noreturn]] auto _unreachable(cstrref file, i32 line) -> void;
/// \brief Terminates the program with the given exit code
/// \note Depending on the code, this might print a message
[[noreturn]] auto exit(ExitCode) -> void;

} // namespace farlands