#include <iostream>
#include <vector>
#include <algorithm>

template <typename C, typename V>
void findAndInsert(C& container, 
                const V& targetVal, 
                const V& insertVal){
    using std::cbegin;
    using std::cend;
    auto it=std::find(cbegin(container), cend(container), targetVal);
    container.insert(it, insertVal);
}

int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    // Using const_iterator to iterate over the vector
    std::vector<int>::const_iterator it;
    for (it = numbers.cbegin(); it != numbers.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // using the template function
    findAndInsert(numbers, 3, 7);
    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Things to Remember
// • Prefer const_iterators to iterators.
// • In maximally generic code, prefer non-member versions of begin, end,
// rbegin, etc., over their member function counterparts.