#include <math.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <curses.h>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>
// funkcja działająca na bazie cina ale zabezpieczona (prosi użytkownika o
// podanie liczby typu int)
auto ask_user_for_integers(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}

//// funkcja działająca na bazie cina ale zabezpieczona (prosi użytkownika o
///podanie znaku/tablicy znaków czyli stringa)
auto ask_user_for_credentials(std::string const prompt) -> std::string {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return value;
}
// Lista intrukcji kalkulatora
auto instruction() -> void {
  std::cout << " \n\
                 ████████  ██████   ██████  ██      ██████   ██████  ██   ██  \n\
                    ██    ██    ██ ██    ██ ██      ██   ██ ██    ██  ██ ██  \n\
                    ██    ██    ██ ██    ██ ██      ██████  ██    ██   ███   \n\
                    ██    ██    ██ ██    ██ ██      ██   ██ ██    ██  ██ ██  \n\
                    ██     ██████   ██████  ███████ ██████   ██████  ██   ██ \n";
  std::cout << "                                                               "
               "The Student Angel\n";
  std::cout << "\n                    The full list of possibilities will be "
               "available below in a moment! \n\n";
  sleep(4);
  std::cout << "Instruction:" << std::endl;
  std::cout << "+ - if u want addition" << std::endl;
  std::cout << "- - if u want substraction" << std::endl;
  std::cout << "* - if u want multiplication" << std::endl;
  std::cout << "/ - if u want division" << std::endl;
  std::cout << "// - if u want completely division" << std::endl;
  std::cout << "% - if u want the rest of the division" << std::endl;
  std::cout << "** - if u want exponentiation" << std::endl;
  sleep(2);
  std::cout << "sqrt1 - if u want the root of the second degree" << std::endl;
  sleep(2);
  std::cout << "sqrt2 - if u want root of any degree" << std::endl;
  sleep(2);
  std::cout << "log - if u want logarithm of any number" << std::endl;
  sleep(1);
  std::cout << "logn - if u want the natural logarithm" << std::endl;
  sleep(1);
  std::cout << "sin - if u want sine of the angle" << std::endl;
  sleep(1);
  std::cout << "cos - if u want cosine of the angle" << std::endl;
  sleep(1);
  std::cout << "tan - if u want tangent of the angle" << std::endl;
  sleep(1);
  std::cout << "cot - if u want cotangent of the angle" << std::endl;
  sleep(0.3);
  std::cout << "asin - if u want arcus sine of the angle" << std::endl;
  sleep(0.3);
  std::cout << "acos - if u want arcus cosine of the angle" << std::endl;
  sleep(0.1);
  std::cout << "atan - if u want arcus tangent of the angle" << std::endl;
  sleep(0.1);
  std::cout << "acot - if u want arcus cotangent of the angle" << std::endl;
  sleep(0.3);
  std::cout << "! - if u want factorial" << std::endl;
  sleep(0.1);
  std::cout << "com - if u want compare the numbers" << std::endl;
  std::cout << "tri - if you want to check if it is possible to build a "
               "triangle with given sides"
            << std::endl;
  std::cout << "fos1 - if u want field od square" << std::endl;
  std::cout << "fos2 - if u want field os square but with the use of a diagonal"
            << std::endl;
  std::cout << "cosor - if u want circuit of square or rhombus" << std::endl;
  std::cout << "for - if u want field of rectangle" << std::endl;
  std::cout
      << "coropod - if u want circuit of rectangle or parallelogram or deltoid"
      << std::endl;
  std::cout << "fot1 - if u want field od triangle" << std::endl;
  std::cout << "fot2 - if u want field of triangle but using the p factor and "
               "all sides"
            << std::endl;
  std::cout << "cot - if u want circuit of triangle" << std::endl;
  std::cout << "fop - if u want field od parallelogram" << std::endl;
  std::cout << "forh - if u want field of rhombus" << std::endl;
  std::cout << "fotr - if u want field of trapeze" << std::endl;
  std::cout << "cotr - if u want circuit of trapeze" << std::endl;
  std::cout << "fod - if u want field od deltoid" << std::endl;
  std::cout << "foc - if u want field od circle" << std::endl;
  std::cout << "coc - if u want circuit of circle" << std::endl;
  std::cout << "focu - if u want field of cube" << std::endl;
  std::cout << "voc - if u want volume of cube" << std::endl;
  std::cout << "focub - if u want field of cuboid" << std::endl;
  std::cout << "vocu - if u want volume of cuboid" << std::endl;
  std::cout << "focy - if u want field of cylinder" << std::endl;
  std::cout << "vocy - if u want volume of cylinder" << std::endl;
  std::cout << "foco - if u want field of cone" << std::endl;
  std::cout << "voco - if u want volume of cone" << std::endl;
  std::cout << "fosp - if u want field of sphere" << std::endl;
  std::cout << "vos - if u want volume of sphere" << std::endl;
  std::cout << "\n\nPress ENTER + ESC + ENTER to exit the program";
  std::cout << "\n";
}

