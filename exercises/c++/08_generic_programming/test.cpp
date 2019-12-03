#include "find_if.hpp"

// function object
template<typename T>
class predicate_template{
    T value;
    
    public:
        predicate_template(const T& x) : value{x} {}
        bool operator()(const T& x) const noexcept {
            return x == value;
        }
};

template <class T>
class predicate_template : public predicate_base{
    T value;

    public: 
        predicate_virtual(const T& x) : value{x} {}
        virtual bool operator()(const T& x) const noexcept override {
            return x == value;
        }
};

int main() {
    constexpr std::size_t N = 1024*1024*100;
    constexpr int target = 99'000'000;
    std::vector<int> v(N);
    std::iota(v.begin(), v.end(), 0);

    //auto it = find_if_hardcoded(v.begin(), v.end(), target);

    //LAMBDA FUNCTIONS
    //["capture"]("args"){"body"};
    find_if_hardcoded(v.begin(), v.end(), 
                      [ &target ](int x){return x == target;}
                      );
}