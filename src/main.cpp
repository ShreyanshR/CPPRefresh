#include <iostream>
#include "utils.h"
#include <ostream>
#include <vector>

#define LOG(x) std::cout << x << std::endl;

void Increment(int& value){
    value++;
}

class Player{


    int x, y;
    int speed;

    Player(){
        x = 0;
        y = 0;
        speed = 5;
    }
    void move(int newX, int newY){
        x = newX;
        y = newY;
    }
};

class Log{
    public:
};

struct Entity
{
    static int x, y;

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

struct Vertex
{
    float x,y,z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
        {

        }

    //Copy constructor
    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.y)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main() {
    /*LOG("Hello World");
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
    */

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(1,2,3));
    vertices.push_back(Vertex(4,5,6));
    vertices.push_back(Vertex(7,8,9));

    //for(int i = 0; i < vertices.size(); i++)
    //    std::cout << vertices[i] << std::endl;


    //vertices.erase(vertices.begin()+1);

    //for (Vertex v: vertices)
    //    std::cout << v << std::endl;

    
    std::cin.get();
    
    return 0;
}
