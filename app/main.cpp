#include <glog/logging.h>

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  LOG(INFO) << "Starting application";
  LOG(INFO) << "Stopping application";
}