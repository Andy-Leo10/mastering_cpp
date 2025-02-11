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

// template: explicit especialization
template <typename T>
class MyTemplateClassA {
public:
    void display() {
        std::cout << "General template" << std::endl;
    }
};

template <>
class MyTemplateClassA<int> { // Explicit specialization for int
public:
    void display() {
        std::cout << "Specialized template for int" << std::endl;
    }
};

// template: partial especialization
template <typename T, typename U>
class MyTemplateClassB {
public:
    void display() {
        std::cout << "General template" << std::endl;
    }
};

template <typename T>
class MyTemplateClassB<T, int> { // Partial specialization for when the second type is int
public:
    void display() {
        std::cout << "Partial specialization where U is int" << std::endl;
    }
};

// main program
int main(){

    // variable types
    int integer = 5;
    float floating = 5.5;
    double double_floating = 5.555;
    bool boolean = true;
    char character = 'c';
    char character_array[] = "char array!";
    std::string string = "my string!";
    // print variables
    print_text("--variables--");
    print_value(integer);
    print_value(floating);
    print_value(double_floating);
    print_value(boolean);
    print_value(character);
    print_value(character_array);
    print_value(string);

    // list of variables
    std::list<int> list_of_integers = {1, 2, 3, 4, 5};
    std::list<float> list_of_floats = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::list<double> list_of_doubles = {1.111, 2.222, 3.333, 4.444, 5.555};
    std::list<bool> list_of_booleans = {true, false, true, false, true};
    std::list<char> list_of_characters = {'a', 'b', 'c', 'd', 'e'};
    std::list<std::string> list_of_strings = {"one", "two", "three", "four", "five"};
    // operations
    // push front and back
    list_of_integers.push_front(0);
    list_of_integers.push_back(6);
    //concatenate lists: the middle parameter is the list to concatenate
    list_of_integers.insert(list_of_integers.end(), list_of_integers.begin(), list_of_integers.end());
    // print lists
    print_text("--lists--");
    print_container(list_of_integers);
    print_container(list_of_floats);
    print_container<std::list<double>>(list_of_doubles);
    print_container(list_of_booleans);
    print_container(list_of_characters);
    print_container(list_of_strings);

    // dictionaries
    std::map<std::string, int> dictionary;
    dictionary["one"] = 1;
    dictionary["two"] = 2;
    dictionary["three"] = 3;
    // insert data
    dictionary.insert(std::pair<std::string, int>("four", 4));
    // print dictionary
    print_text("--dictionary--");
    print_dictionary(dictionary);

    // explicit template specialization
    print_text("--explicit template specialization--");
    MyTemplateClassA<float> my_template_class_a;
    my_template_class_a.display();
    MyTemplateClassA<int> my_template_class_a_int;
    my_template_class_a_int.display();

    // partial template specialization
    print_text("--partial template specialization--");
    MyTemplateClassB<float, float> my_template_class_b;
    my_template_class_b.display();
    MyTemplateClassB<float, int> my_template_class_b_int;
    my_template_class_b_int.display();

    print_text("Hello people!");
    WhatsUp();
    ButWhy();
    capture_data();

    return 0;
}