#include "project/prelude.hpp"

#include <cstdlib>
#include <iostream>

namespace project {

[[noreturn]] auto _unreachable(cstrref file, i32 line) -> void {
  std::cerr << "Reached unreachable code: " << file << '.' << line << std::endl;
  exit(ExitCode::ERR_SYS);
}

[[noreturn]] auto exit(ExitCode code) -> void {
  switch (code) {
  case ExitCode::OK:
    break;
  case ExitCode::ERR_SYS:
    std::cerr << "Exited with a system error" << std::endl;
    break;
  }

  std::exit(static_cast<i32>(code));
}

} // namespace project