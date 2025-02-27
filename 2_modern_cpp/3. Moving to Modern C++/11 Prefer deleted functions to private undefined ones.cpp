#include <iostream>
#include <iostream>

template <class charT, class traits = std::char_traits<charT>>
class basic_ios : public std::ios_base {
public:
    basic_ios() {
        std::cout << "basic_ios default constructor called" << std::endl;
    }
    basic_ios(const basic_ios&) = delete;
    basic_ios& operator=(const basic_ios&) = delete;
    // ...
};

bool isLucky(int number) {return number == 7;}
bool isLucky(char) = delete;
bool isLucky(double) = delete;
bool isLucky(bool) = delete;

template<typename T>
void processPointer(T* ptr) {
    std::cout << "processPointer called" << std::endl;
}

class Widget {
public:
    template<typename T>
    void processPointer(T* ptr) {
        std::cout << "Widget::processPointer called" << std::endl;
    }
};
template<>
void Widget::processPointer<void>(void*) = delete;
template<>
void Widget::processPointer<char>(char*) = delete;

int main(){
    basic_ios<char> ios1;
    // basic_ios<char> ios2(ios1); // error: use of deleted function ‘basic_ios<char>::basic_ios(const basic_ios<char>&)’
    // basic_ios<char> ios3 = ios1; // error: use of deleted function ‘basic_ios<char>::basic_ios(const basic_ios<char>&)’    

    std::cout << isLucky(7) << std::endl;
    // std::cout << isLucky('7') << std::endl; // error: use of deleted function ‘bool isLucky(char)’

    auto ptr = new int;
    processPointer(ptr);
    // processPointer(static_cast<void*>(ptr)); // error: use of deleted function ‘void processPointer(void*)’
    // processPointer(static_cast<char*>(ptr)); // error: use of deleted function ‘void processPointer(char*)’

    Widget w;
    w.processPointer(ptr);
    // w.processPointer(static_cast<void*>(ptr)); // error: use of deleted function ‘void Widget::processPointer(void*)’
    // w.processPointer(static_cast<char*>(ptr)); // error: use of deleted function ‘void Widget::processPointer(char*)’

    return 0;
}

// Things to Remember
// • Prefer deleted functions to private undefined ones.
// • Any function may be deleted, including non-member functions and template
// instantiations.