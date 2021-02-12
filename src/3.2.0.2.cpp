#include <iostream>
#include <string>

void print(const char *hello_world) {
  std::cout << &hello_world << " = " << hello_world << std::endl;
}

auto main() -> int {
  const char *hello_world = "Hello World!";
  print(hello_world);
  return 0;
}
