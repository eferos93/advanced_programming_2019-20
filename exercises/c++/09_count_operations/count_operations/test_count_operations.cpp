#include "instrumented.hpp"
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

template <typename I>
void set_instrumented(const std::size_t n, I first, I last) {
  using value_type = typename std::iterator_traits<I>::value_type;
  value_type::initialize(n);
  std::set<value_type> set{first, last};
  value_type::print_summary();
}

template <typename I>
void vector_instrumented(const std::size_t n, I first, I last) {
  using value_type = typename std::iterator_traits<I>::value_type;
  std::vector<value_type> v{first, last};
  //value_type is instrumented<int>, initilized is a static function
  value_type::initialize(n);
  std::sort(v.begin(), v.end());
  auto it = std::unique(v.begin(), v.end());
  value_type::print_summary();
}

int main() {
  //instrumented is a claas that counts operations
  using value_type = instrumented<int>;
  value_type::print_header();
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    std::vector<value_type> v(n);
    std::iota(v.begin(), v.end(), value_type(-1024));
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i){
      //v[i] is of type instrumented<int>
      //line 41 in instrumented.hpp there is the convertion operator
      //in which T will be substitued by T
      v[i] = int{v[i]} & 1023;
    }
    //SET does less operations as it uses a RBT, but it slower as 
    //the data are not contiguos in memory
    //BUT it is not said that the set is slower, if the operation cost
    //is very high, therefore set could perform better than vector
    // set_instrumented(n,v.begin(),v.end());
    vector_instrumented(n, v.begin(), v.end());
  }
}
