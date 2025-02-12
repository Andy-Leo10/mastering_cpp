#include <iostream> // std::size_t
#include <utility> // std::forward

template <typename T>
class vector {
public:
    T& operator[](std::size_t index){
        static T value;
        return value;
    }
};

class Widget {};

void authenticateUser(){}

bool f(const Widget& w){return true;}

template <typename Container, typename Index>
decltype(auto)
authAndAccess(Container&& c, Index i){
    authenticateUser();
    return std::forward<Container>(c)[i]; // return type is decltype(c[i])
}

int main(){
    const int i=0; // decltype(i) is const int
    bool f(const Widget& w); // decltype(w) is const Widget&, decltype(f) is bool(const Widget&)

    struct Point {
        int x, y; // decltype(Point::x) is int, decltype(Point::y) is int
    };

    Widget w; // decltype(w) is Widget
    if(f(w)){}; // decltype(f(w)) is bool

    vector<int> v; // decltype(v) is vector<int>
    if(v[0] == 0){}; // decltype(v[0]) is int&

    const Widget& cw = w; // decltype(cw) is const Widget&
    auto myWidget1 = cw; // decltype(myWidget1) is Widget
    decltype(auto) myWidget2 = cw; // decltype(myWidget2) is const Widget&
    decltype(auto) result=authAndAccess(v, 0); // decltype(result) is int&

    int x = 0;
    decltype(x) decl_x; // decltype(decl_x) is int
    decltype((x)) decl_x_ref = x; // decltype(decl_x_ref) is int&
    
    return 0;
}

// Things to Remember
// • decltype almost always yields the type of a variable or expression without
// any modifications.
// • For lvalue expressions of type T other than names, decltype always reports a
// type of T&.
// • C++14 supports decltype(auto), which, like auto, deduces a type from its
// initializer, but it performs the type deduction using the decltype rules.