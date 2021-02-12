#include <ctime>
void czekaj(int iMilisekundy) {
  clock_t koniec = clock() + iMilisekundy * CLOCKS_PER_SEC / 1000.0;
  while (clock() < koniec)
    continue;
}

double obliczSekundy(clock_t czas) {
  return static_cast<double>(czas) / CLOCKS_PER_SEC;
}
printf("You have spent %.4fsek time since logging in!\n",
       obliczSekundy(clock()));
