#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
#include "library.hpp" // custom library
#include <memory> // smart pointers

// prototypes
void print_text(const std::string& text);
void capture_data();

template <typename T>
void print_value(const T& value);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}
int my_function(int a, double b) {
    return 10;
}
void my_operation_passing_function_pointer(int X, double Y, int (*function_pointer)(int, double)) {
    std::cout << "my_operation_passing_function_pointer(" << X << ", " << Y << "): " << function_pointer(X, Y) << std::endl;
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
    
    // array of pointers
    print_text("--array of pointers--");
    char* array_of_pointers[3];
    char array1[] = "abc";
    char array2[] = "def";
    char array3[] = "ghi";
    array_of_pointers[0] = array1;
    array_of_pointers[1] = array2;
    array_of_pointers[2] = array3;
    // print the array of pointers in format: direction -> value
    for (int i = 0; i < 3; i++) {
        std::cout << &array_of_pointers[i] << " -> " << array_of_pointers[i] << std::endl;
    }

    // pointer to function
    print_text("--pointer to function--");
    int (*function_pointer)(int, double) = my_function;
    std::cout << "function_pointer(1, 2.0): " << function_pointer(1, 2.0) << std::endl;
    my_operation_passing_function_pointer(3, 4.0, function_pointer);

    // unique pointer
    print_text("--unique pointer--");
    std::unique_ptr<char> unique_pointer = std::make_unique<char>('A');
    std::cout << "unique_pointer: " << *unique_pointer << std::endl;
    // unique pointer cannot be copied. if you do, the ownership will be transferred
    std::unique_ptr<char> unique_pointer_copy = std::move(unique_pointer);
    std::cout << "unique_pointer_copy: " << *unique_pointer_copy << std::endl;
    if (unique_pointer == nullptr) {
        std::cout << "unique_pointer: null after move" << std::endl;
    }
    else {
        std::cout << "unique_pointer:" << *unique_pointer << std::endl;
    }

    // shared pointer
    print_text("--shared pointer--");
    std::shared_ptr<int> shared_pointer = std::make_shared<int>(10);
    std::shared_ptr<int> shared_pointer_copy;
    shared_pointer_copy = shared_pointer;
    // since shared_pointer_copy is a copy of shared_pointer, they both point 
    // to the same memory location. note: they are not Thread-safe
    std::cout << "shared_pointer: " << *shared_pointer << std::endl;
    std::cout << "shared_pointer_copy: " << *shared_pointer_copy << std::endl;
    // shared pointer increases its reference count when copied
    std::cout << "shared_pointer.use_count(): " << shared_pointer.use_count() << " & shared_pointer_copy.use_count(): " << shared_pointer_copy.use_count() << std::endl;

    // weak pointer
    print_text("--weak pointer--");
    std::weak_ptr<int> weak_pointer = shared_pointer;
    // weak pointer does not increase the reference count
    std::cout << "weak_pointer.use_count(): " << weak_pointer.use_count() << std::endl;
    // to access the memory location, you need to lock the weak pointer
    std::shared_ptr<int> shared_pointer_weak = weak_pointer.lock();
    if (shared_pointer_weak) { // 
        std::cout << "weak_pointer.lock(): " << *shared_pointer_weak << std::endl;
    }
    else {
        std::cout << "weak_pointer.lock(): null" << std::endl;
    }
    // then shared_pointer_weak goes out of scope, the memory location is released
    shared_pointer_weak.reset();
    (shared_pointer_weak == nullptr) ? std::cout << "shared_pointer_weak: null" << std::endl : std::cout << "shared_pointer_weak: not null" << std::endl;

    print_text("Hello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}