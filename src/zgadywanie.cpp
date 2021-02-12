#include <iostream>
#include <ncurses.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
int zgadywanie() {
  int close = 1;
  std::cout << " \n\
                                                    ╔╦╗╦╔╗╔╦  ╔═╗╔═╗╔╦╗╔═╗╔═╗ \n\
                                                    ║║║║║║║║  ║ ╦╠═╣║║║║╣ ╚═╗ \n\
                                                    ╩ ╩╩╝╚╝╩  ╚═╝╩ ╩╩ ╩╚═╝╚═╝ \n\
    \n";
  do {
    char c;
    std::random_device rd; // funkcja odpowiadająca za losowanie liczb
    std::uniform_int_distribution<int> test_liczba1(
        1, 100); // przedział z którego ma losować liczby
    std::uniform_int_distribution<int> test_liczba2(1, 50);
    std::uniform_int_distribution<int> test_liczba3(1, 20);
    std::cout << "Choose a level of difficulty: Easy (1), Medium (2), Hard (3)"
              << std::endl;
    sleep(2);
    std::cout << "Easy- Numbers from 1 to 100 at 10 attempts." << std::endl;
    sleep(1);
    std::cout << "Medium- Numbers from 1 to 50 at 5 attempts." << std::endl;
    sleep(1.5);
    std::cout << "Hard- Numbers from 1 to 20 at 2 attempts." << std::endl;
    sleep(2.5);
    int poziom = ask_user_for_integer("Choose level: ");
    int correctAnswer1 = test_liczba1(rd); // wyloswana liczba przez program
    int correctAnswer2 = test_liczba2(rd);
    int correctAnswer3 = test_liczba3(rd);
    std::cout << "\nYour level: " << poziom << std::endl;
    if (poziom != 1 && poziom != 2 &&
        poziom != 3) { // zabezpieczenie sytuacji gdy użytkownik nie wybierze
                       // jednego z 3 dostępnych poziomów
      std::cerr << "Wrong credentials try again" << std::endl;
      continue;
    }
    if (poziom == 1) {
      bool guess1 = false;
      for (auto i = 0; i < 10; ++i) { // pętla żeby przed ostatnią próba
                                      // poinformować o tym użytkownika
        if (i == 9) {
          std::cout << "Your last chance!" << std::endl;
        }
        int zgadnij_liczbe1 = ask_user_for_integer(
            "Your number: "); // użytkownik próbuje zgadnąć liczbę
        if (correctAnswer1 == zgadnij_liczbe1) { // warunek "wygrania gry"
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
          std::cout << "Press enter for the re-roll or exit by pressing ESC + "
                       "ENTER\n";
          sleep(1);
          if ((c = getchar()) ==
              27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
          {
            std::cout << "Thanks for use our program. \n";
            sleep(2);
            return 0;
          }
        } else if (correctAnswer1 < zgadnij_liczbe1) {
          std::cout << "too big" << std::endl; // podpowiedzi programu dotyczące
                                               // wylosowanej przez niego liczby
        } else if (correctAnswer1 > zgadnij_liczbe1) {
          std::cout << "too small" << std::endl;
        }
      }
      if (guess1 == false) {
        std::cout << "You lost! The number was: " << correctAnswer1 << "."
                  << "Try Again!" << std::endl;
        std::cout
            << "Press enter for the re-roll or exit by pressing ESC + ENTER\n";
        sleep(1);
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program. \n";
          sleep(2);
          return 0;
        }
      }
    }
    if (poziom == 2) {
      bool guess2 = false;
      for (auto i = 0; i < 5; ++i) {
        if (i == 4) {
          std::cout << "Your last chance!" << std::endl;
        }
        int zgadnij_liczbe2 = ask_user_for_integer("Your number: ");
        if (correctAnswer2 == zgadnij_liczbe2) {
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
          std::cout << "Press enter for the re-roll or exit by pressing ESC + "
                       "ENTER\n";
          sleep(1);
          if ((c = getchar()) ==
              27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
          {
            std::cout << "Thanks for use our program. \n";
            sleep(2);
            return 0;
          }
        } else if (correctAnswer2 < zgadnij_liczbe2) {
          std::cout << "too big" << std::endl;
        } else if (correctAnswer2 > zgadnij_liczbe2) {
          std::cout << "too small" << std::endl;
        }
      }
      if (guess2 == false) {
        std::cout << "You lost! The number was: " << correctAnswer2 << "."
                  << "Try Again!" << std::endl;
        std::cout << "or press ESC + ENTER to quit\n";
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program. \n";
          sleep(2);
          return 0;
        }
      }
    } else if (poziom == 3) {
      bool guess3 = false;
      for (auto i = 0; i < 2; ++i) {
        if (i == 1) {
          std::cout << "Your last chance!" << std::endl;
        }
        int zgadnij_liczbe3 = ask_user_for_integer("Your number: ");
        if (correctAnswer3 == zgadnij_liczbe3) {
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
          std::cout << "Press enter for the re-roll or exit by pressing ESC + "
                       "ENTER\n";
          sleep(1);
          if ((c = getchar()) ==
              27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
          {
            std::cout << "Thanks for use our program. \n";
            sleep(2);
            return 0;
          }
        } else if (correctAnswer3 < zgadnij_liczbe3) {
          std::cout << "too big" << std::endl;
        } else if (correctAnswer3 > zgadnij_liczbe3) {
          std::cout << "too small" << std::endl;
        }
      }

      if (guess3 == false) {
        std::cout << "You lost! The number was:  " << correctAnswer3 << "."
                  << " Try Again!" << std::endl;
        std::cout << "or press ESC + ENTER to quit\n";
        if ((c = getchar()) ==
            27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
        {
          std::cout << "Thanks for use our program. \n";
          sleep(2);
          return 0;
        }
      }
    }
  } while (close == true);
  return 0;
}
