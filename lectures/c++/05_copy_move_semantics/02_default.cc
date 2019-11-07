#include <iostream>
#include <string>

struct S {
  int a;
  double b;
  std::string s;  // default ctor of string set s to empty string
};

int main() {
  S s1;  // calls default constructor

  S s2{1, 2.3, "alberto"};  // if there are no custom ctors I can
                            // directly initialize the members. Note
                            // that I need access (i.e. they must be
                            // public)
  // it is called aggregate initialization (see
  // https://en.cppreference.com/w/cpp/language/aggregate_initialization)
  // 

  S s3{};  // calls {} on each member: equivalent to S s3 { {}, {}, {} };

  // randomly initialised, empty stgring
  std::cout << s1.a << "--" << s1.b << "--" << s1.s << "\n"; // empty string, weird values for the integer and double
  // normal behaviour
  std::cout << s2.a << "--" << s2.b << "--" << s2.s << "\n";
  // 
  std::cout << s3.a << "--" << s3.b << "--" << s3.s << "\n";

  return 0;
}
