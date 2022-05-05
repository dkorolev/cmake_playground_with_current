#include <iostream>

#include "bricks/dflags/dflags.h"

DEFINE_string(name, "World", "The name to greet.");

int main(int argc, char** argv) {
  ParseDFlags(&argc, &argv);
  std::cout << "Hello, " << FLAGS_name << '!' << std::endl;
}
