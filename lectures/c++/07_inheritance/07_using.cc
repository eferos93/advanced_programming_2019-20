#include <iostream>
//function overloading works through hierarchy by utilizing "using"

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  using foo::f;  // brings all foo::f to this scope
  void f(char x) { std::cout << "char " << x << std::endl; }
};

int main() {
  bar b;
  //without "using foo::f" this would call f(char x)
  b.f(33);
}
