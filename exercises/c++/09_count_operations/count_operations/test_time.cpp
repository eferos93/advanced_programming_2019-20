#include "timer.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

timer<> t;

template <typename I>
void set_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  std::set<value_type> set{first, last};
  t.stop();
}

template <typename I>
void vector_timed(const std::size_t n, I first, I last) {
  t.start();
  // iterator_traits::value_type is a static var ????
  using value_type = typename std::iterator_traits<I>::value_type;
  //std::vector<value_type> v{first, last};
  std::sort(first, last);
  //std::sort(v.begin(), v.end());
  //auto it = std::unique(v.begin(), v.end());
  //std::unique returns an iterator pointing one past of the last one
  // sort(132135) = 112335 %>% unique  = 1235
  auto it = std::unique(first, last);
  t.stop();
}

using namespace std::chrono;
int main() {
  using value_type = int;
  // n < (1 << 25), n is left than 2^25 (1 bit-shifted 25)
  // n <<= 1, left bit-shit of one bit (multiply by two, multiply by two), the = updates n
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    std::vector<value_type> v(n);
    std::iota(v.begin(), v.end(), value_type(-1024));
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i) {
      //bitwise AND
      //since std::iota inserts elements st there are no repetitions
      //the numbers will be repeated from 0 to 1023, then again from 0 to 1023
      v[i] = int{v[i]} & 1023;
    }
    std::cout << std::setw(15) << n << "\t";

    //we want to compare these two functions
    //VECTOR IS FASTER
    //because vector have its elements contiguos in memory 
    // for the other reasons see test_count_operations
    set_timed(n,v.begin(),v.end());
    //vector_timed(n, v.begin(), v.end());
  }
}