// funkcje matematyczne
auto evaluate_addition() -> void {
  auto const b = ask_user_for_integers("Number 1: ");
  auto const a = ask_user_for_integers(
      "Number 2: "); // podanie liczb które użytkownik chce dodać
  std::cout << "Score: " << a + b << std::endl;
}

auto evaluate_subtraction() -> void {
  auto const b = ask_user_for_integers("Number 1: ");
  auto const a = ask_user_for_integers("Number 2: ");
  std::cout << "Score: " << a - b << std::endl;
}

auto evaluate_multiplication() -> void {
  auto const b = ask_user_for_integers("Number 1: ");
  auto const a = ask_user_for_integers("Number 2: ");
  std::cout << "Score: " << a * b << std::endl;
}

auto evaluate_division() -> void {
  auto const b = ask_user_for_integers("Number 1: ");
  auto const a = ask_user_for_integers("Number 2: ");
  if (b == 0) {
    std::cout << "Don't divide by zero \n";
  } else {
    std::cout << "Score: " << b / a << std::endl;
  }
}

auto evaluate_division_completely() -> void {
  auto const b = ask_user_for_integers("Number 1: ");
  auto const a = ask_user_for_integers("Number 2: ");
  if (b == 0) {
    std::cerr << "Don't divide by zero \n";
  } else {
    std::cout << "Score: " << (int)b / (int)a << std::endl;
  }
}

auto evaluate_modulo() -> void {
  auto const b = ask_user_for_integers("Number 1: ");
  auto const a = ask_user_for_integers("Number 2: ");
  if (b == 0) {
    std::cerr << "Don't divide by zero \n";
  } else {
    std::cout << "Score: " << (int)b % (int)a << std::endl;
  }
}

auto evaluate_exponentiation() -> void {
  auto const b = ask_user_for_integers("Your number: ");
  auto const a = ask_user_for_integers("Exponent: ");
  std::cout << "Score: " << pow(b, a) << std::endl;
}

auto evaluate_square_root() -> void {
  auto const a = ask_user_for_integers("Your number: ");
  if (a < 0) {
    std::cerr << "There is no square root of a negative number. Try again!"
              << std::endl;
  } else {
    std::cout << "Score: " << sqrt(a) << std::endl;
  }
}

auto evaluate_square_root_of_any_degree() -> void {
  auto const a = ask_user_for_integers("Your number: ");
  auto const b = ask_user_for_integers("The degree of the square: ");
  if (a < 0) {
    std::cerr << "There is no square root of a negative number. Try again!"
              << std::endl;
  }
  if (b < 2) {
    std::cout << "The lowest degree of the element is 2!" << std::endl;
  } else {
    std::cout << "Score: " << pow(a, (1.0 / b)) << std::endl;
  }
}

auto evaluate_log() -> void {
  auto const a = ask_user_for_integers("Base of the logarithm: ");
  auto const b = ask_user_for_integers("Logarithmic number: ");
  if (a <= 0 || a == 1) {
    std::cerr << "The base of the logarithm must be positive and not 1"
              << std::endl;
  } else if (b <= 0) {
    std::cerr << "The logarithm must be positive!" << std::endl;
  } else {
    std::cout << "Score: " << (log(a)) / (log(b)) << std::endl;
  }
}

auto evaluate_logn() -> void {
  auto const a = ask_user_for_integers("Your number: ");
  if (a <= 0) {
    std::cerr << "The logarithm must be positive!" << std::endl;
  } else {
    std::cout << "Score: " << log(a) << std::endl;
  }
}

auto evaluate_sine() -> void {
  auto const a = ask_user_for_integers("Your degrees: ");
  if (a < 0) {
    std::cerr << "Degrees can't be negative!" << std::endl;
  } else {
    std::cout << "Score: " << sin(a * M_PI / 180.0) << std::endl;
  }
}

auto evaluate_cosine() -> void {
  auto const a = ask_user_for_integers("Your degrees: ");
  if (a < 0) {
    std::cerr << "Degrees can't be negative!" << std::endl;
  } else {
    std::cout << "Score: " << cos(a * M_PI / 180.0) << std::endl;
  }
}

