#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
#include "library.hpp" // custom library

// prototypes
void print_text(const std::string& text);
void capture_data();
template <typename T> void print_value(const T& value);
template <typename Container> void print_container(const Container& container);
template <typename MapType> void print_dictionary(const MapType& dict);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}
void capture_data() {
    std::string input;
    std::cout << "Enter some text: ";
    std::getline(std::cin, input);
    std::cout << "You entered: " << input << std::endl;
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

// main program
int main(){
    
    // CODE

    print_text("Hello people!");
    // WhatsUp();
    // ButWhy();
    capture_data();

    return 0;
}