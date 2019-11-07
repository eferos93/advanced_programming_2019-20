#include <iostream>

int main(int argc, char* argv[]) {
  //note that argv[0] contains "./source.x"
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
