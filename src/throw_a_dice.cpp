#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <curses.h>
auto ask_users_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
int dice() {
  int close = 1;
  std::cout << " \n\
                                                    ╔╦╗╦╔╗╔╦  ╔═╗╔═╗╔╦╗╔═╗╔═╗ \n\
                                                    ║║║║║║║║  ║ ╦╠═╣║║║║╣ ╚═╗ \n\
                                                    ╩ ╩╩╝╚╝╩  ╚═╝╩ ╩╩ ╩╚═╝╚═╝ \n\
 \n";

  std::cout
      << "Description: Welcome! This is a dodecahedron cube, Enjoy! \n"; // dwunastościenna
                                                                         // kostka"
  do {
    std::random_device rd;
    std::uniform_int_distribution<int> kostka_1(
        1, 12); // przedział z którego losuje kostka (12 ścienna)
    std::uniform_int_distribution<int> kostka_2(1, 12);
    int losowa1 = kostka_1(rd) + 4;
    int losowa2 = kostka_2(rd) + 4; // zwiększa wylosowaną liczbę o 4
    char c;

    int wybierz_kostke = ask_users_for_integer("Choose dice 1 or 2: ");

    std::cout << "Selected Dice: " << wybierz_kostke << std::endl;
    if (wybierz_kostke == 1) {

      if (losowa1 > losowa2) {
        std::cout << "Your Dice: " << losowa1 << std::endl;
        sleep(2.5);
        std::cout << "CPU Dice: " << losowa2 << std::endl;
        sleep(1.5);
        std::cout
            << " ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄            ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄ \n\
▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌\n\
▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n\
▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌          \n\
▐░▌   ▄   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ \n\
▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌\n\
▐░▌ ▐░▌░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n\
▐░▌▐░▌ ▐░▌▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌    ▐░▌▐░▌▐░▌          \n\
▐░▌░▌   ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ \n\
▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░░░░░░░░░░░▌\n\
 ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀▀▀▀▀▀▀▀▀▀▀ \n";
        std::cout
            << "Press enter for the re-roll or exit by pressing ESC + ENTER\n";
        sleep(1);
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program. \n";
          while((c = getchar()) != '\n' && c != EOF)
          sleep(2);
          return 0;
        }
      }

      else if (losowa2 > losowa1) {
        std::cout << "Your Dice: " << losowa1 << std::endl;
        sleep(2.5);
        std::cout << "CPU Dice: " << losowa2 << std::endl;
        sleep(1.5);
        std::cout
            << "__   __  _______  __   __    ___      _______  _______  _______ \n\
|  | |  ||       ||  | |  |  |   |    |       ||       ||       | \n\
|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||_     _| \n\
|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____   |   |  \n\
|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  |  |   |  \n\
  |   |  |       ||       |  |       ||       | _____| |  |   |  \n\
  |___|  |_______||_______|  |_______||_______||_______|  |___|  \n";

        std::cout
            << "Press enter for the re-roll or exit by pressing ESC + ENTER\n";
        sleep(1);
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program.\n";
          while((c = getchar()) != '\n' && c != EOF)
          sleep(2);
          return 0;
        }
      }
    } else if (wybierz_kostke == 2) {
      if (losowa2 > losowa1) {
        std::cout << "CPU Dice: " << losowa1 << std::endl;
        sleep(2.5);
        std::cout << "Your Dice: " << losowa2 << std::endl;
        sleep(1.5);
        std::cout
            << " ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄            ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄ \n\
▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌\n\
▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n\
▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌          \n\
▐░▌   ▄   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ \n\
▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌\n\
▐░▌ ▐░▌░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n\
▐░▌▐░▌ ▐░▌▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌    ▐░▌▐░▌▐░▌          \n\
▐░▌░▌   ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ \n\
▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░░░░░░░░░░░▌\n\
 ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀▀▀▀▀▀▀▀▀▀▀ \n";
        std::cout
            << "Press enter for the re-roll or exit by pressing ESC + ENTER\n";
        sleep(1);
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program.\n";
          while((c = getchar()) != '\n' && c != EOF)
          sleep(2);
          return 0;
        }
      } else if (losowa1 > losowa2) {
        std::cout << "CPU Dice: " << losowa1 << std::endl;
        sleep(2.5);
        sleep(1.5);
        std::cout << "Your Dice: " << losowa2 << std::endl;
        std::cout
            << "__   __  _______  __   __    ___      _______  _______  _______ \n\
|  | |  ||       ||  | |  |  |   |    |       ||       ||       | \n\
|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||_     _| \n\
|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____   |   |  \n\
|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  |  |   |  \n\
  |   |  |       ||       |  |       ||       | _____| |  |   |  \n\
  |___|  |_______||_______|  |_______||_______||_______|  |___|  \n";
        std::cout
            << "Press enter for the re-roll or exit by pressing ESC + ENTER\n";
        sleep(1);
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program.\n";
          while((c = getchar()) != '\n' && c != EOF)
          sleep(2);
          return 0;
        }
      }
    }

  } while (close == true);

  return 0;
}
