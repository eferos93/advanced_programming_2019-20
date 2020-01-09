#include <iostream>

//static means that each compilation unit owns its private copy of the variable
//namely there is an internal linkage
//in C++ const implies internal linkage

//in this case however static has another purpose

struct Foo {
  static double s;  // must be defined outside the class
  // static int si = 0; // error: must be const
  static const int sc = 9;  // only integral types are allowed
  // static const double sd;  // error
  int i;
};

//I have to declare s and it must be defined outside the class
double Foo::s;

// double Foo::s = 0;
// double Foo::s = 9;

// int Foo::i = 2; // error, only static members can be defined out of class

int main() {
  Foo::s = 77.88;
  Foo f1;
  Foo f2;
  std::cout << sizeof(f1) << std::endl;
  std::cout << f1.s << '\n' << f2.s << '\n' << Foo::s << std::endl;
  return 0;
}

//static has three meanings:
//1st internal linkage
//2nd static variable
//3rd the same as Java static