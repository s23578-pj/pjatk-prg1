#include <cstring>
#include <iostream>

void *memset(void *s, int c, size_t sz) {
  std::byte *p = (std::byte *)s;

  while (sz--)
    *p++ = (std::byte)c;
  return s;
}

int main() {
  char a[] = "Hello World";
  int b = '-';
  size_t c = 2;
  std::cout << "Before memset function: " << a << std::endl;
  memset(&a, b, c);
  std::cout << "After memset function: " << a << std::endl;

  return 0;
}