auto evaluate_tangent() -> void {
  auto const a = ask_user_for_integers("Your degrees: ");
  if (a < 0) {
    std::cerr << "Degrees can't be negative!" << std::endl;
  } else if (a == 90) {
    std::cout << "Tanget of 90 degrees does not exist!" << std::endl;
  } else {
    std::cout << "Score: " << tan(a * M_PI / 180.0) << std::endl;
  }
}

auto evaluate_cotangent() -> void {
  auto const a = ask_user_for_integers("Your degrees: ");
  if (a < 0) {
    std::cerr << "Degrees can't be negative!" << std::endl;
  } else if (a == 0) {
    std::cout << "Cotanget of 0 degrees does not exist!" << std::endl;
  } else {
    std::cout << "Score: " << 1.0 / tan(a * M_PI / 180.0) << std::endl;
  }
}

auto evaluate_asine() -> void {
  double a = ask_user_for_integers("Your angle: ");
  if (a < -1.0 || a > 1.0) {
    std::cerr << "The asin arguments cannot be less than -1 and greater than 1!"
              << std::endl;
  } else {
    std::cout << "Score: " << asin(a) << std::endl;
  }
}

auto evaluate_acosine() -> void {
  auto const a = ask_user_for_integers("Your angle: ");
  if (a < -1.0 || a > 1.0) {
    std::cerr
        << "The acosin arguments cannot be less than -1 and greater than 1!"
        << std::endl;
  } else {
    std::cout << "Score: " << acos((a * M_PI / 180.0)) << std::endl;
  }
}

auto evaluate_atangent() -> void {
  auto const a = ask_user_for_integers("Your angle: ");
  if (a <= ((-M_PI) / 2.0) || a >= (M_PI / 2.0)) {
    std::cerr << "The atangent arguments cannot be less than -Pi/2 and greater "
                 "than Pi/2!"
              << std::endl;
  } else {
    std::cout << "Score: " << atan(a * M_PI / 180.0) << std::endl;
  }
}

auto evaluate_acotangent() -> void {
  auto const a = ask_user_for_integers("Your radians: ");
  if (a <= 0 || a >= M_PI) {
    std::cerr << "The acotangent arguments cannot be less than -Pi/2 and "
                 "greater than Pi/2!"
              << std::endl;
  } else {
    std::cout << "Score: " << 1 / atan(a * M_PI / 180.0) << std::endl;
  }
}

auto evaluate_factorial() -> void {
  auto const a = ask_user_for_integers("Your number: ");
  int silnia = 1;
  if (a < 0) {
    std::cerr << "The factorial is only counted for non-negative numbers!"
              << std::endl;
  } else {
    for (auto i = 1; i <= a; i++) {
      silnia = silnia * i;
    }

    std::cout << "Score: " << silnia << std::endl;
  }
}

auto evaluate_compare() -> void {
  auto const a = ask_user_for_integers("Number 1: ");
  auto const b = ask_user_for_integers("Number 2: ");
  if (a > b) {
    std::cout << a << ">" << b << std::endl;
  } else if (a < b) {
    std::cout << a << "<" << b << std::endl;
  } else if (a == b) {
    std::cout << a << "==" << b << std::endl;
  }
}

auto evaluate_is_it_triangle() -> void {
  auto const c = ask_user_for_integers("Side length a: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length c: ");
  if (a <= 0 || b <= 0 || c <= 0) {
    std::cerr << "The side lenght can't be negative!" << std::endl;
  } else if ((c > a && c > b && a + b > c) || (b > a && b > c && a + c > b) ||
             (a > b && a > c && b + c > a)) {
    std::cout << "It's triangle" << std::endl;
  } else {
    std::cout << "Its not triangle" << std::endl;
  }
}
auto evaluate_field_of_square1() -> void {
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a * a << std::endl;
  }
}

auto evaluate_field_of_square2() -> void {
  auto const a = ask_user_for_integers("Side length a: ");
  auto const d = (a * sqrt(2));
  if (a <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 0.5 * (d * d);
  }
}

auto evaluate_circuit_of_square_or_rhombus() -> void {
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 4 * a << std::endl;
  }
}

auto evaluate_field_of_rectangle() -> void {
  auto const b = ask_user_for_integers("Side length a: ");
  auto const a = ask_user_for_integers("Side length b: ");
  if (a <= 0 || b <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a * b << std::endl;
  }
}

