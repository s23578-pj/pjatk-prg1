#include <cstring>
#include <iostream>

typedef unsigned char byte;

void *memfrob(void *s, size_t sz) {
  byte *p = (byte *)s;
  byte t = (byte)42;

  while (sz--)
    *p = *p ^ t;
  p++;
  return s;
}

int main() {
  char a[] = "Hello World";
  size_t sz = 3;
  std::cout << "Before memfrob function: " << a << std::endl;
  memfrob(&a, sz);
  std::cout << "After memfrob function: " << a << std::endl;

  return 0;
}
