#include <iostream> // for std::cout
#include <iterator> // for std::begin, std::end
#include <memory> // for std::unique_ptr
#include <functional> // for std::function

template <typename It>
void dwim(It b, It e){
    while(b != e){
        // typename std::iterator_traits<It>::value_type currValue = *b;
        auto currValue = *b; // instead of previous line
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    dwim(std::begin(arr), std::end(arr));

    // for values pointed to by anything pointer-like
    auto derefLess = [](const auto& a, const auto& b){
        return *a < *b;
    };
    auto c = derefLess(&arr[0], &arr[1]);

    // another way of creating lambdas, but is recommended to better use auto
    std::function<bool(const std::unique_ptr<int>&, const std::unique_ptr<int>&)> derefLess2 = [](const std::unique_ptr<int>& a, const std::unique_ptr<int>& b){
        return *a < *b;
    };
    std::unique_ptr<int> p1(new int(1));
    std::unique_ptr<int> p2(new int(2));
    auto c2 = derefLess2(p1, p2);

    return 0;
}

// Things to Remember
// • auto variables must be initialized, are generally immune to type mismatches
// that can lead to portability or efficiency problems, can ease the process of
// refactoring, and typically require less typing than variables with explicitly
// specified types.
// • auto-typed variables are subject to the pitfalls described in Items 2 and 6.