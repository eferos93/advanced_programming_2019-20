#include <fstream>
#include <iostream>
#include <string>
int main() {
  std::ifstream f{"a_file.txt"};
  std::string word;
  f >> word; // i get the first word from the input file stream
  std::cout << "first read word: " << word << std::endl;
  f >> word;
  std::cout << "second read word: " << word << std::endl;
  f >> word;
  std::cout << "third read word: " << word << std::endl;
  f >> word;
  std::cout << "fourth read word: " << word << std::endl;
  int a;
  f >> a;
  std::cout << "first read integer: " << a << std::endl;

  return 0;
}
