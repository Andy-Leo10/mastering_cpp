#include <iostream>
#include <memory> // std::shared_ptr, std::unique_ptr
#include <mutex> // std::mutex

void f(void *p){
    std::cout<<"f(void *)"<<std::endl;
}

class Widget{};

int f1(std::shared_ptr<Widget> spw){
    std::cout<<"f1"<<std::endl;
    return 0;
}

double f2(std::unique_ptr<Widget> upw){
    std::cout<<"f2"<<std::endl;
    return 0.0;
}

bool f3(Widget* pw){
    std::cout<<"f3"<<std::endl;
    return false;
}

template <typename FuncType, 
        typename MuxType,
        typename PtrType>
decltype(auto) lockAndCall(FuncType func, 
                        MuxType& mutex, 
                        PtrType ptr){
    std::cout<<"lockAndCall"<<std::endl;
    std::lock_guard<MuxType> g(mutex);
    return func(ptr);
}

int main(){
    f(nullptr);

    std::mutex f1m, f2m, f3m;
    // auto result1=lockAndCall(f1, f1m, 0); // 0 is not a shared pointer
    // auto result2=lockAndCall(f2, f2m, NULL); // NULL is not a unique pointer
    auto result3=lockAndCall(f3, f3m, nullptr); // nullptr is a null pointer value

    return 0;
}

// Things to Remember
// • Prefer nullptr to 0 and NULL.
// • Avoid overloading on integral and pointer types.