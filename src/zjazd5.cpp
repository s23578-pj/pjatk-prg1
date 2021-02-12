#include <iostream>
#include <string>
/*
// Zadanie Pierwsze Hello World
auto main()-> int
{
    std::cout << "Hello World!" << std::endl;
    return 0;
}

// Zadanie 1.0.0.1 Hello World z własnym imieniem i nazwiskiem
auto main()-> int
{
    std::cout << "Hello Krzysztof Szczypior" << std::endl;
    return 0;
}

//Zadanie 1.0.0.2 Dodawanie
auto main(int argc, char *argv[]) -> int {
  if (argc == 0) {
    return 1;
  }
  auto const a = std::stoi(argv[1]);
  auto const b = std::stoi(argv[2]);
  std::cout << (a + b) << "\n";
  return 0;
}

// Zadanie 1.0.0.3 Mnożenie
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
        std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
}
auto main() -> int
{
    auto const a = ask_user_for_integer("a = ");
    auto const b = ask_user_for_integer("b = ");

    std::cout << "Wynik mnożenia: " << a*b << std::endl;
    return 0;
}

// Zadanie 1.0.0.4 Większa liczba
auto ask_user_for_integer(std::string const prompt) -> int
{
    if(not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto const a = ask_user_for_integer(" a = ");
    auto const b = ask_user_for_integer(" b = ");
    if(a > b)
    {
        std::cout <<"Bigger number is: "<< a << std::endl;
    }
    else if(b > a)
    {
        std::cout <<"Bigger number is: "<< b << std::endl;
    }
    return 0;
}

// Zadanie 1.0.0.5 Wartość absolutna
auto main() -> int
{
    auto a = 0;
    std::cout << "Insert Your number" << std::endl;
    std::cin >> a;
    if (a < 0)
    {
        std::cout << "Absolute value of Your number is: " << (-1)*a <<
std::endl;
    }
    else
    {
        std::cout << a << std::endl;
    }
    return 0;
}

// Zadanie 1.0.0.6 Relacja między liczbami
auto main() -> int
{
    auto a = 0;
    auto b = 0;
    std::cin >> a >> b;
    std::cout << std::endl << "Wynik" << std::endl;
    if (a == b)
    {
        std::cout << a << " == " << b << std::endl;
    }
    if  (a < b)
    {
        std::cout << a << " < " << b << std::endl;
    }
    if (a > b)
    {
        std::cout << a << " > " << b << std::endl;
    }
    return 0;
}

// Zadanie 1.0.0.7 Dodatnia-nieujemna-ujemna
auto ask_user_for_integer(std::string const prompt) -> int
{
    if(not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto const a = ask_user_for_integer(" a = ");
    if(a > 0) {
        std::cout << 1 << std::endl;
    }
    if(a == 0){
        std::cout << 0 << std::endl;
    }
    if(a < 0){
        std::cout << -1 << std::endl;
    }
    return 0;
}

// Zadanie 1.0.0.8 Największa
auto ask_user_for_integer(std::string const prompt) -> int
{
    if(not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto const a = ask_user_for_integer(" a = ");
    auto const b = ask_user_for_integer(" b = ");
    auto const c = ask_user_for_integer(" c = ");
    if(a > b)
    {
        if (a > c)
        {
            std::cout << a << std::endl;
        }
        else
        {
            std::cout << c << std::endl;
        }
    }
    else if(b > c)
    {
        std::cout << b << std::endl;
    }
    return 0;
}

// Zadanie 2.0.0.1 Lista liczb
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto a = ask_user_for_integer("a = ");
    auto b = ask_user_for_integer("b = ");
    for(auto x = a; x < b; x++){
        std::cout << x << std::endl;
}
    return 0;
}

// Zadanie 2.0.0.2 Lista liczb(2)
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto a = ask_user_for_integer("a = ");
    auto b = ask_user_for_integer("b = ");
    auto c = ask_user_for_integer("c = ");
        if(c == 0){
            std::cerr << "Do not divide by 0!" << std::endl;
            return 1;
        }
    for(auto x = a; x < b; x++){
        if(x % c == 0){
        std::cout << x << std::endl;
        }
    }
    return 0;
}

// Zadanie 2.0.0.3 Lista Liczb(3)
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto a = ask_user_for_integer("a = ");
    auto b = ask_user_for_integer("b = ");
    auto s = ask_user_for_integer("s = ");
        if(s == 0){
            std::cerr << "\n<<ERROR!>>\n" << "s` value cannot be 0!"<<
std::endl; return 1;
        }
    std::cout << std::endl;
    if(s > 0){
        for(auto x = a; x < b; x = (x+s)){
            std::cout << x << std::endl;
        }
    }
        else if(s < 0){
        for(auto x = b; x < a; x = (x-s)){
            std::cout << x << std::endl;
        }
    }
    return 0;
}

// Zadanie 2.0.0.4 Liczba pierwsza
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
int main()
{
    do
    {
        int i, m = 0, counter = 0;

        std::cout << "Enter the Number to check Prime: " << std::endl;
        auto n = ask_user_for_integer("n = ");

        if(n < 2 && n > -1)
        {
            std::cout << "Number is not Prime" << std::endl;
            continue;
        }
        else if(n < 0)
        {
            std::cout << "This is not a positive number" << std::endl;
            continue;

        }
        m = n / 2;
        for (i = 2; i <= m; i++)
        {
            if (n % i == 0)
            {
                std::cout << "Number is not Prime." << std::endl;
                counter = 1;
                break;
            }
        }
        if (counter == 0)
            std::cout << "Number is Prime." << std::endl;

    } while (true);

    return 0;
}

============================================================================================


// Zadanie 2.0.0.7 Suma Podzielnych
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto l = ask_user_for_integer("Limit = ");
    auto d = ask_user_for_integer("Dzielnik = ");

    int s = 0;
    for( auto i = l; 1 <= i; i--){
        if(i % d == 0) {
            s = s+i;
            std::cout << "Suma = " << s << std::endl;
        }
    }
    return 0;
}


// Zadanie 2.0.0.8 Silnia (for)

auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto Factorial = 1;
    auto const x = ask_user_for_integer("x = ");
    for(auto i = 1; i <=x; i++){
        Factorial=Factorial*i;
    }
    std::cout << x << "! = " << Factorial << std::endl;
    return 0;
}


// Zadanie 2.0.0.9 WHILE
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto Factorial = 1;
    auto i = 0;
    auto n = 1;

    auto const x = ask_user_for_integer("x = ");
    while(i < x){
        Factorial=n*Factorial;
        i++;
        n++;
    }
    std::cout << x << "! = " << Factorial << std::endl;
    return 0;
}


// Zadanie 2.0.0.10 DO-WHILE
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto Factorial = 1;
    auto i = 0;
    auto n = 1;

    auto const x = ask_user_for_integer("x = ");
    do{
        Factorial=n*Factorial;
        i++;
        n++;
    }while(i<x);
    std::cout << x << "! = " << Factorial << std::endl;
    return 0;
}

// Zadanie 2.0.0.11 RYSOWANIE FIGURY (prostokąt)
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
    std::cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
    }
auto main() -> int
{
    auto const xi = ask_user_for_integer("x = ");
    auto const y = ask_user_for_integer("y = ");
    for(int x = 0 ; x < xi ; x++)
    {
        for(int d = 0; d < y ; d++)
        {
            std::cout << "*";
        }
    std::cout << std::endl;
    }
    return 0;
}
*/
// Zadanie 2.0.0.12 (trójkąt)
#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int {
  if (not prompt.empty()) {
    std::cout << prompt;
  }
  auto value = std::string{};
  std::getline(std::cin, value);
  return std::stoi(value);
}
auto main() -> int {
  char x = '*';
  auto const a = ask_user_for_integer("a=");
  if (a < 2) {
    std::cout << "Minimal size is 2!" << std::endl;
    return 1;
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
