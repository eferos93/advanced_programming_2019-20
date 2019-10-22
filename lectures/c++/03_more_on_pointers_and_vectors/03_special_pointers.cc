#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc;

  int* ap[7];

  void* pv{pi};
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  int* pi2{static_cast<int*>(pv)}; // STATIC cast is performed at COMPILE time
  //double* a = static_cast<double*>(malloc(..)) cast array to double

  pv = ppc;
  pv = ap;
  pv = pi;

  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;  // error, why?
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr; //you cannot dereference null pointers
  pi2 = 0;  // older codes. gets the nullptr

  // pi = NULL; // please don't do this

  double* da{new double[5]{}};
  delete[] da;  // dangling pointer = pointer that points to a mem location that can be used by the OS
  da = nullptr; // set to nullptr

  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  int (*fp)(const char*); //pointer to function of name fp, returns an int, argument of type const char*
  fp = func1;

  fp("hello");

  fp = &func2; //works the same as the one in line 67
  fp("world");

  // fp = func3; // error: wrong signature
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3; //defines a var x of the type pointed by the address &func3
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
