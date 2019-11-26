template <typename T>
// do we have some constraints on T?
class Vector 
{
    std::size_t _size{};
    std::unique_ptr<T[]> elem{};
    std::size_t capacity{};

    void check_and_increase_capacity() {
        if (_capacity == 0)
        {
            reserve(8);
        }
        
        if(_size == _capacity)
        {
            reserve(2*_size);
        } 
        else
        {

        }

    }

    void reserve(const std::size_t new_size) 
    {
        T* new_array = new T[new_size];

        for (std::size_t i=0; i<_size; ++i) {
            new_array[i] = std::move(elem[i]);
        }
        elem.reset(new_array);
        _capacity = new_size;
    }
public:
    auto size() const 
    Vector() = default;
    //avoid implicit conversion
    explicit Vector(const std::size_t& length):
        _size{length},
        elem{new T[length]{}},
        _capacity{length}
        {}
    void push_back(const T& x) {
        check_and_increase_capacity();
        elem[_size] = x;
        ++_size;
    }

    template <typename OT>
    void push_back(OT&& x) {
        check_and_increase_capacity();
        elem[_size] = std::forward<OT>(x);
        ++_size;
    }

    void push_back(T&& x) {
        check_and_increase_capacity();
        elem[_size] = std::move(x);
        ++_size;
    }
    //variadic templates;  template that accepts a undefined number of a type
    template <typename... Types> //parameter pack
    void emplace_back(Types&&... args) {
        check_and_increase_capacity();
        elem[_size] = T{std::forward<Types>(args)...};
        ++_size;
    }
};


//STRUCT default visibility is public
//CLASS what should be kept secret? fields, which represent the state
//      if the value of those memebers
int main() 
{

    Vector<value_type> v;
    value_type x;
    v.push_back(x);

    return 0;
}