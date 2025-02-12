#include <iostream>
#include <boost/type_index.hpp>

template <typename T>
class TD; // Type Displayer

template <typename T>
void f(const T& param){
    using std::cout;
    cout << "T = " << typeid(T).name() << '\n';
    cout << "param = " << typeid(param).name() << '\n';
}

template<typename T>
void boost_type(const T& param){
    using std::cout;
    using boost::typeindex::type_id_with_cvr;
    // show T
    cout << "T = "
    << type_id_with_cvr<T>().pretty_name()
    << '\n';
    // show param's type
    cout << "param = "
    << type_id_with_cvr<decltype(param)>().pretty_name()
    << '\n';
}

int main(){
    const int theAnswer = 42;
    auto x = theAnswer; // x is an int
    auto y = &theAnswer; // y is a const int*

    // this will not compile, but return the type of x and y
    // TD<decltype(x)> xType; // xType is an int
    // TD<decltype(y)> yType; // yType is const int*

    f(x); // void f<int>(const int &param)
    f(y); // void f<const int *>(const int *const &param)

    boost_type(x);
    boost_type(y);

    return 0;
}

// Things to Remember
// • Deduced types can often be seen using IDE editors, compiler error messages,
// and the Boost TypeIndex library.
// • The results of some tools may be neither helpful nor accurate, so an under-
// standing of C++'s type deduction rules remains essential.