#include <iostream>
#include <vector>
#include <atomic>

class Widget{
public:
    Widget(int i, bool b){
        std::cout<<"Default constructor"<<std::endl;
    }
    Widget(std::initializer_list<long double> il){
        std::cout<<"Initializer list constructor"<<std::endl;
    }
private:
    int x{0};
    int y=0;
    // int z(0); error
};

template <typename T, typename Ts>
void doSomeWork1(Ts&& params){
    T localObject(std::forward<Ts>(params)); // using parentheses 
    std::cout<<"type of localObject1: "<<typeid(localObject).name()<<std::endl;
}

template <typename T, typename Ts>
void doSomeWork2(Ts&& params){
    T localObject{std::forward<Ts>(params)}; // using braces 
    std::cout<<"type of localObject2: "<<typeid(localObject).name()<<std::endl;
}

int main(){
    Widget w1(10, true); // constructor
    Widget w2=w1; // copy constructor
    Widget w3{1.0, 2.0, 3.0}; // initializer list constructor
    Widget w4{{}}; // initializer list constructor

    // use of braces
    std::vector<int> v{1,2,3,4,5}; // initializer list

    // uncopyable objects may be initialized using braces or parentheses
    std::atomic<int> ai1{0};
    std::atomic<int> ai2(0);
    // std::atomic<int> ai3=0; // error

    doSomeWork1<std::vector<int>>(v); 
    doSomeWork2<std::vector<int>>(v); 
    // the important thing is to know that the choice between parentheses 
    // and braces can make a significant difference in some cases, std::initializer_list

    return 0;
}

// Things to Remember
// • Braced initialization is the most widely usable initialization syntax, it prevents
// narrowing conversions, and it's immune to C++'s most vexing parse.
// • During constructor overload resolution, braced initializers are matched to
// std::initializer_list parameters if at all possible, even if other construc-
// tors offer seemingly better matches.
// • An example of where the choice between parentheses and braces can make a
// significant difference is creating a std::vector<numeric type> with two
// arguments.
// • Choosing between parentheses and braces for object creation inside templates
// can be challenging.