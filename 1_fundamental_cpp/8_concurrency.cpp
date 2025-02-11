#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
#include "library.hpp" // custom library
#include <chrono> // chrono
#include <thread> // thread
#include <mutex> // mutex
#include <future> // future, async

// define colors for printing
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define NORMAL "\033[0m"

// prototypes
void print_text(const std::string& text);
void capture_data();
template <typename T> void print_value(const T& value);
template <typename Container> void print_container(const Container& container);
template <typename MapType> void print_dictionary(const MapType& dict);

// functions
void print_text(const std::string& text) {
    std::cout << text << std::endl;
}
void capture_data() {
    std::string input;
    std::cout << "Enter some text: ";
    std::getline(std::cin, input);
    std::cout << "You entered: " << input << std::endl;
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

void timer(int seconds, const std::string& color) {
    for (int i = 0; i < seconds; i++) {
        std::cout << color << "Time remaining: " << seconds - i << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void main2() {
    std::cout << BLUE "Hello from main2!" << std::endl;
    timer(3, BLUE);
    std::cout << BLUE "main2 done!" << std::endl;
}

std::mutex mtx;

void my_shared_function_mutex(const std::string& thread_name, int i) {
    mtx.lock();
    std::cout << thread_name << " is counting: " << i << std::endl;
    mtx.unlock();
}

void my_shared_function_lock_guard(const std::string& thread_name, int i) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << thread_name << " is counting: " << i << std::endl;
}

void thread_function() {
    for (int i=0; i<10; i++) {
        my_shared_function_mutex(BLUE "thread", i);
    }
}

bool is_prime (int x) {
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

// main program
int main(){
    
    // thread example
    print_text(WHITE "--- Thread example ---");
    print_text(RED "Hello from main!");
    std::thread t1(&main2);
    // t1.detach(); // run in background (daemon) is better not to use
    while(!t1.joinable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    t1.join();

    // mutex example
    print_text(WHITE "--- Mutex example ---");
    std::thread t2(&thread_function);
    for (int i=10; i>0; i--) 
        my_shared_function_mutex(RED "main", i);
    t2.join();

    // lock_guard example
    print_text(WHITE "--- Lock guard example ---");
    std::thread t3(&thread_function);
    for (int i=10; i>0; i--) 
        my_shared_function_lock_guard(RED "main", i);
    t3.join();

    // task based concurrency
    print_text(WHITE "--- Task based concurrency ---");
    std::future<bool> fut = std::async(is_prime, 444444443);
    std::cout << "Checking, please wait";
    std::chrono::milliseconds span(100);
    while (fut.wait_for(span)==std::future_status::timeout)
        std::cout << '.' << std::flush;
    bool x=fut.get();
    print_text(x?" is prime":" is not prime");

    print_text(RED "Hello people!");
    // WhatsUp();
    // ButWhy();
    // capture_data();

    return 0;
}