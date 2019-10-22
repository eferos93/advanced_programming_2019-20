#include <iostream>

//not working, needs debug
bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while(it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}

int get_int() {
    std::string i;
    while(!(std::cin >> i)) {
        std::string& ref = i;
        if(is_number(ref)) {
            return std::stoi(i);
        }
    }
    return std::stoi(i);
}

int main() {
    int number = get_int();
    std::cout << number << std::endl;
}