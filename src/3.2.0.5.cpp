#include <cstring>
#include <iostream>

void *memcpy(void *s, void *c, size_t sz) {
  std::byte *p = (std::byte)s;
  std::byte p2 = (std::byte *)c;

  while (sz--)
    *p++ = *p2++;
  return s;
}

int main() {
  char a[] = "??llo World";
  char b[] = "He";
  size_t c = 2;
  std::cout << "Before memcpy function: " << a << std::endl;
  memcpy(&a, &b, c);
  std::cout << "After memcpy function: " << a << std::endl;

  return 0;
}
