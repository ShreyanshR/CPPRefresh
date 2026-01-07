#include "utils.h"
#include <iostream>

namespace utils {
    void printMessage(const std::string& message) {
        std::cout << "[INFO] " << message << std::endl;
    }
    
    int add(int a, int b) {
        return a + b;
    }
}
