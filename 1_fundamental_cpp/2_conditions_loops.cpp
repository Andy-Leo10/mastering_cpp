#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
#include "library.hpp" // custom library

// prototypes
void print_text(const std::string& text);
template <typename T>
void print_value(const T& value);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}

// template function
template <typename T>
void print_value(const T& value) {
    std::cout << value << std::endl;
}

// main program
int main(){

    // if and else if condition
    print_text("if and else if condition");
    int number = 5;
    if (number > 5) {
        print_text("Number is greater than 5");
    } else if (number < 5) {
        print_text("Number is less than 5");
    } else {
        print_text("Number is equal to 5");
    }

    // switch case
    print_text("switch case");
    int choice = 2;
    switch (choice) {
        case 1:
            print_text("Choice is 1");
            break;
        case 2:
            print_text("Choice is 2");
            break;
        default:
            print_text("Choice is not 1 or 2");
    }

    // while loop
    print_text("while loop");
    int counter = 0;
    while (counter < 5) {
        print_value(counter);
        counter++;
    }

    // for loop
    print_text("for loop");
    std::string names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    for (int i = 0; i < 5; i++) {
        print_text(names[i]);
    }
    std::list<std::string> names_list = {"Alisson", "Beto", "Carlos", "Damian", "Eva"};
    for (const auto& name : names_list) {
        print_text(name);
    }

    print_text("Hello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}