//extern is for the linker for linking the c and c++ symbols
//include is for the compiler
extern "C" {
#include "hello.h"
}

int main() {
  hello_from_c();
  return 0;
}
