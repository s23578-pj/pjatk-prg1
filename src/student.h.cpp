#ifndef s23578_STUDENT_H
#define s23578_STUDENT_H

#include <string>

namespace s23578 {
class Student {
  std::string const name;
  std::string const surname;
  std::string const index;
  constexpr static size_t semester;
  size_t semester(semester);
  constexpr static double average_grade;

public:
  Student(std::string, size_t const = semester, size_t const = average_grade);
};
} // namespace s23578

#endif
