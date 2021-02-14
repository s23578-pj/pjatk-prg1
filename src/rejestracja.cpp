#include <fstream>
#include <iostream>
#include <list>
#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <vector>
auto ask_user_for_integerr(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}

auto ask_user_for_credential(std::string const prompt) -> std::string {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return value;
}
void czekaj(int iMilisekundy) {
  clock_t koniec = clock() + iMilisekundy * CLOCKS_PER_SEC / 1000.0;
  while (clock() < koniec)
    continue;
}

double obliczSekundy(clock_t czas) {
  return static_cast<double>(czas) / CLOCKS_PER_SEC;
}
auto przywitanie() -> std::string {
  auto hello = "                                                        "
               "Welcome in students program!\n";
  std::cout << " \n\
                             HHHHHHHHH     HHHHHHHHH                   lllllll lllllll                 \n\
                             H:::::::H     H:::::::H                   l:::::l l:::::l                  \n\
                             H:::::::H     H:::::::H                   l:::::l l:::::l                  \n\
                             HH::::::H     H::::::HH                   l:::::l l:::::l                  \n\
                               H:::::H     H:::::H      eeeeeeeeeeee    l::::l  l::::l    ooooooooooo   \n\
                               H:::::H     H:::::H    ee::::::::::::ee  l::::l  l::::l  oo:::::::::::oo  \n\
                               H::::::HHHHH::::::H   e::::::eeeee:::::eel::::l  l::::l o:::::::::::::::o \n\
                               H:::::::::::::::::H  e::::::e     e:::::el::::l  l::::l o:::::ooooo:::::o \n\
                               H:::::::::::::::::H  e:::::::eeeee::::::el::::l  l::::l o::::o     o::::o \n\
                               H::::::HHHHH::::::H  e:::::::::::::::::e l::::l  l::::l o::::o     o::::o \n\
                               H:::::H     H:::::H  e::::::eeeeeeeeeee  l::::l  l::::l o::::o     o::::o \n\
                               H:::::H     H:::::H  e:::::::e           l::::l  l::::l o::::o     o::::o \n\
                             HH::::::H     H::::::HHe::::::::e         l::::::ll::::::lo:::::ooooo:::::o \n\
                             H:::::::H     H:::::::H e::::::::eeeeeeee l::::::ll::::::lo:::::::::::::::o \n\
                             H:::::::H     H:::::::H  ee:::::::::::::e l::::::ll::::::l oo:::::::::::oo  \n\
                             HHHHHHHHH     HHHHHHHHH    eeeeeeeeeeeeee llllllllllllllll   ooooooooooo  \n";
  std::cout << hello << std::endl;
  return hello;
}

const std::string data_filename =
    "data.txt"; // globalna zmienna po to żeby można było zapisywać i ładować
                // dane z tego samego pliku

auto load_userdata(std::vector<std::string> &datauser)
    -> std::vector<std::string> //ładowanie danych z pliku
{
  std::ifstream data(data_filename);

  while (data.eof() == false) {
    std::string elem;
    getline(data, elem);
    // data >> elem;

    datauser.push_back(elem);
  }

  return datauser;
}

auto print_userdata(const std::vector<std::string> &datauser) -> void {
  std::cout << "login: " << datauser[0] << std::endl;
  std::cout << "name: " << datauser[2] << std::endl;
  std::cout << "surname: " << datauser[3] << std::endl;
}

auto save_userdata(const std::vector<std::string> &datauser)
    -> void // zapisywanie danych do pliku
{
  std::ofstream zapis(data_filename);

  for (std::string elem : datauser) {
    zapis << elem << std::endl;
  }

  // zapis.close();
}

auto user_login(std::vector<std::string> &datauser)
    -> bool // system logowania który wczytuje z pliku
// std::vector<std::string>
{
  std::string login2 = ask_user_for_credential("Podaj login: ");
  std::string password2 = ask_user_for_credential("Podaj hasło: ");
  load_userdata(datauser);
  return (datauser.at(0) == login2 && datauser.at(1) == password2);
}
auto user_register()
    -> std::vector<std::string> // użytkownik wpisuje dane które progam
                                // zapamietuje w pliku
{
  std::vector<std::string> datauser;
  std::string login = ask_user_for_credential("Login: ");
  datauser.push_back(login);
  std::string password = ask_user_for_credential("Password: ");
  datauser.push_back(password);
  std::string mail = ask_user_for_credential("Email: ");
  datauser.push_back(mail);
  std::string name = ask_user_for_credential("Name: ");
  datauser.push_back(name);
  std::string surname = ask_user_for_credential("Surname: ");
  datauser.push_back(surname);
  std::string index = ask_user_for_credential("Index number: ");
  datauser.push_back(index);
  std::string date = ask_user_for_credential("Date of birth: ");
  datauser.push_back(date);

  save_userdata(datauser);
  sleep(1.5);
  //user_login(datauser);

  return datauser;
}
auto rdd() -> int {
  system("clear");
  przywitanie();
  std::cout << "Choose 1 if you want to register or 2 if you want to login"
            << std::endl;
  bool is_ok = false;
  do {
    auto choice = ask_user_for_integerr("What do u want to do?:");
    if (choice == 1) {

      user_register();
    } else {
      std::vector<std::string> datauser;
      is_ok = user_login(datauser);

      if (!is_ok) {

        std::cout << "Wrong credentials!!!" << std::endl;

        std::cout << "Try Again\n";
      }
      // menu()
    }
  } while (is_ok == false);
  return 0;
}
