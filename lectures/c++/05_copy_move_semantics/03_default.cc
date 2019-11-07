#include <iostream>

struct X {
  int a = 5;  // in-class initialization
  double b;
  char c = 'a';
  X() = default;  // in-class initializers are used by the constructors
  //default asks the compiler to use a default constructor
  //the compiler generated constr will use the value above
};

struct Y {
  int a = 77;
  double b;
  char c = 'a';
  //the def constructor, will then, assign 5 to a, b uninitialized, c = 'a' as it is in the in-class init.
  Y() : a{5} {}  // what it is written here wins the in-class initialization
  Y(const Y&) = delete;
};

int main() {
  X x1;    // compiler-generated default ctor
  X x2{};  // compiler-generated default ctor calls {} on uninitialized vars
  std::cout << x1.a << "--" << x1.b << "--" << x1.c << "\n";
  std::cout << x2.a << "--" << x2.b << "--" << x2.c << "\n\n";

  Y y1;    // default ctor
  Y y2{};  // default ctor
  std::cout << y1.a << "--" << y1.b << "--" << y1.c << "\n";
  std::cout << y2.a << "--" << y2.b << "--" << y2.c << "\n";

  // Y y3{y2}; // error: call to a deleted function

  return 0;
}
