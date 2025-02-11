#include <iostream> // cout, cin
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

    // pointers
    int integer = 5;
    print_value(integer);
    std::cout << "variable address: " << &integer << std::endl;
    int* integer_pointer = &integer;
    std::cout << "pointer address: " << integer_pointer << std::endl;
    std::cout << "pointer value: " << *integer_pointer << std::endl;
    // modify value by updating pointer
    *integer_pointer = 10;
    std::cout << "variable value: " << integer << std::endl;
    // int* pointer;                   // non-constant pointer to non-constant integer
    // const int* pointer;             // non-constant pointer to constant integer
    // int* const pointer;             // constant pointer to non-constant integer
    // const int* const pointer;       // constant pointer to constant integer

    // Lambda function to print array elements
    auto print_array = [](int* array, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    };

    // pointer to array
    int integer_array[] = {1, 2, 3, 4, 5};
    print_array(integer_array, 5);
    int* integer_array_pointer = integer_array;
    std::cout << "\npointer value: " << integer_array_pointer[0] << std::endl;
    *integer_array_pointer = (int)10;
    print_array(integer_array, sizeof(integer_array) / sizeof(integer_array[0]));
    // advance pointer position
    integer_array_pointer++;
    *integer_array_pointer = (int)20;
    print_array(integer_array, sizeof(integer_array) / sizeof(integer_array[0]));  
    integer_array_pointer = &integer_array[2];
    *integer_array_pointer = (int)30;
    print_array(integer_array, sizeof(integer_array) / sizeof(integer_array[0]));
    integer_array_pointer = integer_array + 3;
    *integer_array_pointer = (int)40;
    print_array(integer_array, sizeof(integer_array) / sizeof(integer_array[0]));
    integer_array_pointer = integer_array;
    *(integer_array_pointer + 4) = (int)50;
    print_array(integer_array, sizeof(integer_array) / sizeof(integer_array[0]));

    print_text("\nHello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}