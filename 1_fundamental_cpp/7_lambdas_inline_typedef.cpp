#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
#include "library.hpp" // custom library

// prototypes
void print_text(const std::string& text);
template <typename T> void print_value(const T& value);
template <typename Container> void print_container(const Container& container);
template <typename MapType> void print_dictionary(const MapType& dict);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}

// template function
template <typename T>
void print_value(const T& value) {
    std::cout << value << std::endl;
}
template <typename Container>
void print_container(const Container& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
template <typename MapType>
void print_dictionary(const MapType& dict) {
    print_text("Dictionary:");
    for (const auto& pair : dict) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    print_text("");
}

/** keyword "inline"
 * - inline is a keyword that tells the compiler to insert the code of the function directly into the calling code
 * - this can improve performance by reducing the overhead of calling a function
 * - inline functions are usually defined in header files
 * - inline functions are usually small functions
 * - inline functions are usually used for getter and setter functions
**/
inline int add(int a, int b) {
    return a + b;
}

/** keyword "typedef"
 * - typedef is a keyword that allows you to create an alias for a data type
 * - typedef is used to create a new name for an existing type
 * - typedef is used to make code more readable and easier to understand
 * - typedef can be used with structures, unions, enums, pointers, and functions
**/
typedef unsigned long ulong;
typedef std::list<int> intList;
typedef int (*funcPtr)(int, int);

// main program
int main(){
    
    // inline function
    print_text("\nInline function:");
    print_value(add(2, 3));

    // typedef
    print_text("\nTypedef:");
    ulong bigNumber = 123456789;
    print_value(bigNumber);
    intList numbers = {1, 2, 3, 4, 5};
    print_container(numbers);
    funcPtr addFunc = add;
    print_value(addFunc(2, 3));

    // lambda function
    print_text("\nLambda function:");
    auto merge_words = [](std::string a, std::string b) -> std::string {
        return a + "-" + b;
    };
    print_text(merge_words("join1", "join2"));
    // minimal lambda
    auto dummy_positive = []{ return false;};
    print_value(dummy_positive()? "Positive" : "Negative");
    // capture list: value and reference
    int a = 10;
    int b = 20;
    auto add_values = [a, &b] { 
        b++;
        return a + b;
    };
    print_value("Sum of: " + std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(add_values()));

    print_text("\nHello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}