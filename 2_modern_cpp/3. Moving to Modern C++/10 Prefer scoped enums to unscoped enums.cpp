#include <iostream>
#include <vector>
#include <tuple>
#include <string>

std::vector<std::size_t> primeFactors(std::size_t n){
    std::vector<std::size_t> factors;
    for(std::size_t i=2; i<=n; ++i){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }
    return factors;
}

// alias for a tuple
using UserInfo=std::tuple<std::string, // name
                        std::string, // email
                        std::size_t>; // reputation

template <typename E> // auto is std::underlying_type_t<E>
constexpr auto toUType(E enumerator) noexcept{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

int main(){
    enum class Color_scoped {black, 
                            white, 
                            red};
    auto white=false;
    Color_scoped c=Color_scoped::black;
    auto d=Color_scoped::white;
    // now we can't do this if(d<14.4)
    if(static_cast<int>(d)<14.4){
        std::cout<< static_cast<int>(d)<< " is less than 14.4"<<std::endl;
    }
    // we cannot pass Color_scoped::color to a function that expects another type
    auto factors=primeFactors(static_cast<std::size_t>(7));
    auto print_factors=[&factors](){
        for(auto& i: factors){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    };
    print_factors();

    // creation of enum class with default underlying type
    enum class Status {good=0, 
                        bad=1, 
                        invalid=2,
                        unknown=100};
    std::cout<<static_cast<int>(Status::unknown)<<std::endl;

    // creation of enum class with char as underlying type
    enum class Alphabet: char {a='a', 
                                b='b', 
                                c='c'};
    std::cout<<static_cast<char>(Alphabet::b)<<std::endl;

    // make more verbose the tuples
    UserInfo uinfo{"Andres Alamo", "andres.alamo@gmail.com", 100};
    auto name=std::get<0>(uinfo); // raw way
    std::cout<<"Name:"<<name<<std::endl;
    enum class UserInfoFields {uiName, 
                            uiEmail, 
                            uiReputation};
    auto email=std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(uinfo); // general
    std::cout<<"Email:"<<email<<std::endl;
    auto reputation=std::get<toUType(UserInfoFields::uiReputation)>(uinfo); // using the template
    std::cout<<"Reputation:"<<reputation<<std::endl;

    return 0;
}

// Things to Remember
// • C++98-style enums are now known as unscoped enums.
// • Enumerators of scoped enums are visible only within the enum. They convert
// to other types only with a cast.
// • Both scoped and unscoped enums support specification of the underlying type.
// The default underlying type for scoped enums is int. Unscoped enums have no
// default underlying type.
// • Scoped enums may always be forward-declared. Unscoped enums may be
// forward-declared only if their declaration specifies an underlying type.