#include <iostream>
#include <vector>

class Widget {
    // Widget class definition
};

std::vector<bool> features(const Widget& w) {
    // Example implementation
    return std::vector<bool>{true, false, true, false, true, true};
}

void processWidget(const Widget& w, bool highPriority) {
    std::cout << "Processing Widget with high priority: " << highPriority << std::endl;
}

int main() {
    Widget w;
    bool highPriorityBool = features(w)[5]; // highPriority is a bool
    processWidget(w, highPriorityBool);
    auto highPriorityAuto = static_cast<bool>(features(w)[3]); // highPriority is a std::vector<bool>::reference
    processWidget(w, highPriorityAuto);

    // using of static_cast
    auto x = 27;
    auto y = static_cast<double>(x);
    auto z = static_cast<char>(y);
    return 0;
}

// Things to Remember
// • “Invisible” proxy types can cause auto to deduce the “wrong” type for an ini‐
// tializing expression.
// • The explicitly typed initializer idiom forces auto to deduce the type you want
// it to have.