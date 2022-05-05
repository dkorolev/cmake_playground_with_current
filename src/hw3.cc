#include <iostream>

#include "current_build.h"

int main(int argc, char** argv) {
  std::cout << "Hello from `" << current::build::kGitCommit << "`." << std::endl;
}
