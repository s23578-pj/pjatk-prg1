#include <iostream>
#include <string>
#include <vector>
auto print_userdata(const std::vector<std::string> &datauser) -> void {
  load_userdata(datauser);
  std::cout << "Login: " << datauser[0] << std::endl;
  std::cout << "E-mail: " << datauser[2] << std::endl;
  std::cout << "Name: " << datauser[3] << std::endl;
  std::cout << "Surname: " << datauser[4] << std::endl;
  std::cout << "Index number: " << datauser[5] << std::endl;
  std::cout << "Date of birth: " << datauser[6] << std::endl;
}
