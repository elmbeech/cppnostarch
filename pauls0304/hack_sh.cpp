// example program
#include <iostream>
#include <string>

int main() {
  std::string name;
  std::cout << "What is you name?";
  getline(std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}

