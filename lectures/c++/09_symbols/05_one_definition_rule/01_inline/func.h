#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>

//inline means: do not put a jump to that function
//suggestion for the compiler, namely, copy and paste the content of the function
//just a suggestion, compiler could ignore it
//in C++ inline implies internal linkage (static)
inline void dummy() {
  std::cout << "dummy\n";
}

#endif /* _FUNC_H_ */
