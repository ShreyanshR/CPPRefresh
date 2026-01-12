#include "utils.h"
#include <iostream>
#define LOG(x) std::cout << x << std::endl;

void Increment(int& value){
    value++;
}

class Player{


    int x, y;
    int speed;

    Player(){
        x = 0;
        y = 0:
        speed = 5;
    }
    void move(x, y){

    }
};

class Log{
    public:
}

struct Entity
{
    static int x, y;

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
}

int main() {
    LOG("Hello World");
    int var = 8;
    char* buffer = new char[8];
    memset(buffer, 0, 8);

    char** ptr = &buffer;

    int a = 5;
    Increment(a);
    LOG(a);

    std::cout << "Welcome to CPPRefresh!" << std::endl;
    
    utils::printMessage("This is a sample C++ project");
    
    int result = utils::add(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;
    
    return 0;
}
