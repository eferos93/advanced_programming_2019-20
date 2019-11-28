#include <iostream>

template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};

//base class is templated, we need to use keyword "this"
//to call foo()
//if your base is templated, use this
template <typename T>
struct Derived : public Base<T> {
  void bar() const { this->foo(); }
};

int main() {
  Derived<int> d;
  d.bar();
}