auto evaluate_circuit_of_rectangle_or_parallelogram_or_deltoid() -> void {
  auto const b = ask_user_for_integers("Side length a: ");
  auto const a = ask_user_for_integers("Side length b: ");
  if (a <= 0 || b <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << (2 * a) + (2 * b) << std::endl;
  }
}

auto evaluate_field_of_triangle1() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || h <= 0) {
    std::cerr << "The side lenght and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 0.5 * (a * h) << std::endl;
  }
}

auto evaluate_field_of_triangle2() -> void {
  auto const c = ask_user_for_integers("Side length c: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length a: ");
  auto const p = (0.5 * (a + b + c));
  if (a <= 0 || b <= 0 || c <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << sqrt(p * ((p - a) * (p - b) * (p - c)))
              << std::endl;
  }
}

auto evaluate_circuit_of_triangle() -> void {
  auto const c = ask_user_for_integers("Side length c: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || b <= 0 || c <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a + b + c << std::endl;
  }
}

auto evaluate_field_of_parallelogram() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || h <= 0) {
    std::cerr << "The side lenght and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a * h << std::endl;
  }
}

auto evaluate_field_of_rhombus() -> void {
  auto const f = ask_user_for_integers("Diagonal length f: ");
  auto const e = ask_user_for_integers("Diagonal lenght e: ");
  if (e <= 0 || f <= 0) {
    std::cerr << "The diagonal lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 0.5 * (e * f) << std::endl;
  }
}

auto evaluate_field_of_trapeze() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || b <= 0 || h <= 0) {
    std::cerr << "The side lenght and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 0.5 * ((a + b) * h) << std::endl;
  }
}

auto evaluate_circuit_of_trapeze() -> void {
  auto const d = ask_user_for_integers("Side length d: ");
  auto const c = ask_user_for_integers("Side length c: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a + b + c + d << std::endl;
  }
}

auto evaluate_field_of_deltoid() -> void {
  auto const d2 = ask_user_for_integers("Diagonal lenght d2: ");
  auto const d1 = ask_user_for_integers("Diagonal lenght d1: ");
  if (d1 <= 0 || d2 <= 0) {
    std::cerr << "The diagonal lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 0.5 * (d1 * d2) << std::endl;
  }
}

auto evaluate_field_of_circle() -> void {
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0) {
    std::cerr << "The ray can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << M_PI * (r * r) << std::endl;
  }
}

auto evaluate_circuit_of_circle() -> void {
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0) {
    std::cerr << "The ray can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 2 * M_PI * r << std::endl;
  }
}

auto evaluate_field_of_cube() -> void {
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 6 * (a * a) << std::endl;
  }
}

auto evaluate_volume_of_cube() -> void {
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0) {
    std::cerr << "The side lenght can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a * a * a << std::endl;
  }
}

auto evaluate_field_of_cuboid() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || b <= 0 || h <= 0) {
    std::cerr << "The side lenght and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 2 * ((a * b) + (b * h) * (h * a)) << std::endl;
  }
}

auto evaluate_volume_of_cuboid() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const b = ask_user_for_integers("Side length b: ");
  auto const a = ask_user_for_integers("Side length a: ");
  if (a <= 0 || b <= 0 || h <= 0) {
    std::cerr << "The side lenght and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << a * b * h << std::endl;
  }
}

auto evaluate_field_of_cylinder() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0 || h <= 0) {
    std::cerr << "The ray and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 2 * M_PI * r * (r * h) << std::endl;
  }
}

auto evaluate_volume_of_cylinder() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0 || h <= 0) {
    std::cerr << "The ray and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << M_PI * (r * r) * h << std::endl;
  }
}

auto evaluate_field_of_cone() -> void {
  auto const l = ask_user_for_integers("Generatrix: ");
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0 || l <= 0) {
    std::cerr << "The ray and generatrix can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << M_PI * r * (r + l) << std::endl;
  }
}

auto evaluate_volume_of_cone() -> void {
  auto const h = ask_user_for_integers("Height: ");
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0 || h <= 0) {
    std::cerr << "The ray and height can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << (1.0 / 3.0) * M_PI * (r * r) * h << std::endl;
  }
}

auto evaluate_field_of_sphere() -> void {
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0) {
    std::cerr << "The ray and can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << 4 * (M_PI * (r * r)) << std::endl;
  }
}

