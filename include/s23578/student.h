#ifndef s23578_STUDENT_H
#define s23578_STUDENT_H

#include <string>

#include <iostream>
namespace s23578 {
class Student {
  std::string name;
  std::string surname;
  std::string index;
  size_t semester;
  double average_grade;

public:
  Student() {
    name = "Krzysztof ";
    surname = "Szczypior ";
    index = "s23578";
    semester = 1;
    average_grade = 4.268;
  }

  auto myself() {
    std::cout << name << " " << surname << "(" << index << "), semestr "
              << semester << ": " << average_grade << std::endl;
  }
  auto read() {
    std::cout << "My Name Is: ";
    std::cin >> name;
    std::cout << "My Surname is: ";
    std::cin >> surname;
    std::cout << "My Index number is: ";
    std::cin >> index;
    std::cout << "My semester is ";
    std::cin >> semester;
    std::cout << "My average grade is: ";
    std::cin >> average_grade;
  }
};
} // namespace s23578

#endif
