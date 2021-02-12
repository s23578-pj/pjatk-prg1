#include <iostream>

auto main() -> int {
  const char *hello_world = "Hello World!";
  std::cout << &hello_world << std::endl;
  return 0;
}
