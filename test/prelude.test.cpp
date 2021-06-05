#include "farlands/prelude.hpp"

#include <gtest/gtest-death-test.h>
#include <gtest/gtest.h>

using namespace farlands;

TEST(exit, OnOkExitCode) {
  EXPECT_EXIT(exit(ExitCode::OK), testing::ExitedWithCode(0), "");
}

TEST(exit, OnErrorExitCode) {
  EXPECT_EXIT(exit(ExitCode::ERR_SYS), testing::ExitedWithCode(1),
              "system error");
}

TEST(UNREACHABLE, KillsTheProcess) {
  EXPECT_EXIT(FARLANDS_UNREACHABLE, testing::ExitedWithCode(1), "unreachable");
}