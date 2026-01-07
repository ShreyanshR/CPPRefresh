#include "utils.h"
#include <iostream>

void Log(const char* message) {
    std::cout << "[LOG] " << message << std::endl;
}

int main() {
    Log("Hello World");
    std::cout << "Welcome to CPPRefresh!" << std::endl;
    
    utils::printMessage("This is a sample C++ project");
    
    int result = utils::add(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;
    
    return 0;
}
