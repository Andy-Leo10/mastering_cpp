#include <iostream> // cout, cin
#include <list> // list
#include <map> // dictionary
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

// struct
struct Bot
{
    std::string name;
    int operating_time;
    void introduce() {
        std::cout << "Hello, I am " << name << "!" << std::endl;
        std::cout << "I have been operating for " << operating_time << " hours." << std::endl;
    }
};

// class
class Robot {
    public:
        // delegate constructor
        Robot() : Robot("C3PO", 2000) {}
        // constructor
        Robot(std::string robot_name, int time) {
            name = robot_name;
            operating_time = time;
        }
        // copy constructor: not allowed
        Robot(const Robot& robot) = delete;
        // move constructor
        Robot(Robot&& robot) {
            name = std::move(robot.name);
            operating_time = std::move(robot.operating_time);
        }
        virtual void introduce() {
            std::cout << "Hello, I am " << name << ". I've operating for " << operating_time << " hours." << std::endl;
        }
        void to_develop_later();
        // method chaining
        Robot& set_name(std::string robot_name) {
            name = robot_name;
            return *this;
        }
        // abstract method: only is declared for an abstract parent class, otherwise the class cannot be instantiated

    protected:
        std::string name;
        int operating_time;
};

void Robot::to_develop_later() {
    std::cout << "This function was written later for " << name << "!" << std::endl;
}

class MobileRobot : public Robot {
    public:
        // delegate constructor
        MobileRobot() : MobileRobot("R4-P44", 777, "differential") {}
        // constructor
        MobileRobot(std::string robot_name, int operating_time, std::string drive_type) : Robot(robot_name, operating_time) {
            this->drive_type = drive_type;
        }
        // override
        void introduce() override {
            std::cout << "Hello, I am " << name << ". I've operating for " << operating_time << " hours." << " My drive type is " << drive_type << "." << std::endl;
        }
    protected:
        std::string drive_type;
};

// example of "static"
class Counter {
public:
    static int count; // Static data member declaration

    Counter() {
        count++;
    }

    static void displayCount() { // Static member function
        std::cout << "Count: " << count << std::endl;
    }
};
// Definition and initialization of static data member
int Counter::count = 0;


// main program
int main(){
    // struct
    print_text("--struct--");
    Bot bot1;
    bot1.name = "Bot1";
    bot1.operating_time = 100;
    bot1.introduce();

    // object of type Robot
    print_text("--pure object--");
    Robot robot1("R2D2", 1000);
    robot1.introduce();
    robot1.to_develop_later();

    // pointer to object of type Robot
    print_text("--pointer to object--");
    Robot* robot2 = new Robot();
    robot2->introduce();
    robot2->set_name("MARS").introduce();
    // properly delete the pointer
    delete robot2;

    print_text("--static variable and function--");
    Counter c1; c1.displayCount();
    Counter c2; c1.displayCount();
    Counter::displayCount(); // Output: Count: 2    

    // move constructor
    print_text("--move constructor--");
    Robot robot3 = std::move(robot1);
    robot3.introduce();

    // class inheritance
    print_text("--inheritance--");
    MobileRobot mobile_robot1;
    mobile_robot1.introduce();

    print_text("Hello people!");
    // WhatsUp();
    // ButWhy();

    return 0;
}