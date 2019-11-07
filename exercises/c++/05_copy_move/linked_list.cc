#include <iostream>
#include <memory> //unique_ptr

enum class method {push_back, push_front};

template <class T>
class List
{
    struct node
    {
        std::unique_ptr<node> next;
        T value;

        node(const T& v, node * p): value{v}, next{p} {}
        node(T&& v, node * p): value{std::move(v)}, next{p} {}
    };
    
    std::unique_ptr<node> head;

    void push_back(const T& v);
    //void push_back(T&& v);

    //void push_front(const T& v);
    //void push_front(T&& v);
    node* tail() {
        //if head == nullptr => SEG FAULT

        auto tmp = head.get();
        while (tmp->next)
        {
            tmp = tmp->next.get();
        }
        return tmp;
        
    }
    public:
    /**
     * CONSTRUCTORS
     **/
    List() noexcept = default; //i expect that no exept are thrown
    //move semantic, note: they do not throw exeptions
    List(List&&) noexcept = default;
    List& operator=(List&&) noexcept = default;
    //COPY SEMATICS, since we now we are working on the heap, DO NOT PUT noexcept
    List(const List& l);
    List& operator=(const List& l);
    //copy semantic
    void insert(const T& v, const method m);
    //move semantic
    void insert(T&& v, const method m);//

    //this let the method to access private fields (friend keyword)
    template <class O>
    friend std::ostream& operator<<(std::ostream&, const List<O>&);
};

template <class T>
void List<T>::insert(const T& v, const method m) {
    //head == nullptr
    if(!head) {
        //head.reset(new node{v, nullptr});
        head = std::make_unique<node>(v,nullptr); //make_unique creates a obj in the head which is temporary (??)
        return;
    }

    switch (m)
    {
    case method::push_back:
        push_back(v);
        break;
    //case method::push_front:
    //    push_front(v);
    //    break;
    default:
        AP_ERROR(false) << "Unknown insertion method";
        break;
    }
}

template <class T>
void List<T>::push_back(const T& v){
    node* last = tail();
    //last->next.reset(new node{v,nullptr});
    last->next = std::make_unique<node>(v,nullptr); //C++14 style
}
template <class T>
std::ostream& operator<< (std::ostream& os, const List<T>& l){
    auto tmp = head.get();
    //while(tmp != nullptr)
    while (tmp)
    {
        os << tmp->value << " ";
        tmp = tmp->next.get();
    }
    return os;
}

int main(){
    try{
        List<int> l{};

        l.insert(4,method::push_back);
        l.insert(5,method::push_back);
        l.insert(3,method::push_front);
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }catch(...){
        std::cerr << "Unknown ex." << std::endl;
    }
}