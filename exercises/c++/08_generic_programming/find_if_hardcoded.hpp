#ifndef __find_if_hardcoded
#define __find_if_hardcoded
//iterators 
template<typename T>
struct predicate_base{
    //overloading operator ()
    virtual bool operator()(const T&) const = 0;
};

template <typename I>
    //requires I is Iterator
    //*I is compatible with predicate
    I __find_if_(I first, const I last, const preticate_base& predicate) {
        while( first != last && !predicate(*first) ) {
            ++first;
        }
        return first;
    }

#endif