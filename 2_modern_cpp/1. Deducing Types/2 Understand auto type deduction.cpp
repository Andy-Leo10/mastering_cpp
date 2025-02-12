#include <initializer_list> // for x3 = {27};

template <typename T>
void func_for_x(T param) {} // conceptual template for deducing x's type

template <typename T>
void func_for_cx(const T param) {} // conceptual template for deducing cx's type

template <typename T>
void func_for_rx(const T& param) {} // conceptual template for deducing rx's type

void someFunc(int, double) {}

template <typename T>
void f(std::initializer_list<T> param) {} 

// auto createInitList1(){
//     return {1,2,3}; // error, cannot deduce type for T
// }
std::initializer_list<int> createInitList2(){
    return {1,2,3};
}

int main(){
    auto x = 27; // x is an int (x neither pointer nor reference)
    const auto cx = x; // cx is a const int (cx neither pointer nor reference)
    const auto& rx = x; // rx is a reference to x as a const int (rx is a non-universal ref)

    func_for_x(x); // T is int, param's type is int
    func_for_cx(cx); // T is int, param's type is int
    func_for_rx(rx); // T is int, param's type is const int&

    // type specifier is universal reference
    auto&& uref1 = x; // x is int and lvalue, so uref1's type is int&
    auto&& uref2 = cx; // cx is const int and lvalue, so uref2's type is const int&
    auto&& uref3 = 27; // 27 is int and rvalue, so uref3's type is int&&

    const char name[] = "J. P. Briggs"; // name's type is const char[13]
    auto arr1 = name; // arr1's type is const char*
    auto& arr2 = name; // arr2's type is const char(&)[13]
    
    auto func1 = someFunc; // func1's type is void(*)(int, double)
    auto& func2 = someFunc; // func2's type is void(&)(int, double)

    // declarations
    auto x1 = 27;
    auto x2(27);
    auto x3 = {27};
    auto x4{27};

    // func_for_x({1,2,3}); // error, cannot deduce type for T
    f({1,2,3}); // T is int, param's type is std::initializer_list<int>


    // auto il = createInitList1(); // error, cannot deduce type for T
    auto il = createInitList2(); // il's type is std::initializer_list<int>

    return 0;
}

// Things to Remember
// • auto type deduction is usually the same as template type deduction, but auto
// type deduction assumes that a braced initializer represents a std::initial
// izer_list, and template type deduction doesn't.
// • auto in a function return type or a lambda parameter implies template type
// deduction, not auto type deduction.