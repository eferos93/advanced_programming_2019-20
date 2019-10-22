#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc{&a}; //read from right to left: a pointer to integer constant
  // *pc = 7; 	// error because when you cannot change the value when deferencing it
  a = 15;  // I can obviously change a

  int* const cp{&a}; //you can change the value of referenced, but not the pointer
  a = b;
  *cp = 33; 
  // cp = &b;   // error

  const int* const cpc{&a};

  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l}; // points one past the last element of a
  for (; a != end; ++a)
    std::cout << *a << std::endl;
}
