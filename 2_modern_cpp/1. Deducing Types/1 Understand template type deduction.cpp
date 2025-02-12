#include <iostream> // std::size_t
#include <array> // std::array

template <typename T>
void f1a(T& param) {}    // ParamType is a Reference

template <typename T>
void f1b(const T& param) {}    // ParamType is a reference to a const

template <typename T>
void f1c(T* param) {}    // ParamType is a Pointer

template <typename T>
void f2(T&& param) {}    // ParamType is a Universal Reference

template <typename T>
void f3(T param) {}    // ParamType is a value

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
    return N;
}

void someFunc(int, double) {}

int main(){
    int x = 27; // x is an int  
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a reference to x as a const int

    // Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
    f1a(x);  // T is int, param's type is int&
    f1a(cx); // T is const int, param's type is const int&
    f1a(rx); // T is const int, param's type is const int&
    f1b(x);  // T is int, param's type is const int&
    f1b(cx); // T is int, param's type is const int&
    f1b(rx); // T is int, param's type is const int&
    f1c(&x); // T is int, param's type is int*
    f1c(&cx); // T is const int, param's type is const int*
    f1c(&rx); // T is const int, param's type is const int*

    // Case 2: ParamType is a Universal Reference
    f2(x);  // T is int&, param's type is int&
    f2(cx); // T is const int&, param's type is const int&
    f2(rx); // T is const int&, param's type is const int& 
    f2(10); // T is int, param's type is int&&

    // Case 3: ParamType is Neither a Pointer nor a Reference
    f3(x);  // T is int, param's type is int
    f3(cx); // T is int, param's type is int
    f3(rx); // T is int, param's type is int
    const char* const ptr = "Fun with pointers"; // ptr is a const pointer to a const char
    f3(ptr); // T is const char*, param's type is const char*

    // Array arguments
    const char name[] = "J. P. Briggs"; // name's type is const char[13]
    const char * ptrToName = name; // name's type is const char*
    f3(name); // T is const char*, param's type is const char* (but name is array)
    f1a(name); // T is const char[13], param's type is const char(&)[13]
    int keyVals[] = {1, 3, 7, 9, 11, 22, 35}; // keyVals's type is int[7]
    int mappedVals[arraySize(keyVals)]; // mappedVals's type is int[7]
    std::array<int, arraySize(keyVals)> mappedVals2; // mappedVals2's type is std::array<int, 7>

    // Function arguments
    f3(someFunc); // T is void(int, double), param's type is void(*)(int, double)
    f1a(someFunc); // T is void(int, double), param's type is void(&)(int, double)

    return 0;
}

// Things to Remember
// • During template type deduction, arguments that are references are treated as
// non-references, i.e., their reference-ness is ignored.
// • When deducing types for universal reference parameters, lvalue arguments get
// special treatment.
// • When deducing types for by-value parameters, const and/or volatile argu-
// ments are treated as non-const and non-volatile.
// • During template type deduction, arguments that are array or function names
// decay to pointers, unless they're used to initialize references.
