#include <iostream> // cout, cin

// prototypes
void print_text(const std::string& text);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}

// main program
int main(){
    print_text("Hello, World!");
    return 0;
}