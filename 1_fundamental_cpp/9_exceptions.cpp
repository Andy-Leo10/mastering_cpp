#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
#include "library.hpp" // custom library

// prototypes
void print_text(const std::string& text);
template <typename T> void print_value(const T& value);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}

// template function
template <typename T>
void print_value(const T& value) {
    std::cout << value << std::endl;
}

int zero_division(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

void multiple(int x) {
    if (x == 0) {
        throw std::runtime_error("Zero");
    } else if (x == 1) {
        throw std::runtime_error("One");
    } else if (x == 2) {
        throw std::runtime_error("Two");
    }
}

class DivideByZero : public std::runtime_error {
public:
    DivideByZero() : std::runtime_error("Division by zero error") {}
};

class opt_1{};
class opt_2 : public std::runtime_error {
public:
    opt_2() : std::runtime_error("Option 2 error") {}
};
class opt_3{};

// main program
int main(){
    
    // handling 1 exception
    print_text("--handling 1 exception--");
    try {
        int a = 10;
        int b = 0;
        int result = zero_division(a, b);
        print_value(result);
    } catch (const std::runtime_error& e) {
        print_text(e.what()); // print error message
    }

    // handling multiple exceptions
    print_text("--handling multiple exceptions--");
    try {
        multiple(0);
        multiple(2);
    } catch (const std::runtime_error& e) {
        print_text(e.what());
    }

    // defined exception class
    print_text("--exception class--");
    try
    {
        int a = 10; int b = 0;
        if(b == 0) {
            DivideByZero d;
            throw d;
        }
        else {
            int result = a / b;
            print_value(result);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; // print error message
    }

    // class level exception
    print_text("--class level exception--");
    try
    {
        int i = 2;
        if(i == 1) throw opt_1();
        else if(i==2) throw opt_2();
        else throw opt_3();
    }
    catch(opt_1 o1)
    {
        std::cout << "Caught opt_1" << std::endl;
    }
    catch(opt_2 o2)
    {
        std::cout << "Caught opt_2" << std::endl;
        std::cerr << o2.what() << '\n'; // print error message
    }
    catch(opt_3 o3)
    {
        std::cout << "Caught opt_3" << std::endl;
    }
    catch(...)
    {
        std::cout << "Default exception" << std::endl;
    }

    print_text("Hello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}