auto evaluate_volume_of_sphere() -> void {
  auto const r = ask_user_for_integers("Ray: ");
  if (r <= 0) {
    std::cerr << "The ray and can't be negative" << std::endl;
  } else {
    std::cout << "Score: " << (4.0 / 3.0) * M_PI * (r * r * r) << std::endl;
  }
}
// sprawdzanie/porównywanie znaków wpisywanych przez użytkownika do przypisanych
// w pamięci
auto make_args(int argc, char *argv[]) -> std::vector<std::string> {
  auto args = std::vector<std::string>{};
  std::copy_n(argv, argc, std::back_inserter(args));
  return args;
}

auto calculator(int argc, char *argv[]) -> int {
  instruction();
  int close = 1;
  char c;
  auto const args = make_args(argc - 1, argv + 1);
  do {
    std::string each = ask_user_for_credentials("What do you wanna do: ");

    // znaki wpisywane przez użytkownika po wpisaniu którego wywołuje się
    // odpowiednia funkcja
    if (each == "+") {
      evaluate_addition();
    } else if (each == "-") {
      evaluate_subtraction();
    } else if (each == "*") {
      evaluate_multiplication();
    } else if (each == "/") {
      evaluate_division();
    } else if (each == "//") {
      evaluate_division_completely();
    } else if (each == "%") {
      evaluate_modulo();
    } else if (each == "**") {
      evaluate_exponentiation();
    } else if (each == "sqrt1") {
      evaluate_square_root();
    } else if (each == "sqrt2") {
      evaluate_square_root_of_any_degree();
    } else if (each == "log") {
      evaluate_log();
    } else if (each == "logn") {
      evaluate_logn();
    } else if (each == "sin") {
      evaluate_sine();
    } else if (each == "cos") {
      evaluate_cosine();
    } else if (each == "tan") {
      evaluate_tangent();
    } else if (each == "cot") {
      evaluate_cotangent();
    } else if (each == "asin") {
      evaluate_asine();
    } else if (each == "acos") {
      evaluate_acosine();
    } else if (each == "atan") {
      evaluate_atangent();
    } else if (each == "acot") {
      evaluate_acotangent();
    } else if (each == "!") {
      evaluate_factorial();
    } else if (each == "com") {
      evaluate_compare();
    } else if (each == "tri") {
      evaluate_is_it_triangle();
    } else if (each == "fos1") {
      evaluate_field_of_square1();
    } else if (each == "fos2") {
      evaluate_field_of_square2();
    } else if (each == "cosor") {
      evaluate_circuit_of_square_or_rhombus();
    } else if (each == "for") {
      evaluate_field_of_rectangle();
    } else if (each == "coropod") {
      evaluate_circuit_of_rectangle_or_parallelogram_or_deltoid();
    } else if (each == "fot1") {
      evaluate_field_of_triangle1();
    } else if (each == "fot2") {
      evaluate_field_of_triangle2();
    } else if (each == "cot") {
      evaluate_circuit_of_triangle();
    } else if (each == "fop") {
      evaluate_field_of_parallelogram();
    } else if (each == "forh") {
      evaluate_field_of_rhombus();
    } else if (each == "fotr") {
      evaluate_field_of_trapeze();
    } else if (each == "cotr") {
      evaluate_circuit_of_trapeze();
    } else if (each == "fod") {
      evaluate_field_of_deltoid();
    } else if (each == "foc") {
      evaluate_field_of_circle();
    } else if (each == "coc") {
      evaluate_circuit_of_circle();
    } else if (each == "focu") {
      evaluate_field_of_cube();
    } else if (each == "voc") {
      evaluate_volume_of_cube();
    } else if (each == "focub") {
      evaluate_field_of_cuboid();
    } else if (each == "vocu") {
      evaluate_volume_of_cuboid();
    } else if (each == "focy") {
      evaluate_field_of_cylinder();
    } else if (each == "vocy") {
      evaluate_volume_of_cylinder();
    } else if (each == "foco") {
      evaluate_field_of_cone();
    } else if (each == "voco") {
      evaluate_volume_of_cone();
    } else if (each == "fosp") {
      evaluate_field_of_sphere();
    } else if (each == "vos") {
      evaluate_volume_of_sphere();
    } else if ((c = getchar()) ==
               27) // instrukcja wciśnięcia klawisza ESC z tablicy ASCII
    {
      std::cout << "Thanks for use our program. \n";
      while((c = getchar()) != '\n' && c != EOF)
      sleep(2);
      return 0;
    } else {
      std::cerr << "Wrong inputs!" << std::endl;
    }
  } while (close == true);
  return 0;
}
