#include <iostream> // cout, cin
#include <list> // list
#include <vector> // vector
#include <deque> // deque
#include <forward_list> // forward_list
#include <set> // set
#include <map> // dictionary
#include <unordered_map> // unordered_map
#include "library.hpp" // custom library

// prototypes
void print_text(const std::string& text);
template <typename T>
void print_value(const T& value);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}

// template function
template <typename T>
void print_value(const T& value) {
    std::cout << value << std::endl;
}
template <typename Container>
void print_container(const Container& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
template <typename MapType>
void print_dictionary(const MapType& dict) {
    print_text("Dictionary:");
    for (const auto& pair : dict) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    print_text("");
}

// main program
int main(){
    
    // vector: dynamic array in forward direction - contiguous memory
    print_text("-> vector");
    std::vector<int> integer_vector = {1, 2, 3};
    integer_vector.push_back(4);
    print_container(integer_vector);
    print_value(integer_vector.at(0));
    integer_vector.pop_back();
    print_container(integer_vector);

    // deque: dynamic array in both directions - not necessary contiguous memory
    print_text("<-> deque");
    std::deque<char> char_deque = {'a', 'b', 'c'};
    char_deque.push_front('z');
    print_container(char_deque);
    char_deque.pop_back();
    print_container(char_deque);
    char_deque.pop_front();
    char_deque.at(1) = 'B';
    char_deque.push_back('C');
    print_container(char_deque);

    // list: dynamic array in both directions - non-contiguous memory
    print_text("<-> list");
    std::list<std::string> string_list = {"one", "two", "three"};
    string_list.pop_back();
    string_list.push_front("zero");
    print_container(string_list);
    // reverse
    string_list.reverse();
    print_container(string_list);
    // swap
    std::list<std::string> string_list2 = {"four", "five"};
    string_list.swap(string_list2);
    print_container(string_list);
    print_container(string_list2);
    // sort
    string_list.sort();
    print_container(string_list);
    // merge
    string_list.merge(string_list2);
    print_container(string_list);

    // forward_list: dynamic array in forward direction - non-contiguous memory
    print_text("-> forward_list");
    std::forward_list<float> float_forward_list = {1.1, 2.2, 3.3};
    print_container(float_forward_list);
    float_forward_list.assign({4.4, 5.5, 6.6});
    print_container(float_forward_list);
    float_forward_list.push_front(0.0);
    print_container(float_forward_list);


    // set: unique elements, sorted
    print_text("-- set");
    std::set<int> integer_set = {2, 1, 3, 4, 3};
    integer_set.insert(6);
    print_container(integer_set);
    // erase greater than 5
    integer_set.erase(integer_set.upper_bound(5), integer_set.end());
    print_container(integer_set);
    // erase less than 3
    integer_set.erase(integer_set.begin(), integer_set.lower_bound(3));
    print_container(integer_set);
    
    // multi-set: multiple elements, sorted
    print_text("-- multi-set");
    std::multiset<int> integer_multiset = {2, 1, 3, 4, 3};
    integer_multiset.insert(6);
    print_container(integer_multiset);
    // erase greater than 5
    integer_multiset.erase(integer_multiset.upper_bound(5), integer_multiset.end());
    print_container(integer_multiset);
    // erase less than 3
    integer_multiset.erase(integer_multiset.begin(), integer_multiset.lower_bound(3));
    print_container(integer_multiset);

    // map: key-value pairs, sorted by key
    print_text("-- map");
    std::map<std::string, int> string_int_map = {{"one", 1}, {"two", 2}, {"three", 3}};
    string_int_map.insert({"four", 4});
    string_int_map.insert({"www", 5});
    print_dictionary(string_int_map);
    // erase less than "three"
    string_int_map.erase(string_int_map.begin(), string_int_map.lower_bound("three"));
    print_dictionary(string_int_map);
    // erase greater than "two"
    string_int_map.erase(string_int_map.upper_bound("two"), string_int_map.end());
    print_dictionary(string_int_map);

    // unordered_map: key-value pairs, not sorted
    print_text("-- unordered_map");
    std::unordered_map<std::string, int> string_int_unordered_map = {{"one", 1}, {"two", 2}, {"three", 3}};
    string_int_unordered_map.insert({"four", 4});
    string_int_unordered_map.insert({"www", 5});
    print_dictionary(string_int_unordered_map);
    // - find
    auto iterator = string_int_unordered_map.find("two");
    if (iterator != string_int_unordered_map.end()) {
        print_value(iterator->second);
    }
    // - erase
    string_int_unordered_map.erase("two");
    print_dictionary(string_int_unordered_map);


    // iterator
    print_text(".. iterator");
    std::vector<int> integer_vector2 = {1, 2, 3, 4, 5};
    for (auto it = integer_vector2.begin(); it != integer_vector2.end(); ++it) {
        std::cout << *it << " ";
    }

    print_text("Hello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}