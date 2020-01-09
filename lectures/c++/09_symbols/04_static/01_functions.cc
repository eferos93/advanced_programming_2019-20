#include <iostream>

void dwim() {
  //in this case, i remembers the value among different invokations of the function
  static int i = 0;  // this line is executed only once
  ++i;
  std::cout << i << std::endl;
}

int main() {
  dwim();
  dwim();
  dwim();
  dwim();
  dwim();
  return 0;
}
