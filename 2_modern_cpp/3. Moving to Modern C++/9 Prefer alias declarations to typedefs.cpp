#include <iostream>
#include <memory>
#include <unordered_map>
#include <list>
#include <string>
#include <type_traits>

// alias declaration
template <typename T>
using MyAlloc = std::allocator<T>;
template <typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;

int main(){
    // c++ 98 typedef
    typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS1;
    // alias declaration
    using UPtrMapSS2 = std::unique_ptr<std::unordered_map<std::string, std::string>>;
    
    // function pointer using typedef
    typedef void (*FuncPtr1)(int, const std::string&);
    // function pointer using alias declaration
    using FuncPtr2 = void (*)(int, const std::string&);

    MyAllocList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    auto print_list = [&list1](){
        for(auto& i: list1){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    };
    print_list();
    
    return 0;
}

// Things to Remember
// • typedefs don't support templatization, but alias declarations do.
// • Alias templates avoid the “::type” suffix and, in templates, the “typename”
// prefix often required to refer to typedefs.
// • C++14 offers alias templates for all the C++11 type traits transformations.